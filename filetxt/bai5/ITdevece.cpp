#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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
        cout << "Tên thiết bị: " << tenThietBi << endl;
        cout << "Mã thiết bị: " << maThietBi << endl;
        cout << "Ngày nhập: " << ngayNhap << endl;
        cout << "Trạng thái: " << trangThai << endl;
    }

    bool daDenThoiHanThanhLy() {
        return trangThai == "đến thời hạn thanh lý";
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
        cout << "Màu sắc: " << mauSac << endl;
        cout << "Tốc độ: " << tocDo << endl;
        cout << "Bộ nhớ: " << boNho << endl;
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
        cout << "Số điểm ảnh: " << soDiemAnh << endl;
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
        cout << "Số màu: " << soMau << endl;
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
        cout << "Tốc độ quét: " << tocDoQuet << endl;
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
        cout << "Số giờ tham chiếu tối đa: " << gioThamChieuToiDa << endl;
    }
};

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
            } else if (ten == "MayInMau") {
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
for (const auto& thietBi : danhSachThietBi) {
    thietBi->hienThiThongTin();
    cout << "--------------------------" << endl;
}
cout << "\n\n\t\tThong tin cac thiet bi :" << endl;
for (const auto& thietBi : danhSachThietBi) {
    if (dynamic_cast<MayTinh*>(thietBi) != nullptr) {
        cout << "Loại thiết bị: Máy tính" << endl;
    } else if (dynamic_cast<MayInDenTrang*>(thietBi) != nullptr) {
        cout << "Loại thiết bị: Máy in đen trắng" << endl;
    } else if (dynamic_cast<MayInMau*>(thietBi) != nullptr) {
        cout << "Loại thiết bị: Máy in màu" << endl;
    } else if (dynamic_cast<MayQuet*>(thietBi) != nullptr) {
        cout << "Loại thiết bị: Máy quét" << endl;
    } else if (dynamic_cast<MayThamChieu*>(thietBi) != nullptr) {
        cout << "Loại thiết bị: Máy tham chiếu" << endl;
    }
    thietBi->hienThiThongTin();
    cout << "--------------------------" << endl;
}
cout << "\n\n\t\tthong tin cac loai mau tinh:" << endl;
for (const auto& thietBi : danhSachThietBi) {
    MayTinh* mayTinh = dynamic_cast<MayTinh*>(thietBi);
    if (mayTinh != nullptr) {
        cout << "Loại thiết bị: Máy tính" << endl;
        mayTinh->hienThiThongTin();
        cout << "--------------------------" << endl;
    }
}


// Giải phóng bộ nhớ
for (const auto& thietBi : danhSachThietBi) {
    delete thietBi;
}
danhSachThietBi.clear();

return 0;
}


