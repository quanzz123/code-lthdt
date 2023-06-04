/*Bài 3: Đọc các số nguyên từ file input.txt biết
+ Chỉ có một dòng duy nhất chứa các số nguyên và mỗi số nguyên các nhau bởi một dấu phẩy
vd: input.txt
1,3,5,9
==========yêu cầu================
-File UCLN.txt lưu 1 so nguyên alf ướcchung lơn nhất cảu tất cả các phần tử của mảng
-File BCNN.txt lưu một số nguyên là bội chung nhỏ nhất cua tất cả các phẩn thử của mảng
* Gợi ý: 
-nghiên cứu các dùng hàm seekg() hoặc suy nghĩ cách giải quyết vướng mắc của bài toán trên*/
#include <bits/stdc++.h>
using namespace std;
//ghi file
void ghi_file(int a[], int &n, ifstream& F) {
    while(!F.eof()) {
        F >> a[n];
        char c;
        F >> c;
        n++;
    }
    
}
//xuatfile
void xuatfile(int a[], int &n, ofstream &F) {
    for(int i = 0; i < n; i++) {
        F << a[i] << " ";
        cout << a[i] << " ";
    }
}
//tim ucll của hai số nguyên
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int tim_ucln(int a[], int n) {
    int x = a[0];
    for(int i = 1; i < n; i++) {
        x = gcd(x, a[i]);
    }
    return x;
}
//Tìm bội chung nhỏ nhất cảu hai số nguyên
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}
//tìm bội chung nhỏ nhất của mảng sô nguyên trong file
int tim_bcnn(int a[], int n) {
    int x = a[0];
    for(int i=1; i<n; i++) {
        x = lcm(x,a[i]);
    }
    return x;
}


int main() {
    int arr[100];
    int n=0;
    ifstream F_in;
    F_in.open("input.txt", ios_base::in);
    ghi_file(arr, n, F_in);
    F_in.close();

    cout << "danh sach cac so nguyen: " << endl;
    ofstream F_out_UCLN;
    F_out_UCLN.open("UCLN.txt", ios_base::out);
    xuatfile(arr, n, F_out_UCLN);
    
    F_out_UCLN << endl << "ucln: " <<  tim_ucln(arr,n);
    F_out_UCLN.close();
    ofstream F_out_BCNN;
    F_out_BCNN.open("BCNN.txt", ios_base::out);
    F_out_BCNN << "bcnn: " << tim_bcnn(arr, n);
    F_out_BCNN.close();


}