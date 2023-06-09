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
void timKiemThongTin(const vector<ThietBi*>& danhSachThietBi, const string& tenTimKiem) {
    bool timThay = false;
    
    cout << "Thong tin cac thiet bi tim thay:" << endl;
    for (const auto& thietBi : danhSachThietBi) {
        if (thietBi->getname() == tenTimKiem) {
            thietBi->hienThiThongTin();
            timThay = true;
        }
    }
    
    if (!timThay) {
        cout << "Khong tim thay thiet bi voi ten '" << tenTimKiem << "'" << endl;
    }
}

int main() {
    vector<ThietBi*> danhSachThietBi;

    // Đọc dữ liệu từ tệp "thietbi.txt"
    ifstream inputFile("thietbi.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            string ten, ma, ngay, trangthai;
            int sodiem, tocdo, bonho, tocdoscan, giothamchieu;
            string mau;
            int somau;

            // Phân tách dữ liệu từ mỗi dòng trong tệp
            stringstream ss(line);
            ss >> ten >> ma >> ngay >> trangthai;

            // Tạo đối tượng ThietBi dựa trên loại thiết bị
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

        inputFile.close();
} else {
cout << "Khong the mo tep  thietbi.txt!" << endl;
return 1; // Kết thúc chương trình với mã lỗi 1
}
// Hiển thị thông tin thiết bị
/*for (const auto& thietBi : danhSachThietBi) {
    thietBi->hienThiThongTin();
    cout << "--------------------------" << endl;
}*/
/*cout << "\n\n\t\tThong tin cac thiet bi :" << endl;
for (const auto& thietBi : danhSachThietBi) {
    if (dynamic_cast<MayTinh*>(thietBi) != nullptr) {
        //cout << "Loai thiet bi: May tinh" << endl;
    } else if (dynamic_cast<MayInDenTrang*>(thietBi) != nullptr) {
        //cout << "Loai thiet bi: May in den trang" << endl;
    } else if (dynamic_cast<MayInMau*>(thietBi) != nullptr) {
        //cout << "Loai thiet bi: May in mau" << endl;
    } else if (dynamic_cast<MayQuet*>(thietBi) != nullptr) {
        //cout << "Loai thiet bi: May quet" << endl;
    } else if (dynamic_cast<MayThamChieu*>(thietBi) != nullptr) {
        //cout << "Loai thiet bi: May tham chieu" << endl;
    }
    thietBi->hienThiThongTin();
    cout << "--------------------------" << endl;
}*/
cout << "\n\n\t\tthong tin cac loai may tinh:" << endl;
for (const auto& thietBi : danhSachThietBi) {
    MayTinh* mayTinh = dynamic_cast<MayTinh*>(thietBi);
    if (mayTinh != nullptr) {
        //cout << "Loai thiet bi: May tinh" << endl;
        mayTinh->hienThiThongTin();
        cout <<endl;
    }
}
cout << "\n\n\t\tthong tin cac loai may in den trang:" << endl;
for (const auto& thietBi : danhSachThietBi) {
    MayInDenTrang* mayInDenTrang = dynamic_cast<MayInDenTrang*>(thietBi);
    if (mayInDenTrang != nullptr && dynamic_cast<MayInMau*>(thietBi) == nullptr) {
        mayInDenTrang->hienThiThongTin();
        cout << endl;
    }
}

cout <<"\n\n\t\tthong tin cac loai may in mau:" << endl;
for (const auto& thietBi : danhSachThietBi) {
    MayInMau* mayInMau = dynamic_cast<MayInMau*>(thietBi);
    if(mayInMau!= nullptr) {
        mayInMau->hienThiThongTin();
        cout << endl;
    }
}
// thống kê các thiết bị đến thời hạn thanh lý
// Tạo danh sách các thiết bị đã qua thanh lý
vector<ThietBi*> danhSachThanhLy;

// Thống kê thiết bị hết hạn sử d ụng và đưa vào danh sách thanh lý
for (ThietBi* tb : danhSachThietBi) {
    if (tb->daDenThoiHanThanhLy()) {
        danhSachThanhLy.push_back(tb);
    }
}

// Hiển thị danh sách các thiết bị được thanh lý
cout << "\n\n\t\t===Danh sach cac thiet bi den thoi han thanh ly==== " << endl;
for (ThietBi* tb : danhSachThanhLy) {
    tb->hienThiThongTin();
    cout<< endl;
    cout << endl;
}
 string tenTimKiem;
    cout << "Nhap ten thiết bị: ";
    getline(cin, tenTimKiem);
    
    // Tìm kiếm và hiển thị thông tin thiết bị theo tên
    timKiemThongTin(danhSachThietBi, tenTimKiem);



// Giải phóng bộ nhớ
for (const auto& thietBi : danhSachThietBi) {
    delete thietBi;
}
danhSachThietBi.clear();

return 0;
}


