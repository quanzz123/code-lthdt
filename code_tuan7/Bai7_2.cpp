#include<bits/stdc++.h>
using namespace std;
class MyDate {
    private:
        int date, month, year;
    public:
        MyDate(int d =0, int m = 0, int y= 0) {
            date = d;
            month = m;
            year = y;
        }
        void add() {
            cout << "Nhap ngay: ";
            cin >> date;
            cout << "Nhap thang: ";
            cin >> month;
            cout << "Nhap nam: ";
            cin >> year;
        }
        void print() {
            //cout << setfill('-') << setw(55) << "-" << endl;
            //cout << setfill(' ');
            cout << "|" << setw(15) << right << date << setw(3);
            cout << "|" << setw(10) << right << month << setw(3);
            cout << "|" <<setw(10) << right << year << setw(3);
            cout << "|" << setw(9) << right << date << "/" << month << "/" << year << setw(5) << "|" << endl;
            cout << setfill('_') << setw(73) << "_" << endl;
            cout << setfill(' ');
        }
        int getdate() {
            return date;
        }
        int getmonth() {
            return month;
        }
        int getyear() {
            return year;
        }
        friend bool operator>=(const MyDate& date1,const MyDate& date2);

};
bool operator>=(const MyDate& date1,const MyDate& date2) {
    if(date1.year > date2.year) {
        return true;
    } else if(date1.year == date2.year && date1.month > date2.month) {
        return true;
    } else if(date1.month == date2.month && date1.date > date2.date) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int n;
    cout << "Nhap n = ";
    cin >> n;
    MyDate *list = new MyDate[n];
    for(int i=0; i<n; i++) {
        list[i].add(); cout << endl;
    }
    cout << setw(3) << setfill('_') << setw(73) << "_" <<endl;
    cout << setfill(' ');
    cout << "|" << setw(5) << right << "stt" << setw(3);
    cout << "|" << setw(15) << right << "date" << setw(3);
    cout << "|" << setw(10) << right << "month" << setw(3);
    cout << "|" << setw(10) << right << "year" << setw(3);
    cout << "|" << setw(15) << right << "day" << setw(5) << "|" << endl;
    cout << setfill('_') << setw(73) << "_" <<endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        cout << "|" << setw(5) << right << i+1 << setw(3);
        list[i].print();
        cout << endl;
    }
    //cout << "day: " << list[1].getdate() << "/" << list[1].getmonth() << "/" << list[1].getyear();
    //cout << "\t>=\t";
    //cout << "day: " << list[3].getdate() << "/" << list[3].getmonth() << "/" << list[3].getyear() << endl;
    /*if(list[1] >= list[2]) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }*/
    
    cout << "\t\t==========The latest date==============";
    cout << endl;
    cout << setw(3) << setfill('_') << setw(73) << "_" <<endl;
    cout << setfill(' ');
    cout << "|" << setw(5) << right << "stt" << setw(3);
    cout << "|" << setw(15) << right << "date" << setw(3);
    cout << "|" << setw(10) << right << "month" << setw(3);
    cout << "|" << setw(10) << right << "year" << setw(3);
    cout << "|" << setw(15) << right << "day" << setw(5) << "|" << endl;
    cout << setfill('_') << setw(73) << "_" <<endl;
    cout << setfill(' ');
    MyDate max = list[0];
    for(int i=0; i<n; i++) {
        if(list[i] >= max) {
            max = list[i];
            cout << "|" << setw(5) << right << i+1 << setw(3);
            max.print();
        }
        
    }

    return 0;   

}