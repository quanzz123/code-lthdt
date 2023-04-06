#include"thuvien_qlsv.h"
int main() {
    int n;
    cout << "\nnhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    SinhVien* ds = new SinhVien[n];

    for(int i=0; i <n; i++) {
        cout <<"\nnhap thong tin sinh vien thu: " << i+1 << endl;
        ds[i].Nhapthongtin();
        cout << endl;
    }

    cout << "\n===Danh sach sinh vien===\n\n";
    for(int i=0; i<n; i++) {
        cout << "\nThong tin sinh vien thu: " << i+1 << endl;
        ds[i].Printf();
        ds[i].XepLoai(ds[i].getDiem());
        cout << endl;
    }
    system("pause");
}