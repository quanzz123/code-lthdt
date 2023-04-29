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
            cout << "(" << fixed << setprecision(0) << x << ", " << fixed << setprecision(0) << y << ")";
        }
        friend double distance(Point a, Point b);
};

double distance(Point a, Point b) {
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
        double perimeter() {
            double ab = distance(a,b);
            double ac = distance(a, c);
            double bc = distance(b,c);
            double p = ab + ac + bc;
            if(ab +ac <= bc || ab + bc <= ac || bc + ac <= ab) {
                cout << "NO" << endl;
                return 0;
            }
            return p;
            //return distance(a, b) + distance(b, c) + distance(c, a);
        }
        double area() {
            double ab = distance(a,b);
            double ac = distance(a, c);
            double bc = distance(b,c);
            double p = (ab + ac + bc) / 2.0;
            if(ab +ac <= bc || ab + bc <= ac || bc + ac <= ab) {
                cout << "NO" << endl;
                return 0;
            }
            return sqrt(p*(p-ab)*(p-ac)*(p-bc));
            //double p = perimeter() / 2;
            //return sqrt(p * (p - distance(a, b)) * (p - distance(b, c)) * (p - distance(c, a)));
        }
        void display() {
            /*cout << "| "; cout << setw(8);
            a.display(); cout << " | "; cout << setw(8);
            b.display(); cout << " | "; cout << setw(8);
            c.display(); cout << " | ";
            cout << setw(6) << fixed << setprecision(2) << perimeter() << " | " << setw(8) << fixed << setprecision(2) << area() << " |\n";*/
			cout << "|" << setw(10); a.display();
			cout << "|" << setw(10); b.display();
			cout << "|" << setw(10); c.display();
			cout << "|" << setw(16) << fixed << setprecision(2) << perimeter();
			cout << "|" << setw(15) << fixed << setprecision(2) << area() << "|" << endl;
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
	cout << "    ______________________________________________________________________________________\n";
    cout << "   | STT | Toa do diem A | Toa do diem B | Toa do diem C |       chu vi   |      Dien tich|\n";
    cout << "   |-----|---------------|---------------|---------------|----------------|---------------|\n";
    for (int i = 0; i < n; i++) {
        cout << "   |  " << i + 1 << "  ";
        triangles[i].display();
    }
	cout << "   |_____|_______________|_______________|_______________|________________|_______________|\n";
    delete[] triangles;
    return 0;
}
