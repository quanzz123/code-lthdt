#include<bits/stdc++.h>
using namespace std;
class Vector {
    private:
    int n;
    int *v;
    public:
        Vector() { //hàm thiết lập không tham số
            n = 0;
            v = NULL;
        }
        Vector(int number) {  //hàm thiết lập một tham só
            n = number;
            v = new int[n];
            for(int i=0; i<n; i++) {
                v[i] = 0;
            }
        }
        Vector(int number, int value) { //hàm thiết lập hai tham số
            n = number;
            v = new int[n];
            for(int i=0; i<n; i++) {
                v[i]  = value;
            }
        }
        void add() {
            cout << "Nhap" << n << "gia tri: ";
            for(int i=0; i<n; i++) {
                cin >> v[i];
            }
        }
        void operator=(Vector &a) { //phép gán đối tượng
            this->n = a.n;
            this->v = new int[a.n];
            for(int i=0; i<n; i++) {
                this->v[i] = a.v[i];
            }
        }
        Vector(Vector &a) {
            this->n = a.n;
            this->v = new int[a.n];
            for(int i=0; i<n; i++) {
                this->v[i] = a.v[i];
            }

        }
        ~Vector() {
            delete[] v;
        }
        void setN(int num) {
            n = num;
        }
        void print() {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};