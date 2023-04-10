#include"thuvien5_3.h"
#include<iomanip>
int main() {
    MatHang M1("banh", 2, 300);
    MatHang M2("keo", 5, 500);
    MatHang M3("sua", 5, 400);
    cout << left << setw(20) << "Ten mat hang"
    << setw(10) << "So Luong"
    << setw(10) << "Don Gia"
    << setw(10) << "Thanh Tien" 
    << endl;
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');

    M1.inthongtin();
    M2.inthongtin();
    M3.inthongtin();

    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');
    system("pause");


}