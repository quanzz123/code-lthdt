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
        void add() {
            cout << "Nhap to do x: ";
            cin >> x;
            cout << "Nhap toa do Y: ";
            cin >> y;
        }
        void display() {
            cout << "(" << x << "," << y << ")";
        }
        friend float distance(Point& p1, Point& p2) {
            return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
        }
};
class Triangle  {
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
        
            cout << setw(15 ) << perimeter() << "|" << setw(15) << area() << "|"; 
        }
};
int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;
    Triangle *list = new Triangle[n];
    for(int i=0; i<n; i++) {
        Point a, b, c;
        a.add();
        b.add();
        c.add();
    }
    for(int i=0; i<n; i++) {

        list.print();
        cout << endl;
    }
    return 0;
}
