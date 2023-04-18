#include"thuvien6_2.h"
int main() {
  Vector v1, v2(5), v3(5,3), v4, v5;  
  
  v3.add();
  v3.print();
  v5 = v3;
  cout << "\nvecto v2 sao chep tu vector v3: ";
  v5.print();

  v2 = v3;
  cout << "vector v2 gan bang vecto v3: ";
  v2.print();
}