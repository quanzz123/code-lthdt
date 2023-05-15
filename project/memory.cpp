/*// Thêm các thiết bị vào danh sách

int main() {
vector<Device*> devices;
devices.push_back(new Printer("Máy in 1", "PR001", "01/05/2023", "Đen trắng", 20, 256, 1200));
devices.push_back(new ColorPrinter("Máy in màu 1", "CP001", "01/06/2023", "Màu", 10, 128, 1200, 16));
devices.push_back(new Scanner("Máy quét 1", "SC001", "01/07/2023", 30));
devices.push_back(new Projector("Máy chiếu 1", "PJ001", "01/08/2023", 2000));

int choice;
do {
    // Hiển thị menu
    cout << "===== Quản lý Thiết bị Công nghệ thông tin =====" << endl;
    cout << "1. Hiển thị thông tin các thiết bị" << endl;
    cout << "2. Thống kê theo tiêu chí" << endl;
    cout << "3. Tìm kiếm thiết bị hết hạn sử dụng" << endl;
    cout << "0. Thoát" << endl;
    cout << "================================================" << endl;
    cout << "Vui lòng chọn: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Hiển thị thông tin các thiết bị
            cout << "===== Thông tin các thiết bị =====" << endl;
            for (Device* device : devices) {
                device->displayInfo();
                cout << "------------------------------" << endl;
            }
            break;
        case 2:
            // Thống kê theo tiêu chí
            cout << "===== Thống kê theo tiêu chí =====" << endl;
            cout << "1. Thống kê theo loại Máy in" << endl;
            cout << "2. Thống kê theo loại Máy quét" << endl;
            cout << "3. Thống kê theo loại Máy chiếu" << endl;
            cout << "0. Quay lại" << endl;
            cout << "===================================" << endl;
            cout << "Vui lòng chọn: ";
            cin >> choice;
                            switch (choice) {
                case 1:
                    // Thống kê theo loại Máy in
                    cout << "===== Thống kê theo loại Máy in =====" << endl;
                    for (Device* device : devices) {
                        if (dynamic_cast<Printer*>(device) != nullptr) {
                            device->displayInfo();
                            cout << "------------------------------" << endl;
                        }
                    }
                    break;
                case 2:
                    // Thống kê theo loại Máy quét
                    cout << "===== Thống kê theo loại Máy quét =====" << endl;
                    for (Device* device : devices) {
                        if (dynamic_cast<Scanner*>(device) != nullptr) {
                            device->displayInfo();
                            cout << "------------------------------" << endl;
                        }
                    }
                    break;
                case 3:
                    // Thống kê theo loại Máy chiếu
                    cout << "===== Thống kê theo loại Máy chiếu =====" << endl;
                    for (Device* device : devices) {
                        if (dynamic_cast<Projector*>(device) != nullptr) {
                            device->displayInfo();
                            cout << "------------------------------" << endl;
                        }
                    }
                    break;
                case 0:
                    // Quay lại menu trước
                    break;
                default:
                    cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
                    break;
            }
            break;
        case 3:
            // Tìm kiếm thiết bị hết hạn sử dụng
            cout << "===== Danh sách thiết bị hết hạn sử dụng =====" << endl;
            bool hasExpiredDevices = false;
            for (Device* device : devices) {
                if (device->getIsExpired()) {
                    device->displayInfo();
                    hasExpiredDevices = true;
                    cout << "------------------------------" << endl;
                }
            }
            if (!hasExpiredDevices) {
                cout << "Không có thiết bị nào hết hạn sử dụng." << endl;
            }
            break;
        case 0:
            // Thoát chương trình
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
            break;
    }
} while (choice != 0);

// Giải phóng bộ nhớ và kết thúc chương trình
for (Device* device : devices) {
    delete device;
}

return 0;*/

/*#include <fstream>

// ...

case 1:
{
    int displayChoice;
    cout << "===== Hiển thị thông tin các thiết bị =====" << endl;
    cout << "1. Hiển thị lên màn hình" << endl;
    cout << "2. Hiển thị trong tệp" << endl;
    cout << "0. Quay lại" << endl;
    cout << "===========================================" << endl;
    cout << "Vui lòng chọn: ";
    cin >> displayChoice;

    switch (displayChoice)
    {
        case 1:
            // Hiển thị thông tin lên màn hình
            for (Device* device : devices)
            {
                device->displayInfo();
                cout << "------------------------------" << endl;
            }
            break;
        case 2:
        {
            // Hiển thị thông tin trong tệp
            ofstream outputFile("thongtin.txt");
            if (outputFile.is_open())
            {
                for (Device* device : devices)
                {
                    device->displayInfo();
                    outputFile << "------------------------------" << endl;
                }
                outputFile.close();
                cout << "Thông tin đã được lưu vào tệp 'thongtin.txt'" << endl;
            }
            else
            {
                cout << "Không thể mở tệp 'thongtin.txt' để ghi." << endl;
            }
            break;
        }
        case 0:
            // Quay lại menu trước
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
            break;
    }
    break;
}*/


/*#include <iostream>
#include <vector>
#include <string>

// ...

void addDevice(std::vector<Device*>& devices) {
    int deviceType;
    std::cout << "===== Nhập thông tin thiết bị mới =====" << std::endl;
    std::cout << "1. Máy in đen trắng" << std::endl;
    std::cout << "2. Máy in màu" << std::endl;
    std::cout << "3. Máy quét" << std::endl;
    std::cout << "4. Máy chiếu" << std::endl;
    std::cout << "0. Quay lại" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Vui lòng chọn loại thiết bị: ";
    std::cin >> deviceType;

    switch (deviceType) {
        case 1: {
            std::string name, code, date;
            bool isExpired;
            int speed, memory, dpi;

            std::cout << "Nhập tên thiết bị: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Nhập mã thiết bị: ";
            std::cin >> code;
            std::cout << "Nhập ngày nhập: ";
            std::cin >> date;
            std::cout << "Nhập tình trạng (1 - Đang sử dụng, 0 - Đến thời hạn thanh lý): ";
            std::cin >> isExpired;
            std::cout << "Nhập tốc độ: ";
            std::cin >> speed;
            std::cout << "Nhập bộ nhớ: ";
            std::cin >> memory;
            std::cout << "Nhập số điểm ảnh: ";
            std::cin >> dpi;

            Device* newDevice = new BlackWhitePrinter(name, code, date, isExpired, speed, memory, dpi);
            devices.push_back(newDevice);

            std::cout << "Thêm máy in đen trắng thành công!" << std::endl;
            break;
        }
        case 2: {
            // Tương tự như trường hợp Máy in đen trắng, bạn có thể thêm mã lệnh để nhập thông tin cho Máy in màu
            // ...
            break;
        }
        case 3: {
            // Tương tự như trường hợp Máy in đen trắng, bạn có thể thêm mã lệnh để nhập thông tin cho Máy quét
            // ...
            break;
        }
        case 4: {
            // Tương tự như trường hợp Máy in đen trắng, bạn có thể thêm mã lệnh để nhập thông tin cho Máy chiếu
            // ...
            break;
        }
        case 0:
            // Quay lại menu trước
            break;
        default:
            std::cout << "Lựa ch*/
/*case 2: {
    std::string name, code, date;
    bool isExpired;
    int speed, memory, dpi, colorCount;

    std::cout << "Nhập tên thiết bị: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Nhập mã thiết bị: ";
    std::cin >> code;
    std::cout << "Nhập ngày nhập: ";
    std::cin >> date;
    std::cout << "Nhập tình trạng (1 - Đang sử dụng, 0 - Đến thời hạn thanh lý): ";
    std::cin >> isExpired;
    std::cout << "Nhập tốc độ: ";
    std::cin >> speed;
    std::cout << "Nhập bộ nhớ: ";
    std::cin >> memory;
    std::cout << "Nhập số điểm ảnh: ";
    std::cin >> dpi;
    std::cout << "Nhập số màu: ";
    std::cin >> colorCount;

    Device* newDevice = new ColorPrinter(name, code, date, isExpired, speed, memory, dpi, colorCount);
    devices.push_back(newDevice);

    std::cout << "Thêm máy in màu thành công!" << std::endl;
    break;
}
case 3: {
    std::string name, code, date;
    bool isExpired;
    int speed, scanSpeed;

    std::cout << "Nhập tên thiết bị: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Nhập mã thiết bị: ";
    std::cin >> code;
    std::cout << "Nhập ngày nhập: ";
    std::cin >> date;
    std::cout << "Nhập tình trạng (1 - Đang sử dụng, 0 - Đến thời hạn thanh lý): ";
    std::cin >> isExpired;
    std::cout << "Nhập tốc độ quét: ";
    std::cin >> speed;
    std::cout << "Nhập tốc độ quét trang: ";
    std::cin >> scanSpeed;

    Device* newDevice = new Scanner(name, code, date, isExpired, speed, scanSpeed);
    devices.push_back(newDevice);

    std::cout << "Thêm máy quét thành công!" << std::endl;
    break;
}
case 4: {
    std::string name, code, date;
    bool isExpired;
    int projectorHours;

    std::cout << "Nhập tên thiết bị: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Nhập mã thiết bị: ";
    std::cin >> code;
    std::cout << "Nhập ngày nhập: ";
    std::cin >> date;
    std::cout << "Nhập tình trạng (1 - Đang sử dụng, 0 - Đến thời hạn thanh lý): ";
    std::cin >> isExpired;
    std::cout << "Nhập số giờ chiếu tối đa: ";
    std::cin >> projectorHours;

    Device* newDevice = new Projector(name, code, date, isExpired, projectorHours);
    devices.push_back(newDevice);

    std::cout << "Thêm máy chiếu thành công!" << std::endl;
    break;
}*/




