#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Date // Class Ngay Sinh
{
    private :
        int day;
        int month;
        int year;
    public :
        void InputDate();
        void OutputDate();
};

class Person // Class Nhan Vien
{
    private :
        string perNumber;
        string perName;
        Date dt; // Goi class ngay sinh tro thanh 1 bien trong class Nhan Vien
    public :
        void InputPerson();
        void OutputPerson();
};

void Date::InputDate()
{
    cin>>day;
    cin>>month;
    cin>>year;
}
void Date::OutputDate()
{
    cout<<"\t"<<day<<" / "<<month<<" / "<<year<<endl;
}
void Person::InputPerson()
{
    ///freopen("data.txt","r",stdin); // Cach Nhap tu file data.txt trong project
    cin>>perNumber;
    cin>>perName;
    dt.InputDate(); // goi ham Nhap ngay sinh
}
void Person::OutputPerson()
{
    cout<<endl;
    cout<<"\t"<<perNumber<<endl;
    cout<<"\t"<<perName<<endl;
    dt.OutputDate(); // goi ham Xuat ngay sinh
}
int main()
{
    Person p1; // khai bao doi tuong nhan vien p1
    p1.InputPerson();
    p1.OutputPerson();

    return 0;
}
