/*Để quản lý điểm thi đầu vào của các thí sinh, cần xây dựng lớpThiSinh gồm thuộc tính và phương thức sau:
- Số báo danh
- Tên thí sinh
- Điểm của 3 môn thi M1, M2, M3
- Nhập thông tin của thí sinh
- Tính tổng điểm 3 môn của thí sinh.
- In thông tin số báo danh, tên, điểm và tổng điểm thi 3 môn
Trên cơ sở lớp đã xây dựng được,viêt chương trình làm các công việc sau
- Nhập danh sách kết quả thi của các thí sinh vào từ bàn phím
- Dưa ra màn hình danh sách thí sinh trúng tuyển (cho phép nhập điểmchuẩn)*/

#include<bits/stdc++.h>
using namespace std;
class ThiSinh {
    private:
        string SBD;
        string Ten;
        float M1, M2, M3;
    public:
        ThiSinh(string SBD="" , string Ten = "", float M1 = 0, float M2 = 0, float M3 = 0) {
            this->SBD = SBD;
            this->Ten = Ten;
            this->M1 = M1;
            this->M2 = M2;
            this->M3 = M3;
        }
        void Nhapthongtin() {
            cout << "Nhap so bao danh thi sinh: ";
            getline(cin, SBD);
            cout << "Nhap ho ten thi sinh: ";
            getline(cin, Ten);
            cout << "Nhap diem mon 1: ";
            cin >> M1;
            cout << "Nhap diem mon 2: ";
            cin >> M2;
            cout << "Nhap diem mon 3: ";
            cin >> M3;
            cin.ignore();
        }
        float sum() {
            return M1 + M2 + M3;
        }
        void inthongtin() {
            cout << setw(20) << left << SBD;
            cout << setw(10) << right << Ten;
            cout << setw(15) << right << M1;
            cout << setw(15) << right << M2;
            cout << setw(15) << right << M3 << endl;
            cout << setfill('-') << setw(75) << "-" << endl;
            cout << setfill(' ');
        }
        ~ThiSinh() {
            cout << "\nHuy bo doi tuong ThiSinh" << endl;
        }

};
int main() {
    int n;
    cout << "\nNhap so luong thi sinh: ";
    cin >> n;
    cin.ignore();

    ThiSinh* ds = new ThiSinh[n];

    for(int i=0; i<n; i++) {
        cout << "\nNhap thong tin thi sinh thu " << i+1 << ": " << endl;
        ds[i].Nhapthongtin();
    }
    cout << "\n\n\t\t===DANH SANH THI SINH===\n\n";
    cout << setw(20) << left << "SBD";
            cout << setw(10) << right << "Ho va Ten";
            cout << setw(15) << right << "Diem M1";
            cout << setw(15) << right << "Diem M2";
            cout << setw(15) << right << "Diem M3" << endl;
            cout << setfill('-') << setw(75) << "-" << endl;
            cout << setfill(' ');
    for(int i=0; i<n; i++) {
        ds[i].inthongtin();
    }
    cout << "\n\n\t\t===DANH SACH THI SINH TRUNG TUUYEN===\n\n";
     cout << setw(20) << left << "SBD";
            cout << setw(10) << right << "Ho va Ten";
            cout << setw(15) << right << "Diem M1";
            cout << setw(15) << right << "Diem M2";
            cout << setw(15) << right << "Diem M3" << endl;
            cout << setfill('-') << setw(75) << "-" << endl;
            cout << setfill(' ');
    for(int i=0; i<n; i++) {
        if(ds[i].sum() >= 24.0) {
            ds[i].inthongtin();
        }
    }
    delete[] ds;
}