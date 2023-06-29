#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class DichVu {
protected:
	float DonGia;
	float giamgia;
public:
	DichVu() {
		DonGia = 0.0;
	}
	virtual float TinhTien(float thamso) {
		return 0.0;
	}
	virtual void hienthi() = 0;
	float getgiamgia() {
		return giamgia;
	}
};
//============================================================
class GiatDo : public DichVu {
protected:
	int soKgquanao;
	float GiamGia;
public:
	GiatDo() : DichVu() {
		soKgquanao = 0;
		GiamGia = 0.0;
	}
	GiatDo(float dg, float gd, int sokg) : DichVu() {
		DonGia = dg;
		GiamGia = gd;
		soKgquanao = sokg;
	}
	void hienthi() override {
		cout << "Giat la - so kg giat la : " << soKgquanao << endl;
	}
	float TinhTien(float thamso) {
		float tiengiat;
		tiengiat = soKgquanao * DonGia;
		if (soKgquanao > 5) {
			tiengiat *= (1 - GiamGia);
		}
		return tiengiat;
	}
	int getsokg() {
		return soKgquanao;
	}
	float getGiamGia() {
		return GiamGia;
	}
};
//===============================================================
class ThueXe : public DichVu {
protected :
	float GiamGia;
	int soGiothuexe;
public:
	ThueXe() : DichVu() {
		GiamGia = 0.0;
		soGiothuexe = 0;
	}
	ThueXe(float dg, float gd, int soH) : DichVu() {
		DonGia = dg;
		GiamGia = gd;
		soGiothuexe = soH;

	}
	void hienthi() override {
		cout << "Thue xe - so gio thue: " << soGiothuexe << endl;
	}
	float TinhTien(float thamso) {
		float tienthue;
		tienthue = DonGia * soGiothuexe;
		if (soGiothuexe > 10) {
			tienthue *= (1 - GiamGia);
		}
		return tienthue;
	}
	int getsoH() {
		return soGiothuexe;
	}
	float getGiaGia() {
		return GiamGia;
	}
	
};
//=========================================
class HoaDon {
protected:
	string maHoaDon;
	string maKhachHang;
	string tenKhachHang;
	/*DichVu* dichvu1;
	DichVu* dichvu2;*/
	float TongTien;

public:
	DichVu* dichvu1;
	DichVu* dichvu2;
	string getmahoadon() {
		return maHoaDon;
	}
	string getmakhachhang() {
		return maKhachHang;
	}
	string gettenkhachhang() {
		return tenKhachHang;
	}
	float gettongtien() {
		return TongTien;
	}
	void setmahoadon(string& maHD) {
		maHoaDon = maHD;
	}
	void setmakhachhang(string& maKH) {
		maKhachHang = maKH;
	}
	void settenkhachhang(string& tenKH) {
		tenKhachHang = tenKH;
	}
	void settongtien(float& TT) {
		TongTien = TT;
	}
	HoaDon() {
		
		dichvu1 = nullptr;
		dichvu2 = nullptr;

	}
	~HoaDon() {
		delete dichvu1;
		delete dichvu2;
	}
	void tinhtiendichvu() const {
		if (dichvu1 != nullptr) {
			dichvu1->TinhTien(0);
		}
		if (dichvu2 != nullptr) {
			dichvu2->TinhTien(0);
		}
	}
	void NhapHoaDon() {
		cout << "Nhap ma hoa don: ";
		getline(cin, maHoaDon);
		cout << "\nNhap ma khach hang: ";
		getline(cin, maKhachHang);
		cout << "\nNhap ten khach hang: ";
		getline(cin, tenKhachHang);
		
		dichvu1 = new GiatDo();
		cout << "\nNhap so KG quan ao: ";
		int KG;
		cin >> KG;
		cin.ignore();
		dichvu1 = new GiatDo(10000, 0.05, KG);

		dichvu2 = new ThueXe();
		cout << "\nNhap so gio thue xe: ";
		int H;
		cin >> H;
		cin.ignore();
		dichvu2 = new ThueXe(20000, 0.1, H);
	}
	void hienthihoadon() const {
		cout << "\t\tHIEN THI HOA DON" << endl;
		cout << "Ma hoa don: " << endl;
		cout << "Ten khach hang: " << endl;
		cout << "Ma khach hang: " << endl;
		cout << "Cac dich vu su dung /t/t so tien \t\t Giam gia" << endl;
		if (dichvu1 != nullptr) {
			dichvu1->hienthi();
			cout << "\t\t\t" << dichvu1->TinhTien(0) << "\t" << dichvu1->getgiamgia() << endl;
		}
		if (dichvu2 != nullptr) {
			dichvu2->hienthi();
			cout << "\t\t\t" << dichvu2->TinhTien(0) << "\t" << dichvu2->getgiamgia() << endl;
		}
		float tongTien = 0.0;
		if (dichvu1 != nullptr)
			tongTien += dichvu1->TinhTien(0);
		if (dichvu2 != nullptr)
			tongTien += dichvu2->TinhTien(0);

		float tongGiamGia = 0.0;
		if (dichvu1 != nullptr)
			tongGiamGia += dichvu1->getgiamgia();
		if (dichvu2 != nullptr)
			tongGiamGia += dichvu2->getgiamgia();

		cout << "Tổng\t\t\t" << tongTien << "\t" << tongGiamGia << endl;

		float soTienPhaiTra = tongTien - tongGiamGia;
		cout << "Số tiền khách hàng phải trả: " << soTienPhaiTra << endl;
	}

};
//===============================================================
void docTepVanBan() {
	ifstream inputFile("ten_tep_van_ban.txt");
	if (!inputFile.is_open()) {
		cout << "Khong thể mở tệp văn bản" << endl;
		return;
	}

	string line;
	vector<HoaDon> danhSachHoaDon;

	while (getline(inputFile, line)) {
		if (line.empty()) {
			// Đây là dòng trống, tạo đối tượng HoaDon mới
			HoaDon hoaDon;

			getline(inputFile, line); // Nhập mã hóa đơn từ tệp
			hoaDon.getmahoadon() = line.substr(line.find(":") + 2);

			getline(inputFile, line); // Nhập mã khách hàng từ tệp
			hoaDon.getmakhachhang() = line.substr(line.find(":") + 2);

			getline(inputFile, line); // Nhập tên khách hàng từ tệp
			hoaDon.gettenkhachhang() = line.substr(line.find(":") + 2);

			getline(inputFile, line); // Nhập đơn giá giặt là từ tệp
			float donGiaGiatLao = stof(line.substr(line.find(":") + 2));

			getline(inputFile, line); // Nhập giảm giá giặt là từ tệp
			float giamGiaGiatLao = stof(line.substr(line.find(":") + 2));

			getline(inputFile, line); // Nhập số kg quần áo từ tệp
			int soKgQuanAo = stoi(line.substr(line.find(":") + 2));
			hoaDon.dichvu1 = new GiatDo(donGiaGiatLao, giamGiaGiatLao, soKgQuanAo);

			getline(inputFile, line); // Nhập đơn giá thuê xe từ tệp
			float donGiaThueXe = stof(line.substr(line.find(":") + 2));

			getline(inputFile, line); // Nhập giảm giá thuê xe từ tệp
			float giamGiaThueXe = stof(line.substr(line.find(":") + 2));

			getline(inputFile, line); // Nhập số giờ thuê xe từ tệp
			int soGioThueXe = stoi(line.substr(line.find(":") + 2));
			hoaDon.dichvu2 = new ThueXe(donGiaThueXe, giamGiaThueXe, soGioThueXe);

			danhSachHoaDon.push_back(hoaDon);
		}
	}

	inputFile.close();

	//// Xử lý danh sách hóa đơn
	for (const HoaDon& hoaDon : danhSachHoaDon) {
		hoaDon.tinhtiendichvu();
		hoaDon.hienthihoadon();
		cout << endl;
	}
}
int main() {
	docTepVanBan();
	system("pause");
	return 0;
}