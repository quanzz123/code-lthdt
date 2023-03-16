#include"iostream"
using namespace std;
int a=5;
int main()
{
    int a=10, b=15;
    ::a+=b++ + a++;
    cout << "\ngia tri cua a= " << a << "\ngia tri cua ::a= " << ::a << endl;
    system("PAUSE");
    return 0;

}
/* kết quả sau là:
a=11 và ::a=31
giải thích: 
- sau khi ++a thì a =11
::a+=b++ + ++a
(5+15)+1 + (10+1)= 31 *\ c