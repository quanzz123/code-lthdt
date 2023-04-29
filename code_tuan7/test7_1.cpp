#include <iostream>
#include <math.h>
#include<iomanip>

using namespace std;

class Point {
    private:
        float x, y;
    public:
        Point(float ox=0, float oy=0) {
            x = ox;
            y = oy;
        }
        void display() {
            cout << "(" << x << ", " << y << ")";
        }
        friend float distance(Point a, Point b);
};

float distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Triangle : public Point {
    private:
        Point a, b, c;
    public:
        Triangle(Point oa=Point(0,0), Point ob=Point(0,0), Point oc=Point(0,0)) {
            a = oa;
            b = ob;
            c = oc;
        }
        float perimeter() {
            return distance(a, b) + distance(b, c) + distance(c, a);
        }
        float area() {
            float p = perimeter() / 2;
            return sqrt(p * (p - distance(a, b)) * (p - distance(b, c)) * (p - distance(c, a)));
        }
        void display() {
            cout << "| "; cout << setw(8);
            a.display(); cout << " | "; cout << setw(8);
            b.display(); cout << " | "; cout << setw(8);
            c.display(); cout << " | ";
            cout << setw(6) << fixed << setprecision(2) << perimeter() << " | " << setw(8) << fixed << setprecision(2) << area() << " |\n";
        }
};

int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    Triangle *triangles = new Triangle[n];

    cout << "Nhap toa do cac diem cua tam giac:\n";
    for (int i = 0; i < n; i++) {
        float xa, xb, xc, ya, yb, yc;
        cout << "Tam giac " << i + 1 << ":\n";
        cout << "Nhap toa do diem A: ";
        cin >> xa >> ya;
        cout << "Nhap toa do diem B: ";
        cin >> xb >> yb;
        cout << "Nhap toa do diem C: ";
        cin >> xc >> yc;
        triangles[i] = Triangle(Point(xa, ya), Point(xb, yb), Point(xc, yc));
    }

    cout << "\nDanh sach tam giac:\n";
	cout << "    _________________________________________________________________________\n";
    cout << "   | STT | Toa do diem A | Toa do diem B | Toa do diem C | Chu vi | Dien tich|\n";
    cout << "   |-----|---------------|---------------|---------------|--------|----------|\n";
    for (int i = 0; i < n; i++) {
        cout << "   |  " << i + 1 << "  ";
        triangles[i].display();
    }
	cout << "   |_____|_______________|_______________|_______________|________|__________|\n";
    delete[] triangles;
    return 0;
}
