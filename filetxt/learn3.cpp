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
    Filein.open("learn_in3.txt", ios_base::in);
    if(Filein.fail() == true) {
        cout << "\nFile khon ton tai" << endl;
        return 0;
    }
    int arr[100];
    int n;
    Filein >> n;
    for(int i = 0; i < n; i++) {
        Filein >> arr[i]; // đọc lần lượt các phần tử có trong mảng.
    }

    //ghi dữ liệu vô file;
    ofstream Fileout;
    Fileout.open("learn_out3.txt", ios_base :: out);
    for(int i = 0; i < n; i++) {
        if(Kiem_tra_so_nguyen_to(arr[i])) {
            Fileout << arr[i] << " ";
        }
    }
       Fileout.close();

}