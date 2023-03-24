#include"iostream"
using namespace std;

void nhap_mang(float** &a, int n, int m ){
    a = new float*[n];
    for(int i=0; i<n; i++){
        a[i] = new float[m];
        for(int j=0; j<m; j++){
            cout << "nhap phan tu thu [" << i << "][" << j << "]";
            cin >> a[i][j];
        }
    }
}
void in_mang(float** a, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void add(float** a, float** b, float** &tong, int n, int m){
    tong = new float*[n];
    for(int i=0; i<n; i++){
        tong[i] = new float[m];
        for(int j=0; j<m; j++){
            tong[i][j] = a[i][j] + b[i][j];

        }
    }
}
void sub(float** a, float** b, float** &hieu, int n, int m){
    hieu = new float*[n];
    for(int i=0; i<n; i++){
        hieu[i] = new float[m];
        for(int j=0; j<m; j++){
            hieu[i][j] = a[i][j] - b[i][j];
        }
    }
}
void giai_phong(float** a, int n ){
    for(int i=0; i<n; i++){
        delete a[i];
    }
    delete a;
}
int main(){
    int n,m,p,q;
    cout << "nhap so hang so cot cua ma tran thu nhat: ";
    cin >> n >> m;
    cout << "nhap so hang so cot cua ma tran thu hai: ";
    cin >> p >> q;
    float** a, **b, **tong, **hieu;
    if(n == p && m == q){
        nhap_mang(a,n,m);
        cout << endl;
        nhap_mang(b,p,q);

        in_mang(a,n,m);
        cout << endl;
        in_mang(b,p,q);

        add(a,b,tong,n,m);
        sub(a,b,hieu,n,m);

        cout << "\ntong cua hai ma tran: " << endl;
        in_mang(tong,n,m);

        cout << "\nhieu cua hai ma tran : " << endl;
        in_mang(hieu,n,m);

        giai_phong(a,n);
        giai_phong(b,p);
        giai_phong(tong,n);
        giai_phong(hieu,n);
    }

}