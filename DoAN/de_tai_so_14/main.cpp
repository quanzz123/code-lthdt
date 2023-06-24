#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class DichVu {
protected:
    float donGia;
public:
    DichVu() {
        donGia = 0.0;
    }
    virtual float tinhTien(float thamso) {
        return 0.0;
    }
};

class GiatLao : public DichVu {
    float giamGia;
    int soKgQuanAo;
public:
    GiatLao() : DichVu() {
        giamGia = 0.0;
        soKgQuanAo = 0;
    }
    GiatLao(float pDonGia, float pGiamGia, int pSoKgQuanAo) : DichVu() {
        donGia = pDonGia;
        giamGia = pGiamGia;
        soKgQuanAo = pSoKgQuanAo;
    }
    float tinhTien(float thamso) {
        float tienGiatLao;
        tienGiatLao = soKgQuanAo * donGia;
        if (soKgQuanAo > 5) {
            tienGiatLao *= (1 - giamGia);
        }
        return tienGiatLao;
    }
};

class ThueXe : public DichVu {
    float giamGia;
    int soGioThue;
public:
    ThueXe() : DichVu() {
        giamGia = 0.0;
        soGioThue = 0;
    }
    ThueXe(float pDonGia, float pGiamGia, int pSoGioThue) : DichVu() {
        donGia = pDonGia;
        giamGia = pGiamGia;
        soGioThue = pSoGioThue;
    }
    float tinhTien(float thamso) {
        float tienThueXe;
        tienThueXe = soGioThue * donGia;
        if (soGioThue > 10) {
            tienThueXe *= (1 - giamGia);
        }
        return tienThueXe;
    }
};

class HoaDon {
protected:
    string maHoaDon;
    string maKhachHang;
    string tenKhachHang;
    DichVu* dichVu1;
    DichVu* dichVu2;
    float tongTien;
public:
    HoaDon() {
        maHoaDon = "";
        maKhachHang = "";
        tenKhachHang = "";
        dichVu1 = NULL;
        dichVu2 = NULL;
        tongTien = 0.0;
    }

    void nhapHoaDon() {
        cout << "Nhap ma hoa don: ";
        getline(cin, maHoaDon);

        cout << "Nhap ma khach hang: ";
        getline(cin, maKhachHang);

        cout << "Nhap ten khach hang: ";
        getline(cin, tenKhachHang);

        dichVu1 = new GiatLao();
        cout << "Nhap so kg quan ao: ";
        int soKgQuanAo;
        cin >> soKgQuanAo;
        cin.ignore();
        dichVu1 = new GiatLao(100000, 0.05, soKgQuanAo);

        dichVu2 = new ThueXe();
        cout << "Nhap so gio thue xe: ";
        int soGioThue;
        cin >> soGioThue;
        cin.ignore();
        dichVu2 = new ThueXe(200000, 0.1, soGioThue);
    }

    void tinhTienDichVu() {
        float tienDichVu1 = dichVu1->tinhTien(0);
        cout << "Tien dich vu 1 (giat lao): " << fixed << setprecision(2)  <<  tienDichVu1 << endl;

        float tienDichVu2 = dichVu2->tinhTien(0);
        cout << "Tien dich vu 2 (thue xe): " << fixed << setprecision(2) << tienDichVu2 << endl;

        tongTien = tienDichVu1 + tienDichVu2;
    }

    void tinhTongTien() {
        cout << "Tong tien phai tra: " << tongTien << endl;
    }

    void hienThiHoaDon() {
        cout << "HÓA ĐƠN SỬ DỤNG DỊCH VỤ" << endl;
        cout << "Mã hóa đơn: " << maHoaDon << endl;
        cout << "Tên khách hàng: " << tenKhachHang << endl;
        cout << "Mã khách hàng: " << maKhachHang << endl;

        cout << "Các dịch vụ sử dụng" << endl;
        cout << "Dịch vụ\tSố tiền\tGiảm giá" << endl;
        cout << "Giặt là\t" << dichVu1->tinhTien(0) << "\t0" << endl;
        cout << "Thuê xe\t" << dichVu2->tinhTien(0) << "\t0" << endl;

        cout << "Tổng\t" << tongTien << "\t0" << endl;
        cout << "Số tiền khách hàng phải trả: " << tongTien << endl;
    }
};

int main() {
    HoaDon hoaDon;
    hoaDon.nhapHoaDon();
    hoaDon.tinhTienDichVu();
    hoaDon.hienThiHoaDon();

    return 0;
}
