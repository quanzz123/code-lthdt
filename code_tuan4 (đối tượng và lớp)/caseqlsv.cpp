#include"case_qlsv.h"
int main() {
    int chon;
    vector<SinhVien> ds;
    do {
        LuaChon();
        cout << "nhap lua chon: ";
        cin >> chon;

        switch (chon) 
        {
        case 1:
            string HoTen;
            int Tuoi;
            float DiemTrungBinh;
            cout << "nhap ho ten sinh vien:";
            cin>> HoTen;
            cout << "nhap tuoi sinh vien: ";
            cin >> Tuoi;
            cout << "nhap diem trung binh cua sinh vien: ";
            cin >> DiemTrungBinh;
            SinhVien sv(HoTen, Tuoi, DiemTrungBinh);
            ds.push_back(sv);
            break;
        
        default:
            break;
        }
    } while(chon != 3);
}