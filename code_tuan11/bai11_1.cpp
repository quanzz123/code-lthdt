#include <bits/stdc++.h>
using namespace std;
class  Frac {
    protected:
        int numerator, dennominator;
    public:
        Frac(int num =  0, int den = 0) {
            numerator = num;
            dennominator = den;

        }
        bool operator>(const Frac &ps) {
            return numerator * ps.dennominator > ps.numerator * dennominator;
        }
        int getnum() {
            return numerator;
        }
        int getden() {
            return dennominator;
        }
};
class MyTime {
    protected:
        int hours;
        int minutes;
        int seconds;
    public:
        MyTime(int h = 0, int m = 0, int s = 0) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        bool operator>(const MyTime &time) {
            if(hours > time.hours) {
                return true;
            } else if(hours == time.hours && minutes > time.minutes) {
                return true;
            } else if(minutes == time.minutes && seconds > time.seconds) {
                return true;
            } else {
                return false;
            }
        }
        void display() {
            cout << hours << ":" << minutes << ":" << seconds;
        }
};
class MyDate {
    protected:
        int day, month, year;
    public:
        MyDate(int d = 0, int m = 0, int y = 0) {
            day = d;
            month = m;
            year = y;
        }
        bool operator>(const MyDate &date) {
            if(year > date.year) {
                return true;
            } else if(year == date.year && month > date.month) {
                return true;
            } else if(month == date.month && day > date.day) {
                return true;
            } else {
                return false;
            }
        }
        void display() {
            cout << day << "/" << month << "/" << year;
        }
};
template <class T>
T Max(T* arr, int size) {
    T max = arr[0];
    for(int i=1; i<size;i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    Frac frac_arr[] = {Frac(1,2), Frac(1,4), Frac(1,5), Frac(1,6)};
    Frac frac_max = Max(frac_arr, 4);
    cout << "max frax = " << frac_max.getnum() << "/" << frac_max.getden() << endl;

    MyDate mydate_arr[] = {MyDate(6,5,2013), MyDate(7,8,2013), MyDate(5,6,2000)};
    MyDate mydate_max = Max(mydate_arr, 3);
    cout << "max date = ";
    mydate_max.display();

    
}