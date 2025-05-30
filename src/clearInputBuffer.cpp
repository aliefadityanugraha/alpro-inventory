#include <iostream>
#include <limits>

using namespace std;

// Prosedur: Membersihkan buffer input setelah cin >> int/double
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}