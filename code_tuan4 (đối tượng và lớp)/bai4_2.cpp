#include"thuvien4_2.h"

int main() {
    point p1, p2, p3;
    Triangle h;
    TriagleValidator t;

    p1.init(0,0);
    p2.init(0,0);
    p3.init(0,0);
    if(t.check(p1,p2,p3)) {
        h.KhoiTao(p1,p2,p3);
        cout << "\nchu vi = " << h.ChuVi() << endl;
        cout << "\nDien tích = " << h.DienTich() << endl;

    } else {
        cout << "\nkhong tao thanh mot tam giac!" << endl;
    }
    return 0;
}