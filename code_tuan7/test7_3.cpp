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
            cout << "|" << "\t" << setw(5) << left << hours << "\t";
            cout << "|" << "\t" << setw(5) << left << minutes << "\t";
            cout << "|" << "\t" << setw(5) << left << seconds << "\t";
            cout << "|" << "\t" << setw(5) << right << hours << ":" << minutes << ":" << seconds << "\t" << "|" << endl;

        }
        friend bool operator>=(MyTime& time1, MyTime& time2);
};
bool operator>=(MyTime& time1, MyTime& time2) {
    if(time1.hours > time2.hours) {
        return true;
    } else if(time1.hours == time2.hours && time1.minutes > time2.minutes) {
        return true;
    } else if(time1.minutes == time2.minutes && time1.seconds > time2.seconds) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int n;
    cout << "Nhap n= ";
    cin >> n;
    MyTime *time = new MyTime[n];
    for(int i=0; i<n; i++) {
        cout << "Nhap time thu: " << i+1 << endl;
        time[i].add();
    }
    cout << "|" << "\t" << setw(5) << left << "stt" << "\t";
    cout << "|" << "\t" << setw(5) << left << "hours" << "\t";
    cout << "|" << "\t" << setw(5) << left << "minutes" << "\t";
    cout << "|" << "\t" << setw(5) << left << "seconds" << "\t";
    cout << "|" << "\t" << setw(10) << right << "time" << "\t" << "|" << endl;
    for(int i=0; i<n;i++) {
        cout << "|" << "\t" << setw(5) << left << i+1 << "\t";
        time[i].display();
    }

}