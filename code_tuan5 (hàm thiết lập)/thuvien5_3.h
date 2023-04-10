#include<bits/stdc++.h>
using namespace std;
class MatHang {
    private:
        string Ten;
        int SoLuong;
        int DonGia;
    public:
        MatHang(string name, int soluong = 0, int dongia = 0) {
            this->Ten = name;
            this->SoLuong = soluong;
            this->DonGia  = dongia;
        }
        void nhapthongtin() {
            cout << "\nNhap ten mat hang: ";
            getline(cin, Ten);
            cout <<"\nNhap So luong: ";
            cin >>SoLuong;
            cout << "\nNhap don gia: ";
            cin >> DonGia;
        }
        void inthongtin() {
            cout << left << setw(20) << Ten
            << setw(10) << SoLuong
            << setw(10) << DonGia
            << setw(10) << SoLuong * DonGia
            << endl;
        }
        ~MatHang() {
            cout << "\nHuy bo doi tuong MatHang!" << endl;
        }
};
/*Bài 5.3: Xây dựng lớp MatHang mô tả các đối tượng mặt hàng, lớp gồm các thành phần
sau:
- Các thuộc tính Tên, Số lượng, Đơn giá.
- Hàm thiết lập ba tham số, trong đó có hai tham số có giá trị ngầm định Số lượng = 0
và Đơn giá = 0
- Hàm nhập thông tin về một mặt hàng.
- Hàm in ra màn hình thông tin về một mặt hàng.
Viết hàm main tạo một đối tượng MatHang M. In ra màn hình thông tin về mặt
hàng.*/