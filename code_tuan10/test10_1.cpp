#include <iostream>
#include <fstream>
using namespace std;

class SV {
protected:
    string lopHoc;
    string hoTen;

public:
    virtual void nhap() = 0;
    virtual void hienThi() = 0;
    virtual void ghi(ofstream& file) = 0;
    virtual void doc(ifstream& file) = 0;
};

class SVSP : public SV {
private:
    float hocBong;

public:
    void nhap() {
        cout << "Nhap lop hoc: ";
        cin >> lopHoc;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap hoc bong: ";
        cin >> hocBong;
    }

    void hienThi() {
        cout << "Loai sinh vien: SVSP" << endl;
        cout << "Lop hoc: " << lopHoc << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Hoc bong: " << hocBong << endl;
    }

    void ghi(ofstream& file) {
        file << "SVSP" << endl;
        file << lopHoc << endl;
        file << hoTen << endl;
        file << hocBong << endl;
    }

    void doc(ifstream& file) {
        file >> lopHoc;
        file.ignore();
        getline(file, hoTen);
        file >> hocBong;
    }

    bool operator>(const SVSP& other) {
        return hocBong > other.hocBong;
    }
};

class SVKS : public SV {
private:
    int hocPhi;

public:
    void nhap() {
        cout << "Nhap lop hoc: ";
        cin >> lopHoc;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap hoc phi: ";
        cin >> hocPhi;
    }

    void hienThi() {
        cout << "Loai sinh vien: SVKS" << endl;
        cout << "Lop hoc: " << lopHoc << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Hoc phi: " << hocPhi << endl;
    }

    void ghi(ofstream& file) {
        file << "SVKS" << endl;
        file << lopHoc << endl;
        file << hoTen << endl;
        file << hocPhi << endl;
    }

    void doc(ifstream& file) {
        file >> lopHoc;
        file.ignore();
        getline(file, hoTen);
        file >> hocPhi;
    }

    bool operator>(const SVKS& other) {
        return hocPhi > other.hocPhi;
    }
};

void sapXepSVSP(SVSP** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                SVSP* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sapXepSVKS(SVKS** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                SVKS* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ghiFile(SV** danhSach, int n) {
    ofstream file("output10_1.txt");
    if (file.is_open()) {
        file << n << endl;
        for (int i = 0; i < n; i++) {
            danhSach[i]->ghi(file);
        }
        file.close();
        cout << "Da ghi du lieu vao file." << endl;
    }
    else {
        cout << "Khong the mo file." << endl;
    }
}

void docFile(SV**& danhSach, int& n) {
    ifstream file("input10_1.txt");
    if (file.is_open()) {
        file >> n;
        file.ignore();
        danhSach = new SV*[n];
        for (int i = 0; i < n; i++) {
            string loai;
            getline(file, loai);
            if (loai == "SVSP") {
                danhSach[i] = new SVSP();
            }
            else if (loai == "SVKS") {
                danhSach[i] = new SVKS();
            }
            danhSach[i]->doc(file);
        }
        file.close();
        cout << "Da doc du lieu tu file." << endl;
    }
    else {
        cout << "Khong the mo file." << endl;
    }
}


int main() {
    SV** danhSach;
    int n;

    docFile(danhSach, n);

    cout << "Danh sach sinh vien truoc khi sap xep:" << endl;
    for (int i = 0; i < n; i++) {
        danhSach[i]->hienthiFile();
        cout << endl;
    }

    if (n > 0) {
        sapXepSVSP(reinterpret_cast<SVSP**>(danhSach), n);
        sapXepSVKS(reinterpret_cast<SVKS**>(danhSach), n);
    }

    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    for (int i = 0; i < n; i++) {
        danhSach[i]->hienThi();
        cout << endl;
    }
    ghiFile(danhSach,n);

    delete[] danhSach;
    return 0;
}
