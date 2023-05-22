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
    const int MAX = 3;
    Colorlaser printers[MAX];
    int count =0;
    ifstream inputfile("printers.txt");
    if(inputfile.is_open()) {
        string name, color;
        int soluong, dpi;

        while(getline(inputfile, name) && count < MAX) {
            inputfile >> soluong >> dpi;
            inputfile.ignore();
            getline(inputfile, color);

            printers[count] = Colorlaser(name, soluon, dpi, color);
            count++;
        }
        inputfile.close();
        cout << "da lay du lieu tu tep printers.txt" << endl;

    } else {
        cout << "Khong dung dinh dang printers.txt" << endl;
    }
    int choice;
    do {
        showmenu();
        cout << "moi nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if(count < MAX) {
                    string name, color;
                    int soluong, dpi;
                    cout << "Nhap ten may in: ";
                    fflush(stdin);
                    getline(cin, name);

                    cout << "Nhap so luong: ";
                    cin >> soluong;

                    cout << "Nhap dpi: ";
                    cin >> dpi;

                    cout << "Nhap may sac: ";
                    fflush(stdin);
                    getline(cin, color);

                    printers[count] = Colorlaser(name, soluong, dpi, color);
                    count++;
                    cout << "Them may in thanh cong!" << endl;
                } else {
                    cout << "da dat gioi han so luong may in" << endl;
                }
                break;
            }
            case 2: {
                
            }
        } 

       
    
}