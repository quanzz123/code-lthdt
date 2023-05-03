#include<bits/stdc++.h>
using namespace std;
class Frac {
    private:
        ///int numerator: tử số, denominator = mẫu số;
        int num, den;
    public:
        Frac(int n=0, int d=0) {
            num = n;
            den = d;
        }
         friend istream& operator>>(istream& is, Frac& f);
            
        friend ostream& operator<<(ostream& os, Frac& f);
        bool operator >= (Frac other) {
        return num*other.den >= den*other.num;
    }
};
istream& operator>>(istream& is, Frac& f) {
    cout << "numerator: ";
    is >> f.num;
    do {
    cout << "denominator: ";
    is >> f.den;
        if(f.den == 0) {
            cout << "the denominator must be no-zero! please re-enter" << endl;

        }
    } while (f.den == 0);
    return is;
}
ostream& operator<<(ostream& os, Frac& f) {
    os << f.num << "/" << f.den;
    return os;
}
int main() {
    Frac arr[3];
    cout << "Enter 3 fraction: " << endl;
    for(int i=0; i<3; i++) {
        cout << "enter fraction " << i+1 << endl;
        cin >> arr[i];
    }
    cout << "output: " << endl;
    for(int i=0; i<3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i=0; i<2; i++) {
        for(int j=i+1; j<3; j++) {
            if(arr[i] >= arr[j]) {
                Frac temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Befor sorting: " << endl;
    for(int i=0; i<3; i++) {
        cout << arr[i] << " ";
    }
}