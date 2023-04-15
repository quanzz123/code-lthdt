#include"libary6_1.h"
int main() {
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    cin.ignore();
    Person* ds = new Person[n];
    for(int i=0; i<n; i++) {
        cout << "\nNhap thong tin nguoi thu " << i+1 << ": " << endl;
        ds[i].Input();
        cout << endl;
    }
    cout << setw(65) << right << "===DANH SACH THONG TIN CA NHAN===" << endl;
    cout << setw(30) << left << "Name";
    cout <<  setw(30) << right << "Address";
    cout << setw(30) << right << "Phone" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        ds[i].Output();
    }
    string s;
    cout << "Nhap ten can tim: ";
    getline(cin, s);
    cin.ignore();
    for(int i=0; i<n; i++) {
        if(ds[i].getName() == s) {
            ds[i].Output();
        } else {
            cout << "\nkhong tim thay ten trong danh sach!" << endl;
        }
    }
    delete[] ds;        
}