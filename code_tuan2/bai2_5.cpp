#include<iostream>
#include<cmath>
using namespace std;

typedef struct{
    int pt;
    int pa;
} so_phuc;

ostream& operator << (ostream& out, const so_phuc& a){
    out << a.pt;
    if(a.pa < 0){
        cout <<"-";
    }
    else{
        cout << "+";
    } 
    cout << abs(a.pa)<< "i";
    return out;
    
}


istream& operator>>(istream& in, so_phuc& c) {
    cout << "Nhap phan thuc: ";
    in >> c.pt;
    cout << "Nhap phan ao: ";
    in >> c.pa;
    return in;
}
so_phuc operator+(const so_phuc& a, const so_phuc& b){
    so_phuc c;
    c.pt = a.pt + b.pt;
    c.pa = a.pa + b.pa;
    return c;
}
so_phuc operator-(const so_phuc& a, const so_phuc& b){
    so_phuc c;
    c.pt = a.pt - b.pt;
    c.pa = a.pa - b.pa;
    return c;
}
bool operator==(const so_phuc& a, const so_phuc& b){
    return a.pt == b.pt && a.pa == b.pa;
}
bool operator!=(const so_phuc& a, const so_phuc& b){
    return !(a == b);
}
int main(){
    so_phuc a, b;
    cout <<"\nnhap so phuc a: ";
    cin >> a;
    cout << "\nnhap so phuc b: ";
    cin >> b;
    cout << "a + b= "<<(a + b) <<endl;
    cout << "a-b= " << (a - b) << endl;
    if(a == b){
        cout << "\na bang b" << endl;

    } else{
        cout << "a khac b" << endl;
    }
    return 0;
}