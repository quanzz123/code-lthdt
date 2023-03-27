#include"libary.h"

int main(){
    point p1, p2, p3;
    Triangcle t;
    TriagleValidator tv;

    p1.init(1, 2);
    p2.init(4, 7);
    p3.init(-2, 3);

    if(tv.check(p1, p2, p3)){
        t.init(p1, p2, p3);
        cout << "\ncv= " << t.cv() << endl;
        cout << "\ndt = " << t.dt() << endl;
    } else{
        cout << "\nkhong tao thanh mot tam giac!" << endl; //ok
    }
    return 0;
}