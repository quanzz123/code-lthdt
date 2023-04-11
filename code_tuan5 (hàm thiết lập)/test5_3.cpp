#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class MatHang {
private:
    string ten;
    int soLuong;
    float donGia;

public:
    MatHang(string ten = "", int soLuong = 0, float donGia = 0) {
        this->ten = ten;
        this->soLuong = soLuong;
        this->donGia = donGia;
    }

    void nhap() {
        cout << "Nhap thong tin mat hang:" << endl;
        cout << "Ten: ";
        getline(cin, ten);
        cin.ignore();
        cout << "So luong: ";
        cin >> soLuong;
        cout << "Don gia: ";
        cin >> donGia;
        cin.ignore();
    }

    void in() {
        cout << setw(20) << left << ten;
        cout << setw(10) << right << soLuong;
        cout << setw(15) << right << fixed << setprecision(2) << donGia;
        cout << setw(15) << right << fixed << setprecision(2) << soLuong * donGia << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;

    cin.ignore(); // loai bo ky tu '\n' trong buffer sau cin >> n

    vector<MatHang> dsMatHang(n);

    // Nhap thong tin cho cac mat hang
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        dsMatHang[i].nhap();
    }

    // In bang thong tin mat hang
    cout << setw(20) << left << "Ten mat hang";
    cout << setw(10) << right << "So luong";
    cout << setw(15) << right << "Don gia";
    cout << setw(15) << right << "Thanh tien" << endl;

    for (int i = 0; i < n; i++) {
        dsMatHang[i].in();
    }

    return 0;
}
