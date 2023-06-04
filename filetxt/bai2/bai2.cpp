/*Đọc các só nguyên tu file INPUT.TXT biết 
+ chỉ có 1 dòng duy nhất chứa các số nguyên
VD: 
12 345 135 7 12 1
===yêu cầu===
+Tìm các phần tử là số Amstrong trong mảng só nguyen đó và ghi vào file Amstrong.txt*/
#include <bits/stdc++.h>
using namespace std;

bool isArmstrongNumber(int number) {
    int originalNumber = number;
    int numDigits = 0;
    int armstrongSum = 0;

    // Đếm số chữ số trong số
    while (number != 0) {
        number /= 10;
        numDigits++;
    }

    // Tính tổng lũy thừa của các chữ số
    number = originalNumber;
    while (number != 0) {
        int remainder = number % 10;
        armstrongSum += pow(remainder, numDigits);
        number /= 10;
    }

    // Kiểm tra nếu tổng lũy thừa bằng số ban đầu
    if (armstrongSum == originalNumber) {
        return true;
    } else {
        return false;
    }
}
// hàm kiểm tra số amstrong
bool isArmstrong(int n) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, 3);
        temp /= 10;
    }
    return sum == n;
}
//hàm đọc su liệu từ file
void Doc_file(int a[], int &n, ifstream &filein) {
    while(filein.eof() == false) {
        filein >> a[n];
        n++;
    }
}

// hàm xuất dữ liệu ra file van bẳn
void In_file(int a[], int& n, ofstream& fileout) {
    for(int i=0 ; i<n ; i++) {
        if(isArmstrongNumber(a[i]) == true) {
            fileout << a[i] << " ";
        }
    }

}
// hàm xuất ra màn hình
void xuat(int a[], int n) {
    for(int i=0; i<n; i++) {
        if(isArmstrongNumber(a[i]) == true) {
            cout << a[i] << " ";
        }
    }
}


int main() {
    ifstream filein;
    filein.open("INPUT.txt", ios_base::in);
    int a[100];
    int n=0;
    Doc_file(a,n,filein);
    cout << "\n\n========day so nguyen==========\n\n";
    xuat(a,n);
    filein.close();

    ofstream fileout;
    fileout.open("Amstrong.txt", ios_base::out);
    In_file(a,n,fileout);
    fileout.close();
    system("pause");
    return 0;


}