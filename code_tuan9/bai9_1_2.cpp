#include<bits/stdc++.h>
#include<sstream>
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
        void Nhapkho(int q) {
            soluong += q;
        }
        void  Xuatkho(int q) {
            if(soluong >= q) {
                soluong -= q;
            } else {
                cout << "khng du so luong trong kho!" << endl;
            }
        }
        void display() {
            cout << "|" << setw(10) << left << name;
            cout << "|" << setw(5) << left << soluong; 
        }
};
class Laser : public Printer {
    protected:
        int Dpi;
    public:
        Laser(string n=" ", int sl=0, int dpi=0) : Printer(n,sl) {
            Dpi = dpi;
        }
        void display() {
            Printer::display();
            cout << "|" << setw(5) << left << Dpi;
        }
};
class ColorPrinter : public Printer {
    protected:
        string Color;
    public:
        ColorPrinter(string n =" ", int sl=0, string cl=" ") : Printer(n,sl) {
            Color = cl;
        }
        void display() {
            Printer::display();
            cout << "|" << setw(5) << left << Color;
        }
};
class ColorLaser : public Laser, public ColorPrinter {
    protected:
    public:
        ColorLaser(string n=" ", int sl=0, int dpi=0, string cl=0) : Laser(n,sl, dpi) , ColorPrinter(n, sl, cl) {
    
        }
        void display() {
            Laser::display();
            cout << "|" << setw(5) << left << Color << endl;
        }
};
int main() {
    vector<ColorLaser> Printers;
    int choice;
    int q;
    string name;
    int dpi;
    string color;

    do {
        cout << "\n===MENU===" << endl;
        cout << "1.Nhap them san pham vao kho" << endl;
        cout << "2.Hien thi thong tin cac san pham" << endl;
        cout << "3.Xuat kho" << endl;
        cout << "0.Thoat khoi chuong trinh" << endl;
        cout << "Moi nhap lua chon cua ban: " ;
        cin >> choice;

        switch (choice) 
            case 1:
                cout << "Nhap tong tin dan pham: " << endl;
                cout << "Nhap ten may in: ";
                fflush(stdin);
                getline(cin, name);
                cout << "so luong: ";
                cin >> q;
                cout << "Nhap dpi: ";
                cin >> dpi;
                cout << "Nhap mau sac cua san pham: ";
                fflush(stdin);
                getline(cin, color);
                Printers.push_back(ColorLaser(name, q, dpi, color));
                cout << "San pham duoc them vao kho!" << endl;
                break;
            case 2:
                cout << "thong tin cac san pham: "<< endl;
                for (int i = 0; i < Printers.size(); i++) {
                    cout << "|" << setw(3) << left << i+1;
                    Printers[i].display();
                }
                break;
            case 3:
                cout << "Nhap so luong san pham can xuat kho: ";
                cin >> q;
                Printers[0].ColorPrinter::Xuatkho(q);
                break;
            case 0:
                cout << "Exit!" << endl;
                break;
            default :
                cout << "lua chon khong hop le moi nhap lai lua chon!" << endl;
                break;
        
    }


while (choice != 0);

ifstream inputFile("printers.txt");
if(inputFile.is_open()) {
    while(!inputFile.eof()) {
        string line;

        if(line.empty()) {
            continue; //bỏ qua các dòng trống.
        }
        stringstream ss(line);
        string name;
        int soluong;
        int dpi;
        string color;

        ss >> name >> soluong >> dpi >> color;

        // thêm vào vector vector Printes.
        Printers.push_back(ColorLaser(name, soluong, dpi, color));
    }
    inputFile.close();
} else {
    cout << "khong the mo tep tu file!" << endl;
}
return 0;
}