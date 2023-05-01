
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << setfill(' ') << setw(3) << "stt" << " | "
         << setw(5) << "hour" << " | "
         << setw(7) << "minute" << " | "
         << setw(7) << "second" << " | "
         << setw(12) << "time" << endl;
    cout << setfill('-') << setw(5) << "|"
         << setw(8) << "|"
         << setw(10) << "|"
         << setw(10) << "|"
         << setfill('-') <<  setw(15) << "-" << endl;
    cout << setfill(' ') << setw(3) << "1" << " | "
         << setw(5) << "1" << " | "
         << setw(7) << "1" << " | "
         << setw(7) << "1" << " | "
         << setw(12) << "1:1:1" << endl;
    return 0;
}
