#include"thuvien4_4.h"
int main() {
    const int so_hs = 3;
    HocSinh hs[so_hs];
    //tao mot vong for dể nhập các dữ liệu của học sinh
    for(int i=0; i<=so_hs; i++) {
        cout << "\nnhap thong tin cua hoc sinh thu " << i+1 << endl;
        hs[i].khoitao();
        cout << endl;
    }
    //hiện thị dữ liệu học sinh

    for(int i=0; i <= so_hs; i++) {
        hs[i].printf();
        cout << endl;
    }

    //kiểm tra và hiển thị các học sinh có ddiemr trung binh >= 5
    cout << "\ndanh sach hoc sinh co diem trung binh >= 5" << endl;

    for(int i=0; i <= so_hs; i++) {
        if(hs[i].diem_tb() >= 5) {
            hs->printf();
        }
    }
    system("pause");

}