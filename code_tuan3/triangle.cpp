#include"libary.h"

int main(){
    point p1, p2, p3;
    Triangcle t;
    TriagleValidator tv;

    p1.init(0, 0);
    p2.init(3, 0);
    p3.init(0, 4);

    if(tv.check(p1, p2, p3)){
        t.init(p1, p2, p3);
        cout << "\ncv= " << t.cv() << endl;
        cout << "\ndt = " << t.dt() << endl;
    } else{
        cout << "\nkhong to thanh mot tam giac!" << endl; //ok
    }
    return 0;
}