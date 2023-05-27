#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class SV {
protected:
    string lopHoc;
    string hoTen;

public:
    SV() {}
    SV(const string& lopHoc, const string& hoTen) : lopHoc(lopHoc), hoTen(hoTen) {}

    virtual void nhap() {
        cout << "Nhap lop hoc: ";
        cin >> lopHoc;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
    }

    virtual void hienThi() const {
        cout << "Lop hoc: " << lopHoc << endl;
        cout << "Ho ten: " << hoTen << endl;
    }
     string getlophoc() const {
        return lopHoc;
    }
     string gethovaten() const {
        return hoTen;
    }
};

class SVSP : public SV {
private:
    double hocBong;

public:
    SVSP() {}
    SVSP(const string& lopHoc, const string& hoTen, double hocBong) : SV(lopHoc, hoTen), hocBong(hocBong) {}

    void nhap() override {
        SV::nhap();
        cout << "Nhap hoc bong: ";
        cin >> hocBong;
    }

    void hienThi() const override {
        SV::hienThi();
        cout << "Hoc bong: " << hocBong << endl;
    }

    bool operator>(const SVSP& other) const {
        return hocBong > other.hocBong;
    }
};

class SVKS : public SV {
private:
    double hocPhi;

public:
    SVKS() {}
    SVKS(const string& lopHoc, const string& hoTen, double hocPhi) : SV(lopHoc, hoTen), hocPhi(hocPhi) {}

    void nhap() override {
        SV::nhap();
        cout << "Nhap hoc phi: ";
        cin >> hocPhi;
    }

    void hienThi() const override {
        SV::hienThi();
        cout << "Hoc phi: " << hocPhi << endl;
    }

    bool operator>(const SVKS& other) const {
        return hocPhi > other.hocPhi;
    }

};
void ghiSinhVien(ofstream& outFile, const SV& sv) {
    outFile << "Lop hoc: " << sv.getlophoc() << endl;
    outFile << "Ho ten: " << sv.gethovaten() << endl;
}

int main() {
    vector<SVSP> danhSachSVSP;
    vector<SVKS> danhSachSVKS;

    // Đọc dữ liệu từ tệp input.txt
    ifstream inFile("input10_1.txt");
    if (!inFile) {
        cerr << "Khong the mo file input.txt" << endl;
        return 1;
    }

    int n;
    inFile >> n;

    for (int i = 0; i < n; i++) {
        string loaiSinhVien;
        inFile >> loaiSinhVien;

        if (loaiSinhVien == "SVSP") {
            string lopHoc;
            string hoTen;
            double hocBong;
            inFile.ignore();
            getline(inFile, lopHoc);
            getline(inFile, hoTen);
            inFile >> hocBong;
            SVSP svsp(lopHoc, hoTen, hocBong);      
            danhSachSVSP.push_back(svsp);
            } else if (loaiSinhVien == "SVKS") {
                string lopHoc;
                string hoTen;
                double hocPhi;
                inFile.ignore();
                getline(inFile, lopHoc);
                getline(inFile, hoTen);
                inFile >> hocPhi;
                SVKS svks(lopHoc, hoTen, hocPhi);
                danhSachSVKS.push_back(svks);
        }
}
inFile.close();

// Hiển thị thông tin các đối tượng SVSP và SVKS
cout << "Danh sach SVSP: " << endl;
for (const SVSP& svsp : danhSachSVSP) {
    svsp.hienThi();
    cout << endl;
}

cout << "Danh sach SVKS: " << endl;
for (const SVKS& svks : danhSachSVKS) {
    svks.hienThi();
    cout << endl;
}

// Sắp xếp danh sách SVSP và SVKS
sort(danhSachSVSP.begin(), danhSachSVSP.end(), [](const SVSP& a, const SVSP& b) {
    return a > b;
});

sort(danhSachSVKS.begin(), danhSachSVKS.end(), [](const SVKS& a, const SVKS& b) {
    return a > b;
});

// Ghi thông tin các đối tượng SVSP vào tệp output.txt
ofstream outFile("output10_1.txt");
if (!outFile) {
    cerr << "Khong the mo file output.txt" << endl;
    return 1;
}

outFile << "Danh sach SVSP sau khi sap xep theo hoc bong: " << endl;
for (const SVSP& svsp : danhSachSVSP) {
    ghiSinhVien(outFile, svsp);
    outFile << endl;
}

// Ghi thông tin các đối tượng SVKS vào tệp output.txt
outFile << "Danh sach SVKS sau khi sap xep theo hoc phi: " << endl;
for (const SVKS& svks : danhSachSVKS) {
    ghiSinhVien(outFile, svks);
    outFile << endl;
}

outFile.close();

return 0;
}
