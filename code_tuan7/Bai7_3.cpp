#include<bits/stdc++.h>
using namespace std;

class MyTime {
    private:
        int hour, minute, second;
    public:
        MyTime(int h=0, int m=0, int s=0) {
            hour = h;
            minute = m;
            second = s;
        }
        void add {
            cout << "Nhap kim gio: ";
            cin >> hour;
            cout << "Nhap ki phut: ";
            cin >> minute;
            cout << "Nhap kim giay: ";
            cin >> second;
        }
        void print() {
            cout << "|" << setw(15) << right << hour << setw(5);
            cout << "|" << setw(15) << right << minute << setw(5);
            cout << "|" << setw(15) << right << second << setw(5);
            cout << "|" << setw(15) << right << hour << ":" << minute << ":" << second << "|" << setw(5) << endl;
            cout << setfill('_') << setw(45) << "_" << endl;
            cout << setfill(' ');

        }
        friend bool operator>=(MyTime& time1, MyTime& time2) {
            if(time1.hour > time2.hour) {
                return true;
            } else if(time1.hour == time2.hour && time1.minute > time2.minute) {
                return true;
            } else if(time1.minute == time2.minute && time1.second > time2.second) {
                return true;
            } else {
                return false;
            }

};
int main() {
    int n;
    cout << "Nhap n = ";
    cin >> n;
    MyTime *time = new MyTime[n];
    for(int i=0 i<n; i++) {
        time[i].add();
    }
    cout << setfill('_') << setw(45) << "_" << endl;
    cout << setfill(' ');
    cout << setw(15) << right << "hour" << setw(5);
    cout << setw(15) << right << "minute" << setw(5);
    cout << setw(15) << right << "second" << setw(5);
    cout << setw(15) << right << "time" << setw(5);
    cout << setfill('_') << setw(45) << "_" << endl;
    cout << setfill(' ');
    for(int i=0;i<n; i++) {

    }

}