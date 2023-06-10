#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Sach {
protected:
    string maSoSach;
    string tenSach;
    string chuDe;
    string tacGia;
    string nhaXuatBan;
    string ngayXuatBan;
    int soTrang;
    int soBanLuu;

public:
    Sach(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, int soTrang, int soBanLuu) {
        maSoSach = maSo;
        tenSach = ten;
        this->chuDe = chuDe;
        this->tacGia = tacGia;
        this->nhaXuatBan = nhaXuatBan;
        this->ngayXuatBan = ngayXuatBan;
        this->soTrang = soTrang;
        this->soBanLuu = soBanLuu;
    }

    virtual void hienThiThongTin() {
        cout << "ma so sach: " << maSoSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Chu de: " << chuDe << endl;
        cout << "Tac gia: " << tacGia << endl;
        cout << "nha xuat ban: " << nhaXuatBan << endl;
        cout << "ngay xuat ban: " << ngayXuatBan << endl;
        cout << "So trang: " << soTrang << endl;
        cout << "So ban luu thu vien: " << soBanLuu << endl;
    }
      // Getter và Setter cho các thuộc tính

    string getMaSoSach() {
        return maSoSach;
    }

    void setMaSoSach(string maSo) {
        maSoSach = maSo;
    }

    string getTenSach() {
        return tenSach;
    }

    void setTenSach(string ten) {
        tenSach = ten;
    }

    string getChuDe() {
        return chuDe;
    }

    void setChuDe(string chuDe) {
        this->chuDe = chuDe;
    }

    string getTacGia() {
        return tacGia;
    }

    void setTacGia(string tacGia) {
        this->tacGia = tacGia;
    }

    string getNhaXuatBan() {
        return nhaXuatBan;
    }

    void setNhaXuatBan(string nhaXuatBan) {
        this->nhaXuatBan = nhaXuatBan;
    }

    string getNgayXuatBan() {
        return ngayXuatBan;
    }

    void setNgayXuatBan(string ngayXuatBan) {
        this->ngayXuatBan = ngayXuatBan;
    }

    int getSoTrang() {
        return soTrang;
    }

    void setSoTrang(int soTrang) {
        this->soTrang = soTrang;
    }

    int getSoBanLuu() {
        return soBanLuu;
    }

    void setSoBanLuu(int soBanLuu) {
        this->soBanLuu = soBanLuu;
    }

};

class SachMuonVe : public Sach {
private:
    string ngayMuon;
    string ngayHenTra;

public:
    SachMuonVe(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, int soTrang, int soBanLuu, string ngayMuon, string ngayHenTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu) {
        this->ngayMuon = ngayMuon;
        this->ngayHenTra = ngayHenTra;
    }

    void hienThiThongTin() override {
        Sach::hienThiThongTin();
        cout << "Ngay muon: " << ngayMuon << endl;
        cout << "Ngay hen tra: " << ngayHenTra << endl;
    }
    string getNgayMuon() {
        return ngayMuon;
    }
    string getNgayHenTra() {
        return ngayHenTra;
    }
};

class SachMuonDoc : public Sach {
private:
    string gioMuon;
    string gioTra;

public:
    SachMuonDoc(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, int soTrang, int soBanLuu, string gioMuon, string gioTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu) {
        this->gioMuon = gioMuon;
        this->gioTra = gioTra;
    }
    void hienThiThongTin() override {
    Sach::hienThiThongTin();
    cout << "Gio muon doc: " << gioMuon << endl;
    cout << "Gio tra: " << gioTra << endl;
}
    string getGioMuon() {
        return gioMuon;
    }
    string getGioTra() {
        return gioTra;
    }
};

int main() {

    vector<Sach*> danhSachSach;

    ifstream inputFile("danh_sach_sach.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            // Xử lý và tạo đối tượng SachMuonVe từ dòng dữ liệu
            // Ví dụ: 12345,Sach 1,Khoa hoc,Tac gia 1,Nha xuat ban kimdong,2022-01-01,200,5,2023-05-01,2023-05-15
            // ... (phân tách dữ liệu và tạo đối tượng SachMuonVe) ...
            // Sau đó, thêm đối tượng SachMuonVe vào danh sách danhSachSach
            stringstream ss(line);
        string maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, ngayMuon, ngayHenTra, gioMuon, gioTra;
        int soTrang, soBanLuu;
        getline(ss, maSo, ',');
        getline(ss, ten, ',');
        getline(ss, chuDe, ',');
        getline(ss, tacGia, ',');
        getline(ss, nhaXuatBan, ',');
        getline(ss, ngayXuatBan, ',');
        ss >> soTrang;
        ss.ignore();
        ss >> soBanLuu;
        ss.ignore();
        getline(ss, ngayMuon, ',');
        getline(ss, ngayHenTra, ',');
        getline(ss, gioMuon, ',');
        getline(ss, gioTra, ',');

        if (!gioMuon.empty() && !gioTra.empty()) {
            SachMuonDoc* sachMuonDoc = new SachMuonDoc(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, gioMuon, gioTra);
            danhSachSach.push_back(sachMuonDoc);
        } else if (!ngayMuon.empty() && !ngayHenTra.empty()) {
            SachMuonVe* sachMuonVe = new SachMuonVe(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, ngayMuon, ngayHenTra);
            danhSachSach.push_back(sachMuonVe);
        } else {
            Sach* sach = new Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu);
            danhSachSach.push_back(sach);
        }
    }

        inputFile.close();
    } else {
        cout << "Khong the mo file danh_sach_sach.txt" << endl;
        return 0;
    }
    vector<SachMuonVe*> danhSachSachMuonVe;
vector<SachMuonDoc*> danhSachSachMuonDoc;

// Thêm sách vào danh sách tương ứng
if (!gioMuon.empty() && !gioTra.empty()) {
    SachMuonDoc* sachMuonDoc = new SachMuonDoc(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, gioMuon, gioTra);
    danhSachSachMuonDoc.push_back(sachMuonDoc);
} else if (!ngayMuon.empty() && !ngayHenTra.empty()) {
    SachMuonVe* sachMuonVe = new SachMuonVe(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, ngayMuon, ngayHenTra);
    danhSachSachMuonVe.push_back(sachMuonVe);
} else {
    Sach* sach = new Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu);
    // Xử lý sách không thuộc loại mượn về hoặc mượn đọc theo yêu cầu của bạn
}

// Thống kê sách mượn về
cout << "Cac sach cho phep muon ve:" << endl;
for (const auto& sach : danhSachSachMuonVe) {
    sach->hienThiThongTin();
    cout << endl;
}

// Thống kê sách mượn đọc
cout << "Cac sach cho phep muon doc:" << endl;
for (const auto& sach : danhSachSachMuonDoc) {
    sach->hienThiThongTin();
    cout << endl;
}

// Giải phóng bộ nhớ
for (const auto& sach : danhSachSachMuonVe) {
    delete sach;
}

for (const auto& sach : danhSachSachMuonDoc) {
    delete sach;
}




    return 0;

  
}