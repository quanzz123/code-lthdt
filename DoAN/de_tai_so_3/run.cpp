#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
using namespace std;

// Lớp cơ sở Thiết bị
class ThietBi
{
protected:
     string tenThietBi;
     string maThietBi;
     int ngayNhap;
     int thangNhap;
     int namNhap;
     string trangThai;

public:
     ThietBi(string ten, string ma, int ngay, int thang, int nam, string trangthai)
         : tenThietBi(ten), maThietBi(ma), ngayNhap(ngay), thangNhap(thang), namNhap(nam), trangThai(trangthai) {}

     virtual void hienThiThongTin()
     {
          cout << "|" << setw(15) << tenThietBi;                                                          // 12
          cout << "|" << setw(11) << maThietBi;                                                           // 11
          cout << "|" << setw(2) << ngayNhap << "/" << setw(2) << thangNhap << "/" << setw(4) << namNhap; // 9
          cout << "|" << setw(15) << trangThai;
     }

     bool daDenThoiHanThanhLy()
     {
          return trangThai == "thanh ly";
     }
     string getname()
     {
          return tenThietBi;
     }
     string getID()
     {
          return maThietBi;
     }
     int getngay()
     {
          return ngayNhap;
     }
     int getthang()
     {
          return thangNhap;
     }
     int getnam()
     {

          return namNhap;
     }
     string gettrangthai()
     {
          return trangThai;
     }
};

// Lớp Máy tính
class MayTinh : public ThietBi
{
protected:
     string mauSac;
     int tocDo;
     int boNho;

public:
     MayTinh(string ten, string ma, int ngay, int thang, int nam, string trangthai, string mau, int tocdo, int bonho)
         : ThietBi(ten, ma, ngay, thang, nam, trangthai), mauSac(mau), tocDo(tocdo), boNho(bonho) {}

     void hienThiThongTin()
     {
          ThietBi::hienThiThongTin();
          cout << "|" << setw(7) << mauSac; // 7
          cout << "|" << setw(6) << tocDo;  // 6
          cout << "|" << setw(6) << boNho << "|";
          ; // 6
     }
     string getmausac()
     {
          return mauSac;
     }
     int getbonho()
     {
          return boNho;
     }
     int gettocdo()
     {
          return tocDo;
     }
};

// Lớp Máy in
class MayIn : public ThietBi
{
protected:
     int soDiemAnh;

public:
     MayIn(string ten, string ma, int ngay, int thang, int nam, string trangthai, int sodiem)
         : ThietBi(ten, ma, ngay, thang, nam, trangthai), soDiemAnh(sodiem) {}
};

// Lớp Máy in đen trắng
class MayInDenTrang : public MayIn
{
public:
     MayInDenTrang(string ten, string ma, int ngay, int thang, int nam, string trangthai, int sodiem)
         : MayIn(ten, ma, ngay, thang, nam, trangthai, sodiem) {}

     void hienThiThongTin()
     {
          MayIn::hienThiThongTin();
          cout << "|" << setw(11) << soDiemAnh << "|";
     }
     int getsodiemanh()
     {
          return soDiemAnh;
     }
};

// Lớp Máy in màu
class MayInMau : public MayInDenTrang
{
protected:
     int soMau;

public:
     MayInMau(string ten, string ma, int ngay, int thang, int nam, string trangthai, int sodiem, int somau)
         : MayInDenTrang(ten, ma, ngay, thang, nam, trangthai, sodiem), soMau(somau) {}

     void hienThiThongTin()
     {
          MayInDenTrang::hienThiThongTin();
          cout << setw(6) << soMau << "|";
     }
     int getsomau()
     {
          return soMau;
     }
};
// Lớp Máy quét
class MayQuet : public ThietBi
{
protected:
     int tocDoQuet;

public:
     MayQuet(string ten, string ma, int ngay, int thang, int nam, string trangthai, int tocdoscan)
         : ThietBi(ten, ma, ngay, thang, nam, trangthai), tocDoQuet(tocdoscan) {}

     void hienThiThongTin()
     {
          ThietBi::hienThiThongTin();
          cout << "|" << setw(11) << tocDoQuet << "|";
     }
     int gettocsoquet()
     {
          return tocDoQuet;
     }
};

// Lớp Máy tham chiếu
class MayThamChieu : public ThietBi
{
protected:
     int gioThamChieuToiDa;

public:
     MayThamChieu(string ten, string ma, int ngay, int thang, int nam, string trangthai, int giothamchieu)
         : ThietBi(ten, ma, ngay, thang, nam, trangthai), gioThamChieuToiDa(giothamchieu) {}

     void hienThiThongTin()
     {
          ThietBi::hienThiThongTin();
          cout << "|" << setw(8) << gioThamChieuToiDa << "|"; // maxhours
     }
     int getgiochieutoida()
     {
          return gioThamChieuToiDa;
     }
};

class QuanLiMenu
{
private:
     vector<ThietBi *> danhsachThietBi;

public:
     void run()
     {
          int luachon1;
          while (true)
          {
               clearScreen();

               cout << "\n\n\t=======MENU=========" << endl;
               cout << "\n1.Them thiet bi tu file thietbi.txt" << endl;
               cout << "\n2.Hien thi thong tin cac thiet bi" << endl;
               cout << "\n3.Thong ke va tim kiem" << endl;
               cout << "\n0.Thoat chuong trinh" << endl;
               cout << "===========================" << endl;
               cout << "moi nhap lua chon:  ";
               cin >> luachon1;

               switch (luachon1)
               {
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
     void giaiphong()
     {
          for (const auto &thietbi : danhsachThietBi)
          {
               delete thietbi;
          }
          danhsachThietBi.clear();
     }

private:
     void clearScreen()
     {
          // Function to clear the screen
#ifdef _WIN32
          std::system("cls");
#else
          std::system("clear");
#endif
     }

     void themThietBiTuFile()
     {
          ifstream inputfile("thietbi.txt");
          if (inputfile.is_open())
          {
               string line;
               while (getline(inputfile, line))
               {
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
                    if (ten == "MayTinh")
                    {

                         getline(ss, mau, ',');

                         ss >> tocdo;
                         ss.ignore();
                         ss >> bonho;
                         danhsachThietBi.push_back(new MayTinh(ten, ma, ngay, thang, nam, trangthai, mau, tocdo, bonho));
                    }
                    else if (ten == "MayInDenTrang")
                    {
                         ss >> sodiem;
                         danhsachThietBi.push_back(new MayInDenTrang(ten, ma, ngay, thang, nam, trangthai, sodiem));
                    }
                    else if (ten == "MayinMau")
                    {

                         ss >> sodiem;
                         ss.ignore();
                         ss >> somau;
                         danhsachThietBi.push_back(new MayInMau(ten, ma, ngay, thang, nam, trangthai, sodiem, somau));
                    }
                    else if (ten == "MayQuet")
                    {
                         ss >> tocdoscan;
                         danhsachThietBi.push_back(new MayQuet(ten, ma, ngay, thang, nam, trangthai, tocdoscan));
                    }
                    else if (ten == "MayThamChieu")
                    {
                         ss >> giothamchieu;
                         danhsachThietBi.push_back(new MayThamChieu(ten, ma, ngay, thang, nam, trangthai, giothamchieu));
                    }
               }
               inputfile.close();
               cout << "\nNhap du lieu thanh cong" << endl;
               _getch();
          }
          else
          {
               cout << "\nKhong the mo file" << endl;
               _getch();
          }
     }

     void hienThiThongTinThietBi()
     {
          clearScreen();
          int luachon2;
          while (luachon2 != 0)
          {
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

               switch (luachon2)
               {
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

     void hienThiMayTinh()
     {
          clearScreen();
          cout << "\n\n\t\t\t====THONG TIN CAC LOAI MAY TINH======\n\n"
               << endl;
          cout << (char)218 << setfill('-') << setw(76) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(7) << "COL";
          cout << "|" << setw(6) << "SPE";
          cout << "|" << setw(6) << "MEM"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(7) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &thietbi : danhsachThietBi)
          {
               MayTinh *maytinh = dynamic_cast<MayTinh *>(thietbi);
               if (maytinh != nullptr)
               {
                    maytinh->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(7) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void hienThiMayInDenTrang()
     {
          clearScreen();

          cout << "\n\n\t\t=====THONG TIN CAC LOAI MAY IN DEN TRANG=====\n\n"
               << endl;
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &thietbi : danhsachThietBi)
          {
               MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang *>(thietbi);
               if (mayindentrang != nullptr && dynamic_cast<MayInMau *>(thietbi) == nullptr)
               {
                    mayindentrang->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void hienThiMayInMau()
     {
          clearScreen();
          cout << "\n\n\t====THONG TIN CAC LOAI MAY IN MAU======" << endl;
          cout << (char)218 << setfill('-') << setw(73) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX";
          cout << "|" << setw(6) << "COLS"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &thietbi : danhsachThietBi)
          {
               MayInMau *mayinmau = dynamic_cast<MayInMau *>(thietbi);
               if (mayinmau != nullptr)
               {
                    mayinmau->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void hienThiMayQuet()
     {
          clearScreen();
          cout << "\n\n\t===HIEN THI THONG TIN CAC LOAI MAY QUET========" << endl;
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "SSPE"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &thietbi : danhsachThietBi)
          {
               MayQuet *mayquet = dynamic_cast<MayQuet *>(thietbi);
               if (mayquet != nullptr)
               {
                    mayquet->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void hienThiMayChieu()
     {
          clearScreen();
          cout << "\n\n\t======HIEN THI THONG TIN CAC LOAI MAY CHIEU====" << endl;
          cout << (char)218 << setfill('-') << setw(63) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(8) << "MAXH"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(8) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &thietbi : danhsachThietBi)
          {
               MayThamChieu *maythamchieu = dynamic_cast<MayThamChieu *>(thietbi);
               if (maythamchieu != nullptr)
               {
                    maythamchieu->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(8) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void thongKeVaTimKiem()
     {
          int luachon3;

          while (luachon3 != 0)
          {
               clearScreen();
               cout << "\n\n\t===Thong ke và tim kiem===\n\n"
                    << endl;
               cout << "\n1.Thong ke" << endl;
               cout << "\n2.Tim kiem" << endl;
               cout << "\n0.Thoat" << endl;
               cout << "===================" << endl;
               cout << "Moi nhap lua chon: ";
               cin >> luachon3;

               switch (luachon3)
               {
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

     void thongKe()
     {
          int luachon3_1;

          while (luachon3_1 != 0)
          {
               clearScreen();
               cout << "\n\n\t===Thong ke===\n\n"
                    << endl;
               cout << "\n1.Thong ke danh sach thiet bi thanh ly" << endl;
               cout << "\n2.Thong ke danh sach thiet bi dang su dung" << endl;
               cout << "\n0.Thoat" << endl;
               cout << "===================" << endl;
               cout << "Moi nhap lua chon cua ban: ";
               cin >> luachon3_1;

               switch (luachon3_1)
               {
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

     void thongKeDanhSachThanhLy()
     {
          clearScreen();
          vector<ThietBi *> danhsachthanhly;

          for (ThietBi *tb : danhsachThietBi)
          {
               if (tb->daDenThoiHanThanhLy())
               {
                    danhsachthanhly.push_back(tb);
               }
          }

          // cout << "\n\n\t======Thong ke danh sach thiet bi thanh ly======\n\n" << endl;

          // for (ThietBi* tb : danhsachthanhly) {
          //     tb->hienThiThongTin();
          //     cout << endl;
          // }
          cout << "\n\n\t\t\t==== DANH SACH MAY TINH BI THANH LY ====\n\n";
          cout << (char)218 << setfill('-') << setw(76) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(7) << "COL";
          cout << "|" << setw(6) << "SPE";
          cout << "|" << setw(6) << "MEM"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(7) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachthanhly)
          {
               MayTinh *maytinh = dynamic_cast<MayTinh *>(tb);
               if (maytinh != nullptr)
               {
                    maytinh->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(7) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t\t==== DANH SACH MAU IN DEN TRANG BI THANH LY====\n\n";
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachthanhly)
          {
               MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang *>(tb);
               if (mayindentrang != nullptr && dynamic_cast<MayInMau *>(tb) == nullptr)
               {
                    mayindentrang->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t====== THONG KE DANH SACH MAY IN MAU BI THANH LY======\n\n";
          cout << (char)218 << setfill('-') << setw(73) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX";
          cout << "|" << setw(6) << "COLS"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachthanhly)
          {
               MayInMau *mayinmau = dynamic_cast<MayInMau *>(tb);
               if (mayinmau != nullptr)
               {
                    mayinmau->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t========= THONG KE DANH SACH MAY QUET BI THANH LY ========\n\n";
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "SSPE"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachthanhly)
          {
               MayQuet *mayquet = dynamic_cast<MayQuet *>(tb);
               if (mayquet != nullptr)
               {
                    mayquet->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t======= THONG KE DANH SACH MAY CHIEU BI THANH LY ========\n\n";
          cout << (char)218 << setfill('-') << setw(63) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(8) << "MAXH"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(8) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachthanhly)
          {
               MayThamChieu *maychieu = dynamic_cast<MayThamChieu *>(tb);
               if (maychieu != nullptr)
               {
                    maychieu->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(8) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void thongKeDanhSachDangSuDung()
     {
          clearScreen();
          vector<ThietBi *> danhsachdangsuadung;

          for (ThietBi *tb : danhsachThietBi)
          {
               if (!tb->daDenThoiHanThanhLy())
               {
                    danhsachdangsuadung.push_back(tb);
               }
          }

          cout << "\n\n\t\t\t==== DANH SACH MAY TINH DANG SU DUNG ====\n\n";
          cout << (char)218 << setfill('-') << setw(76) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(7) << "COL";
          cout << "|" << setw(6) << "SPE";
          cout << "|" << setw(6) << "MEM"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(7) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachdangsuadung)
          {
               MayTinh *maytinh = dynamic_cast<MayTinh *>(tb);
               if (maytinh != nullptr)
               {
                    maytinh->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(7) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t\t==== DANH SACH MAU IN DEN TRANG DANG SU DUNG====\n\n";
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachdangsuadung)
          {
               MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang *>(tb);
               if (mayindentrang != nullptr && dynamic_cast<MayInMau *>(tb) == nullptr)
               {
                    mayindentrang->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t====== THONG KE DANH SACH MAY IN MAU DANG SU DUNG======\n\n";
          cout << (char)218 << setfill('-') << setw(73) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX";
          cout << "|" << setw(6) << "COLS"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachdangsuadung)
          {
               MayInMau *mayinmau = dynamic_cast<MayInMau *>(tb);
               if (mayinmau != nullptr)
               {
                    mayinmau->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t========= THONG KE DANH SACH MAY QUET DANG SU DUNG ========\n\n";
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "SSPE"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachdangsuadung)
          {
               MayQuet *mayquet = dynamic_cast<MayQuet *>(tb);
               if (mayquet != nullptr)
               {
                    mayquet->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }
          cout << "\n\n\t======= THONG KE DANH SACH MAY CHIEU DANG SU DUNG ========\n\n";
          cout << (char)218 << setfill('-') << setw(63) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(8) << "MAXH"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(8) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (ThietBi *tb : danhsachdangsuadung)
          {
               MayThamChieu *maychieu = dynamic_cast<MayThamChieu *>(tb);
               if (maychieu != nullptr)
               {
                    maychieu->hienThiThongTin();
                    cout << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(8) << "-"
                         << "|" << endl; // scanspeed
                    cout << setfill(' ');
               }
          }

          _getch();
          clearScreen();
     }

     void timKiem()
     {
          int luachon3_2;

          while (luachon3_2 != 0)
          {
               clearScreen();
               cout << "\n\n\t===Tim kiem===\n\n"
                    << endl;
               cout << "\n1.Tim kiem thiet bi theo ma" << endl;
               cout << "\n2.Tim kiem thiet bi theo ten" << endl;
               cout << "\n0.Thoat" << endl;
               cout << "===================" << endl;
               cout << "Moi nhap lua chon cua ban: ";
               cin >> luachon3_2;

               switch (luachon3_2)
               {
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

     void timKiemTheoMa()
     {
          clearScreen();
          string ma;
          string loaithietbi;
          cout << "\n\n\t===Tim kiem thiet bi theo ma===\n"
               << endl;
          cout << "Nhap loai thiet bi: ";
          cin >> loaithietbi;
          cout << endl;
          cout << "Nhap ma thiet bi can tim: ";
          cin >> ma;

          bool found = false;

          for (ThietBi *tb : danhsachThietBi)
          {
               // Compare the ma of the tb object with the input ma
               // If found, display the information and set found to true
               // ...
               if (loaithietbi == "MayTinh")
               {
                    if (tb->getID() == ma)
                    {
                         tb->hienThiThongTin();
                         cout << endl;
                         found = true;
                         break;
                    }
               }
          }

          if (!found)
          {
               cout << "\nKhong tim thay thiet bi voi ma " << ma << endl;
          }

          _getch();
          clearScreen();
     }

     void timKiemTheoTen()
     {
          clearScreen();
          string ten;
          cout << "\n\n\t===Tim kiem thiet bi theo ten===\n"
               << endl;
          cout << "Nhap ten thiet bi can tim: ";
          cin.ignore();
          getline(cin, ten);

          bool found = false;

          for (const auto &tb : danhsachThietBi)
          {
               // Compare the ten of the tb object with the input ten
               // If found, display the information and set found to true
               // ...
               if (tb->getname() == ten)
               {
                    if (ten == "MayTinh")
                    {
                         inBangMayTinh();
                         cout << endl;
                         break;
                    } else if(ten == "MayInDenTrang") {
                         inBangMayInDenTrang();
                         cout << endl;
                         break;
                    } else if(ten == "MayinMau") {
                         inBangMayInMau();
                         cout << endl;
                         break;
                    } else if(ten == "MayQuet") {
                         inBangMayQuet();
                         cout << endl;
                         break;
                    } else if(ten == "MayThamChieu") {
                         inBangMayChieu();
                         cout << endl;
                         break;
                    } else {
                         cout << "\nKhong tim thay thiet bi voi ten " << ten << endl;
                    }
                    
                    found = true;
               }
          }

          if (!found)
          {
               cout << "\nKhong tim thay thiet bi voi ten " << ten << endl;
          }

          // _getch();
          // clearScreen();
     }
     void inBangMayTinh()
     {
          // In tiêu đề của bảng

          cout << "\n\n\t\t\t====THONG TIN CAC LOAI MAY TINH======\n\n"
               << endl;
          cout << (char)218 << setfill('-') << setw(76) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(7) << "COL";
          cout << "|" << setw(6) << "SPE";
          cout << "|" << setw(6) << "MEM"
               << "|" << endl;
          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(7) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(6) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &tb : danhsachThietBi)
          {
               if (dynamic_cast<MayTinh *>(tb) != nullptr)
               {
                    MayTinh *maytinh = dynamic_cast<MayTinh *>(tb);
                    // In thông tin từng thiết bị vào từng cột
                    if(maytinh != nullptr) {
                         maytinh->hienThiThongTin();
                         cout << endl;
                    }
                    
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(7) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|";
                    cout << setfill(' ');
                    cout << setfill('-') << setw(6) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
          _getch();
          clearScreen();
     }

     void inBangMayInDenTrang()
     {
          clearScreen();
          // In tiêu đề của bảng
          cout << "\n\n\t\t=====THONG TIN CAC LOAI MAY IN DEN TRANG=====\n\n"
               << endl;
          cout << (char)218 << setfill('-') << setw(66) << "-" << (char)191 << endl;
          cout << setfill(' ');
          cout << "|" << setw(15) << "NAME";
          cout << "|" << setw(11) << "ID";
          cout << "|" << setw(10) << "DATE";
          cout << "|" << setw(15) << "STATIC";
          cout << "|" << setw(11) << "PIX"
               << "|" << endl;

          cout << "|";
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(10) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(15) << "-"
               << "|";
          cout << setfill(' ');
          cout << setfill('-') << setw(11) << "-"
               << "|" << endl;
          cout << setfill(' ');
          for (const auto &tb : danhsachThietBi)
          {
               if (dynamic_cast<MayInDenTrang *>(tb) != nullptr && dynamic_cast<MayInMau *>(tb) == nullptr)
               {
                    MayInDenTrang *mayindentrang = dynamic_cast<MayInDenTrang *>(tb);
                    // In thông tin từng thiết bị vào từng cột
                    cout << "|" << setw(15) << mayindentrang->getname();
                    cout << "|" << setw(11) << mayindentrang->getID();
                    cout << "|" << setw(2) << mayindentrang->getngay() << "/" << setw(2)
                         << mayindentrang->getthang() << "/" << setw(4) << mayindentrang->getnam();
                    cout << "|" << setw(15) << mayindentrang->gettrangthai();
                    cout << "|" << setw(11) << mayindentrang->getsodiemanh() << "|" << endl;
                    cout << "|";
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // name
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|"; // id
                    cout << setfill(' ');
                    cout << setfill('-') << setw(10) << "-"
                         << "|"; // date
                    cout << setfill(' ');
                    cout << setfill('-') << setw(15) << "-"
                         << "|"; // static
                    cout << setfill(' ');
                    cout << setfill('-') << setw(11) << "-"
                         << "|" << endl;
                    cout << setfill(' ');
               }
          }
           _getch();
          clearScreen();
     }
     void inBangMayInMau()
     {
          clearScreen();
          for (const auto &tb : danhsachThietBi)
          {
               if (dynamic_cast<MayInMau *>(tb) != nullptr)
               {
                    MayInMau *mayinmau = dynamic_cast<MayInMau *>(tb);
                    cout << "|" << setw(15) << mayinmau->getname();
                    cout << "|" << setw(11) << mayinmau->getID();
                    cout << "|" << setw(2) << mayinmau->getngay() << "/" << setw(2)
                         << mayinmau->getthang() << "/" << setw(4) << mayinmau->getnam();
                    cout << "|" << setw(15) << mayinmau->gettrangthai();
                    cout << "|" << setw(6) << mayinmau->getsomau() << "|" << endl;
               }
          }
           _getch();
          clearScreen();
     }
     void inBangMayQuet()
     {
          clearScreen();
          for (const auto &tb : danhsachThietBi)
          {
               if (dynamic_cast<MayQuet *>(tb) != nullptr)
               {
                    MayQuet *mayquet = dynamic_cast<MayQuet *>(tb);
                    cout << "|" << setw(15) << mayquet->getname();
                    cout << "|" << setw(11) << mayquet->getID();
                    cout << "|" << setw(2) << mayquet->getngay() << "/" << setw(2)
                         << mayquet->getthang() << "/" << setw(4) << mayquet->getnam();
                    cout << "|" << setw(15) << mayquet->gettrangthai();
                    cout << "|" << setw(11) << mayquet->gettocsoquet() << "|" << endl;
               }
          }
           _getch();
          clearScreen();
     }
     void inBangMayChieu()
     {
          clearScreen();
          for (const auto &tb : danhsachThietBi)
          {
               if (dynamic_cast<MayThamChieu *>(tb) != nullptr)
               {
                    MayThamChieu *maychieu = dynamic_cast<MayThamChieu *>(tb);
                    cout << "|" << setw(15) << maychieu->getname();
                    cout << "|" << setw(11) << maychieu->getID();
                    cout << "|" << setw(2) << maychieu->getngay() << "/" << setw(2)
                         << maychieu->getthang() << "/" << setw(4) << maychieu->getnam();
                    cout << "|" << setw(15) << maychieu->gettrangthai();
                    cout << "|" << setw(8) << maychieu->getgiochieutoida() << "|" << endl;
               }
          }
           _getch();
          clearScreen();
     }
};

int main()
{
     QuanLiMenu menu;
     menu.run();
     menu.giaiphong();
     return 0;
}