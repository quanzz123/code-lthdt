#include <iostream>
#include <cstring>
using namespace std;

class Vector {
private:
    int n;
    int* v;

public:
    Vector() {
        n = 0;
        v = NULL;
    }

    Vector(int size) {
        n = size;
        v = new int[n];
        memset(v, 0, n * sizeof(int));
    }

    Vector(int size, int* arr) {
        n = size;
        v = new int[n];
        memcpy(v, arr, n * sizeof(int));
    }

    Vector(const Vector& obj) {
        n = obj.n;
        v = new int[n];
        memcpy(v, obj.v, n * sizeof(int));
    }

    ~Vector() {
        delete[] v;
    }

    Vector& operator=(const Vector& obj) {
        if (this == &obj) {
            return *this;
        }

        delete[] v;

        n = obj.n;
        v = new int[n];
        memcpy(v, obj.v, n * sizeof(int));

        return *this;
    }

    void add() {
        v = new int[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap v[" << i << "]: ";
            cin >> v[i];
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector v1;
    Vector v2(5);
    int arr[] = {1, 2, 3, 4, 5};
    Vector v3(5, arr);

    cout << "Nhap so phan tu cho vector 1: ";
    cin >> v1.n;
    v1.add();

    cout << "Vector 1: ";
    v1.print();

    cout << "Vector 2: ";
    v2.print();

    cout << "Vector 3: ";
    v3.print();

    Vector v4(v3);
    cout << "Vector 4 (sao chep tu vector 3): ";
    v4.print();

    Vector v5;
    v5 = v2;
    cout << "Vector 5 (gan bang vector 2): ";
    v5.print();

    return 0;
}
