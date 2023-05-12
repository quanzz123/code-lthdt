#include<bits/stdc++.h>
using namespace std;
class Vector {
    private:
        int n;
        int *v;
    public:
        Vector() {
            n = 0;
            v = NULL;

        }
        Vector(int size);
        Vector(int size, int val);
        Vector(Vector& a);
        ~Vector() {
            delete[] v;
        }
        friend istream operator >>(istream& is, Vector& vec);
        friend ostream operator<<(ostream& os, Vector& vec);
        friend operator+(vector& vec1, Vector& vec2);
};
Vector::Vector(int size) {
    n = size;
    v = new int[n];
    for(int i=0; i<n; i++) {
        v[i] = 0;
    }

}
Vector::Vector(int size, int val) {
    n = size;
    v = new int[n];
    for(int i=0; i<n; i++) {
        v[i] = val;
    }
}
Vector::Vector(Vector& a) {
    n = a.n;
    v = new int[n];
    for(in i=0; i<n; i++) {
        v[i] = a.v[i];
    }
}
istream& operator>>(istream& is, Vector& vec) {
    cout << "Enter: " << endl;
    for(int i=0; i<vec.n; i++) {
        is >> vec.v[i];
    }
    return is;
}
ostream& operator<<(ostream& os, Vector& vec) {
    os << "[";
    for(int i=0; i<vec.n; i++) {
        os << vec.v[i];
        if(i < vec.n) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
Vector operator+(vector& vec1, Vector& vec2) {
    if(vec1.n == vec2.n) {
        Vector c(vec1.n);
        for(int i=0; i<c.n ; i++) {
            c.v[i] = vec1.v[i] + vec2.v[i];
        }
        return c;
    } else {
        cout << " Vectors must have same size to add";
    }
}
int main() {

}