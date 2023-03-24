#include<iostream>
using namespace std;

struct phanso {
    int ts;
    int ms;
};

// Các phép toán số học
phanso operator+(phanso a, phanso b) {
    phanso c;
    c.ts = a.ts * b.ms + b.ts * a.ms;
    c.ms = a.ms * b.ms;
    return c;
}

phanso operator-(phanso a, phanso b) {
    phanso c;
    c.ts = a.ts * b.ms - b.ts * a.ms;
    c.ms = a.ms * b.ms;
    return c;
}

phanso operator-(phanso a) {
    phanso c;
    c.ts = -a.ts;
    c.ms = a.ms;
    return c;
}

phanso operator*(phanso a, phanso b) {
    phanso c;
    c.ts = a.ts * b.ts;
    c.ms = a.ms * b.ms;
    return c;
}

phanso operator/(phanso a, phanso b) {
    phanso c;
    c.ts = a.ts * b.ms;
    c.ms = a.ms * b.ts;
    return c;
}

// Các phép toán quan hệ
bool operator>(phanso a, phanso b) {
    return a.ts * b.ms > b.ts * a.ms;
}

bool operator>=(phanso a, phanso b) {
    return a.ts * b.ms >= b.ts * a.ms;
}

bool operator<(phanso a, phanso b) {
    return a.ts * b.ms < b.ts * a.ms;
}

bool operator<=(phanso a, phanso b) {
    return a.ts * b.ms <= b.ts * a.ms;
}

bool operator==(phanso a, phanso b) {
    return a.ts * b.ms == b.ts * a.ms;
}

bool operator!=(phanso a, phanso b) {
    return a.ts * b.ms != b.ts * a.ms;
}

// Các phép toán tăng, giảm
phanso operator++(phanso &a) {
    a.ts += a.ms;
    return a;
}

phanso operator--(phanso &a) {
    a.ts -= a.ms;
    return a;
}

// Các phép toán nhập, xuất
ostream& operator<<(ostream& os, const phanso& a) {
    os << a.ts << "/" << a.ms;
    return os;
}

istream& operator>>(istream& is, phanso& a) {
    cout << "Nhap tu so: ";
    is >> a.ts;
    do {
        cout << "Nhap mau so: ";
        is >> a.ms;
        if (a.ms == 0) {
            cout << "Mau so phai khac 0. Hay nhap lai." << endl;
        }
    } while (a.ms == 0);
    return is;
}

int main() {
    phanso a, b, c;
    cout << "Nhap phan so a: ";
    cin >> a;
    cout << "Nhap phan so b: ";
    cin >> b;
    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;
}
   
