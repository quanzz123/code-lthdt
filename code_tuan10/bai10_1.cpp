#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class SV {
protected:
    string lopHoc;
    string hoTen;
public:
    SV() {}
    SV(string lopHoc, string hoTen) : lopHoc(lopHoc), hoTen(hoTen) {}
    virtual void nhap() {
        cout << "Nhap lop hoc: ";
        cin >> lopHoc;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
    }
    virtual void hienThi() {
        cout << "Lop hoc: " << lopHoc << endl;
        cout << "Ho ten: " << hoTen << endl;
    }
    virtual void ghi(ofstream& file) {
        file << lopHoc << endl;
        file << hoTen << endl;
    }
    virtual void doc(ifstream& file) {
        getline(file, lopHoc);
        getline(file, hoTen);
    }
};

class SVSP : public SV {
private:
    float hocBong;
public:
    SVSP() {}
    SVSP(string lopHoc, string hoTen, float hocBong) : SV(lopHoc, hoTen), hocBong(hocBong) {}
    void nhap() {
        SV::nhap();
        cout << "Nhap hoc bong: ";
        cin >> hocBong;
    }
    void hienThi() {
        SV::hienThi();
        cout << "Hoc bong: " << hocBong << endl;
    }
    void ghi(ofstream& file) {
        SV::ghi(file);
        file << hocBong << endl;
    }
    void doc(ifstream& file) {
        SV::doc(file);
        file >> hocBong;
        file.ignore();
    }
    bool operator>(const SVSP& other) {
        return hocBong > other.hocBong;
    }
};

class SVKS : public SV {
private:
    float hocPhi;
public:
    SVKS() {}
    SVKS(string lopHoc, string hoTen, float hocPhi) : SV(lopHoc, hoTen), hocPhi(hocPhi) {}
    void nhap() {
        SV::nhap();
        cout << "Nhap hoc phi: ";
        cin >> hocPhi;
    }
    void hienThi() {
        SV::hienThi();
        cout << "Hoc phi: " << hocPhi << endl;
    }
    void ghi(ofstream& file) {
        SV::ghi(file);
        file << hocPhi << endl;
    }
    void doc(ifstream& file) {
        SV::doc(file);
        file >> hocPhi;
        file.ignore();
    }
    bool operator>(const SVKS& other) {
        return hocPhi > other.hocPhi;
    }
};

void sapXepSVSP(SVSP** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*arr[i] > *arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void sapXepSVKS(SVKS** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*arr[i] > *arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void nhapDanhSach(SV** arr, int n) {
    for (int i = 0; i < n; i++) {
        int choice;
        cout << "Nhap loai sinh vien (1 - SVSP, 2 - SVKS): ";
        cin >> choice;

        if (choice == 1) {
            arr[i] = new SVSP();
        }
        else if (choice == 2) {
            arr[i] = new SVKS();
        }
        arr[i]->nhap();
    }
}

void hienThiDanhSach(SV** arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i]->hienThi();
        cout << endl;
    }
}

void ghiFile(ofstream& file, SV** arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i]->ghi(file);
        file << endl;
    }
}

void docFile(ifstream& file, SV** arr, int n) {
    for (int i = 0; i < n; i++) {
        int choice;
        file >> choice;

        if (choice == 1) {
            arr[i] = new SVSP();
        }
        else if (choice == 2) {
            arr[i] = new SVKS();
        }
        arr[i]->doc(file);
    }
}


int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SV** danhSach = new SV * [n];

    cout << "Nhap thong tin sinh vien: " << endl;
    nhapDanhSach(danhSach, n);

    cout << "Thong tin sinh vien: " << endl;
    hienThiDanhSach(danhSach, n);

    cout << "Sap xep danh sach SVSP theo hoc bong: " << endl;
    sapXepSVSP(reinterpret_cast<SVSP**>(danhSach), n);
    hienThiDanhSach(danhSach, n);

    cout << "Sap xep danh sach SVKS theo hoc phi: " << endl;
    sapXepSVKS(reinterpret_cast<SVKS**>(danhSach), n);
    hienThiDanhSach(danhSach, n);

    ofstream file("output10_1.txt");
    if (file.is_open()) {
        ghiFile(file, danhSach, n);
        file.close();
        cout << "Da ghi du lieu vao file output.txt" << endl;
    }
    else {
        cout << "Khong mo duoc file" << endl;
    }

    ifstream inputFile("input10_1.txt");
    if (inputFile.is_open()) {
        cout << "Doc du lieu tu file input10_1.txt" << endl;
        docFile(inputFile, danhSach, n);
        inputFile.close();
    }
    else {
        cout << "Khong mo duoc file" << endl;
    }

    cout << "Thong tin sinh vien sau khi doc tu file: " << endl;
    hienThiDanhSach(danhSach , n);

    // Đoạn code tiếp theo tương tự như trước đó

    delete[] danhSach;
    return 0;
}

