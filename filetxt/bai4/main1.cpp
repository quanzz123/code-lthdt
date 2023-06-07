#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#include <iostream>

//khai bao cau trúc lớp ngày tháng năm sinh
class Namsinh {
    protected:
        int ngay;
        int thang;
        int nam;
    public:
        //phương thức getter của ngày
        int getterngay() {
            return ngay;
        }
        //phương thức setter của ngày
        void setterngay(int NGAY) {
            ngay = NGAY;
        }
         //phương thức getter của thang
        int getterthang() {
            return thang;
        }
        //phương thức setter của thang
        void setterthang(int THANG) {
            thang = THANG;
        }
         //phương thức getter của nam
        int getternam() {
            return nam;
        }
        //phương thức setter của nam
        void setternam(int NAM) {
            nam = NAM;
        }
};
//khai bao lớp cha : NhanVien
class NhanVien {
    protected:
        string maNhanVien;
        string tenNhanVien;
        Namsinh namsinh;
        string diachi;
        float luongcoban;
        float hesoluong;
    public:
        virtual  void Doc_File(ifstream &);
        virtual void xuat();
};
//cài dặt phương thức đọc file của lớp cha
void NhanVien::Doc_File(ifstream &filein) {
    getline(filein, maNhanVien, ',');
    filein.ignore();
    getline(filein, tenNhanVien, ',');
    int ngay;
    filein.ignore();
    filein >> ngay;
    namsinh.setterngay(ngay);
    
    string ngayStr, thangStr, namStr;
    getline(filein, ngayStr, '/');
    getline(filein, thangStr, '/');
    getline(filein, namStr, ',');

    namsinh.setterngay(stoi(ngayStr));
    namsinh.setterthang(stoi(thangStr));
    namsinh.setternam(stoi(namStr));


    filein.ignore();
    getline(filein, diachi, ',');
    filein.ignore();
    filein >> hesoluong;
    filein.ignore();
    filein >> luongcoban;
    
}
//xuẩt thổng tin nhân viên
void NhanVien::xuat() {
    cout << "ma nhan vien: " << maNhanVien << endl;
    cout << "Ten nhan vien: " << tenNhanVien << endl;
    cout << "Ngay thang nam sinh: " << namsinh.getterngay() << "/" << namsinh.getterthang() << "/" << namsinh.getternam() << endl;
    cout << "dia chi: " << diachi << endl;
    cout << "He so luong: " << hesoluong << endl;
    cout << "Luong co ban: " << luongcoban << endl;
}

//khai bao lop con nhan vien lập trình kế thừa nhân vien
class NhanVienLapTrinh : public NhanVien {
    private:
        float tienlamNgoaiGio;
    public:
        void Doc_File(ifstream &);
        void xuat();

};
// cài dặt phương thức đọc file của lớp nhân viên lập trình
void NhanVienLapTrinh::Doc_File(ifstream &filein) {
    NhanVien::Doc_File(filein);
    filein >> tienlamNgoaiGio;
}
//xuat thong tin nhan vien lap trinh
void NhanVienLapTrinh ::xuat() {
    NhanVien::xuat();
    cout << "Tien lam ngoai gio: " << tienlamNgoaiGio << endl;
}
//khai báo lớp con NhanVienThietKe kế thừa lóp cha NhanVien
class NhanVienThietKe : public NhanVien {
    private:
        float tienthuong;
    public:
        void Doc_File(ifstream &);
        void xuat();

};
// cài dặt phương thức đọc file của lớp nhân viên lập trình
void NhanVienThietKe::Doc_File(ifstream &filein) {
    NhanVien::Doc_File(filein);
    filein >> tienthuong;
}
// xuất thông tin nhân viên thiết kế
void NhanVienThietKe::xuat() {
    NhanVien::xuat();
    cout << "tien thuong: " << tienthuong << endl;
}

void Menu(NhanVien* ds[], int& n) {
    ifstream filein;
    filein.open("NHANVIEN1.txt", ios_base::in);
    while (true) {
        system("cls");
        cout << "\n\n\n\t===MENU=======";
        cout << "\n1. Doc thong tin nhan vien";
        cout << "\n2. Xuat thong tin nhan vien";
        cout << "\n0. Ket thuc";
        cout << "\n\n\t=== END ===";
        int luachon;
        cout << "\nMoi nhap lua chon: ";
        cin >> luachon;

        switch (luachon) {
            case 1: {
                filein >> n;
                NhanVien* x = NULL;
                for (int i = 0; i < n; i++) {
                    char c;
                    filein >> c;
                    filein.seekg(-1, ios_base::cur);  // Tại vị trí hiện tại dịch sang trái 1 byte để về đầu dòng
                    if (c == 'P') {
                        x = new NhanVienLapTrinh();
                        x->Doc_File(filein);
                    } else if (c == 'D') {
                        x = new NhanVienThietKe();
                        x->Doc_File(filein);
                    }
                    ds[i] = x;
                }
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                    cout << "\n\tNhan vien thong tin thu " << i + 1 << endl;
                    ds[i]->xuat();
                }
                break;
            }
            case 0: {
                filein.close();
                return;
            }
            default: {
                cout << "Lua chon khong hop le! Moi nhap lai.\n";
                break;
            }
        }
        system("pause");
    }
}

int main() {
    NhanVien *ds[100];// khai báo mảng một chiều luu trữ 2 loại nhân viên
    int n=0;
    Menu(ds, n);
    system("pause");
    return 0;
}