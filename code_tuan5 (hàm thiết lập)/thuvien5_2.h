#include<bits/stdc++.h>
using namespace std;
class Crircle {
    private:
        float x, y, r;
    public:
        Crircle() {
            x= 0;
            y = 0;
            r = 0;
        }
        Crircle(float ox, float oy, float BanKinh) {
            x = ox;
            y = oy;
            r = BanKinh;
        }
        Crircle(Crircle &a) {
            this->r = a.r;
            this->x = a.x;
            this->y = a.y;
        }
        float DienTich() {
            return M_PI * r * r;
        }
        void print() {
            cout << "\nDien tich cua duong tron: " << DienTich() << endl;
        }
        ~Crircle() {
            cout << "\nHuy bo doi tuong Crircle!" << endl;
        }
};
/*Bài 5.2: Xây dựng lớp Circle mô tả các đối tượng đường tròn, lớp gồm có các thành
phần sau:
- Thuộc tính r mô tả bán kính của đường tròn.
- Hàm thiết lập không tham số đặt bán kính bằng 0.
- Hàm thiết lập một tham số đặt bán kính bằng d.
- Hàm thiết lập sao chép.
- Hàm tính diện tích.
- Hàm in diện tích.
Viết hàm main tạo một đường tròn có bán kính bằng k với k nhập vào từ bàn
phím. In ra màn hình diện tích của đường tròn vừa tạo.*/