#include<bits/stdc++.h>
using namespace std;
class Point {
    private:
        int x, y;
    public:
        Point(int ox=0, int oy=0) {
            x = ox;
            y = oy;
        }
        void display() {
            cout << "(" << x << "," << y << ")";
        }
        friend float distance(Point& p1, Point& p2) {
            return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
        }
};
class Triangle {
    private:
        Point p1, p2, p3;
    public:
        Triangle(Point oa, Point ob, Point oc) {
            p1 = oa;
            p2 = ob;
            p3 = oc;
        }
        float perimeter() {
            float a = distance(p1, p2);
            float b = distance(p1, p3);
            float c = distance(p2, p3);
            return a + b + c;
        }
        float area() {
            float a = distance(p1, p2);
            float b = distance(p1, p3);
            float c = distance(p2, p3);
            float p = (a + b + c) / 2.0;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
        void print() {
            cout << "Thong tin tam giac: " << endl;
            p1.display();
            cout << ",";
            p2.display();
            cout << ",";
            p3.display();
            cout << ",";
            cout << "Perimeter: " << perimeter() << endl;
            cout << "Area: " << area() << endl;
        }
};