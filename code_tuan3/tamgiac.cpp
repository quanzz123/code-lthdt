#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x, y;
public:
    void init(float ox, float oy) {
        x = ox;
        y = oy;
    }

    void move(float dx, float dy) {
        x += dx;
        y += dy;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }
};

class Triangle {
private:
    Point p1, p2, p3;
public:
    void init(Point point1, Point point2, Point point3) {
        p1 = point1;
        p2 = point2;
        p3 = point3;
    }

    float distance(Point point1, Point point2) {
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        float distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        return distance;
    }

    float perimeter() {
        float a = distance(p1, p2);
        float b = distance(p2, p3);
        float c = distance(p3, p1);
        float perimeter = a + b + c;
        return perimeter;
    }

    float area() {
        float a = distance(p1, p2);
        float b = distance(p2, p3);
        float c = distance(p3, p1);
        float p = (a + b + c) / 2;
        float area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }
};
class TriangleValidator {
public:
    bool isValid(Point p1, Point p2, Point p3) {
        float a = distance(p1, p2);
        float b = distance(p2, p3);
        float c = distance(p3, p1);
        if (a + b > c && b + c > a && c + a > b) {
            return true;
        }
        return false;
    }

private:
    float distance(Point point1, Point point2) {
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        float distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        return distance;
    }
};


int main() {
    Point p1, p2, p3;
    Triangle t;

    p1.init(0, 0);
    p2.init(3, 0);
    p3.init(0, 4);

    t.init(p1, p2, p3);

    cout << "Perimeter: " << t.perimeter() << endl;
    cout << "Area: " << t.area() << endl;

    return 0;
}
