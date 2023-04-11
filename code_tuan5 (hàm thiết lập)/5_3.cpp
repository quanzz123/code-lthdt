#include<bits/stdc++.h>
using namespace std;
class MatHang {
    private:
        string Ten;
        int SoLuong;
        int DonGia;
    public:
        MatHang(string Ten = "", int SoLuong = 0, int DonGia = 0) {
            this->Ten = Ten;
            this->SoLuong = SoLuong;
            this->DonGia  = DonGia;
        }
        void nhapthongtin() {
            cout << "\nNhap ten mat hang: ";
            getline(cin, Ten);
            cin.ignore();
            cout <<"\nNhap So luong: ";
            cin >>SoLuong;
            cout << "\nNhap don gia: ";
            cin >> DonGia;
            cin.ignore();
        }
        void inthongtin() {
        cout << setw(20) << left << Ten;
        cout << setw(10) << right << SoLuong;
        cout << setw(15) << right << fixed << setprecision(2) << DonGia;
        cout << setw(18) << right << fixed << setprecision(2) << SoLuong * DonGia << endl;
        cout << setfill('-') << setw(63) << "-" << endl;
        cout << setfill(' ');
        }
        ~MatHang() {
            cout << "\nHuy bo doi tuong MatHang!" << endl;
        }
};
/*Bài 5.3: Xây dựng lớp MatHang mô tả các đối tượng mặt hàng, lớp gồm các thành phần
sau:
- Các thuộc tính Tên, Số lượng, Đơn giá.
- Hàm thiết lập ba tham số, trong đó có hai tham số có giá trị ngầm định Số lượng = 0
và Đơn giá = 0
- Hàm nhập thông tin về một mặt hàng.
- Hàm in ra màn hình thông tin về một mặt hàng.
Viết hàm main tạo một đối tượng MatHang M. In ra màn hình thông tin về mặt
hàng.*/
int main() {
    int n;
    cout << "nhap so luong mat hang: ";
    cin >> n;
    cin.ignore();
    vector<MatHang> ds(n);
    for(int i=0; i<n; i++) {
        ds[i].nhapthongtin();
    }
    cout <<"\n\n\t\t===BANG THONG KE CAC MAT HANG===\n\n";
    cout << setw(20) << left << "Ten mat hang";
    cout << setw(10) << right << "So luong";
    cout << setw(15) << right << "Don gia";
    cout << setw(18) << right << "Thanh tien(VND)" << endl;
    cout << setfill('-') << setw(63) << "-" << endl;
    cout << setfill(' ');

    for(int i=0; i<n; i++) {
        ds[i].inthongtin();
    }
    return 0;
}