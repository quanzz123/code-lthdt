#include <iostream>
using namespace std;

int main() {
    // Khai báo kích thước của mảng
    int n = 5;

    // Sử dụng toán tử new để tạo mảng
    int* arr = new int[n];

    // Gán giá trị cho từng phần tử trong mảng
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Sử dụng mảng
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ đã được cấp phát cho mảng
    delete[] arr;

    return 0;
}
