#include <iostream>

using namespace std;

bool isTriangle(double a, double b, double c) {
    return (a + b > c) && (b + c > a) && (a + c > b);
}

int main() {
    double a, b, c;

    cout << "Nhap vao 3 so thuc a, b, c: ";
    cin >> a >> b >> c;

    if (isTriangle(a, b, c)) {
        cout << "a, b, c tao thanh 3 canh cua tam giac.";
    } else {
        cout << "a, b, c khong tao thanh 3 canh cua tam giac.";
    }

    return 0;
}
