#include"iostream"
using namespace std;
 void taovecto(float *&a, int n){
    a = new float[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
 }
 void invecto(float *a, int n){
    cout << "(";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << ")";
    cout << endl;
 }
 void giai_phong(float *a){
    delete a;
 }
 void add(float *a, int n, float *b,int m, float * &tong){
    if(n != m){
        cout << "\nhai vecto khong cung chieu!" << endl;
        return;
    }
    tong = new float[n];
    for(int i=0; i<n; i++){
        tong[i] = a[i] + b[i];
    }
 }
 void sub(float *a, int n, float *b, int m, float *&hieu){
    if(n != m){
        cout << "\nhai vecto khong cung chieu!" << endl;
        return;
    }
    hieu = new float[n];
    for(int i=0; i<n; i++){
        hieu[i] = a[i] - b[i];
    }
 }
 int main(){
    int n,m;
    cout << "\nnhap so phan tu cua vecto thu nhat: ";
    cin >> n;
    cout << "\nnhap so phan tu cua vecto thu hai ";
    cin >> m;
    float *a, *b, *tong, *hieu;
    taovecto(a,n);
    cout << endl;
    taovecto(b,m);

    invecto(a,n);
    cout << endl;
    invecto(b,m);

    add(a,n,b,m,tong);
    sub(a,n,b,m,hieu);

    cout << "\ntong cua hai vecto: " << endl;
    invecto(tong,n);

    cout << "\nhieu cua hai vecto: " << endl;
    invecto(hieu,n);

    giai_phong(a);
    giai_phong(b);
    giai_phong(tong);
    giai_phong(hieu);


 }