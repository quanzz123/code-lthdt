#include<bits/stdc++.h>
using namespace std;

class hcn{
    private:
        int a, b;
    public:
        void khaitao(int a1, int b1){
            a = a1;
            b = b1;
        }
        float chuvi(){
            return (a + b) / 2.0;
        }
        float dientich(){
            return a * b;
        }
        void printf(){
            cout << "chieu dai= " << a << endl;
            cout << "chieu rong= " << b << endl;
            cout << "chu vi= " << chuvi() << endl << "dien tich = " << dientich() << endl;
        }
        float A(){
            return a;
        }
        float B(){
            return b;
        }
};