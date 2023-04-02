#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Hinhchunhat {
    private:
        float x,y;
        float Dai, Rong;
    public:
        void hcn(float ox, float oy, float chieudai, float chieurong) {
            x = ox;
            y = oy;

            Dai = chieudai;
            Rong = chieurong;
        }
        float ChuVi() {
            return (Dai + Rong) / 2;
        }
        float DienTich(){
            return Dai * Rong;
        }
        void Printf() {
            cout << "\ndiem goc ben trai: " << "(" <<  x << ";" << y << ")" << endl;
            cout << "\nChieu dai: " << Dai << endl;
            cout << "\nChieu rong: " << Rong << endl;
            cout << "\nChu vi hinh chu nhat: " << ChuVi() << endl;
            cout << "\nDien tich hinh chu nhat: " << DienTich() << endl;
        }

};
/*Bài 4.1. Xây dựng lớp HinhChuNhat mô tả các đối tượng hình chữ nhật trên hệ trục tọa
độ, lớp gồm các thành phần:
- Các thuộc tính mô tả gồm: điểm góc trên bên trái, chiều dài, chiều rộng
- Hàm khởi tạo hình chữ nhật
- Hàm tính chu vi
- Hàm tính diện tích
- Hàm hiển thị tọa độ góc trên trái, chu vi, diện tích hình chữ nhật
Viết hàm main tạo một đối tượng hình chữ nhật và hiển thị thông tin của hình chữ
nhật vừa tạo.*/
