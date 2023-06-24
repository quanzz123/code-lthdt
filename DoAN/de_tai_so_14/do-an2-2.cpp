#include <iostream>
#include <string>
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
protected:
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
        if (soGioThue > 10)
		 { 
		 tienThueXe *= 0.9;
		  } 
		  return tienThueXe; }
		   };
class HoaDon {
   protected: 
       string maHoaDon; 
	   string maKhachHang; 
	   string tenKhachHang; 
	   DichVu *dichVu1; 
	   DichVu *dichVu2; 
	   float tongTien;
   public:
       HoaDon()
	    {
	       maHoaDon = "";
		   maKhachHang = ""; 
		   tenKhachHang = ""; 
		   dichVu1 = NULL; 
		   dichVu2 = NULL; 
		   tongTien = 0.0;
		    }
 //////////////////////////           
void nhapHoaDon() {
    cout << "Nhap ma hoa don: ";
    getline(cin, maHoaDon);
    cout << "Nhap ma khach hang: ";
    getline(cin, maKhachHang);
    cout << "Nhap ten khach hang: ";
    getline(cin, tenKhachHang);

    dichVu1 = new GiatLao();
    dichVu2 = new ThueXe();
}

void tinhTienDichVu() {
    float tienDichVu1 = dichVu1->tinhTien(0);
    cout << "Tien dich vu 1 (giat lao): " << tienDichVu1 << endl;
    float tienDichVu2 = dichVu2->tinhTien(0);
    cout << "Tien dich vu 2 (thue xe): " << tienDichVu2 << endl;
    tongTien = tienDichVu1 + tienDichVu2;
}

void tinhTongTien() {
    cout << "Tong tien phai tra: " << tongTien << endl;
}
};
int main() { 
HoaDon hoaDon;
hoaDon.nhapHoaDon();
hoaDon.tinhTienDichVu();
hoaDon.tinhTongTien();
return 0;
}





