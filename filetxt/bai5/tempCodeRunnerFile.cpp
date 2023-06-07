#include <iostream>
#include <vector>
#include <string>

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

    // Thêm các thiết bị vào danh sách
    danhSachThietBi.push_back(new MayTinh("Máy tính ", "MT001", "01/01/2023", "đang sử dụng", "Đen", 3, 8));
    danhSachThietBi.push_back(new MayInDenTrang("Máy in đen trắng ", "MIDT001", "02/01/2023", "đến thời hạn thanh lý", 1200));
    danhSachThietBi.push_back(new MayInMau("Máy in màu ", "MIM001", "03/01/2023", "đang sử dụng", 1200, 4));
    danhSachThietBi.push_back(new MayQuet("Máy quét ", "MQ001", "04/01/2023", "đang sử dụng", 2400));
    danhSachThietBi.push_back(new MayThamChieu("Máy tham chiếu ", "MTC001", "05/01/2023", "đến thời hạn thanh lý", 8));

    // Hiển thị thông tin các thiết bị
    cout << "Thông tin các thiết bị:" << endl;
    for (ThietBi* tb : danhSachThietBi) {
        tb->hienThiThongTin();
        cout << endl;
    }

    // Thống kê thiết bị hết hạn sử dụng và đưa vào danh sách thanh lý
    vector<ThietBi*> danhSachThanhLy;
    for (ThietBi* tb : danhSachThietBi) {
        if (tb->daDenThoiHanThanhLy()) {
            danhSachThanhLy.push_back(tb);
        }
    }

    // Hiển thị danh sách thiết bị đề nghị thanh lý
    cout <<"\n\n";
    cout << "----------Danh sách thiết bị đề nghị thanh lý----------\n\n" << endl;
    for (ThietBi* tb : danhSachThanhLy) {
        tb->hienThiThongTin();
        cout << endl;
    }

    // Giải phóng bộ nhớ
    for (ThietBi* tb : danhSachThietBi) {
        delete tb;
    }
    danhSachThietBi.clear();

    return 0;
}
