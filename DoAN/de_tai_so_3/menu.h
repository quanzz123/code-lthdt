

class QuanLiMenu {
private:
    vector<ThietBi*> danhsachThietBi;

public:
    void run() {
        int luachon1;
        while (true) {
            clearScreen();

            cout << "\n\n\t=======MENU=========" << endl;
            cout << "\n1.Them thiet bi tu file thietbi.txt" << endl;
            cout << "\n2.Hien thi thong tin cac thiet bi" << endl;
            cout << "\n3.Thong ke va tim kiem" << endl;
            cout << "\n0.Thoat chuong trinh" << endl;
            cout << "===========================" << endl;
            cout << "moi nhap lua chon:  ";
            cin >> luachon1;

            switch (luachon1) {
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

private:
    void clearScreen() {
        // Function to clear the screen
    }

    void themThietBiTuFile() {
        ifstream inputfile("thietbi.txt");
        if (inputfile.is_open()) {
            string line;
            while (getline(inputfile, line)) {
                // Parse the line and create objects based on the data
                // ...

                // Add the created object to the danhSachThietBi vector
                // danhsachThietBi.push_back(...);
            }
            inputfile.close();
            cout << "\nNhap du lieu thanh cong" << endl;
            _getch();
        } else {
            cout << "\nKhong the mo file" << endl;
            _getch();
        }
    }

    void hienThiThongTinThietBi() {
        clearScreen();
        int luachon2;
        while (luachon2 != 0) {
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

            switch (luachon2) {
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

    void hienThiMayTinh() {
        clearScreen();
        cout << "\n\n\t====Thong tin cac loai may tinh======" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayTinh* maytinh = dynamic_cast<MayTinh*>(thietbi);
            if (maytinh != nullptr) {
                maytinh->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayInDenTrang() {
        clearScreen();
        cout << "\n\n\t=====Thong tin cac loai may in den trang=====" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayInDenTrang* mayindentrang = dynamic_cast<MayInDenTrang*>(thietbi);
            if (mayindentrang != nullptr && dynamic_cast<MayInMau*>(thietbi) == nullptr) {
                mayindentrang->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayInMau() {
        clearScreen();
        cout << "\n\n\t====Thong tin cac loai may in mau======" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayInMau* mayinmau = dynamic_cast<MayInMau*>(thietbi);
            if (mayinmau != nullptr) {
                mayinmau->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayQuet() {
        clearScreen();
        cout << "\n\n\t===Hien thi thong tin cac loai may quet========" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayQuet* mayquet = dynamic_cast<MayQuet*>(thietbi);
            if (mayquet != nullptr) {
                mayquet->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void hienThiMayChieu() {
        clearScreen();
        cout << "\n\n\t======Hien thi thong tin cac loai may chieu====" << endl;
        for (const auto& thietbi : danhsachThietBi) {
            MayThamChieu* maythamchieu = dynamic_cast<MayThamChieu*>(thietbi);
            if (maythamchieu != nullptr) {
                maythamchieu->hienThiThongTin();
                cout << endl;
            }
        }
        _getch();
        clearScreen();
    }

    void thongKeVaTimKiem() {
        int luachon3;

        while (luachon3 != 0) {
            clearScreen();
            cout << "\n\n\t===Thong ke và tim kiem===\n\n" << endl;
            cout << "\n1.Thong ke" << endl;
            cout << "\n2.Tim kiem" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon: ";
            cin >> luachon3;

            switch (luachon3) {
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

    void thongKe() {
        int luachon3_1;

        while (luachon3_1 != 0) {
            clearScreen();
            cout << "\n\n\t===Thong ke===\n\n" << endl;
            cout << "\n1.Thong ke danh sach thiet bi thanh ly" << endl;
            cout << "\n2.Thong ke danh sach thiet bi dang su dung" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> luachon3_1;

            switch (luachon3_1) {
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

    void thongKeDanhSachThanhLy() {
        clearScreen();
        vector<ThietBi*> danhsachthanhly;

        for (ThietBi* tb : danhsachThietBi) {
            if (tb->daDenThoiHanThanhLy()) {
                danhsachthanhly.push_back(tb);
            }
        }

        cout << "\n\n\t======Thong ke danh sach thiet bi thanh ly======\n\n" << endl;

        for (ThietBi* tb : danhsachthanhly) {
            tb->hienThiThongTin();
            cout << endl;
        }

        _getch();
        clearScreen();
    }

    void thongKeDanhSachDangSuDung() {
        clearScreen();
        vector<ThietBi*> danhsachdangsuadung;

        for (ThietBi* tb : danhsachThietBi) {
            if (!tb->daDenThoiHanThanhLy()) {
                danhsachdangsuadung.push_back(tb);
            }
        }

        cout << "\n\n\t======Thong ke danh sach thiet bi dang su dung======\n\n" << endl;

        for (ThietBi* tb : danhsachdangsuadung) {
            tb->hienThiThongTin();
            cout << endl;
        }

        _getch();
        clearScreen();
    }

    void timKiem() {
        int luachon3_2;

        while (luachon3_2 != 0) {
            clearScreen();
            cout << "\n\n\t===Tim kiem===\n\n" << endl;
            cout << "\n1.Tim kiem thiet bi theo ma" << endl;
            cout << "\n2.Tim kiem thiet bi theo ten" << endl;
            cout << "\n0.Thoat" << endl;
            cout << "===================" << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> luachon3_2;

            switch (luachon3_2) {
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

    void timKiemTheoMa() {
        clearScreen();
        string ma;
        cout << "\n\n\t===Tim kiem thiet bi theo ma===\n" << endl;
        cout << "Nhap ma thiet bi can tim: ";
        cin >> ma;

        bool found = false;

        for (ThietBi* tb : danhsachThietBi) {
            // Compare the ma of the tb object with the input ma
            // If found, display the information and set found to true
            // ...
        }

        if (!found) {
            cout << "\nKhong tim thay thiet bi voi ma " << ma << endl;
        }

        _getch();
        clearScreen();
    }

    void timKiemTheoTen() {
        clearScreen();
        string ten;
        cout << "\n\n\t===Tim kiem thiet bi theo ten===\n" << endl;
        cout << "Nhap ten thiet bi can tim: ";
        cin.ignore();
        getline(cin, ten);

        bool found = false;

        for (ThietBi* tb : danhsachThietBi) {
            // Compare the ten of the tb object with the input ten
            // If found, display the information and set found to true
            // ...
        }

        if (!found) {
            cout << "\nKhong tim thay thiet bi voi ten " << ten << endl;
        }

        _getch();
        clearScreen();
    }
};

