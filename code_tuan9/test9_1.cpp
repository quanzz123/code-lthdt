#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Printer {
protected:
    string Name;
    int Soluong;
public:
    Printer() {}
    void nhapkho(int q) {
        Printer::Soluong += q;
    }
    void xuatkho(int q) {
        if (Printer::Soluong >= q) {
            Printer::Soluong -= q;
        } else {
            cout << "Khong du so luong trong kho." << endl;
        }
    }
};

class Laser : public Printer {
protected:
    int Dpi;
public:
    Laser(int dpi) : Dpi(dpi) {}
};

class ColorPrinter : public Printer {
protected:
    string Color;
public:
    ColorPrinter(string color) : Color(color) {}
};

class ColorLaser : public Laser, public ColorPrinter {
public:
    ColorLaser(string name, int soluong, int dpi, string color)
        : Laser(dpi), ColorPrinter(color) {
        Name = name;
        Soluong = soluong;
    }
};

void displayMenu() {
    cout << "============= MENU =============" << endl;
    cout << "1. Them may in" << endl;
    cout << "2. Xuat may in" << endl;
    cout << "3. Hien thi thong tin may in" << endl;
    cout << "0. Thoat" << endl;
    cout << "================================" << endl;
}

int main() {
    const int MAX_PRINTERS = 3;
    ColorLaser printers[3];
    int count = 0;

    ifstream inputFile("printers.txt");
    if (inputFile.is_open()) {
        string name, color;
        int soluong, dpi;

        while (getline(inputFile, name) && count < 3) {
            inputFile >> soluong >> dpi;
            inputFile.ignore();
            getline(inputFile, color);

            printers[count] = ColorLaser(name, soluong, dpi, color);
            count++;
        }

        inputFile.close();
        cout << "Da nap du lieu tu tep printers.txt." << endl;
    } else {
        cout << "Khong the mo tep printers.txt." << endl;
    }

    int choice;
    do {
        displayMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (count < 3) {
                    string name, color;
                    int soluong, dpi;

                    cout << "Nhap ten may in: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Nhap so luong: ";
                    cin >> soluong;

                    cout << "Nhap Dpi: ";
                    cin >> dpi;

                    cout << "Nhap mau sac: ";
                    cin.ignore();
                    getline(cin, color);

                    printers[count] = ColorLaser(name, soluong, dpi, color);
                    count++;
                    cout << "Them may in thanh cong!" << endl;
                } else {
                    cout << "Da dat gioi han so luong may in." << endl;
                }
                break;
            }
            case 2: {
                if (count > 0) {
                    int index;
                    cout << "Nhap index cua may in muon xuat: ";
                    cin >> index;

                    if (index >= 0 && index < count) {
                        int q;
                        cout << "Nhap so luong muon xuat: ";
                                               cin >> q;
                        printers[index].xuatkho(q);
                        cout << "Xuat may in thanh cong!" << endl;
                    } else {
                        cout << "Index khong hop le." << endl;
                    }
                } else {
                    cout << "Chua co may in nao trong kho." << endl;
                }
                break;
            }
            case 3: {
                if (count > 0) {
                    cout << "Thong tin cac may in:" << endl;
                    for (int i = 0; i < count; i++) {
                        cout << "May in " << i + 1 << ":" << endl;
                        cout << "Ten: " << printers[i].Name << endl;
                        cout << "Dpi: " << printers[i].Dpi << endl;
                        cout << "Mau sac: " << printers[i].Color << endl;
                        cout << "So luong trong kho: " << printers[i].Soluong << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Chua co may in nao trong kho." << endl;
                }
                break;
            }
            case 0: {
                cout << "Ket thuc chuong trinh." << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le." << endl;
                break;
            }
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

