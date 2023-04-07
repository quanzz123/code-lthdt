#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class SinhVien {
    private:
        string HoTen;
        int Tuoi;
        float DiemTrungBinh;
    public:
        SinhVien(string Ten, int age, float dtb) {
            HoTen = Ten;
            Tuoi = age;
            DiemTrungBinh = dtb;
        }
        string getTen() {
            return HoTen;
        }
        int getTuoi() {
            return Tuoi;
        }
        float getDtb() {
            return DiemTrungBinh;
        }
        string XepLoai() {
            if(DiemTrungBinh >= 8.0) {
                return "Gioi";
            } else if(DiemTrungBinh >= 7.0 && DiemTrungBinh <= 8.0) {
                return "Kha";
            } else if(DiemTrungBinh >= 5.0 && DiemTrungBinh <= 7.0) {
                return "Trung Binh";
            } else {
                return "Kem";
            }
        }
        
};
void LuaChon() {
    cout << "1. Them sinh vien." << endl;
    cout << "2. Hien thi thong tin sinh vien." << endl;
    cout << "3.Thoat." << endl;
}
/* // Hàm chính (tiếp tục)
int main() {
    int choice;
    vector<SinhVien> danhSachSinhVien;

    do {
        showMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                string hoTen;
                int tuoi;
                float diemTrungBinh;

                cout << "Nhap ho ten sinh vien: ";
                cin >> hoTen;

                cout << "Nhap tuoi sinh vien: ";
                cin >> tuoi;

                cout << "Nhap diem trung binh: ";
                cin >> diemTrungBinh;

                SinhVien sv(hoTen, tuoi, diemTrungBinh);
                danhSachSinhVien.push_back(sv);

                cout << "Da them thanh cong!" << endl;

                break;

            case 2:
                cout << "Danh sach sinh vien:" << endl;

                for (int i = 0; i < danhSachSinhVien.size(); i++) {
                    SinhVien sv = danhSachSinhVien[i];

                    cout << i + 1 << ". Ho ten: " << sv.getHoTen() << ", Tuoi: " << sv.getTuoi() << ", Diem trung binh: " << sv.getDiemTrungBinh() << ", Xep loai: " << sv.xepLoai() << endl;
                }

                break;

            case 3:
                cout << "Tam biet!" << endl;

                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai!" << endl;

                break;
        }
    } while (choice != 3);

    return 0;
}
*/ 