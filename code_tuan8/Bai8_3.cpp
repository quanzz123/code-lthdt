#include<bits/stdc++.h>
using namespace std;
class MyAddress {
    protected:
        string province;
        string district;
    public:
        MyAddress(string prov =" ", string dist = " ") {
            province = prov;
            district = dist;
        }
        void input() {
            cout << "Enter province: ";
            fflush(stdin);
            getline(cin, province);
            cout << "Enter di strict: ";
            fflush(stdin);
            getline(cin, district);
        }
        void display() {
            cout << "|" << "\t" << setw(10) << left << province << "\t";
            cout << "|" <<"\t" << setw(10) << left <<  district << "\t";
           
        }
};
class Person : public MyAddress {
    protected:
        string name;
        string phone;
    public:
        Person(string n=" ", string p=" ", string prov=" ", string dist=" ") : MyAddress(prov, dist) {
            name = n;
            phone  = p;
        }
        void input() {
            cout << "Enter name: ";
            fflush(stdin);
            getline(cin, name);
            cout << "Enter Phone: ";
            fflush(stdin);
            getline(cin, phone);
            MyAddress :: input();
        }
        void display() {
            cout << "|" << "\t" << setw(20) << left <<  name << "\t";
            cout << "|" << "\t" << setw(15) << left <<  phone << "\t";
            MyAddress::display();
        }
};
class Officer : public Person {
    protected:
        int salary;
    public:
        Officer(string n=" ", string p=" ", string prov=" ", string dist=" ", int s= 0) : Person(n,p,prov,dist) {
            salary = s;
        }
        void input() {
            Person ::input();
            cout << "Enter salary: ";
            cin >> salary;
            cin.ignore();
        }
        void display() {
            Person ::display();
            cout  << "|" << "\t" <<  setw(5) << left <<  salary << "\t" << "|" << endl;
            cout << "|";
            cout << setfill('-') << setw(15) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(31) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(23) << "-" << "|";
            cout << setfill(' ');
            cout << setfill('-') << setw(15) << "-" << "|" << endl;
            cout << setfill(' ');
        }
        friend operator>(Officer& o1, Officer& o2) {
            return o1.salary > o2.salary;
        }
};
int main() {
    //int n;
    //cout << "Nhap n = ";
    //cin >> n;
    //Officer *o = new Officer[n];
    Officer o[4];
    for(int i=0; i<n; i++) {
        o[i].input();
    }
    cout <<"+" << setfill('-') << setw(135) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << "\t" << setw(5) << left << "stt" << "\t";
    cout << "|" << "\t" << setw(20) << left << "Name" << "\t";
    cout << "|" << "\t" << setw(15) << left << "Phone" << "\t";
    cout << "|" << "\t" << setw(10) << left << "Province" << "\t";
    cout << "|" << "\t" << setw(10) << left << "District" << "\t";
    cout << "|" << "\t" << setw(5) << right << "Salary" << "\t" << "|" << endl;
    cout << "|";
    
    cout << setfill('-') << setw(15) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(31) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(23) << "-" << "|";
    cout << setfill(' ');
    cout << setfill('-') << setw(15) << "-" << "|" << endl;
    cout << setfill(' ');
    for(int i=0; i<n; i++) {
        cout << "|" << "\t" << setw(5) << left << i+1 << "\t";
        o[i].display();
    }
   

    return 0;
}
