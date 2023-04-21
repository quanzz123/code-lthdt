#include<bits/stdc++.h>
using namespace std;
class Matrix {
    private:
        int m,n;
        int **v;
    public:
        Matrix() {
           n = 0;
           m = 0;
           v = NULL; 
        }
        Matrix(int row, int col);
        Matrix(int row, int col, int **val);
        void add();
        void print();
        ~Matrix();
        Matrix(Matrix &a);
        void operator=(Matrix &a);
        friend istream& operator>>(istream& is, Matrix& mat);
        friend ostream& operator<<(ostream& os, Matrix& mat);
};
// https://github.com/bogdanmacovei/OOP-Matrix-Class
//https://github.com/Agil1ty/Matrix