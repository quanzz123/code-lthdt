#include<iostream>
#include<cmath>

using namespace std;

typedef struct{
    float pt;
    float pa;

} sophuc;

ostream& operator<<(ostream& out , const sophuc& c){
    out << c.pt;
    if(c.pa < 0){
        cout << "-";
    }
    else{
        cout <<"+";
    }
    cout << abs(c.pa) << "i";
    return out;
}
istream& operator>>(istream& in, sophuc& c){
    cout << "\nnhap phan thuc: ";
    cin >> c.pt;
    cout << "\nnhap phan ao: ";
    cin >> c.pa;
    return in;
}
sophuc operator+(const sophuc& a, const sophuc& b){
    sophuc c;
    c.pt = a.pt + b.pt;
    c.pa = a.pa + b.pa;
    return c;
}
sophuc operator-(const sophuc& a, const sophuc& b){
     sophuc c;
    c.pt = a.pt - b.pt;
    c.pa = a.pa - b.pa;
    return c;
}
bool operator==(const sophuc& a, const sophuc& b){
    return a.pt == b.pt && a.pa == b.pa;
}
bool operator!=(const sophuc& a, sophuc& b){
    return !(a == b);
}