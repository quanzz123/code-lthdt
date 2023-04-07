#include<iostream>
#include<vector>

using namespace std;
class SinhVien {
    private:
        string hoten;
        int tuoi;
        float diemTB;
    public:
        SinhVien(string ten, int age, float tb) {
            hoten = ten;
            tuoi = age;
            diemTB = tb;
        }
        void xeploai() {
            if(diemTB >= 8.0) {
                cout <<"xep loai gioi!" << endl;

            } else if(diemTB >=7.0 && diemTB <= 8.0) {
                cout << "xep loai kha!" << endl;
            } else if(diemTB >=5.0 && diemTB <= 7.0) {
                cout <<"xep loai trung binh!" << endl;
            } else {
                cout << "xep loai kem!" << endl;
            }
        }
        void hienthithongtin() {
            cout << "ho ten: " << hoten << endl;
            cout << "tuoi: " << tuoi << endl;
            cout << "diem trung binh: " << diemTB << endl;
        }
        string getTen() {
            return hoten;
        }
};
class quanlisv {
    private:
        vector<SinhVien> ds;
    public:
        void themsinhvien(SinhVien sv) {
            ds.push_back(sv);
        }
        void hienthi();
        void xeploaiSV(string ten);
};
void quanlisv ::hienthi() {
    for(int i=0; i< ds.size(); i++) {
        cout << "\nsinh vien thu " << i+1 << endl;
        ds[i].hienthithongtin();
        ds[i].xeploai();
    }
}
void quanlisv ::xeploaiSV(string ten) {
    for(int i=0;i<ds.size(); i++) {
        if(ds[i].getTen() == ten) {
            ds[i].xeploai();
            break;
        }
    }
}
int main() {
    quanlisv a;
    int luachon;

    do {
        cout << "Nhap lua chon!" << endl;
        cout << "1. them sinh vien." << endl;
        cout << "2.hien thi danh sach sinh vien." << endl;
        cout << "3.xep loai sinh vien." << endl;
        cout << "4.thoat chuong trinh." << endl;
        cin >> luachon;
        string hoten = "";
        int tuoi;
        float diemTB;
        SinhVien sv(hoten, tuoi, diemTB);
        switch (luachon)
        {
        case 1:
            cout << "nhap ho ten sinh vien: ";
            cin.ignore();
            getline(cin, hoten);
            cout <<"nhap tuoi cu sinh vien: ";
            cin >> tuoi;
            cout << "nhap diem trung binh cua sinh vien: ";
            cin >> diemTB;
            a.themsinhvien(sv);
            break;
        case 2:
            a.hienthi();
            break;
        case 3:
            cout <<"nhap ten sinh vien can xep loai: " << endl;
            cin.ignore();
            getline(cin, hoten);
            a.xeploaiSV(hoten);
            break;;

        case 4:
            cout << "thoat" << endl;;
            break;
        default:
            cout << "khong co chuc nang nay!" << endl;
            break;
        }

    }while(luachon !=4);
}