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
            cout << "|"  << setw(9) << left << namecolor;
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
            cout << "|"<< setw(3) << left << ox ;
            cout << "|" << setw(3) << left << oy ;
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
            cout << "|" << setw(8) << left << fixed << setprecision(0)<<  r;
            cout << "|" << setw(9) << left << fixed << setprecision(2)<< dt() << "|" << endl;
            cout << "|";
            cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(9) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(8) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(9) << "-" << "|" << endl;
    cout << setfill(' ');
        }

};
int main() {
    freopen("dulieu8_4.txt", "r", stdin);
    freopen("ketqua8_4.txt", "w", stdout);
    int n;
    cin >> n;
    Cricle *c = new Cricle[n];
    for(int i=0; i<n; i++) {
        string color;
        int a, b, r;

        cin >> color;
        cin >> a >> b >> r;
        c[i] = Cricle(color, a, b, r);
    }
    cout << "\n\n";
    cout << "\t"<<  "===========bang thong ke===========" << endl;
    cout << (char)218 << setfill('-') << setw(40) << "-" << (char)191 << endl;
    cout << setfill(' ');
    cout << "|" << setw(3) << left << "stt";
    cout << "|" << setw(9) << left << "Namecolor";;
    cout << "|"<< setw(3) << left << "ox";
    cout << "|"<< setw(3) << left << "oy";
    cout << "|" << setw(8) << left << "ban kinh";
    cout << "|" << setw(9) << left << "Dien tich" << "|" << endl;
    cout << "|";
    cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(9) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(3) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(8) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(9) << "-" << "|" << endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        cout << "|"<< setw(3) << left << i+1;
        cout << setfill(' ');
        c[i].display();
    }
    cerr << "----hoan thanh ------" << endl;
    return 0;
}

    
