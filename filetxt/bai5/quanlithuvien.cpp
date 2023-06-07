#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
// Hàm để tạo ra sách từ thông tin trong tệp văn bản
Sach* taoSachTuThongTin(string thongTin) {
vector<string> danhSachThongTin;
string delimiter = ",";
size_t pos = 0;
string token;
while ((pos = thongTin.find(delimiter)) != string::npos) {
    token = thongTin.substr(0, pos);
    danhSachThongTin.push_back(token);
    thongTin.erase(0, pos + delimiter.length());
}
danhSachThongTin.push_back(thongTin);

string maSo = danhSachThongTin[0];
string ten = danhSachThongTin[1];
string chuDe = danhSachThongTin[2];
string tacGia = danhSachThongTin[3];
string nhaXuatBan = danhSachThongTin[4];
string ngayXuatBan = danhSachThongTin[5];
int soTrang = stoi(danhSachThongTin[6]);
int soBanLuu = stoi(danhSachThongTin[7]);

if (danhSachThongTin.size() == 10) {
    string ngayMuon = danhSachThongTin[8];
    string ngayHenTra = danhSachThongTin[9];
    return new SachMuonVe(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, ngayMuon, ngayHenTra);
} else if (danhSachThongTin.size() == 9) {
    string gioMuon = danhSachThongTin[8];
    string gioTra = danhSachThongTin[9];
    return new SachMuonDoc(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu, gioMuon, gioTra);
} else {
    return new Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, soTrang, soBanLuu);
}
}

// Hàm để lưu thông tin sách vào tệp văn bản
void luuSachVaoTep(vector<Sach*> danhSachSach, string tenTep) {
ofstream file(tenTep);
if (file.is_open()) {
    for (Sach* sach : danhSachSach) {
        file << sach->getMaSoSach() << ",";
        file << sach->getTenSach() << ",";
        file << sach->getChuDe() << ",";
        file << sach->getTacGia() << ",";
        file << sach->getNhaXuatBan() << ",";
        file << sach->getNgayXuatBan() << ",";
        file << sach->getSoTrang() << ",";
    file << sach->getSoTrang() << ",";
    file << sach->getSoBanLuu();
        // Ghi thông tin sách mượn về
        SachMuonVe* sachMuonVe = dynamic_cast<SachMuonVe*>(sach);
        if (sachMuonVe != nullptr) {
            file << "," << sachMuonVe->getNgayMuon() << ",";
            file << sachMuonVe->getNgayHenTra();
        }
        
        // Ghi thông tin sách mượn đọc
        SachMuonDoc* sachMuonDoc = dynamic_cast<SachMuonDoc*>(sach);
        if (sachMuonDoc != nullptr) {
            file << "," << sachMuonDoc->getGioMuon() << ",";
            file << sachMuonDoc->getGioTra();
        }
        
        file << endl;
    }
    file.close();
    cout << "Luu thanh cong!" << endl;
}
else {
    cout << "Khong the mo tep!" << endl;
}
}
// Hàm để đọc thông tin sách từ tệp văn bản
vector<Sach*> docSachTuTep(string tenTep) {
vector<Sach*> danhSachSach;
string line;
ifstream file(tenTep);
if (file.is_open()) {
    while (getline(file, line)) {
        Sach* sach = taoSachTuThongTin(line);
        danhSachSach.push_back(sach);
    }
    file.close();
}
else {
    cout << "Khong the mo tep!" << endl;
}

return danhSachSach;
}
int main() {
vector<Sach*> danhSachSach;
string tenTep = "danh_sach_sach.txt";
// Đọc thông tin sách từ tệp văn bản
danhSachSach = docSachTuTep(tenTep);

// Hiển thị thông tin sách
for (Sach* sach : danhSachSach) {
    sach->hienThiThongTin();
    cout << endl;
}

// Lưu thông tin sách vào tệp văn bản
luuSachVaoTep(danhSachSach, "sach_moi.txt");

// Giải phóng bộ nhớ của các đối tượng sách
for (Sach* sach : danhSachSach) {
    delete sach;
}

return 0;
}