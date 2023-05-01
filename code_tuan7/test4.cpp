#include<bits/stdc++.h>
using namespace std;
int main() {
    cout << setw(10) << left << "stt" << "\t";
    cout << "|";
    cout << setw(10) << left << "gio" << "\t";
    cout << "|";
    cout << setw(10) << left << "phut" << "\t";
    cout << "|";
    cout << setw(10)  << left << "giay" << "\t";
    cout << "|";
    cout << endl;

    for(int i=0; i<5; i++) {
    cout << setw(10) << left << i+11 << "\t";
    cout << "|";
    cout << setw(10) << left << i+12 << "\t";
    cout << "|";
    cout << setw(10) << left << i+12 << "\t";
    cout << "|";
    cout << setw(10)  << left << i+13 << "\t";
    cout << "|";
    cout << endl;
    }
}