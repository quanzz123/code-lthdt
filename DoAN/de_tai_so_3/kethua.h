#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// Lớp cơ sở Thiết bị
class ThietBi {
protected:
    string tenThietBi;
    string maThietBi;
    int ngayNhap;
    int thangNhap;
    int namNhap;
    string trangThai;

public:
    ThietBi(string ten, string ma, int ngay, int thang, int nam,  string trangthai)
        : tenThietBi(ten), maThietBi(ma), ngayNhap(ngay),thangNhap(thang), namNhap(nam), trangThai(trangthai) {}

    virtual void hienThiThongTin() {
        cout << char(179) << setw(15) <<  tenThietBi; //12
        cout << char(179) << setw(11) << maThietBi; // 11
        cout << char(179) << setw(12) << ngayNhap << "/" << thangNhap << "/" << namNhap; //9
        cout << char(179) << setw(15) << trangThai;
       
    } 

    bool daDenThoiHanThanhLy() {
        return trangThai == "thanh ly";
    }
    string getname() {
        return tenThietBi;
    }
    string getID() {
        return maThietBi;
    }
};

// Lớp Máy tính
class MayTinh : public ThietBi {
protected:
    string mauSac;
    int tocDo;
    int boNho;

public:
    MayTinh(string ten, string ma, int ngay, int thang, int nam,  string trangthai, string mau, int tocdo, int bonho)
        : ThietBi(ten, ma, ngay, thang, nam,  trangthai), mauSac(mau), tocDo(tocdo), boNho(bonho) {}

    void hienThiThongTin() {
        ThietBi::hienThiThongTin();
        cout << char(179) << setw(7) << mauSac << char(179) ; // 7
        cout << char(179) << setw(6) << tocDo << char(179) ; // 6
        cout <<char(179) << setw(6) << boNho << char(179);; // 6
    }
};

// Lớp Máy in
class MayIn : public ThietBi {
protected:
    int soDiemAnh;

public:
    MayIn(string ten, string ma, int ngay, int thang, int nam, string trangthai, int sodiem)
        : ThietBi(ten, ma, ngay,thang, nam, trangthai), soDiemAnh(sodiem) {}
};

// Lớp Máy in đen trắng
class MayInDenTrang : public MayIn {
public:
    MayInDenTrang(string ten, string ma, int ngay, int thang, int nam,  string trangthai, int sodiem)
        : MayIn(ten, ma, ngay, thang, nam,  trangthai, sodiem) {}

    void hienThiThongTin() {
        MayIn::hienThiThongTin();
        cout << char(179) << setw(11) << soDiemAnh << char(179);
    }
};

// Lớp Máy in màu
class MayInMau : public MayInDenTrang {
protected:
    int soMau;

public:
    MayInMau(string ten, string ma, int ngay, int thang, int nam, string trangthai, int sodiem, int somau)
        : MayInDenTrang(ten, ma, ngay, thang, nam, trangthai, sodiem), soMau(somau) {}

    void hienThiThongTin() {
        MayInDenTrang::hienThiThongTin();
        cout << char(179) << setw(6) << soMau << char(179);
    }
};
// Lớp Máy quét
class MayQuet : public ThietBi {
protected:
    int tocDoQuet;

public:
    MayQuet(string ten, string ma, int ngay, int thang, int nam, string trangthai, int tocdoscan)
        : ThietBi(ten, ma, ngay, thang, nam, trangthai), tocDoQuet(tocdoscan) {}

    void hienThiThongTin() {
        ThietBi::hienThiThongTin();
        cout << char(179) << setw(11) << tocDoQuet << char(179);
    }
};

// Lớp Máy tham chiếu
class MayThamChieu : public ThietBi {
protected:
    int gioThamChieuToiDa;

public:
    MayThamChieu(string ten, string ma, int ngay, int thang, int nam, string trangthai, int giothamchieu)
        : ThietBi(ten, ma, ngay, thang, nam, trangthai), gioThamChieuToiDa(giothamchieu) {}

    void hienThiThongTin() {
        ThietBi::hienThiThongTin();
        cout << char(179) << setw(8) << gioThamChieuToiDa << char(179) ; // maxhours
    }
};
// Hàm xóa màn hình console
void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void timKiemThongTin(const vector<ThietBi*>& danhSachThietBi, const string& tenTimKiem, const string &ID) {
    bool timThay = false;
    
    cout << "Thong tin cac thiet bi tim thay:/n/n" << endl;
    for (const auto& thietBi : danhSachThietBi) {
        if (thietBi->getname() == tenTimKiem && thietBi->getID() == ID) {
            thietBi->hienThiThongTin();
            timThay = true;
        }
    }
    
    if (!timThay) {
        cout << "Khong tim thay thiet bi voi ten '" << tenTimKiem << "'" << endl ;
        cout << "Khong tim thay thiet bi voi ID '" << ID << "'" << endl;
    }
}