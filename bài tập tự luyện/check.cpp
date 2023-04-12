#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Hàm kiểm tra tính hợp lệ của các ký tự mở ngoặc và đóng ngoặc trong biểu thức toán học
int validlatex(string s) {
// Tạo một stack 'st' để lưu trữ các ký tự mở ngoặc
stack<char> st;
// Duyệt lần lượt từng ký tự 'c' trong chuỗi 's'
for (char c : s) {
// Nếu 'c' là một ký tự MỞ ngoặc, đưa 'c' vào đỉnh của stack 'st'
if (c == '(' || c == '{' || c == '[') {
st.push(c);
}
// Nếu 'c' là một ký tự ĐÓNG ngoặc
else if (c == ')' || c == '}' || c == ']') //sẽ có 2 trường hợp: st rỗng hoặc đã chứa
// Nếu stack st đang rỗng, tức là không có ký tự MỞ ngoặc tương ứng với ký tự đóng ngoặc này, thì chuỗi invalid, xuất 0
if (st.empty()) {
return 0;
}
// Nếu ký tự ĐÓNG ngoặc này khớp với ký tự MỞ ngoặc ở đỉnh của stack 'st', thì loại bỏ ký tự mở ngoặc này khỏi đỉnh của stack 'st'
else if (c == ')' && st.top() == '(') {
st.pop();
} else if (c == '}' && st.top() == '{') {
st.pop();
} else if (c == ']' && st.top() == '[') {
st.pop();
}
// Nếu không, chuỗi không hợp lệ, trả về giá trị 0
else {
return 0;
}
}
}
// Sau khi duyệt qua toàn bộ chuỗi, nếu stack 'st' còn phần tử, tức là vẫn còn ký tự mở ngoặc
// chưa có ký tự đóng ngoặc tương ứng, thì chuỗi không hợp lệ, trả về giá trị 0
// Nếu không, chuỗi hợp lệ, trả về giá trị 1
return st.empty() ? 1 : 0;
}
int main() {
string s;
getline(cin, s);
int is_valid = validlatex(s);
if (is_valid) {
cout << "1" << endl;
} else {
cout << "0" << endl;
}
return 0;
}