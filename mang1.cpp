#include <iostream>
using namespace std;

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu thu " << i << ": ";
        cin >> a[i];
    }

    int max = timMax(a, n);

    cout << "Gia tri lon nhat trong mang la: " << max << endl;

    return 0;
}
