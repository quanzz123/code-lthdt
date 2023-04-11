#include<bits/stdc++.h>
using namespace std;
class MatHang {
    private:
        string Ten;
        int SoLuong;
        int DonGia;
    public:
        MatHang(string Ten = "", int SoLuong = 0, int DonGia = 0) {
            this->Ten = Ten;
            this->SoLuong = SoLuong;
            this->DonGia = DonGia;
        }
        void Nhapthongtin() {
            cout << "nhap ten mat hang: ";
            getline(cin,Ten);
            cout << "nhap so luong: ";
            cin >> SoLuong;
            cout << "nhap don gia: ";
            cin >> DonGia;
            cin.ignore();
        }
        void inthongtin() {
            cout << setw(20) << left << Ten << "|";
            cout << setw(10) << right << SoLuong;
            cout << setw(15) << right << DonGia;
            cout << setw(18) << right << SoLuong * DonGia << endl;
            cout << setfill('-') << setw(65) << "-" << endl;
            cout << setfill(' ');
        }
        ~MatHang() {
            cout << "\nHuy bo doi tuong MatHang!" << endl;
        }
};