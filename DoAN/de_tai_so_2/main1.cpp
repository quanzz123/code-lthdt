#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Lớp Nhân viên
class Employee {
protected:
    string fullName;
    string employeeID;
    string dateOfBirth;
    string gender;
    string hometown;
    string joinDate;
    double salary;

public:
    Employee() {}

    void setFullName(const string& name) {
        fullName = name;
    }

    void setEmployeeID(const string& id) {
        employeeID = id;
    }

    void setDateOfBirth(const string& dob) {
        dateOfBirth = dob;
    }

    void setGender(const string& gen) {
        gender = gen;
    }

    void setHometown(const string& town) {
        hometown = town;
    }

    void setJoinDate(const string& jDate) {
        joinDate = jDate;
    }

    void setSalary(double sal) {
        salary = sal;
    }

    string getFullName() const {
        return fullName;
    }

    string getEmployeeID() const {
        return employeeID;
    }

    string getDateOfBirth() const {
        return dateOfBirth;
    }

    string getGender() const {
        return gender;
    }

    string getHometown() const {
        return hometown;
    }

    string getJoinDate() const {
        return joinDate;
    }

    double getSalary() const {
        return salary;
    }

    void displayInformation() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Gender: " << gender << endl;
        cout << "Hometown: " << hometown << endl;
        cout << "Join Date: " << joinDate << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Lớp Nhân viên văn phòng kế thừa từ lớp Nhân viên
class OfficeEmployee : public Employee {
private:
    string officeRoom;

public:
    void setOfficeRoom(const string& room) {
        officeRoom = room;
    }

    string getOfficeRoom() const {
        return officeRoom;
    }
};

// Lớp Công nhân sản xuất kế thừa từ lớp Nhân viên
class FactoryWorker : public Employee {
private:
    int productionTarget;

public:
    void setProductionTarget(int target) {
        productionTarget = target;
    }

    int getProductionTarget() const {
        return productionTarget;
    }

    bool isFemale() const {
        return (gender == "Female" || gender == "female");
    }

    bool isRestDay(const string& day) const {
        if (isFemale()) {
            // Các ngày nghỉ bất kỳ trong tuần đối với nhân viên nữ
            // Để đơn giản, giả sử chỉ có Thứ Hai và Thứ Tư là ngày nghỉ
            return (day == "Monday" || day == "Wednesday");
        } else {
            // Ngày Chủ nhật là ngày nghỉ đối với nhân viên nam
            return (day == "Sunday");
        }
    }
};

// Lớp Quản lý nhân sự
class HRManager {
private:
    vector<Employee> employees;

public:
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    void displayEmployees() const {
        for (const auto& emp : employees) {
            emp.displayInformation();
            cout << "---------------------" << endl;
        }
    }

    int countFemaleOffDays(const string& day) const {
        int count = 0;
        for (const auto& emp : employees) {
            if (emp.getGender() == "Female" || emp.getGender() == "female") {
                const FactoryWorker* factoryWorker = dynamic_cast<const FactoryWorker*>(&emp);
                if (factoryWorker != nullptr && factoryWorker->isRestDay(day)) {
                    count++;
                }
            }
        }
        return count;
    }

    void displayDepartedEmployees() const {
        cout << "Departed Employees:" << endl;
        for (const auto& emp : employees) {
            // Assume employees who have no join date are departed
            if (emp.getJoinDate().empty()) {
                emp.displayInformation();
                cout << "---------------------" << endl;
            }
        }
    }
};

int main() {
    HRManager hrManager;

    // Đọc dữ liệu từ tệp txt và thêm nhân viên vào Quản lý nhân sự
    ifstream inputFile("employees.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Employee employee;

            // Phân tích dòng dữ liệu từ tệp txt
            // Giả sử mỗi dòng có định dạng: Họ và tên,Mã nhân viên,Ngày sinh,Giới tính,Quê quán,Ngày vào công ty,Lương
            // Có thể tùy chỉnh phương thức này phù hợp với định dạng dữ liệu của tệp txt của bạn
            size_t pos = 0;
            pos = line.find(',');
            employee.setFullName(line.substr(0, pos));
            line.erase(0, pos + 1);

            // Tương tự, phân tích các thuộc tính khác từ dòng dữ liệu

            hrManager.addEmployee(employee);
        }

        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }

    // Hiển thị thông tin nhân viên
    hrManager.displayEmployees();

    // Thống kê số nhân viên nữ đăng ký nghỉ theo thứ trong tuần (đối với Công nhân sản xuất)
    string dayOfWeek = "Monday";
    int femaleOffDays = hrManager.countFemaleOffDays(dayOfWeek);
    cout << "Female employees off on " << dayOfWeek << ": " << femaleOffDays << endl;

    // Hiển thị thông tin các nhân viên đã chuyển đi (không có ngày vào công ty)
    hrManager.displayDepartedEmployees();

    return 0;
}
