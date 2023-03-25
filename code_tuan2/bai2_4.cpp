#include"iostream"

using namespace std;

typedef struct{
    int ts;
    int ms;

}ps;

ostream& operator<<(ostream& os, const ps& a){
    os << a.ts << "/" << a.ms;
    return os;
}
istream& operator>>(istream& is, ps& a){
    cout << "nhap tu so: ";
    is >> a.ts;
    do{
        cout << "nhap mau so: ";
        is >> a.ms;
        if(a.ms == 0 ){
            cout << "mau so phai khac 0! moi nhap lai!" << endl;
        }
    }while (a.ms == 0);
    return is;
}
ps operator+(ps a, ps b){
    ps c;
    c.ts = a.ts * b.ms + a.ms * b.ts;
    c.ms = a.ms * b.ms;
}
ps operator-(ps a){
    ps c;
    c.ts = -a.ts;
    c.ms = a.ms;
    return c;
}
ps operator-(ps a, ps b){
    ps c;
    c.ts = a.ts*b.ms - a.ms*b.ts;
    c.ms = a.ms * b.ms;
    return c;
}
ps operator*(ps a, ps b){
    ps c;
    c.ts = a.ts * b.ts;
    c.ms = a.ms * b.ms;
    return c;
}
ps operator/(ps a, ps b){
    ps c;
    c.ts = a.ts * b.ms;
    c.ms = a.ms * b.ts;
    return c;
}
bool operator>(ps a, ps b){
    return a.ts*b.ms > a.ms*b.ts;
}
bool operator==(ps a, ps b){
    return a.ts*b.ms == b.ts*a.ms;
}
int main(){
    ps a, b, c;
    cout << "nhap phan so a: ";
    cin >> a;
    cout << "nhap phan so b: ";
    cin >> b;
    cout << "tong hai phan so: " << (a + b) << endl;

    cout << "phan so a > b:  " << (a > b) << endl;
    cout << "phan so a = b:  " << (a == b) << endl;
}