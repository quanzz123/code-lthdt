#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class HocSinh {
    private:
        string ho_ten;
        float diem_ki1;
        float diem_ki2;
    public:
        void khoitao() {
            cout << "\nnhap ho va ten hoc sinh: ";
            getline(cin,ho_ten);
            cout << "\nnhap diem ki 1 : ";
            cin >> diem_ki1;
            cout << "\nnhap diem ki 2: ";
            cin >> diem_ki2;
            cin.ignore();
        }
        /*bool check_diemtb() {
            float diem_tb;
            diem_tb = (diem_ki1 + diem_ki2 * 2) / 3;
            return diem_tb;
        }*/
        void printf() {
            cout << "\nho va ten: " << ho_ten << endl;
            cout << "\ndiem ki 1 : " << diem_ki1 << endl;
            cout << "\ndiem ki 2: " << diem_ki2 << endl;
            cout << "\ndiem trung binh: " << diem_tb() << endl;
        }
        float diem_tb() {
            return (diem_ki1 + 2 * diem_ki2) / 3;

        }
};
/*Bài 4.4. Xây dựng lớp HocSinh mô tả các học sinh của một lớp học, lớp gồm các thành
phần:
- Các thuộc tính mô tả họ tên, điểm kỳ 1, điểm kỳ 2.
- Hàm khởi tạo.
- Hàm nhập dữ liệu.
- Hàm hiển thị dữ liệu.
- Hàm kiểm tra điểm trung bình năm học của học sinh có >= 5 hay không? (điểm
trung bình năm học = (điểm kỳ 1 + 2 * điểm kỳ 2) / 3).
Viết hàm main tạo 3 đối tượng học sinh; Hiển thị dữ liệu những học sinh vừa tạo;
Hiển thị những học sinh có điểm trung bình năm học >= 5. */


