#include"thuvien2_5.h"

int main(){
    sophuc a,b;
    cout << "\nhap so phuc a: ";
    cin >> a;
    cout << "\nnhap so phuc b: ";
    cin >> b;

    if(a == b){
        cout <<"\n a bang b!" << endl;
    }
    else{
        cout << "\n a khong bang b!" << endl;
    }
    cout << "\na + b = " << (a+b) << endl;
    cout << "\na - b= " << (a-b) << endl;
    system("pause");
}