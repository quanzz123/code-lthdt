/*Tạo lớp SACH để quản lý sách trong thư viện.
 Yêu cầu mỗi loại sách cầnlưu trữ các thông tin sau: 
 Tên sách, Tác giả, Số lượng, Năm xuất bản.
 Xây dựng các phương thức để nhập và hiển thị các thông tin về sách.
 Viết chương trình chính thực hiện:
 - Nhập thông tin cho n cuốn sách.
 - Hiển thị thông tin về những cuốn sách có số lượng lớn nhất*/

 #include<bits/stdc++.h>
 using namespace std;
 class SACH {
    private:
        string TenSach;
        string TacGia;
        int SoLuong;
        int Namxb;
    public:
        SACH(string TenSach = "", string TacGia = "", int SoLuong = 0, int Namxb = 0) {
            this->TenSach = TenSach;
            this->TacGia  = TacGia;
            this->SoLuong = SoLuong;
            this->Namxb = Namxb;
        }
        void Nhap_data() {
            cout << "Nhap ten sach: ";
            cin.ignore();
            getline(cin,TenSach);
            cout << "Nhap ten tac gia: ";
            cin.ignore();
            getline(cin, TacGia);
            cout << "Nhap so luong sach: ";
            cin >> SoLuong;
            cout << "Nhap nam xuat ban: ";
            cin >> Namxb;
            cin.ignore();
        }
        int getSoLuong() {
            return SoLuong;
        }
        void in_data() {
            cout << setw(20) <<left << TenSach;
            cout << setw(10) << right << TacGia;
            cout << setw(15) << right << SoLuong;
            cout << setw(15) << right << Namxb << endl;
            cout << setfill('-') << setw(60) << "-" <<endl;
            cout << setfill(' ');
        }
 };
 int main() {
    int n;
    cout << "\nNhap so luong luong cuon sach: ";
    cin >> n;
    cin.ignore();

    SACH* ds = new SACH[n];
    for(int i=0; i<n; i++) {
        cout << "\nNhap thong tin cuon sach thu " << i+1 << ": " << endl;
        ds[i].Nhap_data();
        cout << endl;
    }

    cout <<"\n\n\t\t\t===DANH SACH TEN CAC CUON SACH===\n\n";
    cout << setw(20) <<left << "Ten Sach";
            cout << setw(10) << right << "Tac Gia";
            cout << setw(15) << right << "So Luong";
            cout << setw(15) << right << "Nam xuat ban"<< endl;
            cout << setfill('-') << setw(60) << "-" <<endl;
            cout << setfill(' ');
    for(int i=0; i<n; i++) {
        ds[i].in_data();
    }
 }