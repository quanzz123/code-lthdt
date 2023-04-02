#include"thuvien3_2.h"
int main(){
    
    hcn h;
    float a, b;
    cout << "\nnhap chieu dai: " << endl;
    cin >> a;
    cout <<"\nnhap chieu rong: " << endl;
    cin >> b;
   
    
    h.khaitao(a,b);
    h.chuvi();
    h.dientich();
    h.printf();
    system("pause");
}
