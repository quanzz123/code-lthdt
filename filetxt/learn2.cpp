#include <iostream>
#include <fstream>
using namespace std;
int main() {

    //=============ĐỌC FILE=============;
    // CÚ PHÁP : iftream <Tên Biến File>;

    //Bước1 :  KHAI BÁO RA BIẾN ĐỂ ĐỌC FILE
    ifstream Filein; //Khai báo một biến thuộc kiểu ifstream để đọc dữ liệu từ tệp file
    // BƯỚC 2: MỞ FILE CẦN ĐỌC DỮ LIỆU
    // Biến file ở đây là Filein.open(<Tên đường đãn file cần mở để đọc>, <chế độ đọc file>);
    Filein.open("learn_in2.txt", ios_base :: in);
    // Lệnh kiểm tra xem có mo file ra thanh cong hay không
    if(Filein.fail() == true) {
        cout << "\nfile khong ton tai!";
        return 0; // kết thúc chương trình
    }
    cout << "\nfile co ton tai" << endl;

    //Bước 3 : XỬ LÍ FILE - DỌC DỮ LIỆU TỪ FILE
    int x;
    int y;
    // đọc dữ liệu từ file
    Filein >> x; // đọc số nguyên đầu tiên tùe file
    Filein >> y; // đọc số nguyên tiếp theo từ file
    cout << "\nTong cua hai so nguyen trong file: " << x + y << endl;
    Filein.close();
    //=============GHI DÚ LIỆU TỪ FILE================
    ofstream Fileout;
    Fileout.open("learn_out2.txt", ios_base :: out);//khi chua có file thì nó sẽ tự tạo ra file
    Fileout << x+y; // lấy x +y rồi ghi vào txt

    // Bước 4: ĐÓNG FILE SAU KHI ĐÃ XỬ LÍ.
    Fileout.close();
    system("pause");
}