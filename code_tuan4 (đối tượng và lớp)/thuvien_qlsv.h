#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SinhVien {
    private:
        string Ten;
        int Tuoi;
        float DiemTb;
    public:
        void Nhapthongtin() {
            cout << "\nnhap ho ten sinh vien: ";
            getline(cin, Ten);
            cout << "\nnhap tuoi sinh vien: ";
            cin >> Tuoi;
            cout << "\nNhap diem trung binh cua sinh vien: ";
            cin >> DiemTb;
            cin.ignore();
        }
        void XepLoai(float diem) {
            if(diem >= 8.0) {
                cout << "\n Xep loai gioi!" << endl;
            } else if(diem >= 7.0) {
                cout << "\nXep loai Kha!" << endl;

            } else if(diem >= 5.0) {
                cout << "\nXep loai trung binh!" << endl;
            } else {
                cout << "\nXep loai kem!" << endl;
            }
        
        }
        void Printf() {
            cout << "\nHo va ten sinh vien: " << Ten << endl;
            cout << "\ntuoi cua sinh vien: " << Tuoi << endl;
            cout << "\nDiem trung binh cua sinh vien: " << DiemTb << endl;
        }
        float getDiem() {
            return DiemTb;
        }

};