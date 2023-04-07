#include<iostream>
#include<string>
using namespace std;

class TaiKhoan {
    private:
        string ten;
        string so_tk;
        string NH;
        int so_du;
        int gui;
        int rut;
    public:
        void nhap_data() {
            cout << "\nnhap ten chu tai khoan: ";
            getline(cin, ten);
            cout << "\nnhap so tai khoan: ";
            getline(cin, so_tk);
            cout << "\nnhap ten ngan hang: ";
            getline(cin, NH);
            cout << "\nnhap so du tai khoan: ";
            cin >> so_du;
            cout << "\nnhap so tien gui: ";
            cin >> gui;
            cout << "\nnhap so tien rut: ";
            cin >> rut;
            cin.ignore();

        }
        void gui_tien(int tien) {
            if(tien <= 500000) {
                so_du +=tien;
                cout << "\nnap tien thanh cong!" << endl;
            
            } else {
                cout << "\nvuot qua han muc giao dich!" << endl;
            }
            
        }
        void rut_tien(int tien) {
            if(tien > so_du) {
                cout << "\nso du khong du!" << endl;
            } else {
                so_du -= tien;
                cout << "\nrut tien thanh cong!" << endl;
            }
        }
        float sodu() {
            
            return so_du;
        }
        int tiengui() {
            return gui;
        }
        int tienrut() {
            return rut;
        }
        void hien_thi() {
            cout << "\nten nguoi gui tien: " << ten << endl;
            cout << "\nso tai khoan: " << so_tk << endl;
            cout << "\nten ngan hang: " << NH << endl;
            cout << "\nso du trong tai khoan: " << so_du << endl;

        }
};
/*Bài 4.5*. Xây dựng lớp TaiKhoan mô tả thông tin tài khoản ngân hàng bao gồm những
thành phần sau:
- Các thuộc tính mô tả tên người gửi tiền, số tài khoản, tên ngân hàng, số tiền.
- Hàm khởi tạo tài khoản.
- Hàm cho phép gửi một số lượng tiền vào tài khoản.
- Hàm cho phép rút một số lượng tiền từ tài khoản (sau khi đã kiểm tra tài khoản
còn tiền).
- Hàm hiển thị các thông tin về tên và tài khoản.
Viết hàm main tạo một đối tượng và thực hiện các công việc gửi tiền, rút tiền cho đối
tượng đó; Mở rộng chương trình tạo 3 đối tượng TaiKhoan và in ra màn hình những
chủ tài khoản có số tiền >n (với n được nhập từ bàn phím).
Gợi ý: Xây dựng phương thức trả về số tiền trong tài khoản.*/