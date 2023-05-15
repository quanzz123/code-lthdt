#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class MyColor {
protected:
    string NameColor;

public:
    MyColor(string n = " ") {
        NameColor = n;
    }

    void input() {
        cout << "Enter namecolor: ";
        getline(cin, NameColor);
    }

    void display() {
        cout << "|" << "\t" << setw(10) << left << NameColor << "\t";
    }
};

class Point : public MyColor {
protected:
    int ox;
    int oy;

public:
    Point(string n = " ", int x = 0, int y = 0) : MyColor(n) {
        ox = x;
        oy = y;
    }

    void input() {
        MyColor::input();
        cout << "Enter x = ";
        cin >> ox;
        cout << "Enter y = ";
        cin >> oy;
    }

    void display() {
        MyColor::display();
        cout << "|" << "\t" << setw(3) << left << ox << "\t";
        cout << "|" << "\t" << setw(3) << left << oy << "\t";
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const Point& point) {
        os << point.NameColor << "\n";
        os << point.ox << " " << point.oy << "\n";
        return os;
    }
};

int main() {
    Point* s[20];
    Point* tg;
    int a, b;
    string fn;

    freopen("dulieu8_5.txt", "r", stdin);
    freopen("ketqua8_5.txt", "w", stdout);

    int n = 0;
    while (true) {
        fn = "";
        cin >> fn;
        if (fn.size() == 0)
            break;
            string fn1;
        getline(cin, fn1); // Discard the remaining part of the line
        fn += fn1;
        cin >> a >> b;
        s[n] = new Point(fn, a, b);
        n++;
    }

    cout << "---------------------DANH SACH BAN DAU---------------------\n\n";
    for (int i = 0; i < n; i++) {
        s[i]->display();
    }

    /*for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*s[i] > *s[j]) {
                tg = s[i];
                s[i] = s[j];
                s[j] = tg;
            }
        }
    }*/

    cout << "\n\n";
    cout << "-----------------DANH SACH SAU KHI SAP XEP-----------------\n\n";
    for (int i = 0; i < n; i++) {
        s[i]->display();
    }

    /*for (int i = 0; i < n; i++) {
        outputFile << *s[i];
    }*/

    

    cerr << "----CHUONG TRINH DA HOAN THANH----";
    return 0;
}
