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
    string ngayNhap;
    string trangThai;

public:
    ThietBi(string ten, string ma, string ngay, string trangthai)
        : tenThietBi(ten), maThietBi(ma), ngayNhap(ngay), trangThai(trangthai) {}

    virtual void hienThiThongTin() {
        cout << "|"<< setw(12) <<  tenThietBi; //12
        cout << "|" << setw(11) << maThietBi; // 11
        cout << "|" << setw(9) << ngayNhap; //9
        cout << "|" << setw(10) << trangThai; //10
    } 

    bool daDenThoiHanThanhLy() {
        return trangThai == "thanhly";
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
    MayTinh(string ten, string ma, string ngay, string trangthai, string mau, int tocdo, int bonho)
        : ThietBi(ten, ma, ngay, trangthai), mauSac(mau), tocDo(tocdo), boNho(bonho) {}

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
    MayIn(string ten, string ma, string ngay, string trangthai, int sodiem)
        : ThietBi(ten, ma, ngay, trangthai), soDiemAnh(sodiem) {}
};

// Lớp Máy in đen trắng
class MayInDenTrang : public MayIn {
public:
    MayInDenTrang(string ten, string ma, string ngay, string trangthai, int sodiem)
        : MayIn(ten, ma, ngay, trangthai, sodiem) {}

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
    MayInMau(string ten, string ma, string ngay, string trangthai, int sodiem, int somau)
        : MayInDenTrang(ten, ma, ngay, trangthai, sodiem), soMau(somau) {}

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
    MayQuet(string ten, string ma, string ngay, string trangthai, int tocdoscan)
        : ThietBi(ten, ma, ngay, trangthai), tocDoQuet(tocdoscan) {}

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
    MayThamChieu(string ten, string ma, string ngay, string trangthai, int giothamchieu)
        : ThietBi(ten, ma, ngay, trangthai), gioThamChieuToiDa(giothamchieu) {}

    void hienThiThongTin() {
        ThietBi::hienThiThongTin();
        cout << "|" << setw(8) << gioThamChieuToiDa << endl; // maxhours
    }
};
void timKiemThongTin(const vector<ThietBi*>& danhSachThietBi, const string& tenTimKiem, const string& ID) {
    bool timThay = false;
    
    cout << "Thong tin cac thiet bi tim thay:/n/n" << endl;
    for (const auto& thietBi : danhSachThietBi) {
        if (thietBi->getname() == tenTimKiem && thietBi->getID() == ID) {
            thietBi->hienThiThongTin();
            timThay = true;
        }
    }
    
    if (!timThay) {
        cout << "Khong tim thay thiet bi voi ten '" << tenTimKiem << "'" << endl;
        cout << "Khong tim thay thiet bi voi id '" << ID << "'" << endl;
    }
}
int main() {
    vector<ThietBi*> danhSachThietBi;

//menu các lựa chọn
    int luachon;
    while (true) {
       
        cout << "==================MENU=================" << endl;
        cout << "\n1.them thiet bi" << endl;
        cout << "\n2.hien thi thong tin may tinh" << endl;
        cout << "\n3.Hien thi thong tin may in den trang" << endl;
        cout << "\n4.Hien thi thong tin may in mau" << endl;
        cout << "\n5.Hien thi thong tin may quet" << endl;
        cout << "\n6.Hien thi thong tin may chieu" << endl;
        cout << "\n7.Hien thi thong tin thiet bi thanh ly" << endl;
        cout << "\n8.tim kiem thiet bi theo ten" << endl;
        cout << "\n0.Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Moi nhap lua chon cau ban: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1: {
            //dọc dữ liệu từ file
            ifstream inputfile("thietbi.txt");
            if(inputfile.is_open()) {
                string line;
                while(getline(inputfile, line)) {
                    string ten, ma, ngay, trangthai;
                    int sodiem, tocdo, bonho, tocdoscan, giothamchieu;
                    string mau;
                    int somau;

                    //phân tách dứ liệu từ mỗi dòng trong tệp
                    stringstream ss(line);
                    ss >> ten >> ma >> ngay >> trangthai;
                    //tạo đối tượng ThietBi dựa trên các loại thiết bị
                    if (ten == "MayTinh") {
                    ss >> mau >> tocdo >> bonho;
                    danhSachThietBi.push_back(new MayTinh(ten, ma, ngay, trangthai, mau, tocdo, bonho));
                    } else if (ten == "MayInDenTrang") {
                    ss >> sodiem;
                    danhSachThietBi.push_back(new MayInDenTrang(ten, ma, ngay, trangthai, sodiem));
                    } else if (ten == "MayinMau") {
                    ss >> sodiem >> somau;
                    danhSachThietBi.push_back(new MayInMau(ten, ma, ngay, trangthai, sodiem, somau));
                    } else if (ten == "MayQuet") {
                    ss >> tocdoscan;
                    danhSachThietBi.push_back(new MayQuet(ten, ma, ngay, trangthai, tocdoscan));
                    } else if (ten == "MayThamChieu") {
                    ss >> giothamchieu;
                    danhSachThietBi.push_back(new MayThamChieu(ten, ma, ngay, trangthai, giothamchieu));
                    }                    
                }
                inputfile.close();
                cout << "\nNhap du lieu tu tep thanh cong!" << endl;
            } else {
                cout << "\nKhong the mo file!" << endl;
                return 1;
            }
            break;
        }
        case 2: {
            //hiển thị thông tin máy tính
            cout << "\n\n\t====Thong tin cac loai may tinh===" << endl;
            for (const auto& thietBi : danhSachThietBi) {
                MayTinh* mayTinh = dynamic_cast<MayTinh*>(thietBi);
                if (mayTinh != nullptr) { 
                mayTinh->hienThiThongTin();
                cout <<endl;
                }
            }
                break;
        }
        case 3: {
            //hien thi thong tin cac loai may in den trang
            cout << "\n\n\t====Thong tin cac loai may in den trang===" << endl;
            for(const auto& thietBi : danhSachThietBi) {
                MayInDenTrang* mayInDenTrang = dynamic_cast<MayInDenTrang*>(thietBi);
                if(mayInDenTrang != nullptr && dynamic_cast<MayInMau*>(thietBi) == nullptr) {
                    mayInDenTrang->hienThiThongTin();
                    cout << endl;
                }
            }
            break;
        }
        case 4: {
            //hien thi thong tin cac loai may in mau
            cout << "\n\n\t====Thong tin cac loai may in mau===" << endl;
            for(const auto& thietBi : danhSachThietBi) {
                MayInMau* mayInMau = dynamic_cast<MayInMau*>(thietBi);
                if(mayInMau != nullptr) {
                    mayInMau->hienThiThongTin();
                    cout << endl;
                }
            }
            break;
        }
        case 5: {
            //hien thi thong tin cac loai may in mau
            cout << "\n\n\t====Thong tin cac loai may quet===" << endl;
            for(const auto& thietBi : danhSachThietBi) {
                MayQuet* mayQuet = dynamic_cast<MayQuet*>(thietBi);
                if(mayQuet != nullptr) {
                    mayQuet->hienThiThongTin();
                    cout << endl;
                }
            }
            break;
        }
        case 6: {
             //hien thi thong tin cac loai may chieu
            cout << "\n\n\t====Thong tin cac loai may chieu===" << endl;
            for(const auto& thietBi : danhSachThietBi) {
                MayThamChieu* maychieu = dynamic_cast<MayThamChieu*>(thietBi);
                if(maychieu != nullptr) {
                    maychieu->hienThiThongTin();
                    cout << endl;
                }
            }
            break;
        }
        case 7: {
            //hien thi thong tin cac loai thiet bi den thoi han thanh ly
            //tao danh sach cac thiet bi den thoi han thanh li
            vector<ThietBi*>danhsachthanhly;
            //thong ke cac thiet bi den hanh thanh ly
            for(ThietBi* tb : danhSachThietBi) {
                if(tb->daDenThoiHanThanhLy()) {
                    danhsachthanhly.push_back(tb);
                }
            }
            //hien thi thong tin danh sach
            cout << "\n\n\t==Danh sach thiet bi den thoi han hanh li==" << endl;
            for(ThietBi* tb : danhsachthanhly) {
                tb->hienThiThongTin();
                cout << endl << endl;
            }
            break;
        }
        case 8: {
            string tenTimKiem;
            cout << "Nhap ten thiet bi: ";
            cin.ignore();
            getline(cin, tenTimKiem);
            timKiemThongTin(danhSachThietBi,tenTimKiem);
            cout << endl << endl;
            break;
        }
        case 0:
            cout << "thoat chuong trinh! cam on ban da su dung!" << endl;
            return 0;
        
        default:
            cout << "lua chon khong hop le!" << endl;
        }
    }

// Giải phóng bộ nhớ
for (const auto& thietBi : danhSachThietBi) {
    delete thietBi;
}
danhSachThietBi.clear();

return 0;
}


