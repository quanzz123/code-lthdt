#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp SinhVien
class SinhVien {
    private:
        string hoTen;
        int tuoi;
        float diemTrungBinh;

    public:
        // Hàm khởi tạo
        SinhVien(string ten, int age, float dtb) {
            hoTen = ten;
            tuoi = age;
            diemTrungBinh = dtb;
        }

        // Phương thức lấy thông tin họ tên
        string getHoTen() {
            return hoTen;
        }

        // Phương thức lấy thông tin tuổi
        int getTuoi() {
            return tuoi;
        }

        // Phương thức lấy thông tin điểm trung bình
        float getDiemTrungBinh() {
            return diemTrungBinh;
        }

        // Phương thức tính xếp loại của sinh viên
        string xepLoai() {
            if (diemTrungBinh >= 8.0) {
                return "Gioi";
            } else if (diemTrungBinh >= 7.0 && diemTrungBinh < 8.0) {
                return "Kha";
            } else if (diemTrungBinh >= 5.0 && diemTrungBinh < 7.0) {
                return "TB";
            } else {
                return "Kem";
            }
        }
};

// Hàm hiển thị menu
void showMenu() {
    cout << "1. Them sinh vien" << endl;
    cout << "2. Hien thi danh sach sinh vien" << endl;
    cout << "3. Thoat" << endl;
}

// Hàm chính (tiếp tục)
int main() {
    int choice;
    vector<SinhVien> danhSachSinhVien;

    do {
        showMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        string hoTen;
        int tuoi;
        float diemTrungBinh;
        SinhVien sv;

// Nhập thông tin sinh viên mới
switch (choice) {
    case 1:
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
        
        // Khởi tạo đối tượng SinhVien và thêm vào vector
        sv = SinhVien(hoTen, tuoi, diemTrungBinh);
        danhSachSinhVien.push_back(sv);
        
        cout << "Them sinh vien thanh cong!\n";
        break;
    case 2:
        // Tương tự như trường hợp 1
        // ...
    case 3:
        // Tương tự như trường hợp 1
        // ...
    default:
        cout << "Lua chon khong hop le!\n";
        break;
}
                
    } while (choice != 3);

    return 0;
}
