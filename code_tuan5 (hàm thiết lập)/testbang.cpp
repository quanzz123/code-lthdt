#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class MatHang {
private:
    string Ten;
    int SoLuong;
    float DonGia;
public:
    MatHang(string ten="", int sl=0, float dg=0.0) {
        Ten = ten;
        SoLuong = sl;
        DonGia = dg;
    }
    void nhapThongTin() {
        cout << "Nhap ten mat hang: ";
        getline(cin, Ten);
        cout << "Nhap so luong: ";
        cin >> SoLuong;
        cout << "Nhap don gia: ";
        cin >> DonGia;
    }
    void inThongTin() {
        cout << left << setw(20) << Ten
             << setw(10) << SoLuong
             << setw(10) << fixed << setprecision(2) << DonGia
             << setw(10) << fixed << setprecision(2) << SoLuong * DonGia
             << endl;
    }
};

int main() {
    MatHang mh1("Sua", 2, 15000);
    MatHang mh2("Keo", 5, 5000);
    MatHang mh3("Tra", 3, 20000);
    
    cout << left << setw(20) << "Ten mat hang"
         << setw(10) << "So luong"
         << setw(10) << "Don gia"
         << setw(10) << "Thanh tien"
         << endl;
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');
    
    mh1.inThongTin();
    mh2.inThongTin();
    mh3.inThongTin();
    
    return 0;
}
