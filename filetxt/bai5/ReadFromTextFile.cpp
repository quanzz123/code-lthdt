#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string name;
    int age;
    float score;

public:
    Student(const string &name, int age, float score)
        : name(name), age(age), score(score) {}

    string getName() const
    {
        return name;
    }

    void setName(const string &newName)
    {
        name = newName;
    }

    int getAge() const
    {
        return age;
    }

    void setAge(int newAge)
    {
        age = newAge;
    }

    float getSalary() const
    {
        return score;
    }

    void setSalary(float newSalary)
    {
        score = newSalary;
    }
};

int main()
{
    ifstream file("students.txt"); // Mở tệp văn bản "students.txt"

    if (!file.is_open())
    { // Kiểm tra xem tệp đã được mở thành công hay chưa
        cout << "Không thể mở tệp!" << endl;
        return 1;
    }

    vector<Student> students; // Mảng các đối tượng Student

    string line;
    while (getline(file, line))
    { // Đọc từng dòng trong tệp
        string name;
        int age;
        float score;

        // Sử dụng các phép cắt chuỗi hoặc phân tích để trích xuất thông tin từ dòng
        // Ví dụ: nếu dòng có định dạng "John Smith,20,1000.50"
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);
        if (commaPos1 != string::npos && commaPos2 != string::npos)
        {
            name = line.substr(0, commaPos1);
            age = stoi(line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1));
            score = stof(line.substr(commaPos2 + 1));

            // Tạo đối tượng Student và thêm vào mảng
            students.emplace_back(name, age, score);
        }
    }

    file.close(); // Đóng tệp

    // In thông tin các đối tượng Student trong mảng
    for (const auto &student : students)
    {
        cout << "Name: " << student.getName() << ", Age: "
             << student.getAge() << ", Score: " << student.getSalary() << endl;
    }

    return 0;
}