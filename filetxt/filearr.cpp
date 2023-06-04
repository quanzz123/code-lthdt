/*đọc một dãy só nguyen từ file van bản
+ đọc dãy số này từ trong tệp văn bản
input.txt
1 2 3 4 5
Ghi vào file kết quả các số nguyên tố có trong dãy số*/
//đoc 1 số nguyên từ file input
// ghi dữ liệu ra file output
/* + ghi vào true - nếu số nguyên đó là số nguyên tố
   + ghi vào false - nếu  số nguyên đó không phải là số nguyên tô */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <fstream>

// hàm kiểm tra số nguyên tố
bool Kiem_tra_so_nguyen_to(int n) {
   if(n <= 1) {
    return false;
   }
   for(int i=2; i <= sqrt(n); i++) {
    if(n % i == 0) {
        return false;
    }
   }
   return true;
}
int main() {
    //đoc dư liệ từ file;
    ifstream Filein;
    Filein.open("input_filearr.txt", ios_base::in);
    if(Filein.fail() == true) {
        cout << "\nFile khon ton tai" << endl;
        return 0;
    }
    int arr[100];
    int i=0;
    int dem = 0;
    // đọc mảng số nguyên từ file bằng cách kiẻm tra xem con trỏ chỉ vị đã trỏ đến cuối file chưa
    while(!Filein.eof()) { // eof = end of file
        Filein >> arr[i];
        i++;
        dem++;
    }

    //ghi dữ liệu vô file;
    ofstream Fileout;
    Fileout.open("output_filearr.txt", ios_base :: out);
    for(int i = 0; i < dem; i++) {
        if(Kiem_tra_so_nguyen_to(arr[i]) == true) {
            cout << arr[i] << " ";
            Fileout << arr[i] << " ";
        }
    }
       Fileout.close();

}