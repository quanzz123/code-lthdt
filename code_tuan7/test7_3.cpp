#include<bits/stdc++.h>
using namespace std;
class MyTime {
    private:
        int hours, minutes, seconds;
    public:
        MyTime(int h=0, int m=0, int s=0) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        void add() {
            cout << "Nhap kim gio: ";
            cin >> hours;
            cout << "Nhap kim phut: ";
            cin >> minutes;
            cout << "Nhap kim giay: ";
            cin >> seconds;
            cout << endl;
        }
        void display() {
            cout << "|" << "\t" << setw(5) << left << hours;
            cout << "|" << "\t" << setw(5) << left << minutes;
            cout << "|" << "\t" << setw(5) << left << seconds;
        }
};