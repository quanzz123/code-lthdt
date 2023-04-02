#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class point {
    private:
        float x ,y;
    public:
        void init(float ox, float oy) {
            x = ox;
            y = oy;
        }
        void printf() {
            cout << "\nhoanh do: " << x << endl;
            cout << "\ntung do: " << y << endl;
        }
        float X() {
            return x;

        }
        float Y() {
            return y;
        }
};
class Triangle {
    private:
        point A, B, C;
    public:
        void KhoiTao(point oa, point ob, point oc) {
            A = oa;
            B = ob;
            C = oc;
        }
        float canh(point p1, point p2) {
            float x1, x2, y1, y2, canh;
            x1 = p1.X();
            y1 = p1.Y();
            x2 = p2.X();
            y2 = p2.Y();
            return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

        }
        float ChuVi() {
            float a ,b, c, cv;
            a = canh(B, C);
            b = canh(A, B);
            c = canh(A, C);
            return  a + b + c;
            

        }
        float DienTich() {
            float a, b, c, p, dt;
            a = canh(B, C);
            b = canh(A, B);
            c = canh(A, C);
            p = (a + b + c) / 2.0;
            return  sqrt(p * (p-a) * (p-b) * (p-c));
        }
};
class TriagleValidator {
    private:
        Triangle h;
    public:
        float canh(point p1, point p2) {
            float x1, x2, y1, y2, canh;
            x1 = p1.X();
            y1 = p1.Y();
            x2 = p2.X();
            y2 = p2.Y();
            return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        }
        bool check(point A, point B, point C) {
            float a, b, c;
            a = canh(B, C);
            b = canh(A, B);
            c = canh(A, C);
            if(a+b>c && a+c>b && b+c>a) {
                return true;
            }
            return false;
        }

};
/* Bài 4.2*. Xây dựng lớp Tamgiac mô tả các đối tượng tam giác trên hệ trục tọa độ, lớp
gồm các thành phần:
- Các thuộc tính mô tả gồm: 3 điểm xác định tam giác
- Hàm khởi tạo tam giác
- Hàm tính chu vi
- Hàm tính diện tích
- Hàm hiển thị tọa độ góc 3 điểm, chu vi, diện tích tam giác
Viết hàm main tạo một đối tượng tam giác và hiển thị thông tin của tam giác vừa tạo.*/