#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Khai báo lớp GiatLao
class GiatLao {
public:
    float donGia;
    float giamGia;
    int soKgQuanAo;

    GiatLao(float donGia, float giamGia, int soKgQuanAo)
        : donGia(donGia), giamGia(giamGia), soKgQuanAo(soKgQuanAo) {}

    float tinhTien() {
        float tien = donGia * soKgQuanAo;
        if (soKgQuanAo > 5)
            tien -= tien * giamGia;
        return tien;
    }
};

// Khai báo lớp ThueXe
class ThueXe {
public:
    float donGia;
    float giamGia;
    int soGioThueXe;

    ThueXe(float donGia, float giamGia, int soGioThueXe)
        : donGia(donGia), giamGia(giamGia), soGioThueXe(soGioThueXe) {}

    float tinhTien() {
        float tien = donGia * soGioThueXe;
        if (soGioThueXe > 10)
            tien -= tien * giamGia;
        return tien;
    }
    float getdonGia() {
        return donGia;

    }
    float getgiamgia() {
        return giamGia;
    }
    int getsoGioThuexe() {
        return soGioThueXe;
    }
};

// Khai báo lớp HoaDon
class HoaDon {
public:
    string maHoaDon;
    string maKhachHang;
    string tenKhachHang;
    GiatLao* dichVu1;
    ThueXe* dichVu2;

    HoaDon() {
        dichVu1 = nullptr;
        dichVu2 = nullptr;
    }

    ~HoaDon() {
        delete dichVu1;
        delete dichVu2;
    }

    void tinhTienDichVu() {
        if (dichVu1 != nullptr)
            dichVu1->tinhTien();
        if (dichVu2 != nullptr)
            dichVu2->tinhTien();
    }

    void hienThiHoaDon() {
        cout << "HÓA ĐƠN SỬ DỤNG DỊCH VỤ" << endl;
        cout << "Mã hóa đơn: " << maHoaDon << endl;
        cout << "Tên khách hàng: " << tenKhachHang << endl;
        cout << "Mã khách hàng: " << maKhachHang << endl;

        cout << "Các dịch vụ sử dụng\tSố tiền\tGiảm giá" << endl;
        if (dichVu1 != nullptr)
            cout << "Giặt là\t\t" << dichVu1->tinhTien() << "\t" << dichVu1->giamGia << endl;
        if (dichVu2 != nullptr)
            cout << "Thuê xe\t\t" << dichVu2->tinhTien() << "\t" << dichVu2->giamGia << endl;

        float tongTien = 0.0;
        if (dichVu1 != nullptr)
            tongTien += dichVu1->tinhTien();
        if (dichVu2 != nullptr)
            tongTien += dichVu2->tinhTien();

        float tongGiamGia = 0.0;
        if (dichVu1 != nullptr)
            tongGiamGia += dichvu1->giamGia;
        if (dichVu2 != nullptr)
            tongGiamGia += dichVu2->giamGia;

        cout << "Tổng\t\t\t" << tongTien << "\t" << tongGiamGia << endl;

        float soTienPhaiTra = tongTien - tongGiamGia;
        cout << "Số tiền khách hàng phải trả: " << soTienPhaiTra << endl;
    }
};

void docTepVanBan() {
    ifstream inputFile("ten_tep_van_ban.txt");
    if (!inputFile.is_open()) {
        cout << "Khong the mo tep vao" << endl;
        return;
    }

    string line;
    vector<HoaDon> danhSachHoaDon;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            // Đây là dòng trống, tạo đối tượng HoaDon mới
            HoaDon hoaDon;

            getline(inputFile, line); // Nhập mã hóa đơn từ tệp
            hoaDon.maHoaDon = line.substr(line.find(":") + 2);

            getline(inputFile, line); // Nhập mã khách hàng từ tệp
            hoaDon.maKhachHang = line.substr(line.find(":") + 2);

            getline(inputFile, line); // Nhập tên khách hàng từ tệp
            hoaDon.tenKhachHang = line.substr(line.find(":") + 2);

            getline(inputFile, line); // Nhập đơn giá giặt là từ tệp
            float donGiaGiatLao = stof(line.substr(line.find(":") + 2));

            getline(inputFile, line); // Nhập giảm giá giặt là từ tệp
            float giamGiaGiatLao = stof(line.substr(line.find(":") + 2));

            getline(inputFile, line); // Nhập số kg quần áo từ tệp
            int soKgQuanAo = stoi(line.substr(line.find(":") + 2));
            hoaDon.dichVu1 = new GiatLao(donGiaGiatLao, giamGiaGiatLao, soKgQuanAo);

            getline(inputFile, line); // Nhập đơn giá thuê xe từ tệp
            float donGiaThueXe = stof(line.substr(line.find(":") + 2));

            getline(inputFile, line); // Nhập giảm giá thuê xe từ tệp
            float giamGiaThueXe = stof(line.substr(line.find(":") + 2));

            getline(inputFile, line); // Nhập số giờ thuê xe từ tệp
            int soGioThueXe = stoi(line.substr(line.find(":") + 2));
            hoaDon.dichVu2 = new ThueXe(donGiaThueXe, giamGiaThueXe, soGioThueXe);

            danhSachHoaDon.push_back(hoaDon);
        }
    }

    inputFile.close();

    // Xử lý danh sách hóa đơn
    for (const HoaDon& hoaDon : danhSachHoaDon) {
        hoaDon.tinhTienDichVu();
        hoaDon.hienThiHoaDon();
        cout << endl;
    }
}

int main() {
    docTepVanBan();

    return 0;
}
