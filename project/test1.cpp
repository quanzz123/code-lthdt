#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inputFile("printer.txt"); // Mở tệp văn bản để đọc dữ liệu

if (inputFile.is_open()) {
    string line;
    int count = 0;

    while (getline(inputFile, line)) {
        if (line.find("Officer") != string::npos) {
            // Bắt đầu một thông tin Officer mới
            officers[count].input(); // Gọi hàm input để nhập dữ liệu cho officer

            count++;
        }
    }

    inputFile.close(); // Đóng tệp sau khi hoàn thành đọc dữ liệu
}
else {
    cout << "Unable to open file";
}

}