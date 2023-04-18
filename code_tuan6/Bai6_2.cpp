#include"libary6_2.h"
int main() {
  Vector v1, v2(5), v3(3,1.5);
  
  v1.add();
  
  Vector v4(v2); // Thiết lập sao chép
  
  v2 = v3; // Phép gán đối tượng
  
  v1.print();
  v2.print();
  v3.print();
  v4.print();
  
  return 0;
}