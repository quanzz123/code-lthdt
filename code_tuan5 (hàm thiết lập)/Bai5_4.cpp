#include"thuvien5_4.h"
int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;
    cin.ignore();
    TamGiac* ds = new TamGiac[n];
    for(int i=0; i<n; i++) {
        cout << "\nnhap ba canh tam giac thu " << i+1 << endl;
        ds[i].nhap();
    }
    cout << "\n\n\t\t===THONG TIN CAC TAM GIAC===\n\n";
    for(int i=0; i<n; i++) {
        cout << "\nThong tin tam giac thu " << i+1 << endl;
        ds[i].in();
        
    }
    return 0;
}