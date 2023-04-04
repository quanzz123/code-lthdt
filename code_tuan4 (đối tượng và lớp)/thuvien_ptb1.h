/* mô tả bài toán giải phương trình bậc nhất.Viết chương trình khái báo và sử dụng đối tượng
phương trình bậc nhất*/
#include<bits/stdc++.h>
using namespace std;
class PTB1 {
    private:
        float a,b;
    public:
        void Nhap_heso() {
            cout << "\nnhap he so a: ";
            cin >> a;
            cout << "\nnhap he so b: ";
            cin >> b;
        }

        void Giai_PTB1() {
            if(a == 0) {
                if(b == 0) {
                    cout << "\nphuong trinh vo nghiem!" << endl;
                } else {
                    cout << "\nphuong trinh co vo so nghiem!" << endl;
                } 
                
            } else {
                float x ;
                x = -b / a;
                cout << "\nnghiem cua phuong trinh la: " << x << endl;
            }
        }
};