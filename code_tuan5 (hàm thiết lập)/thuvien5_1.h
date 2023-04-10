#include<bits/stdc++.h>
#include<string>  
using namespace std;                                      
class MyFlle {
    private:
        string Name;
        int Size;
        int Attrib;
    public:
        MyFlle() {
            Name = "";
            Size = 0;
            Attrib = 0;
        }
        void Input() {
            cout << "nNhap ten cua tep: ";
            getline(cin, Name);
            cin.ignore();
            cout << "Nhap kich thuoc tep: ";
            cin >> Size;
            cout << "Nhap so hieu thuoc tinh tep: ";
            cin >> Attrib;
        }
        void print() {
            cout << "\nTen tep: " << Name << endl;
            cout << "\nKich thuoc: " << Size << "MB" << endl;
            cout << "\nSo hieu thuoc tinh tep: " << Attrib << endl;
        }
        ~MyFlle() {
            cout <<"\nHuy bo do tuong MyFile!" << endl;
        }
};
/*Bài 5.1: Xây dựng lớp Myfile mô tả các đối tượng tệp, lớp gồm các thành phần sau:
- Các thuộc tính Name, Size, Attrib mô tả tên tệp, kích thước tệp, số hiệu thuộc
tính của tệp.
- Hàm thiết lập.
- Hàm nhập thông tin tệp.
- Hàm huỷ bỏ.
- Hàm in ra màn hình thông tin tệp
Viết hàm main tạo một đối tượng tệp f. In ra màn hình thông tin về đối tượng vừa
tạo*/