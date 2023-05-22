/*Trung tâm Thực hành – Thí nghiệm của một trường đại học cần quản lý các thiết bị
công nghệ thông tin, bao gồm: Máy tính, Máy in, Máy quét, Máy chiếu, trong đó
Máy in được chia thành hai loại là Máy in đen trắng và Máy in màu. Các thiết bị
được quản lý các thông tin chung bao gồm: Tên thiết bị, Mã thiết bị, Ngày nhập,
Tình trạng (đang sử dụng được hoặc đến thời hạn thanh lý). Máy in được quản lý
thêm thông tin Màu sắc, Tốc độ, Bộ nhớ; Máy in đen trắng được kế thừa từ Máy
in và bổ sung thêm Số điểm ảnh; Máy in màu được kế thừa từ Máy in đen trắng và
bổ sung thêm Số màu. Máy quét được quản lý thêm Tốc độ quét, Máy chiếu được
quản lý thêm Số giờ chiếu tối đa. Nếu đến thời hạn thanh lý thì thiết bị sẽ được
chuyển vào danh sách thiết bị đề nghị thanh lý. Xây dựng chương trình quản lý
thực hiện được các chức năng cơ bản sau: Quản lý danh sách thiết bị; hiển thị
thông tin các thiết bị; thống kê, tìm kiếm theo các tiêu chí; những thiết bị hết hạn
sử dụng đưa vào danh sách thanh lý*/
#include<bits/stdc++.h>
using namespace std;
class ITDevice {
    protected:
        string name; //ten thiết bị
        string code; //mã thiết bị
        string date; //ngày nhập
        bool status; //tình trang
    public:
        ITDevice(string n=" ", string c=" ", string d=" ") {
            name = n;
            code = c;
            date = d;
            status = false;
        }
        void input() {
            cout << "Nhap ten thiet bi: ";
            fflush(stdin);
            getline(cin, name);
            cout << "Nhap ma thiet bi: ";
            fflush(stdin);
            getline(cin, code);
            cout << "Nhap ngay nhap thiet bi: ";
            fflush(stdin);
            getline(cin, date);
            cout << "Nhap tinh trang (1 - Dang su dung, 0 - Den thoi han thanh ly): ";
            cin >> status;
        }
        void display() {
            cout << "\n\t===danh sach may tinh===\n";
            cout << "Ten thiet bi: " << name << endl;
            cout << "Ma thiet bi: " << code << endl;
            cout << "Ngay nhap thiet bi: " << date << endl;
            cout << "Tinh trang: " << (status ? "het han" : "con han") << endl;
        }
        bool getStatus() {
            return status; // tạo hàm kiểm tra bool để kiểm tra tình trang của sản phẩm, với 1 là vòn hàng và 0 là hết hàng
        }
        string getName() {
            return name; //tao hàm get lấy thêm thiết bị
        }

};
class Printer : public ITDevice {
    protected:
        string color;
        int speed;
        int memory;
    public:
        Printer(string n=" ",string c=" ", string d=" ",string col=" ", int sp=0, int mem=0) :ITDevice(n,c,d) {
            color = col;
            speed = sp;
            memory = mem;
        }
        void input() {
            ITDevice::input();
            cout << "Toc do in: ";
            cin >> speed;
            cout << "Bo nho: ";
            cin >> memory;
        }
        void display() {
            cout << "\n\t===danh sach may in===\n";
            ITDevice::display();
            cout << "Toc do: " << speed << endl;
            cout << "Bo nho: " << memory << endl;
        }
};
// máy in đen trắng
class BWPrinter : public Printer {
    protected:
        int pixels; //điểm ảnh
    public:
        BWPrinter(string n=" ",string c=" ", string d=" ",string col=" ", int sp=0, int mem=0, int pix=0) : Printer(n,c,d,col,sp,mem) {
            pixels = pix;
        }
        void input() {
            Printer::input();
            cout << "so diem anh: ";
            cin >> pixels;
        }
        void display() {
            cout << "\n\t===danh sach may in den trang===\n";
            Printer::display();
            cout << "So diem anh: " << pixels << endl;
        }
};
class ColorPrinter : public BWPrinter {
    protected:
        int colors; // số màu
    public:
        ColorPrinter(string n=" ",string c=" ", string d=" ",string col=" ", int sp=0, int mem=0, int pix=0, int cols=0) : BWPrinter(n,c,d,col,sp,mem,pix) {
            colors = cols;
        }
        void input() {
            BWPrinter::input();
            cout << "so mau: ";
            cin >> colors;
        }
        void display() {
            cout << "\n\t===danh sach may in mau===\n";
            BWPrinter::display();
            cout << "So mau: " << colors << endl;
        }
};
class Scaner : public ITDevice {
    protected:
        int scanspeed;
    public:
        Scaner(string n=" ",string c=" ", string d=" ", string s=" ", int ss=0) : ITDevice(n,c,d) {
            scanspeed = ss;
        }
        void input() {

            ITDevice::input();
            cout << "Nhap toc do quet: ";
            cin >> scanspeed;
        }
        void display() {
            cout << "\n\t===danh sach may quet===\n";
            ITDevice::display();
            cout << "toc do quet: " << scanspeed << endl;
        }
};
class Projector : public ITDevice {
    protected:
        int maxHours;
    public:
        Projector(string n=" ",string c=" ", string d=" ", int ss=0, int mH =0) : ITDevice(n,c,d) {
            maxHours = mH;
        }
        void input() {
            ITDevice::input();
            cout << "Nhap so gio chieu toi da: ";
            cin >> maxHours;
        }
        void display() {
            cout << "\n\tdanh sach may chieu===\n";
            ITDevice::display();
            cout << "so gio max: " << maxHours << endl;
        }
};
int main() {
    vector<ITDevice*> devices;
    int choice;

    while (true) {
        cout << "================= MENU =================" << endl;
        cout << "1. Them thiet bi" << endl;
        cout << "2. Hien thi thong tin cac thiet bi" << endl;
        cout << "3. Thong ke va tim kiem" << endl;
        cout << "4. Danh sach thiet bi het han su dung" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "========================================" << endl;
        cout << "Nhap lu chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int deviceChoice;
                cout << "================= MENU =================" << endl;
                cout << "1. May tinh" << endl;
                cout << "2. May in den trang" << endl;
                cout << "3. May in mau" << endl;
                cout << "4. May quet" << endl;
                cout << "5. May chieu" << endl;
                cout << "0. Quay lai" << endl;
                cout << "========================================" << endl;
                cout << "Nhap lua chon cua ban: ";
                cin >> deviceChoice;

                switch (deviceChoice) {
                    case 1: {
                        ITDevice* newDevice = new ITDevice();
                        newDevice->input();
                        devices.push_back(newDevice);
                        cout << "Tham may tanh thanh cang!" << endl;
                        break;
                    }
                    case 2: {
                        BWPrinter* newDevice = new BWPrinter();
                        newDevice->input();
                        devices.push_back(newDevice);
                        cout << "Them may in đen trang thanh cong!" << endl;
                        break;
                    }
                    case 3: {
                        ColorPrinter* newDevice = new ColorPrinter();
                        newDevice->input();
                        devices.push_back(newDevice);
                        cout << "Them may in mau thanh cong!" << endl;
                        break;
                    }
                    case 4: {
                        Scaner* newDevice = new Scaner();
                        newDevice->input();
                        devices.push_back(newDevice);
                        cout << "Them may quet thanh cong!" << endl;
                        break;
                    }
                    case 5: {
                        Projector* newDevice = new Projector();
                        newDevice->input();
                        devices.push_back(newDevice);
                        cout << "Them may chieu thanh cong!" << endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Laa chon khong hop le!" << endl;
                }

                break;
            }
            case 2: {
                if (devices.empty()) {
                    cout << "Danh sach thiet bi trong!" << endl;
                } else {
                    cout << "====== Danh sach thiet bi ======" << endl;
                    for (ITDevice* device : devices) {
                        device->display();
                        cout << "-----------------------" << endl;
                    }
                }

                break;
            }
             case 3: {
    int searchChoice;
    cout << "----- Thong ke và tim kiem -----"<<endl;
    cout << "1. Thong ke theo tinh trang" << endl;
    cout << "2. Tim kiem theo ten" << endl;
    cout << "3. Quay lai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> searchChoice;

    switch (searchChoice) {
        case 1: {
            int statusChoice;
            cout << "----- Thong ke theo tinh trang -----" << endl;
            cout << "1. Thiet bi đang su dung đuoc" << endl;
            cout << "2. Thiet bi đen thoi han thanh ly" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> statusChoice;

            if (statusChoice == 1) {
                int countInUse = 0;
                for (ITDevice* device : devices) {
                    if (device->getStatus() == true) {
                        countInUse++;
                    }
                }
                cout << "So luong thiet bi đang su dung đuoc: " << countInUse << endl;
            } else if (statusChoice == 2) {
                int countExpired = 0;
                for (ITDevice* device : devices) {
                    if (device->getStatus() == false) {
                        countExpired++;
                    }
                }
                cout << "So lưong thiet bi đen thoi han thanh ly: " << countExpired << endl;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }

            break;
        }
        case 2: {
            string searchName;
            cout << "----- Tim kiem theo ten -----" << endl;
            cout << "Nhap ten thiet bi can tim kiem: ";
            cin.ignore();
            getline(cin, searchName);

            bool found = false;
            for (ITDevice* device : devices) {
                if (device->getName() == searchName) {
                    device->display();
                    found = true;
                }
            }

            if (!found) {
                cout << "Khong tim thay thiet bi nao co ten: " << searchName << endl;
            }

            break;
        }
        case 3:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
    }

    break;
}

            
            case 4: {
                vector<ITDevice*> expiredDevices;
                // Kiểm tra và lưu trữ các thiết bị hết hạn vào danh sách expiredDevices
                for (ITDevice* device : devices) {
                    // Kiểm tra nếu tình trạng là hết hạn
                    if (device->getStatus()) {
                        expiredDevices.push_back(device);
                    }
                }

                if (expiredDevices.empty()) {
                    cout << "Khong co thiet bi nao het han su dung!" << endl;
                } else {
                    cout << "===== Danh sach thiet bi het han =====" << endl;
                    for (ITDevice* device : expiredDevices) {
                        device->display();
                        cout << "-----------------------" << endl;
                    }
                }

                break;
            }
            case 0:
                cout << "Thoat chuong trinh. Cam on ban đa su dung!" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }

    return 0;
}

            


