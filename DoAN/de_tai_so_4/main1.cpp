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
    string getphuongthuc() {
        return phuongthuc;
    }
    void setphuongthuc(string phuongthuc) {
        this->phuongthuc = phuongthuc;
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
    SachMuonVe(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, string phuongthuc, int soTrang, int soBanLuu, string ngayMuon, string ngayHenTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu) {
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
    SachMuonDoc(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, string phuongthuc, int soTrang, int soBanLuu, string gioMuon, string gioTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu) {
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
void timKiemThongTin(const vector<Sach*>&danhSachSach , const string& TimKiemTG) {
    bool timThay = false;
    
    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    for (const auto& Sach : danhSachSach) {
        if (Sach->getTacGia() == TimKiemTG) {
            Sach->hienThiThongTin();
            cout << "-----------------";
            cout << endl;
            timThay = true;
        }
    }
    
    if (!timThay) {
        cout << "Khong tim thay sach voi ten '" << TimKiemTG << "'" << endl << endl;
    }
} // giải thích đoạn code tìm kiếm thông tin
/* Hàm "timKiemThongTin" nhận vào hai đối số:

"danhSachSach" là một tham chiếu tới một vector chứa con trỏ đến các đối tượng sách. Đối tượng sách được đại diện bởi lớp có tên "Sach".
"TimKiemTG" là một tham chiếu tới một chuỗi (string) đại diện cho tên tác giả cần tìm kiếm.
Khởi tạo một biến boolean có tên "timThay" với giá trị ban đầu là false. Biến này sẽ được sử dụng để kiểm tra xem có sách nào được tìm thấy hay không.

In ra thông báo "Thong tin cac sach tim thay:" trên màn hình.

Sử dụng vòng lặp for-each để duyệt qua từng phần tử trong danh sách sách.

Trong mỗi lần lặp, đoạn code kiểm tra xem tên tác giả của sách hiện tại có khớp với tên tác giả được tìm kiếm hay không bằng cách so sánh giá trị trả về từ hàm "getTacGia()" của đối tượng sách với chuỗi "TimKiemTG".

Nếu tên tác giả khớp, đoạn code gọi phương thức "hienThiThongTin()" của đối tượng sách để hiển thị thông tin của sách đó trên màn hình. Sau đó, in ra dòng gạch ngang và đặt biến "timThay" thành true.

Sau khi kết thúc vòng lặp, kiểm tra giá trị của biến "timThay". Nếu giá trị là false, tức là không tìm thấy sách nào với tác giả có tên tương ứng, in ra thông báo "Khong tim thay sach voi ten '..." trên màn hình.*/
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
        string maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, ngayMuon, ngayHenTra, gioMuon, gioTra;
        int soTrang, soBanLuu;
        
        getline(ss, maSo, ',');
       
        getline(ss, ten, ',');
        
        getline(ss, chuDe, ',');
        
        getline(ss, tacGia, ',');
       
        getline(ss, nhaXuatBan, ',');
       
        getline(ss, ngayXuatBan, ',');

        getline(ss, phuongthuc,',');

        
        ss >> soTrang;
        ss.ignore();
        ss >> soBanLuu; 
       
       

        if (phuongthuc == "doc") {
            ss.ignore();
            getline(ss, gioMuon, ',');
            
            getline(ss, gioTra, ',');
            danhSachSach.push_back(new SachMuonDoc(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu, gioMuon, gioTra));
        } else if (phuongthuc == "muon") {
            ss.ignore();
            getline(ss, ngayMuon, ',');
            
            getline(ss, ngayHenTra, ',');
            
            danhSachSach.push_back(new SachMuonVe(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu, ngayMuon, ngayHenTra));
        } else {
            
            danhSachSach.push_back(new Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu));
        }
    }

        inputFile.close();
    } else {
        cout << "Khong the mo file danh_sach_sach.txt" << endl;
        return 0;
    }
/*Mở tệp tin "danh_sach_sach.txt" bằng cách tạo một đối tượng ifstream với tên "inputFile" và truyền tên tệp tin vào hàm constructor.

Kiểm tra xem việc mở tệp tin thành công hay không bằng cách sử dụng phương thức "is_open()" của đối tượng "inputFile". Nếu không thành công, in ra thông báo lỗi và kết thúc hàm.

Nếu việc mở tệp tin thành công, sử dụng vòng lặp while để đọc từng dòng trong tệp tin.

Trong mỗi lần lặp, dòng dữ liệu được lưu trong biến "line".

Sử dụng đối tượng stringstream "ss" để xử lý và phân tách dữ liệu từ dòng "line".

Sử dụng các lệnh getline và toán tử >> để lấy giá trị từ stringstream "ss" và gán cho các biến tương ứng, phân tách bằng dấu ','.

Nếu "phuongthuc" là "doc", tiếp tục đọc các giá trị "gioMuon" và "gioTra" từ stringstream "ss". Sau đó, tạo đối tượng "SachMuonDoc" mới với các thông tin đã đọc và thêm nó vào danh sách "danhSachSach".

Nếu "phuongthuc" là "muon", tiếp tục đọc các giá trị "ngayMuon" và "ngayHenTra" từ stringstream "ss". Sau đó, tạo đối tượng "SachMuonVe" mới với các thông tin đã đọc và thêm nó vào danh sách "danhSachSach".

Nếu không phải các trường hợp trên, tức là "phuongthuc" không là "doc" hoặc "muon", tạo đối tượng "Sach" mới với các thông tin đã đọc và thêm nó vào danh sách "danhSachSach".

Sau khi đọc hết dữ liệu trong tệp tin, đóng tệp tin bằng cách gọi phương thức "close()" của đối tượng "inputFile".

Nếu không thể mở tệp tin, in ra thông báo lỗi và kết thúc hàm.*/
cout << "\n\n\t====Danh sach sach cho phep muon doc====" << endl;
for (const auto& sach : danhSachSach) {
    SachMuonDoc* sachMuonDoc = dynamic_cast<SachMuonDoc*>(sach);
    SachMuonVe* sachMuonVe = dynamic_cast<SachMuonVe*>(sach);
    if (sachMuonDoc != nullptr) {
        sachMuonDoc->hienThiThongTin();
        cout << "--------------------" << endl;
        cout << endl;
    }
}
/*In ra thông báo "====Danh sach sach cho phep muon doc====" trên màn hình.

Sử dụng vòng lặp for-each để duyệt qua từng phần tử trong danh sách sách.

Trong mỗi lần lặp, đoạn code sử dụng dynamic_cast để thử chuyển đổi con trỏ đến đối tượng sách thành con trỏ đến đối tượng "SachMuonDoc" hoặc "SachMuonVe". dynamic_cast được sử dụng để kiểm tra và thực hiện chuyển đổi kiểu động an toàn trong C++.

Nếu chuyển đổi thành công và con trỏ "sachMuonDoc" không trỏ đến nullptr (tức là đối tượng sách là một đối tượng "SachMuonDoc"), đoạn code gọi phương thức "hienThiThongTin()" của đối tượng "SachMuonDoc" để hiển thị thông tin của sách đó trên màn hình. Sau đó, in ra dòng gạch ngang và xuống dòng.

Quá trình lặp lại cho đến khi duyệt qua tất cả các sách trong danh sách.*/
cout << "\n\n\t====Danh sach sach cho phep muon ve====" << endl;
for (const auto& sach : danhSachSach) {
    SachMuonVe* sachMuonVe = dynamic_cast<SachMuonVe*>(sach);
    if(sachMuonVe != nullptr) {
        sachMuonVe->hienThiThongTin();
        cout << "--------------------" << endl;
        cout << endl;
    }
}

//tương tự như cách giải thích cảu phần trên
//tìm kiếm theo tên nhà xuất bản
            string tenTimKiem;
            cout << "Nhap ten tac gia: ";
            getline(cin, tenTimKiem);
            timKiemThongTin(danhSachSach,tenTimKiem);
            cout << endl << endl;


 // Giải phóng bộ nhớ cho các đối tượng sách
    for (Sach* sach : danhSachSach) {
        delete sach;
    }

    return 0;

  
}