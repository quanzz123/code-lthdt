#include<iostream>
#include<string>
using namespace std;

class TaiKhoan {
    private:
        string ten;
        string so_tk;
        string NH;
        int so_du;
        int gui;
        int rut;
    public:
        void nhap_data() {
            cout << "\nnhap ten chu tai khoan: ";
            getline(cin, ten);
            cout << "\nnhap so tai khoan: ";
            getline(cin, so_tk);
            cout << "\nnhap ten ngan hang: ";
            getline(cin, NH);
            cout << "\nnhap so du tai khoan: ";
            cin >> so_du;
            cin.ignore();

        }
        void gui_tien(int tien) {
            if(tien <= 500000) {
                so_du +=tien;
                cout << "\nnap tien thanh cong!" << endl;
            
            }
            
        }
        void rut_tien(int tien) {
            if(tien > so_du) {
                cout << "\nso du khong du!" << endl;
            } else {
                so_du -= tien;
                cout << "\nrut tien thanh cong!" << endl;
            }
        }
        float sodu() {
            return so_du;
        }
        int tiengui() {
            return gui;
        }
        int tienrut() {
            return rut;
        }
        void hien_thi() {
            cout << "\nten nguoi gui tien: " << ten << endl;
            cout << "\nso tai khoan: " << so_tk << endl;
            cout << "\nten ngan hang: " << NH << endl;
            cout << "\nso du trong tai khoan: " << so_du << endl;

        }
};