#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <sstream>
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
        cout << "|" << setw(12) << ngayNhap << "/" << thangNhap << "/" << namNhap; //9
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
        cout << "|"<< setw(7) << mauSac ; // 7
        cout << "|" << setw(6) << tocDo; // 6
        cout << "|" << setw(6) << boNho << "|";; // 6
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
        cout<< setw(6) << soMau << "|";
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


class QuanLiMenu {
private:
    vector<ThietBi*> danhsachThietBi;

public:
    void run() {
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

            switch (luachon1) {
                case 1:
                    themThietBiTuFile();
                    break;

                case 2:
                    hienThiThongTinThietBi();
                    break;

                case 3:
                    thongKeVaTimKiem();
                    break;

                case 0:
                    clearScreen();
                    cout << "Thoat chuong trinh." << endl;
                    return;

                default:
                    cout << "Lua chon khong hop le." << endl;
                    _getch();
            }
        }
    }

private:
    void clearScreen() {
        // Function to clear the screen
            #ifdef _WIN32
            std::system("cls");
            #else
            std::system("clear");
            #endif
    }

    void themThietBiTuFile() {
        ifstream inputfile("thietbi.txt");
        if (inputfile.is_open()) {
            string line;
            while (getline(inputfile, line)) {
                // Parse the line and create objects based on the data
                // ...

                // Add the created object to the danhSachThietBi vector
                // danhsachThietBi.push_back(...);
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
            cout << "\nKhong the mo file" << endl;
            _getch();
        }
    }

    void hienThiThongTinThietBi() {
        clearScreen();
        int luachon2;
        while (luachon2 != 0) {
            cout << "\n\n\t==========Hien thi thong tin============" << endl;
            cout << "\n1.May tinh" << endl;
            cout << "\n2.May in den trang" << endl;
            cout << "\n3.May in mau" << endl;
            cout << "\n4.May quet" << endl;
            cout << "\n5.May chieu" << endl;
            cout << "\n0.Quay lai" << endl;
            cout << "================================================" << endl;
            cout << "Moi nhap lua chon: ";
            cin >> luachon2;

            switch (luachon2) {
                case 1:
                    hienThiMayTinh();
                    break;

                case 2:
                    hienThiMayInDenTrang();
                    break;

                case 3:
                    hienThiMayInMau();
                    break;

                case 4:
                    hienThiMayQuet();
                    break;

                case 5:
                    hienThiMayChieu();
                    break;

                case 0:
                    break;

                default:
                    cout << "\nLua chon khong hop le!" << endl;
                    _getch();
            }
        }
    }

    void hienThiMayTinh() {
        clearScreen();
        cout << "\n\n\t====Thong tin cac loai may tinh======" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayTinh* maytinh = dynamic_cast<MayTinh*>(thietbi);
            if (maytinh != nullptr) {
                maytinh->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayInDenTrang() {
        clearScreen();
        cout << "\n\n\t=====Thong tin cac loai may in den trang=====" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayInDenTrang* mayindentrang = dynamic_cast<MayInDenTrang*>(thietbi);
            if (mayindentrang != nullptr && dynamic_cast<MayInMau*>(thietbi) == nullptr) {
                mayindentrang->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayInMau() {
        clearScreen();
        cout << "\n\n\t====Thong tin cac loai may in mau======" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayInMau* mayinmau = dynamic_cast<MayInMau*>(thietbi);
            if (mayinmau != nullptr) {
                mayinmau->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayQuet() {
        clearScreen();
        cout << "\n\n\t===Hien thi thong tin cac loai may quet========" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayQuet* mayquet = dynamic_cast<MayQuet*>(thietbi);
            if (mayquet != nullptr) {
                mayquet->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayChieu() {
        clearScreen();
        cout << "\n\n\t======Hien thi thong tin cac loai may chieu====" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayThamChieu* maythamchieu = dynamic_cast<MayThamChieu*>(thietbi);
            if (maythamchieu != nullptr) {
                maythamchieu->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void thongKeVaTimKiem() {
        int luachon3;

        while (luachon3 != 0) {
            clearScreen();
            cout << "\n\n\t===Thong ke và tim kiem===\n\n" << endl;
            cout << "\n1.Thong ke" << endl;
            cout << "\n2.Tim kiem" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon: ";
            cin >> luachon3;

            switch (luachon3) {
                case 1:
                    thongKe();
                    break;

                case 2:
                    timKiem();
                    break;

                case 0:
                    break;

                default:
                    cout << "\nLua chon khong hop le!" << endl;
                    _getch();
            }
        }
    }

    void thongKe() {
        int luachon3_1;

        while (luachon3_1 != 0) {
            clearScreen();
            cout << "\n\n\t===Thong ke===\n\n" << endl;
            cout << "\n1.Thong ke danh sach thiet bi thanh ly" << endl;
            cout << "\n2.Thong ke danh sach thiet bi dang su dung" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> luachon3_1;

            switch (luachon3_1) {
                case 1:
                    thongKeDanhSachThanhLy();
                    break;

                case 2:
                    thongKeDanhSachDangSuDung();
                    break;

                case 0:
                    break;

                default:
                    cout << "Lua chon khong hop le!" << endl;
                    _getch();
            }
        }
    }

    void thongKeDanhSachThanhLy() {
        clearScreen();
        vector<ThietBi*> danhsachthanhly;

        for (ThietBi* tb : danhsachThietBi) {
            if (tb->daDenThoiHanThanhLy()) {
                danhsachthanhly.push_back(tb);
            }
        }

        // cout << "\n\n\t======Thong ke danh sach thiet bi thanh ly======\n\n" << endl;

        // for (ThietBi* tb : danhsachthanhly) {
        //     tb->hienThiThongTin();
        //     cout << endl;
        // }
        cout << "\n\n\t===danh sach may tinh bi thanh ly====\n\n";
        for(ThietBi* tb : danhsachthanhly) {
            MayTinh* maytinh = dynamic_cast<MayTinh*>(tb);
            if(maytinh != nullptr) {
                maytinh->hienThiThongTin();
                cout << endl;
            }
        }

        _getch();
        clearScreen();
    }

    void thongKeDanhSachDangSuDung() {
        clearScreen();
        vector<ThietBi*> danhsachdangsuadung;

        for (ThietBi* tb : danhsachThietBi) {
            if (!tb->daDenThoiHanThanhLy()) {
                danhsachdangsuadung.push_back(tb);
            }
        }

        cout << "\n\n\t======Thong ke danh sach thiet bi dang su dung======\n\n" << endl;

        for (ThietBi* tb : danhsachdangsuadung) {
            tb->hienThiThongTin();
            cout << endl;
        }

        _getch();
        clearScreen();
    }

    void timKiem() {
        int luachon3_2;

        while (luachon3_2 != 0) {
            clearScreen();
            cout << "\n\n\t===Tim kiem===\n\n" << endl;
            cout << "\n1.Tim kiem thiet bi theo ma" << endl;
            cout << "\n2.Tim kiem thiet bi theo ten" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> luachon3_2;

            switch (luachon3_2) {
                case 1:
                    timKiemTheoMa();
                    break;

                case 2:
                    timKiemTheoTen();
                    break;

                case 0:
                    break;

                default:
                    cout << "Lua chon khong hop le!" << endl;
                    _getch();
            }
        }
    }

    void timKiemTheoMa() {
        clearScreen();
        string ma;
        cout << "\n\n\t===Tim kiem thiet bi theo ma===\n" << endl;
        cout << "Nhap ma thiet bi can tim: ";
        cin >> ma;

        bool found = false;

        for (ThietBi* tb : danhsachThietBi) {
            // Compare the ma of the tb object with the input ma
            // If found, display the information and set found to true
            // ...
        }

        if (!found) {
            cout << "\nKhong tim thay thiet bi voi ma " << ma << endl;
        }

        _getch();
        clearScreen();
    }

    void timKiemTheoTen() {
        clearScreen();
        string ten;
        cout << "\n\n\t===Tim kiem thiet bi theo ten===\n" << endl;
        cout << "Nhap ten thiet bi can tim: ";
        cin.ignore();
        getline(cin, ten);

        bool found = false;

        for (ThietBi* tb : danhsachThietBi) {
            // Compare the ten of the tb object with the input ten
            // If found, display the information and set found to true
            // ...
        }

        if (!found) {
            cout << "\nKhong tim thay thiet bi voi ten " << ten << endl;
        }

        _getch();
        clearScreen();
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
    QuanLiMenu menu;
    menu.run();

    return 0;
}