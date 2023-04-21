#include"libary6_3.h"
Matrix :: ~Matrix() {
    for(int i=0; i<n; i++){
        delete[] v[i];
    }
    delete v;
}
istream& operator>>(istream& is, Matrix& mat) {
    cout << "nhap so hang: ";
    is >> mat.n;
    cout << "nhap so cot: ";
    is >> mat.m;
    mat.v = new int*[mat.n];
    for(int i=0; i<mat.n; i++) {
        mat.v[i] = new int[mat.m];
        for(int j=0; j<mat.m; j++) {
            cout << "Nhap phanthu thu [" << i << "][" << j << "]";
            is >> mat.v[i][j]; 
        }
    }
    return is;
}
ostream& operator<<(ostream& os, Matrix& mat) {
    for(int i=0; i<mat.n; i++) {
        for(int j=0; j<mat.m; j++) {
            os << mat.v[i][j] << "  ";
        }
        cout << endl;
    }
}
Matrix :: Matrix(int row, int col) {
     n = row;
     m = col;
     v = new int*[n];
     for(int i=0; i<n; i++) {
        v[i] = new int[m];
        for(int j=0; j<m; j++) {
            v[i][j] = 0;
        }
     }
}
Matrix :: Matrix(int row, int col, int val) {
    n = row;
    m = col;
    v = new int*[n];
    for(int i=0; i<n; i++) {
        v[i] = new int[m];
        for(int j=0; j<n; j++) {
            v[i][j] = val;
        }
    }
}
Matrix :: Matrix(Matrix &a) {
    n = a.n;
    m = a.m;
    v = new int*[n];
    for(int i=0; i<n; i++) {
        v[i] = new int[m];
        for(int j=0; j<m; j++) {
            v[i][j] = a.v[i][j];
        }
     }
}
void Matrix :: operator=(Matrix &a) {
    n = a.n;
    m = a.m;
    v = new int*[n];
    for(int i=0; i<a.n; i++) {
        v[i] = new int[a.m];
        for(int j=0; j<a.m; j++) {
            v[i][j] = a.v[i][j];
        } 
    }
}
void Matrix :: print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
}
int main() {
    Matrix a;
    cin >> a;
    cout << a;
}