#include <iostream>
#include <string>
using namespace std;

class TaiKhoan {
private:
    string ten;
    string soTK;
    string tenNganHang;
    double soTien;

public:
    void nhapThongTin() {
        cout << "Nhap ten nguoi gui tien: ";
        getline(cin, ten);
        cout << "Nhap so tai khoan: ";
        getline(cin, soTK);
        cout << "Nhap ten ngan hang: ";
        getline(cin, tenNganHang);
        cout << "Nhap so tien: ";
        cin >> soTien;
        cin.ignore(); // bo qua ky tu \n con lai trong buffer
    }

    void hienThiThongTin() {
        cout << "Ten nguoi gui tien: " << ten << endl;
        cout << "So tai khoan: " << soTK << endl;
        cout << "Ten ngan hang: " << tenNganHang << endl;
        cout << "So tien: " << soTien << endl;
    }

    double laySoTien() {
        return soTien;
    }

    void napTien(double soTienNap) {
        soTien += soTienNap;
        cout << "Nap tien thanh cong!" << endl;
    }

    void rutTien(double soTienRut) {
        if (soTienRut > soTien) {
            cout << "Khong du tien de rut!" << endl;
        }
        else {
            soTien -= soTienRut;
            cout << "Rut tien thanh cong!" << endl;
        }
    }
};

int main() {
    int n;
    double giaTriN;
    cout << "Nhap so tai khoan: ";
    cin >> n;
    cin.ignore();

    TaiKhoan* dsTK = new TaiKhoan[n];

    // Nhập thông tin cho từng tài khoản
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho tai khoan " << i + 1 << ":" << endl;
        dsTK[i].nhapThongTin();
    }

    // Hiển thị thông tin các tài khoản
    cout << "\nDanh sach tai khoan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin tai khoan " << i + 1 << ":" << endl;
        dsTK[i].hienThiThongTin();
    }
}

    // Kiểm tra và hiển thị các tài khoản có số tiền lớn hơn giá trị nào đó
