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
        cout << "|" << setw(15) <<  tenThietBi; //12
        cout << "|" << setw(11) << maThietBi; // 11
        cout << "|" << setw(2) << ngayNhap << "/" << setw(2) << thangNhap << "/" << setw(4) <<  namNhap; //12
        cout << "|" << setw(15) << trangThai;
       
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
        cout << "|" << setw(7) << mauSac; // 7
        cout << "|" << setw(6) << tocDo ; // 6
        cout << "|" << setw(6) << boNho << "|"; // 6
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
        cout << "|" << setw(11) << soDiemAnh << "|";
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
        cout << setw(6) << soMau << "|";
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
        cout << "|" << setw(11) << tocDoQuet << "|";
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
        cout << "|" << setw(8) << gioThamChieuToiDa << "|" ; // maxhours
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
        cout << "=====================================" << endl;
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
               
                _getch();
                clearScreen();
                break;
                
            }
            case 2: {
                clearScreen();
               
                int luachon2;
                while (luachon2 != 0) {
                cout << "\n\n==========Hien thi thong tin===============" << endl;
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
                        cout << "\n\n\t\t\t====thongtin cac loai may tinh======\n\n" << endl;
                        cout << (char)218 << setfill('-') << setw(76) << "-" << (char)191 << endl;
                        cout << setfill(' ');
                        cout << "|" << setw(15) << "NAME";
                        cout << "|" << setw(11) << "ID";
                        cout << "|" << setw(10) << "DATE";
                        cout << "|" << setw(15) << "STATIC";
                        cout << "|" << setw(7) << "COL";
                        cout << "|" << setw(6) << "SPE";
                        cout << "|" << setw(6) << "MEM" << "|" << endl;
                        cout << "|";
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(10) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(7) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(6) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(6) << "-" << "|" << endl;
                        cout << setfill(' ');
                        for(const auto& thietbi : danhsachThietBi) {
                            MayTinh *maytinh = dynamic_cast<MayTinh*>(thietbi);
                            if(maytinh != nullptr) {
                                maytinh->hienThiThongTin();
                                
                                cout << endl;
                                cout << "|";
                                cout << setfill('-') << setw(15) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(10) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(15) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(7) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(6) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(6) << "-" << "|" << endl;
                                cout << setfill(' ');
                            }
                        
                        }
                        _getch();
                        
                        clearScreen();
                        
                        break;
                    }
                    case 2: {
                        clearScreen();
                        
                        //hien thi thong tin cac loai may in den trang
                        cout << "\n\n\t\t\t=====thong tin cac loai may in den trang=====\n\n" << endl;
                        cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
                        cout << setfill(' ');
                        cout << "|" << setw(15) << "NAME";
                        cout << "|" << setw(11) << "ID";
                        cout << "|" << setw(10) << "DATE";
                        cout << "|" << setw(15) << "STATIC";
                        cout << "|" << setw(11) << "PIX" << "|" << endl;

                        cout << "|";
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(10) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|" << endl;
                        cout << setfill(' ');
                        for(const auto& thietbi : danhsachThietBi) {
                            MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang*>(thietbi);
                            if(mayindentrang != nullptr && dynamic_cast<MayInMau*>(thietbi) == nullptr) {
                                mayindentrang->hienThiThongTin();
                                cout << endl;
                                cout << "|";
                                cout << setfill('-') << setw(15) << "-" << "|"; // name
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|"; // id
                                cout << setfill(' ');
                                cout << setfill('-') << setw(10) << "-" << "|"; // date
                                cout << setfill(' ');
                                cout << setfill('-') << setw(15) << "-" << "|"; // static
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|" << endl;
                                cout << setfill(' ');

                            }
                        }
                        _getch();
                        clearScreen();
                        
                        break;
                    }
                    case 3: {
                        clearScreen();
                        //hien thi may in mau
                        cout << "\n\n\t====thong tin cac loai may in mau======\n\n" << endl;
                        cout << (char)218 << setfill('-') << setw(73) << "-" << (char)191 << endl;
                        cout << setfill(' ');
                        cout << "|" << setw(15) << "NAME";
                        cout << "|" << setw(11) << "ID";
                        cout << "|" << setw(10) << "DATE";
                        cout << "|" << setw(15) << "STATIC";
                        cout << "|" << setw(11) << "PIX";
                        cout << "|" << setw(6) << "COLS" << "|" << endl;

                        cout << "|";
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(10) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(6) << "-" << "|" << endl;
                        cout << setfill(' ');
                        for(const auto& thietbi : danhsachThietBi) {
                            MayInMau *mayinmau = dynamic_cast<MayInMau*>(thietbi);
                            if(mayinmau != nullptr) {
                                mayinmau->hienThiThongTin();
                                cout<< endl;
                                cout << "|";
                                cout << setfill('-') << setw(15) << "-" << "|"; // name
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|"; // id
                                cout << setfill(' ');
                                cout << setfill('-') << setw(10) << "-" << "|"; // date
                                cout << setfill(' ');
                                cout << setfill('-') << setw(15) << "-" << "|"; // static
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|";
                                cout << setfill(' ');
                                cout << setfill('-') << setw(6) << "-" << "|" << endl;
                                cout << setfill(' ');

                            }
                        }
                        _getch();
                        clearScreen();
                        break;
                    }
                    case 4 : {
                        clearScreen();
                        //hien thi may quet 
                        cout << "\n\n\t===Hien thi thong tin cac loai may quet========\n\n" << endl;
                        cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
                        cout << setfill(' ');
                        cout << "|" << setw(15) << "NAME";
                        cout << "|" << setw(11) << "ID";
                        cout << "|" << setw(10) << "DATE";
                        cout << "|" << setw(15) << "STATIC";
                        cout << "|" << setw(11) << "SSPE" << "|" << endl;
                        cout << "|";
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(10) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|" << endl;
                        cout << setfill(' ');
                        for(const auto& thietbi : danhsachThietBi) {
                            MayQuet *mayquet =dynamic_cast<MayQuet*>(thietbi);
                            if(mayquet != nullptr) {
                                mayquet->hienThiThongTin();
                                cout << endl;
                                cout << "|";
                                cout << setfill('-') << setw(15) << "-" << "|"; // name
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|"; // id
                                cout << setfill(' ');
                                cout << setfill('-') << setw(10) << "-" << "|"; // date
                                cout << setfill(' ');
                                cout << setfill('-') << setw(15) << "-" << "|"; // static
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|" << endl; // scanspeed
                                cout << setfill(' ');
                            }
                        }
                        _getch();
                        clearScreen();
                        break;
                    }
                    case 5: {
                        clearScreen();
                        //hien thi thong tin cac loai may chieu
                        cout << "\n\n\t======Hien thi thong tin cac loai may chieu====\n\n" << endl;
                        cout << (char)218 << setfill('-') << setw(63) << "-" << (char)191 << endl;
                        cout << setfill(' ');
                        cout << "|" << setw(15) << "NAME";
                        cout << "|" << setw(11) << "ID";
                        cout << "|" << setw(10) << "DATE";
                        cout << "|" << setw(15) << "STATIC";
                        cout << "|" << setw(8) << "MAXH" << "|" << endl;
                        cout << "|";
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(11) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(10) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(15) << "-" << "|";
                        cout << setfill(' ');
                        cout << setfill('-') << setw(8) << "-" << "|" << endl;
                        cout << setfill(' ');
                        for(const auto& thietbi : danhsachThietBi) {
                            MayThamChieu *maythamchieu = dynamic_cast<MayThamChieu*>(thietbi);
                            if(maythamchieu != nullptr) {
                                maythamchieu->hienThiThongTin();
                                cout << endl;
                                cout << "|";
                                cout << setfill('-') << setw(15) << "-" << "|"; // name
                                cout << setfill(' ');
                                cout << setfill('-') << setw(11) << "-" << "|"; // id
                                cout << setfill(' ');
                                cout << setfill('-') << setw(10) << "-" << "|"; // date
                                cout << setfill(' ');
                                cout << setfill('-') << setw(15) << "-" << "|"; // static
                                cout << setfill(' ');
                                cout << setfill('-') << setw(8) << "-" << "|" << endl; // scanspeed
                                cout << setfill(' ');
                            }
                        }
                        _getch();
                        clearScreen();
                        break;
                    }
                    case 0 : {
                        break;
                    }
                    default :
                        cout << "\nlua chon khong hop le!" << endl;
                        _getch();
                }
                }
                
                break;
            }
            case 3: {
                clearScreen();
                int luachon3;
                while (luachon3 != 0) {
                    cout << "\n\n\t===Thong ke và tim kiem===\n\n" << endl;
                    cout << "\n1.THong ke" <<endl;
                    cout << "\n2.tim kiem" << endl;
                    cout << "\n0.thoat" << endl;
                    cout << "===================" << endl;
                    cout << "moi nhap lua chon: ";
                    cin >> luachon3;
                    switch (luachon3) {
                        case 1 : {
                            clearScreen();
                            int luachon3_1;
                            while (luachon3_1 != 0) {
                                cout << "\n\n\t===Thong ke===\n\n" << endl;
                                cout << "\n1.thong ke danh sach thiet bi thanh ly" << endl;
                                cout << "\n2.thong ke danh danh sach thiet bi dang su dung" << endl;
                                cout << "\n0.thoat" << endl;
                                cout << "==================================================" << endl;
                                cout << "moi nhap lua chon cua ban: ";
                                cin >> luachon3_1;
                                switch (luachon3_1) {
                                    case 1 : {
                                        clearScreen();
                                        vector<ThietBi*>danhsachthanhly;
                                        for(ThietBi *tb : danhsachThietBi) {
                                            if(tb->daDenThoiHanThanhLy()) {
                                                danhsachthanhly.push_back(tb);
                                            }
                                        }
                                        cout << "\n\n\t======Thong ke danh sach thiet bi thanh ly======\n\n" << endl;
                                        for(ThietBi*tb : danhsachthanhly) {
                                            tb->hienThiThongTin();
                                            cout << endl;
                                        }
                                        _getch();
                                        clearScreen();
                                        break;
                                    }
                                    case 2: {
                                        clearScreen();
                                        vector<ThietBi*>danhsachdangsuadung;
                                        for(ThietBi *tb :danhsachThietBi) {
                                            if(tb->daDenThoiHanThanhLy() == false) {
                                                danhsachdangsuadung.push_back(tb);
                                            }
                                        }
                                        cout << "\n\n\t=======Thong ke danh sach thiet bi con dang su dung=====\n\n" <<endl;
                                        for(ThietBi*tb : danhsachdangsuadung) {
                                            tb->hienThiThongTin();
                                            cout << endl;
                                        
                                        }
                                        _getch();
                                        clearScreen();
                                        break;
                                    }
                                    case 0:
                                        break;
                                    default:
                                        cout << "lua chon khong hop le!" << endl;
                                }
                            }
                            _getch();
                            clearScreen();
                            break;
                        }
                        case 2: {
                            clearScreen();

                            _getch();
                            clearScreen();
                            break;
                        }
                        case 0:
                            break;
                        default :
                            cout << "lua chon khong hop le" <<endl;

                    }
                }
                _getch();
                clearScreen();
                break;
            }
            case 0:
                break;
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