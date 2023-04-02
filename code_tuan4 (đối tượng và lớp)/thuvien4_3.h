#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class PTB1 {
    private:
        float a,b;
    public:
        void nhap_heso() {
            cout <<"\nnhap he so a: ";
            cin >> a;
            cout << "\nnhap he so b: ";
            cin >> b;
        }
        void giai_PTB1();

};
/*Bài 4.3. Xây dựng lớp PTBN mô tả các đối tượng phương trình bậc nhất, lớp gồm các
thành phần:
- Các thuộc tính mô tả gồm: hai hệ số a, b
- Hàm khởi tạo phương trình bậc nhất
- Hàm giải phương trình bậc nhất
Viết hàm main tạo một đối tượng phương trình bậc nhất. Hiển thị kết quả giải
phương trình đó.*/