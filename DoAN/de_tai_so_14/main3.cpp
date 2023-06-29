#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
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

    // void nhapHoaDon(ifstream& file) {
    //     getline(file, maHoaDon);

    //     getline(file, maKhachHang);

    //     getline(file, tenKhachHang);

    //     int soKgQuanAo;
    //     file >> soKgQuanAo;
    //     file.ignore();
    //     dichVu1 = new GiatLao(100000, 0.05, soKgQuanAo);

    //     int soGioThue;
    //     file >> soGioThue;
    //     file.ignore();
    //     dichVu2 = new ThueXe(200000, 0.1, soGioThue);
    // }

    void tinhTienDichVu() {
        float tienDichVu1 = dichVu1->tinhTien(0);
        //cout << "Tien dich vu 1 (giat la): " << fixed << setprecision(2) << tienDichVu1 << endl;

        float tienDichVu2 = dichVu2->tinhTien(0);
        //cout << "Tien dich vu 2 (thue xe): " << fixed << setprecision(2) << tienDichVu2 << endl;

        tongTien = tienDichVu1 + tienDichVu2;
    }

    void tinhTongTien() {
        cout << "Tong tien phai tra: " << tongTien << endl;
    }

    void hienThiHoaDon() const {
        cout << "\t\tHOA DON SU DUNG DICH VU" << endl;
        cout << "\t\tMa hoa don: " << maHoaDon << endl;
        cout << "Ten khach hang: " << tenKhachHang << endl;
        cout << "Ma khach hang: " << maKhachHang << endl;

        cout << "cac dich vu su dung" << endl;
        cout << "Dich vu\t\t\tSo tien\t\tGiam gia" << endl;
        cout << "Giat la\t\t\t" << dichVu1->tinhTien(0) << "\t\t0" << endl;
        cout << "Thue xe\t\t\t" << dichVu2->tinhTien(0) << "\t\t0" << endl;

        cout << "Tong\t\t\t" << tongTien << "\t\t0" << endl;
        cout << "So tien khach phai tra: " << tongTien << endl;
		cout << "\n\n\n";
    }
	void nhapHoaDon(ifstream& file) {
    getline(file, maHoaDon);
    getline(file, maKhachHang);
    getline(file, tenKhachHang);

    int soKgQuanAo;
    file >> soKgQuanAo;
    file.ignore();
    dichVu1 = new GiatLao(10000, 0.05, soKgQuanAo);

    int soGioThue;
    file >> soGioThue;
    file.ignore();
    dichVu2 = new ThueXe(20000, 0.1, soGioThue);
}

};

int main() {
    vector<HoaDon> danhSachHoaDon;
    ifstream file("data.txt"); // Thay đổi "data.txt" thành tên tệp tin bạn muốn đọc

    if (file.is_open()) {
        while (!file.eof()) {
            HoaDon hoaDon;
            hoaDon.nhapHoaDon(file);
            hoaDon.tinhTienDichVu();
            danhSachHoaDon.push_back(hoaDon);
        }

        file.close();

        // for (const HoaDon& hoaDon : danhSachHoaDon) {
        //     hoaDon.hienThiHoaDon();
        //     cout << endl;
        // }
    } else {
        cout << "Không thể mở tệp tin." << endl;
    }
	for (const HoaDon& hoaDon : danhSachHoaDon) {
            hoaDon.hienThiHoaDon();
            cout << endl;
        }

    return 0;
}








