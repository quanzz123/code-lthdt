#include <bits/stdc++.h>
using namespace std;
//khai bao cau trúc lớp ngày tháng năm sinh
class Namsinh {
    private:
        int  ngay;
        int thang;
        int nam;
    public:
        //phương thức getter của ngày
        int getterngay() {
            return ngay;
        }
        //phương thức setter của ngày
        int setterngay(int NGAY) {
            ngay = NGAY;
        }
         //phương thức getter của thang
        int getterthang() {
            return thang;
        }
        //phương thức setter của thang
        int setterthang(int THANG) {
            thang = THANG;
        }
         //phương thức getter của nam
        int getternam() {
            return nam;
        }
        //phương thức setter của nam
        int setternam(int NAM) {
            nam = NAM;
        }
};
//khai bao lớp cha : NhanVien
class NhanVien {
    protected:
        string maNhanVien;
        string tenNhanVien
        Namsinh namsinh;
        string diachi;
        flaot luongcoban;
        float hesoluong;
    public:
        virtual  void Doc_file(ifstream &);
        virtual void xuat();
};
//cài dặt phương thức đọc file của lớp cha
void NhanVien::Doc_file(ifstream &filein) {
    getline(filein, maNhanVien, ',');
    filein.seekg(1,1);// dịch con trỏ chỉ vị tại vị trí hiện tại sang bên phải 1 byte
    getline(filein, tenNhanVien, ',');
    int ngay;
    filein >> ngay;
    Namsinh.setterngay(ngay);
    filein.seekg(1,1);

    int thang;
    filein >> thang;
    Namsinh.setterthang(thang);
    filein.seekg(1,1); //dùng con trỏ chỉ vị để bỏ qua kí tự "/" trong file

    int nam;
    filein >> nam;
    Namsinh.setternam(nam);

    filein.seekg(2,1); // dịch con trỏ chỉ vị sang trái 2 byte bỏ qua dáu "," và khoảng trống
    getline()


}

//khai bao lop con nhan vien lập trình kế thừa nhân vien
class NhanVienLapTrinh : public NhanVien {
    private:
        float tienlamNgoaiGio;
    public:
        void Doc_File(ifstream &);

};
//khai báo lớp con NhanVienThietKe kế thừa lóp cha NhanVien
class NhanVienThietKe : public NhanVien {
    private:
        float tienthuong;
    public:
        void Doc_File(ifstream &);

};
int main() {

}