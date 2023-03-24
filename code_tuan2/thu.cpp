#include <iostream>
using namespace std;

struct phanso {
    int ts;
    int ms;
};

istream& operator>>(istream& is, phanso& p) {
    cout << "Nhap tu so: ";
    is >> p.ts;
    cout << "Nhap mau so: ";
    is >> p.ms;
    return is;
}

ostream& operator<<(ostream& os, const phanso& p) {
    os << p.ts << "/" << p.ms;
    return os;
}

int main() {
    phanso a;
    cout << "Nhap phan so a: ";
    cin >> a;
    cout << "Phan so vua nhap la: " << a << endl;
    return 0;
}
