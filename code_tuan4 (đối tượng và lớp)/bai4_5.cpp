#include"thuvien4_5.h"
int main() {
    int n;
    cout << "\nnhap so luong tai khoan: ";
    cin >> n;
    cin.ignore();

    TaiKhoan* ds = new TaiKhoan[n];

    //nhap thong tin cho tung tai khoan
    for(int i=0; i < n; i++) {
        cout << "\nnhap thong tin cho tai khoan " << i+1 << ":" <<endl;
        ds[i].nhap_data();

    }
    cout <<"\n====danh sach tai khoan====\n" << endl;
    for(int i=0; i<n; i++) {
    
        ds[i].hien_thi();
        ds[i].gui_tien(ds[i].tiengui());
        
    }
}