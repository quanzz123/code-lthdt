#include"thuvien4_4.h"
int main() {
    int n;
    cout << "nhap so luong sinh vien";
    cin >> n;
    cin.ignore();
    HocSinh* hs = new HocSinh[n];
    //tao mot vong for dể nhập các dữ liệu của học sinh
    for(int i=0; i<=n; i++) {
        cout << "\nnhap thong tin cua hoc sinh thu " << i+1 << endl;
        hs[i].khoitao();
        cout << endl;
    }
    //hiện thị dữ liệu học sinh

    for(int i=0; i <= n; i++) {
        hs[i].printf();
        cout << endl;
    }

    //kiểm tra và hiển thị các học sinh có ddiemr trung binh >= 5
    cout << "\ndanh sach hoc sinh co diem trung binh >= 5" << endl;

    for(int i=0; i <= n; i++) {
        if(hs[i].diem_tb() >= 5) {
            hs[i].printf();
        }
    }
    system("pause");

}