#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Lớp Nhân viên
class Employee {
    friend class HRManager;
protected:
    string fullName;
    string employeeID;
    string dateOfBirth;
    string gender;
    string hometown;
    string joinDate;
    double salary;

public:
    Employee(const string& name, const string& id, const string& dob, const string& gen, const string& town, const string& jDate, double sal)
        : fullName(name), employeeID(id), dateOfBirth(dob), gender(gen), hometown(town), joinDate(jDate), salary(sal) {}

    virtual void displayInformation() const {
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
    OfficeEmployee(const string& name, const string& id, const string& dob, const string& gen, const string& town, const string& jDate, double sal, const string& room)
        : Employee(name, id, dob, gen, town, jDate, sal), officeRoom(room) {}

    string getOfficeRoom() const {
        return officeRoom;
    }
};

// Lớp Công nhân sản xuất kế thừa từ lớp Nhân viên
class FactoryWorker : public Employee {
private:
    int productionTarget;

public:
    FactoryWorker(const string& name, const string& id, const string& dob, const string& gen, const string& town, const string& jDate, double sal, int target)
        : Employee(name, id, dob, gen, town, jDate, sal), productionTarget(target) {}

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
    vector<Employee*> employees;
    vector<Employee*> departedEmployees;

public:
    virtual ~HRManager() {
        // Giải phóng bộ nhớ của các đối tượng nhân viên và nhân viên đã chuyển đi
        for (const auto& emp : employees) {
            delete emp;
        }

        for (const auto& departedEmp : departedEmployees) {
            delete departedEmp;
        }
    }

    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void addDepartedEmployee(Employee* emp) {
        departedEmployees.push_back(emp);
    }

    void displayEmployees() const {
        for (const auto& emp : employees) {
            emp->displayInformation();
            cout << "---------------------" << endl;
        }
    }

    int countFemaleOffDays(const string& day) const {
        int count = 0;
        for (const auto& emp : employees) {
            FactoryWorker* factoryWorker = dynamic_cast<FactoryWorker*>(emp);
            if (factoryWorker != nullptr && factoryWorker->isRestDay(day)) {
                count++;
            }
        }
        return count;
    }

    void displayDepartedEmployees() const {
        cout << "Departed Employees:" << endl;
        for (const auto& emp : departedEmployees) {
            emp->displayInformation();
            cout << "---------------------" << endl;
        }
    }
   void displayEmployeesOnOffDays(const HRManager& hrManager, const string& day);
};
void HRManager::displayEmployeesOnOffDays(const HRManager& hrManager, const string& day) {
    cout << "Employees on " << day << ":" << endl;

    for (const auto& emp : hrManager.employees) {
        FactoryWorker* factoryWorker = dynamic_cast<FactoryWorker*>(emp);
        if (factoryWorker != nullptr && factoryWorker->isRestDay(day)) {
            emp->displayInformation();
            cout << "---------------------" << endl;
        }
    }
}
int main() {
    HRManager hrManager;

    // Đọc dữ liệu từ tệp văn bản và thêm nhân viên vào Quản lý nhân sự
    ifstream inputFile("employees.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            // Phân tích dòng dữ liệu từ tệp văn bản
            // Giả sử mỗi dòng có định dạng: Loại nhân viên,Họ và tên,Mã nhân viên,Ngày sinh,Giới tính,Quê quán,Ngày vào công ty,Lương,Phòng (đối với Nhân viên văn phòng),Định mức sản phẩm (đối với Công nhân sản xuất)
            // Có thể tùy chỉnh phương thức này phù hợp với định dạng dữ liệu của tệp văn bản của bạn
            size_t pos = 0;
            string employeeType = line.substr(0, line.find(','));
            line.erase(0, line.find(',') + 1);
            
            if (employeeType == "OfficeEmployee") {
                pos = line.find(',');
                string name = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Tương tự, phân tích các thuộc tính khác từ dòng dữ liệu
                pos = line.find(',');
                string id = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(',');
                string dob = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(',');
                string gen = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(',');
                string town = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(',');
                string jDate = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(',');
                int sal = stod(line.substr(0, pos));
                line.erase(0, pos + 1);

                string room = line;

                OfficeEmployee* officeEmployee = new OfficeEmployee(name, id, dob, gen, town, jDate, sal, room);
                hrManager.addEmployee(officeEmployee);
            } else if (employeeType == "FactoryWorker") {
                pos = line.find(',');
                string name = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Tương tự, phân tích các thuộc tính khác từ dòng dữ liệu
                    pos = line.find(',');
                    string id = line.substr(0, pos);
                    line.erase(0, pos + 1);

                    pos = line.find(',');
                    string dob = line.substr(0, pos);
                     line.erase(0, pos + 1);

                    pos = line.find(',');
                    string gen = line.substr(0, pos);
                    line.erase(0, pos + 1);

                    pos = line.find(',');
                    string town = line.substr(0, pos);
                    line.erase(0, pos + 1);

                    pos = line.find(',');
                    string jDate = line.substr(0, pos);
                    line.erase(0, pos + 1);

                    pos = line.find(',');
                    int sal = stod(line.substr(0, pos));
                    line.erase(0, pos + 1);

                    int target = stoi(line); // Không cần phân tích thêm
                FactoryWorker* factoryWorker = new FactoryWorker(name, id, dob, gen, town, jDate, sal, target);
                hrManager.addEmployee(factoryWorker);
            }

            // Các trường thông tin khác sẽ tùy thuộc vào loại nhân viên
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }

    // Hiển thị thông tin nhân viên
    cout << "\n\n\t===thong tin nhan vien========" << endl;
    hrManager.displayEmployees();

    // Thống kê số nhân viên nữ đăng ký nghỉ theo thứ trong tuần
    int femaleOffDaysMonday = hrManager.countFemaleOffDays("Monday");
    int femaleOffDaysWednesday = hrManager.countFemaleOffDays("Wednesday");
    cout << "Number of female workers taking off on Monday: " << femaleOffDaysMonday << endl;
    cout << "Number of female workers taking off on Wednesday: " << femaleOffDaysWednesday << endl;




    // Hiển thị thông tin nhân viên nghỉ vào ngày thứ Hai và Thứ Tư
    cout << "\n\n\t======Employees on Monday and Wednesday==========" << endl;
    hrManager.displayEmployeesOnOffDays(hrManager, "Monday");
    hrManager.displayEmployeesOnOffDays(hrManager, "Wednesday");

    // Hiển thị thông tin nhân viên chuyển đi
    hrManager.displayDepartedEmployees();

    return 0;
}
