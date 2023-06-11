#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <sstream>
#include <bits/stdc++.h>
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
        cout << "|"<< setw(12) <<  tenThietBi; //12
        cout << "|" << setw(11) << maThietBi; // 11
        cout << "|" << setw(12) << ngayNhap << "/" << thangNhap << "/" << namNhap; //9
       
    } 

    bool daDenThoiHanThanhLy() {
        return trangThai == "thanh ly";
    }
    string getname() {
        return tenThietBi;
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
        cout << "|" << setw(7) << mauSac ; // 7
        cout << "|" << setw(6) << tocDo ; // 6
        cout << "|"<< setw(6) << boNho << "|" << endl; // 6
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
        cout << "|" << setw(11) << soDiemAnh;
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
        cout << "|" << setw(6) << soMau;
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
        cout << "|" << setw(11) << tocDoQuet;
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
        cout << "|" << setw(8) << gioThamChieuToiDa << endl; // maxhours
    }
};

int main() {
    vector<ThietBi*> danhsachThietBi;
    //menu1
    int luachon1;
    while (true) {
        cout << "\n\n\t=======MENU=========" << endl;
        cout << "\n1.Them thiet bi tu file thietbi.txt" << endl;
        cout << "\n2.Hien thi thông tin cac thiet bi" << endl;
        cout << "\n3.Thong ke va tim kiem" << endl;
        cout << "\n0.Thoat chuong trinh" << endl;
        cout << "===========================" << endl;
        cin >> luachon1;
        switch(luachon1) {
            case 1: {
                //dọc dữ liệu từ tệp văn bản
                ifstream inputfile("thietbi.txt");
                if(inputfile.open()) {
                    string line;
                    while(getline(inputfile, line)) {
                        stringstream ss(line);
                        string ten, ma, trangthai;
                        int ngay, thang, nam;
                        int sodiem, tocdo, bonho, tocdoscan, giothamchieu;
                        string mau;
                        int somau;

                        getline(ss, ten, ',');
                        getline(ss, ma, ',');
                    
                        ss >> ngay;
                        ss.ignore(); // bỏ qua dau cach
                        ss >> thang;
                        ss.ignore(); // bỏ qua dau cach
                        ss >> nam;
                        ss.ignore();
                        getline(ss, trangthai, ',');
                        if(ten == "MayTinh") {
                            ss >> mau;
                            ss.ignore();
                            ss >> tocdo;
                            ss.ignore();
                            ss >> bonho;
                            danhsachThietBi.push_back(new MayTinh(ten, ma, ngay, thang, nam, trangthai, mau, tocdo, bonho));
                        } else if(ten == "MayInDenTrang") {
                            ss >> sodiem;
                            danhsachThietBi.push_back(new MayInDenTrang(ten, ma, ngay, thang, nam, trangthai, sodiem));
                        } else if(ten == "MayinMau") {
                            
                            ss >> sodiem;
                            ss.ignore();
                            ss >> somau;
                            danhsachThietBi.push_back(new MayInMau(ten, ma, ngay, thang, nam, trangthai, sodiem, somau));
                        } else if(ten == "MayQuet") {
                            ss >> tocdoscan;
                            danhsachThietBi.push_back(new MayQuet(ten, ma, ngay, thang, nam, trangthai, tocdoscan));
                        } else if(ten == "MayThamChieu") {
                            ss >> giothamchieu;
                            danhsachThietBi.push_back(new MayThamChieu(ten, ma, ngay, thang, nam, trangthai, giothamchieu));
                        }
                    }
                }
                break;
            }
            default:
                cout << "lau chon khonh hop le" << endl;
        }
    }
}