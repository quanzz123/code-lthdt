#include<bits/stdc++.h>
using namespace std;

class ABC{
    private:
        int x,y;
    public:
        void init(int x1=0 , int y1 = 0){
            x = x1;
            y = y1;
        }
        void printf(){
            cout << "(" << x << "," << y << ")";
        }
};