#include <iostream>
#include<cmath>

using namespace std;

struct sophuc {
    float pt;
    float pa;
};

// Phép cộng 2 số phức
sophuc operator+(const sophuc& a, const sophuc& b) {
    sophuc c;
    c.pt = a.pt + b.pt;
    c.pa = a.pa + b.pa;
    return c;
}

// Phép trừ 2 số phức
sophuc operator-(const sophuc& a, const sophuc& b) {
    sophuc c;
    c.pt = a.pt - b.pt;
    c.pa = a.pa - b.pa;
    return c;
}

// Phép so sánh bằng 2 số phức
bool operator==(const sophuc& a, const sophuc& b) {
    return a.pt == b.pt && a.pa == b.pa;
}

// Phép so sánh khác 2 số phức
bool operator!=(const sophuc& a, const sophuc& b) {
    return !(a == b);
}

// Phép xuất số phức
ostream& operator<<(ostream& out, const sophuc& c) {
    out << c.pt << (c.pa < 0 ? " - " : " + ") << abs(c.pa) << "i";
    return out;
}

// Phép nhập số phức
istream& operator>>(istream& in, sophuc& c) {
    cout << "Nhap phan thuc: ";
    in >> c.pt;
    cout << "Nhap phan ao: ";
    in >> c.pa;
    return in;
}

int main() {
    sophuc a, b;
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    if (a == b) {
        cout << "a bang b" << endl;
    } else {
        cout << "a khac b" << endl;
    }
    return 0;
}
