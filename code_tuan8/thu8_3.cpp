#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class MyAddress {
protected:
    string province;
    string district;

public:
    MyAddress() {}
    MyAddress(string province, string district) : province(province), district(district) {}

    void input() {
        cout << "Province: ";
        getline(cin, province);
        cout << "District: ";
        getline(cin, district);
    }

    void display() {
        cout << "Province: " << province << endl;
        cout << "District: " << district << endl;
    }
};

class Person : public MyAddress {
protected:
    string name;
    string phone;

public:
    Person() {}
    Person(string province, string district, string name, string phone)
        : MyAddress(province, district), name(name), phone(phone) {}

    void input() {
        MyAddress::input();
        cout << "Name: ";
        getline(cin, name);
        cout << "Phone: ";
        getline(cin, phone);
    }

    void display() {
        MyAddress::display();
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Officer : public Person {
private:
    double salary;

public:
    Officer() {}
    Officer(string province, string district, string name, string phone, double salary)
        : Person(province, district, name, phone), salary(salary) {}

    void input() {
        Person::input();
        cout << "Salary: ";
        cin >> salary;
        cin.ignore(); // ignore the newline character after reading double value
    }

    void display() {
        Person::display();
        cout << "Salary: " << salary << endl;
    }

    bool operator>(const Officer& other) const {
        return salary > other.salary;
    }
};

int main() {
    // Declare an array of 4 Officer objects
    Officer officers[4];

    // Input data for each officer
    for (int i = 0; i < 4; i++) {
        cout << "Enter information for Officer " << i + 1 << ":" << endl;
        officers[i].input();
        cout << endl;
    }

    // Sort the officers based on salary
    sort(officers, officers + 4, greater<Officer>());

    // Display the officers
    cout << "Officers sorted by salary:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Officer " << i + 1 << ":" << endl;
        officers[i].display();
        cout << endl;
    }

    // Open a text file for writing
    ofstream outputFile("officers.txt");

    // Write officer information to the file
    for (int i = 0; i < 4; i++) {
        outputFile << "Officer " << i + 1 << ":" << endl;
        outputFile << "-----------------" << endl;
        officers[i].display();
        outputFile << endl;
    }

    // Close the file
    outputFile.close();

    return 0;
}
