#include"thuvien5_4.h"
int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    freopen("5_4.txt", "r", stdin);
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
        if(ds[i].Geta(), ds[i].Getb(), ds[i].Getc()) {
            cout << "\nChu vi =  " << ds[i].ChuVi() << endl;
            cout << "\nDien Tich = " << ds[i].DienTich() << endl;
        } else {
            cout << "\nBa canh khong tao thanh mot tam giac!" << endl;
        }
        
    }
    return 0;
}