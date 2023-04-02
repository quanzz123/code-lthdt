#include<streambuf>
#include<bits/stdc++.h>
using namespace std;

class HocSinh {
    private:
        char ho_ten[20];
        float diem_ki1;
        float diem_ki2;
    public:
        void khoitao() {
            cout << "\nnhap ho va ten hoc sinh: ";
            cin >> ho_ten;
            cout << "\nnhap diem ki 1 : ";
            cin >> diem_ki1;
            cout << "\nnhap diem ki 2: ";
            cin >> diem_ki2;
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

