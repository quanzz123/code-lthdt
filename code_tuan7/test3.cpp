#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << setfill(' ') << setw(4) << "stt" << " | "
         << setw(6) << "hour" << " | "
         << setw(8) << "minute" << " | "
         << setw(12) << "second" << " | "
         << setw(16) << "time" << " |" << endl;
    cout << setfill('-') << setw(4) << "+" << "|"
         << setw(6) << "+" << "|"
         << setw(8) << "+" << "|"
         << setw(12) << "+" << "|"
         << setw(16) << "+" << "|" << endl;
    
    for (int i = 1; i <= 5; i++) {
        cout << setfill(' ') << setw(4) << i << " | "
             << setw(6) << i << " | "
             << setw(8) << i << " |
             << setw(12) << i << " | "
             << setw(16) << i << ":" << i << ":" << i << " |" << endl;
        cout << setfill('-') << setw(4) << "+" << "|"
             << setw(6) << "+" << "|"
             << setw(8) << "+" << "|"
             << setw(12) << "+" << "|"
             << setw(16) << "+" << "|" << endl;
    }
    
    return 0;
}
