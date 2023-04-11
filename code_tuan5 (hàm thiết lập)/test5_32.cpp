#include"thuvien5_3.h"
#include<iomanip>
#include<vector>
int main() {
    int n;
    cin >> n;
    vector<MatHang> ds(n);

    for(int i=0; i<n; i++){ 
        ds[i].nhapthongtin();
    }
    cout << left << setw(20) << "Ten mat hang"
    << setw(10) << "So Luong"
    << setw(10) << "Don Gia"
    << setw(10) << "Thanh Tien (VND)" 
    << endl;
    //cout << setfill('-') << setw(50) << "-" << endl;
    //cout << setfill(' ');

    for(int i=0; i < n; i++) {
        ds[i].inthongtin();
    }
    //cout << setfill('-') << setw(50) << "-" << endl;
    //cout << setfill(' ');
    system("pause");


}