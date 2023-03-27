#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;
class point{
    private:
        float x,y;
    public:
        void init(float ox, float oy){
            x = ox;
            y = oy;
        }
        void move(float dx, float dy){
            x += dx;
            y += dy;
        }
        void display(){
            cout << "\ntoa do cua x= " << x << endl;
            cout << "\ntoa do cua y= " << y << endl;
        }
        float X(){
            return x;
        }
        float Y(){
            return y;
        }

};
class Triangcle{
    private:
        point a, b, c;
    public:
        void init(point oa, point ob, point oc){
            a = oa;
            b = ob;
            c = oc;
        }
        float canh(point a, point b){
            float x1, x2, y1, y2, canh;
            x1 = a.X();
            y1 = a.Y();

            x2 = b.X();
            y2 = b.Y();

            canh = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
            return canh;
        }
        float cv(){
            float ab, ac, bc, cv;
            ab = canh(a, b);
            ac = canh(a, c);
            bc = canh(b,c);
            cv = ab + ac + bc;
            return cv;
        }
        float dt(){
            float ab, ac, bc, dt, p;
            ab = canh(a, b);
            ac = canh(a, c);
            bc = canh(b, c);
            p = (ab + ac + bc ) / 2.0;
            dt = sqrt(p * (p - ab) * (p - ac) * (p - bc));
            return dt;
        }

};
class TriagleValidator{
    private:
        float canh(point a, point b){
            float x1, x2, y1, y2, canh;
            x1 = a.X();
            y1 = a.Y();

            x2 = b.X();
            y2 = b.Y();

            canh = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
            return canh;
        }
    public:
        bool check(point a, point b, point c){
            float ab , ac, bc;
            ab = canh(a, b);
            ac = canh(a, c);
            bc = canh(b, c);
            if(ab+ac>bc && ab+bc>ac && ac+bc>ab ){
                return true;
            }
            return false;
        }

};