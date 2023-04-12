/*Xây dựng lớp cơ sở HOCSINH có các thông tin sau: 
Họ tên, Lớp, điểmtoán, văn, ngoại ngữ và các phương thức nhập, xuất, dữ liệu, tính điểm trungbình.
Viết chương trình chính thực hiện nhập vào một danh sách N học sinh, 
sauđó hiển thị danh sách những học sinh có điểm trung bình >=5.*/

#include<bits/stdc++.h>
using namespace std;
class HOCSINH {
    private:
        string HoTen;
        string Lop;
        float Toan, Van, NgoaiNgu;
    public:
        HOCSINH(string HoTen = "", string Lop = "", float Toan = 0, float Van = 0, float NgoaiNgu = 0) {
            this->HoTen = HoTen;
            this->Lop = Lop;
            this->Toan = Toan;
            this->Van = Van;
            this->NgoaiNgu = NgoaiNgu;
        }
        void Nhap() {
            cout << "Nhap ho va ten cua hoc sinh: ";
            getline(cin, HoTen);
            cout << "Nhap lop: ";
            cin >> Lop
            cout << "Nhap diem mon toan: ";
            cin >> Toan;
            cout << "Nhap diem mon van: ";
            cin >> Van;
            cout << "Nhap diem mon ngoai ngu: ";
            cin >> NgoaiNgu;
            cin.ignore();

        }
        float diemTb(){
            return (Toan + Van + NgoaiNgu) / 3.0;
        }
        void in() {
            cout << setw(20) << left << HoTen;
            cout << setw(10) << right << Lop;
            cout << setw(15) << right << Toan;
            cout << setw(15) << right << Van;
            cout << setw(15) << right << NgoaiNgu;
            cout << setw(15) << right << diemTb() <<endl;
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');

        }
        ~HOCSINH() {
            cout << "\nhuy bo doi tuong HOCSINH" << endl;
        }
};
int main() {
    int n;
    cout << "\nNhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore();
    HOCSINH* ds = new HOCSINH[n];
    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin hoc sinh thu " << i+1 << ": "<< endl;
        ds[i].Nhap();
    }

    cout << "\n\n\t\t\t\t===DANH SACH HOC SINH===\n\n";
    cout << setw(20) << left << "HoTen";
            cout << setw(10) << right << "Lop";
            cout << setw(15) << right <<" Toan";
            cout << setw(15) << right << "Van";
            cout << setw(15) << right << "NgoaiNgu";
            cout << setw(15) << right << "Trung Binh" <<endl;
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');
    for(int i = 0; i < n; i++) {
        ds[i].in();
    }
    cout << "\n\n\t\t\t==DANH SACH HOC SINH CO DIEM TREN 5===\n\n";
    cout << setw(20) << left << "HoTen";
            cout << setw(10) << right << "Lop";
            cout << setw(15) << right <<" Toan";
            cout << setw(15) << right << "Van";
            cout << setw(15) << right << "NgoaiNgu";
            cout << setw(15) << right << "Trung Binh" <<endl;
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');
    for(int i=0; i<n; i++) {
        if(ds[i].diemTb() >= 5.0) {
            ds[i].in();
        }
    }
    return 0;
}