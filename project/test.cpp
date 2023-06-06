#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Hàm để xử lý hiệu ứng khi rê chuột đến một chức năng
void handleMouseHover(const string& function) {
    system("cls"); // Xóa màn hình để vẽ lại menu
    
    cout << "\n===MENU===" << endl;
    cout << "1. Nhập thêm sản phẩm vào kho" << endl;
    cout << "2. Hiển thị thông tin các sản phẩm" << endl;
    cout << "3. Xuất kho" << endl;
    cout << "0. Thoát khỏi chương trình" << endl;
    
    cout << "\nĐang rê chuột đến chức năng: " << function << endl;
    // Các xử lý khác khi rê chuột đến chức năng
    // ...
}

int main() {
    int choice;

    do {
        system("cls"); // Xóa màn hình để vẽ lại menu

        cout << "\n===MENU===" << endl;
        cout << "1. nhap them san pham vao kho" << endl;
        cout << "2. hien thi thong tin san pham" << endl;
        cout << "3. xuat kho" << endl;
        cout << "0. thoat khoi chuong trinh" << endl;

        cout << "moi nhap su lua chon cua ban ";
        cin >> choice;

        // Xóa dòng báo lựa chọn để tạo hiệu ứng rê chuột
        COORD cursorPosition;
        cursorPosition.X = 0;
        cursorPosition.Y = choice + 4;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

        switch (choice) {
            case 1:
                handleMouseHover("nhap them san pham va kho");
                break;
            case 2:
                handleMouseHover("hien thi thong tin san pham");
                break;
            case 3:
                handleMouseHover("xuat kho");
                break;
            case 0:
                handleMouseHover(" thoat khoi chuong trinh");
                break;
            default:
                cout << "lua chon cua ban khong hop le! vui long nhap lai." << endl;
                Sleep(1000); // Dừng 1 giây trước khi vẽ lại menu
                break;
        }
    } while (choice != 0);

    return 0;
}
