#include"iostream"

using namespace std;

class point{
    private :
        float x,y;
    public :
        void init(float ox, float oy){ 
            x = ox;
            y = oy;
        }
        // đưa tất cả các ham move và display vào trong định nghía lớp.
        void move(float dx, float dy){
            x += dx;
            y += dy;
        }
        void display(){
            cout << "\ntoa do cua x la: " << x << "\ttoa do cua y la : " << y ;
        }
};
int main()
{
    point p, q;
    p.init(2,3);
    p.display();
    cout << endl;
    cout << "\n\n toa do sau khi tinh tien: \n\n";
    p.move(3,4);
    p.display();
    cout << endl;
}


