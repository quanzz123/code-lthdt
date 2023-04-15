/*Bài 6.1: Một quyển danh bạ điện thoại của một cơ quan chứa các thông tin về họ tên, địa
chỉ, số điện thoại của các cán bộ. Xây dựng lớp Person, lớp gồm các thành phần sau:
- Thuộc tính: Name, Address, Phone để mô tả các thông tin trong danh bạ.
- Hàm thiết lập không tham số
- Hàm thiết lập ba tham số
- Hàm huỷ bỏ.
- Hàm nhập dữ liệu
- Hàm getName trả về Name.
- Hàm getAddress trả về Address.
- Hàm getPhone trả về Phone.
- Hàm hiển thị có gọi đến các hàm getName, getAddress, getPhone.
Viết hàm main tạo mảng các đối tượng thuộc lớp Person. Hiển thị thông tin của các đối
tượng vừa tạo*/

#include<bits/stdc++.h>
using namespace std;
class Person {
    private:
        string Name;
        string Address;
        string Phone;
    public:
        Person(string Name="", string Address="", string Phone="") {
            this->Name = Name;
            this->Address = Address;
            this->Phone = Phone;

        }
        ~Person() {
        }
        void Input() {
            cout << "Nhap ho ten: ";
            getline(cin,Name);
            cout << "Nhap dia chi: ";
            getline(cin, Address);
            cout << "Nhap so Phone: ";
            getline(cin, Phone);
            cin.ignore();
        }
        void Output() {
            cout <<  setw(30) << left << getName();
            cout << setw(30) << right << getAddress();
            cout << setw(30) << right << getPhone() << endl;
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');
        }
        string getName() {
            return Name;
        }
        string getAddress() {
            return Address;
        }
        string getPhone() {
            return Phone;
        }

};