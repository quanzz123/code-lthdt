#include"thuvien5_2.h"
int main() {
    int k;
    float ox, oy;
    cout << "\nnhap ban kinh cua duong trom: ";
    cin >> k;
    cout << "\nnhap toa do cua tam duong tron: ";
    cin >> ox >> oy;
    Crircle O(ox, oy, k);
    O.print();


}