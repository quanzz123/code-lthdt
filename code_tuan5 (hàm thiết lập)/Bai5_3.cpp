#include"thuvien5_3.h"
int main() {
    int n;
    cout << "nhap so luong mat hang: ";
    //freopen("5_3.txt", "r", stdin);
    cin >> n;
    cin.ignore();
    MatHang* ds = new MatHang[n];
    for(int i=0; i<n; i++) {
        ds[i].Nhapthongtin();
    }
    cout << "\n\n\t\t===BANG THONG KE CAC MAT HANG===\n\n";
    cout << setw(20) << left << "Ten Mat Hang";
    cout << setw(10) << right << "So Luong" ;
    cout << setw(15) << right << "Don Gia" ;
    cout << setw(18) << right << "Thanh Tien(VND)" << endl;
    cout << setfill('-') << setw(65) << "-" <<endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        ds[i].inthongtin();
    }
    return 0;
}