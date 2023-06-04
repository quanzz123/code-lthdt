#include<bits/stdc++.h>
using namespace std;
class MyColor {
    protected:
        string namecolor;
    public:
        MyColor(string nc =" ") {
            namecolor = nc;
        }
        void input() {
            cout << "Enter color: ";
            fflush(stdin);
            getline(cin, namecolor);
        }
        void display() {
            cout << "|" << "\t" << setw(10) << left << namecolor << "\t";
        }
};
class Point : public MyColor {
    protected:
        int ox;
        int oy;
    public:
        Point(string nc=" ", int x=0, int y=0) : MyColor(nc){
            ox = x;
            oy = y;
        }
        void input() {
            MyColor::input();
            cout << "Enter x: ";
            cin >> ox;
            cout << "Enter y: ";
            cin >> oy;
        }
        void display() {
            MyColor::display();
            cout << "|" << "\t" << setw(3) << left << ox << "\t";
            cout << "|" << "\t" << setw(3) << left << oy << "\t";
        }
};
class Cricle : Point {
    protected:
        float r;
    public:
        Cricle(string nc=" ", int x=0, int y=0, float bk=0) : Point(nc, x, y) {
            r = bk;
        }
        float dt() {
            return M_PI * pow(r, 2);
        }
        void input() {
            Point::input();
            cout << "Enter r: ";
            cin >> r;
        }
        void display() {
            Point::display();
            cout << "|" << "\t" << setw(8) << left << r << "\t";
            cout << "|" << "\t" << setw(10) << left << dt() << "\t" << "|" << endl;
            cout << "|";
            cout << setfill('-') << setw(15) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(15) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(15) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|" << endl;
            cout << setfill(' ');
        }

};
int main() {
    int n;
    cout << "n= ";
    cin >> n;
    Cricle *c = new Cricle[n];
    for(int i=0; i<n; i++) {
        c[i].input();
    }
    cout <<(char)218 << setfill('-') << setw(119) << "-" << (char)191 << endl;
    cout << setfill(' ');
    cout << "|" << "\t" << setw(2) << left << "stt" << "\t";
    cout << "|" << "\t" << setw(10) << left << "Namecolor" << "\t";
    cout << "|" << "\t" << setw(3) << left << "ox" << "\t";
    cout << "|" << "\t" << setw(3) << left << "oy" << "\t";
    cout << "|" << "\t" << setw(8) << left << "ban kinh" << "\t";
    cout << "|" << "\t" << setw(10) << left << "Dien tich" << "\t" << "|" << endl;
    cout << "|";
    cout << setfill('-') << setw(15) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(15) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(15) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|" << endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        cout << "|" << "\t" << setw(2) << left << i+1 << "\t";
        c[i].display();
    }
    return 0;
}

    
