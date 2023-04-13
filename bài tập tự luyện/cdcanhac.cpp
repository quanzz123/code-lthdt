/*Bài 5: Xây dựng lớp CDCANHAC có các thông tin: 
Tên đĩa, số lượng bài, giátiền và các phương thức nhập, xuất dữ liệu.
Viết chương trình chính thực hiện nhập vào một danh sách n đĩa ca nhạc,sau đó hiển thị danh sách vừa nhập. 
Tìm và hiển thị thông tin của đĩa có sốlượng bài hát lớn nhất*/

#include<bits/stdc++.h>
using namespace std;
class CDCANHAC {
    private:
        string TenCD;
        int SoLuong;
        int GiaTien;
    public:
        CDCANHAC(string TenCD = "", int SoLuong = 0, int GiaTien = 0) {
            this->TenCD = TenCD;
            this->SoLuong = SoLuong;
            this->GiaTien = GiaTien;
        }
        void Nhap_data() {
            cout << "Nhap ten dia CD: ";
            getline(cin, TenCD);
            cout << "Nhap so luong dia cd: ";
            cin >> SoLuong;
            cout << "Nhap gia tien cua dia cd: ";
            cin >> GiaTien;
            cin.ignore();
        }
        int get_SoLuong() {
            return SoLuong;
        }
        void In_data() {
            cout << setw(20) << left << TenCD;
            cout << setw(10) << right << SoLuong;
            cout << setw(15) << right << GiaTien;
            cout << setw(15) << right << SoLuong*GiaTien << endl;
            cout << setfill('-') << setw(60) << "-" << endl;
            cout << setfill(' ');
        }
        ~CDCANHAC() {
            cout << "\nHuy bo doi tuong cd ca nhac!" << endl;
        }
};
int main() {
    int n;
    cout << "Nhap so luong dia cd: ";
    cin >> n;
    cin.ignore();

    CDCANHAC* cd = new CDCANHAC[n];

    for(int i=0 ; i<n; i++) {
        cout << "\nNhap thong tin cd thu " << i+1 << ": " << endl;
        cd[i].Nhap_data();
        cout << endl;
    }
    cout << "\n\n\t\t===DANH SACH THONG TIN CAC LOAI DIA CD===\n\n";
    cout << setw(20) << left << "TenCD";
            cout << setw(10) << right << "SoLuong";
            cout << setw(15) << right << "GiaTien";
            cout << setw(15) << right << "Thanh Tien" << endl;
            cout << setfill('-') << setw(60) << "-" << endl;
            cout << setfill(' ');
    for(int i=0; i<n; i++) {
        cd[i].In_data();
    }
    cout << "\n\n\t\t=== THONG TIN DIA CD CO SO LUONG LON NHAT===\n\n";
    cout << setw(20) << left << "TenCD";
            cout << setw(10) << right << "SoLuong";
            cout << setw(15) << right <<" GiaTien";
            cout << setw(15) << right << "Thanh Tien" << endl;
            cout << setfill('-') << setw(60) << "-" << endl;
            cout << setfill(' ');
    int max = 0;
    for(int i=0; i<n; i++) {
        if(cd[i].get_SoLuong() > max) {
            max = cd[i].get_SoLuong();
        }
    }
    for(int i=0; i<n; i++) {
        if(cd[i].get_SoLuong() == max) {
            cd[i].In_data();
        }
    }
    delete[] cd;
}