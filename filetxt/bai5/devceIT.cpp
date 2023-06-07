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

    int choice;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. them thiet bi" << endl;
        cout << "2. Hien thi thong tin thiet bi" << endl;
        cout << "3. Thong ke cac thiet bi den thoi han thanh li" << endl;
        cout << "4. Hiển thị danh sach de nghi thanh li" << endl;
        cout << "0. Thoat chuong tinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int loaiThietBi;
                cout << "Chon mot loai thiet bi: " << endl;
                cout << "1.May tinh" << endl;
                cout << "2.May in den tran" << endl;
                cout << "3.may in mau" << endl;
                cout << "4.may quyet" << endl;
                cout << "5.May tham chieu" << endl;
                cin >> loaiThietBi;

                string ten, ma, ngay, trangthai;

                cout << "Nhapo ten thiet bi ";
                cin.ignore();
                getline(cin, ten);
                cout << "Nhap ma thiet bi: ";
                getline(cin, ma);
                cout << "ngay nhap thiet bi: ";
                getline(cin, ngay);
                cout << "nhap trang thi cua thiet bi: ";
                getline(cin, trangthai);

                switch (loaiThietBi) {
                    case 1: {
                        string mauSac;
                        int tocDo, boNho;
                        cout << "Nhập màu sắc: ";
                        getline(cin, mauSac);
                        cout << "Nhập tốc độ: ";
                        cin >> tocDo;
                        cout << "Nhập bộ nhớ: ";
                        cin >> boNho;

                        danhSachThietBi.push_back(new MayTinh(ten, ma, ngay, trangthai, mauSac, tocDo, boNho));
                        break;
                    }
                    case 2: {
                        int soDiemAnh;
                        cout << "Nhập số điểm ảnh: ";
                        cin >> soDiemAnh;

                        danhSachThietBi.push_back(new MayInDenTrang(ten, ma, ngay, trangthai, soDiemAnh));
                        break;
                    }
                    case 3: {
                        int soDiemAnh, soMau;
                        cout << "Nhập số điểm ảnh: ";
                        cin >> soDiemAnh;
                        cout << "Nhập số màu: ";
                        cin >> soMau;

                        danhSachThietBi.push_back(new MayInMau(ten, ma, ngay, trangthai, soDiemAnh, soMau));
                        break;
                    }
                    case 4: {
                        int tocDoQuet;
                        cout << "Nhập tốc độ quét: ";
                    
                        cin >> tocDoQuet;

                        danhSachThietBi.push_back(new MayQuet(ten, ma, ngay, trangthai, tocDoQuet));
                        break;
                    }
                    case 5: {
                        int gioThamChieuToiDa;
                        cout << "Nhập số giờ tham chiếu tối đa: ";
                        cin >> gioThamChieuToiDa;

                        danhSachThietBi.push_back(new MayThamChieu(ten, ma, ngay, trangthai, gioThamChieuToiDa));
                        break;
                    }
                    default:
                        cout << "Lựa chọn không hợp lệ!" << endl;
                        break;
                }
                break;
            }
            case 2: {
                cout << "Thông tin các thiết bị:" << endl;
                for (ThietBi* tb : danhSachThietBi) {
                    tb->hienThiThongTin();
                    cout << endl;
                }
                break;
            }
            case 3: {
                vector<ThietBi*> danhSachThanhLy;
                for (ThietBi* tb : danhSachThietBi) {
                    if (tb->daDenThoiHanThanhLy()) {
                        danhSachThanhLy.push_back(tb);
                    }
                }
                cout << "Đã thống kê xong!" << endl;
                break;
            }
           
            case 0:
                cout << "Chương trình đã kết thúc." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ
    for (ThietBi* tb : danhSachThietBi) {
        delete tb;
    }
    danhSachThietBi.clear();

    return 0;
}

