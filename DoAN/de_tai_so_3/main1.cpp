#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <conio.h>
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
        cout << "|" << setw(15) << trangThai;
       
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
// Hàm xóa màn hình console
void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}
void timKiemThongTin(const vector<ThietBi*>& danhSachThietBi, const string& tenTimKiem) {
    bool timThay = false;
    
    cout << "Thong tin cac thiet bi tim thay:/n/n" << endl;
    for (const auto& thietBi : danhSachThietBi) {
        if (thietBi->getname() == tenTimKiem) {
            thietBi->hienThiThongTin();
            timThay = true;
        }
    }
    
    if (!timThay) {
        cout << "Khong tim thay thiet bi voi ten '" << tenTimKiem << "'" << endl << endl;
    }
}
int main() {
    vector<ThietBi*> danhsachThietBi;
    //menu1
    int luachon1;
    
    while (true) {
        clearScreen();
        cout << "\n\n\t=======MENU=========" << endl;
        cout << "\n1.Them thiet bi tu file thietbi.txt" << endl;
        cout << "\n2.Hien thi thong tin cac thiet bi" << endl;
        cout << "\n3.Thong ke va tim kiem" << endl;
        cout << "\n0.Thoat chuong trinh" << endl;
        cout << "===========================" << endl;
        cout << "moi nhap lua chon:  ";
        cin >> luachon1;
        switch(luachon1) {
            case 1: {
                //dọc dữ liệu từ tệp văn bản
                ifstream inputfile("thietbi.txt");
                if(inputfile.is_open()) {
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
        
                            getline(ss, mau, ',');
                            
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
                    inputfile.close();
                    cout << "\nNhap du lieu thanh cong" << endl;
                    _getch();
                } else {
                    cout << "\nkhong the mo file" << endl;
                    _getch();
                    return 1;
                }
               
                
                break;
                
            }
            case 2: {
                clearScreen();
                int luachon2;
                while (luachon2 != 0) {
                cout << "\n\n\t==========Hien thi thong tin============" << endl;
                cout << "\n1.May tinh" << endl;
                cout << "\n2.May in den trang" << endl;
                cout << "\n3.May in mau" << endl;
                cout << "\n4.May quet" << endl;
                cout << "\n5.May chieu" << endl;
                cout << "\n0.quay lai" << endl;
                cout <<"================================================" << endl;
                cout << "moi nhap lua chon: " ;
                cin >> luachon2;
                switch(luachon2) {
                    case 1: {
                        clearScreen();
                        //hien thi thong tin các loai may tinh
                        cout << "\n\n\t====thongtin cac loai may tinh======" << endl;
                        for(const auto& thietbi : danhsachThietBi) {
                            MayTinh *maytinh = dynamic_cast<MayTinh*>(thietbi);
                            if(maytinh != nullptr) {
                                maytinh->hienThiThongTin();
                            
                                cout << endl;
                               
                            }
                        
                        }
                        //_getch();
                        cin.ignore();
                        cin.get();
                        clearScreen();
                        break;
                    }
                    case 2: {
                        clearScreen();
                        //hien thi thong tin cac loai may in den trang
                        cout << "\n\n\t=====thong tin cac loai may in den trang=====" << endl;
                        for(const auto& thietbi : danhsachThietBi) {
                            MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang*>(thietbi);
                            if(mayindentrang != nullptr && dynamic_cast<MayInMau*>(thietbi) == nullptr) {
                                mayindentrang->hienThiThongTin();
                                cout << endl;
                            }
                        }
                        _getch();\
                        clearScreen();
                        break;
                    }
                    case 3: {
                        //hien thi may in mau
                        cout << "\n\n\t====thong tin cac loai may in mau======" << endl;
                        for(const auto& thietbi : danhsachThietBi) {
                            MayInMau *mayinmau = dynamic_cast<MayInMau*>(thietbi);
                            if(mayinmau != nullptr) {
                                mayinmau->hienThiThongTin();
                                cout<< endl;
                            }
                        }
                        _getch();
                        break;
                    }
                    case 4 : {
                        //hien thi may quet 
                        cout << "\n\n\t===Hien thi thong tin cac loai may quet========" << endl;
                        for(const auto& thietbi : danhsachThietBi) {
                            MayQuet *mayquet =dynamic_cast<MayQuet*>(thietbi);
                            if(mayquet != nullptr) {
                                mayquet->hienThiThongTin();
                                cout << endl;
                            }
                        }
                        _getch();
                        break;
                    }
                    case 5: {
                        //hien thi thong tin cac loai may chieu
                        cout << "\n\n\t======Hien thi thong tin cac loai may chieu====" << endl;
                        for(const auto& thietbi : danhsachThietBi) {
                            MayThamChieu *maythamchieu = dynamic_cast<MayThamChieu*>(thietbi);
                            if(maythamchieu != nullptr) {
                                maythamchieu->hienThiThongTin();
                                cout << endl;
                            }
                        }
                        _getch();
                        break;
                    }
                    case 0 : {
                        break;
                    }
                    default :
                        cout << "\nlua chon khong hop le!" << endl;
                }
                }
                
                break;
            }
            case 3: {
                int luachon3;
                cout << "\n\n\t==thong ke va tim kiem===\n\n" << endl;
                cout <<"\n1.thong ke" << endl;
                cout << "\n2.tim kiem" << endl;
                cout << "\n0.thoat" << endl;
                cout << "\nmoi nhap lua chon: ";
                cin >> luachon3;
                switch (luachon3) {
                    case 1: {
                        int luachon4;

                        break;
                    }
                    default :
                        cout << "lua chon khong hop le" << endl;
                }
                break;
            }
            default:
                cout << "lua chon khonh hop le" << endl;
        }
    }

    //giai phong bo nho
    for(const auto& thietbi : danhsachThietBi) {
        delete thietbi;
    }
    danhsachThietBi.clear();
    system("pause");
    return 0;
}