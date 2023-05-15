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
        }
        void display() {
            cout << "Ten thiet bi: " << name << endl;
            cout << "Ma thiet bi: " << code << endl;
            cout << "Ngay nhap thiet bi: " << date << endl;
            cout << "Tinh trang: " << (status ? "het han" : "con han") << endl;
        }

};
class Printer : public ITDevice {
    protected:
        string color;
        int speed;
        int memory;
    public:
        Printer(string n=" ",string c=" ", string d=" ",string col=" ", int sp=" ", int mem=" ") :ITDevice(n,c,d) {
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
        BWPrinter(string n=" ",string c=" ", string d=" ",string col=" ", int sp=" ", int mem=" ", int pix=0) : Printer(n,c,d,col,sp,mem) {
            pixels = pix;
        }
        void input() {
            Printer::input();
            cout << "so diem anh: ";
            cin >> pixels;
        }
        void display() {
            Printer::display();
            cout << "So diem anh: " << pixels << endl;
        }
};
class ColorPrinter : public BWPrinter {
    protected:
        int colors; // số màu
    public:
        ColorPrinter(string n=" ",string c=" ", string d=" ",string col=" ", int sp=" ", int mem=" ", int pix=0, int cols=0) : BWPrinter(n,c,d,col,sp,mem,pix) {
            colors = cols;
        }
        void input() {
            BWPrinter::input();
            cout << "so mau: ";
            cin >> colors;
        }
        void display() {

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
            ITDevice::display();
            cout << "toc do quet: " << scanspeed << endl;
        }
};
class Protector : public ITDevice {
    protected:
        int maxHours;
    public:
        Protector(string n=" ",string c=" ", string d=" ", string s=" ", int ss=0, int mH =0) : ITDevice(n,c,d,ss) {
            maxHours = mH;
        }
        void input() {
            ITDevice::input();
            cout << "Nhap so gio chieu toi da: ";
            cin >> maxHours;
        }
        void display() {
            ITDevice::display();
            cout << "so gio max: " << maxHours << endl;
        }
};
int main() {
    vector<Device*> devices;
    int choice;
    
