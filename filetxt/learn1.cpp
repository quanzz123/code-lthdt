//Cách đọc file trong c++
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file;
    file.open("learn_in1.txt");
    //viết trong dây
    int a[20];
    int n;
    file >> n;
    cout << "gia tri cua mang la : " << n << endl;
    for(int i=0; i<n; i++) {
        file >> a[i];
    }
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    
    
    file.close();
    ofstream file1 ("learn_out1.txt");
        for(int i=n=1; i >=0; i--) {
            file1 << a[i] << " ";
    }
file1.close();
    


    //ghi file
    return 0;
}