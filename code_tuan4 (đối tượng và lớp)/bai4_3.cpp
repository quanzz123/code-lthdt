#include"thuvien4_3.h"
void PTB1 ::giai_PTB1() {
    if(a == 0) {
        if(b == 0) {
            cout << "\nphuong trinh vo nghiem!" << endl;
        } else {
            cout << "\nphuong trinh vo so nghiem!" << endl;
        }
    } else {
        float x;
        x = -b / a;
        cout << "\nnghiem cua phuong trinh la: " << x << endl;
    }
}
int main() {
    PTB1 y;
    y.nhap_heso();
    y.giai_PTB1();
    system("pause");

}