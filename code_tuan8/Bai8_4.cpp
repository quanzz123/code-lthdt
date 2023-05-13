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
            cout << "|" << "\t" << setw(8) << left << namecolor << "\t";
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
            cout << "|" << "\t" << setw(3) << left << ox << "\t" << setw(3) << left << oy << "\t";
        }
};
class Cricle : Point {
    protected:
        float r;
    public:
        Cricle(string nc=" ", int x=0; int y=0, float bk=0) : Point(nc, x, y) {
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
            cout << "|" << "\t" << setw(3) << left << r << "\t";
        }

};
int main() {
    int n;
    cout << "n= ";
    cin >> n;
    Cricle *c = new Cricle[n];
}

    
