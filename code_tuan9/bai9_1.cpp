#include<bits/stdc++.h>
using namespace std;
class Printer {
    protected:
        string name;
        int soluong;
    public:
        Printer(string n=" ", int sl=0) {
            name = n;
            soluong = sl;
        }
        void nhapkho(int q) {
            soluong += q;
        }
        void xuatkho(int q) {
            if(soluong >= q) {
                soluong -= q;
            } else {
                cout << "khong du so luong trong kho" << endl;
            }
        } 
        string getname() {
            return name;
        }
        int getsoluong() {
            return soluong;
        }
};
class laser : public virtual Printer {
    protected:
    int Dpi;
    public: 
        laser(string n=" ", int sl=0, int dpi=0) : Printer(n,sl) {
            Dpi = dpi;
        }
        int getdpi() {
            return Dpi;
        }
};
class Colorprinter : public virtual Printer {
    protected:
        string color;
    public:
        Colorprinter(string n=" ", int sl=0, string col=" ") : Printer(n,sl) {
            color = col;
        }
        string getcolor() {
            return color;
        }
};
class Colorlaser : public laser, public  Colorprinter {
    public:
        Colorlaser(string n=" ", int sl=0, int dpi=0, string col=" ")
        :Printer(n,sl), laser(n,sl, dpi), Colorprinter(n,sl,col) {}
};
void showmenu() {
    cout << "=== MENU ===" << endl;
    cout << "1. Nhap kho" << endl;
    cout << "2. Xuat kho" << endl;
    cout << "3. In so luong trong kho" << endl;
    cout << "4. Hien thi thong tin may in" << endl;
    cout << "0. Exit" << endl;
}
int main() {
    Colorlaser cl(" p1", 2, 3, " red");
    
}