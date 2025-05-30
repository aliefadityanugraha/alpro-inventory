// header.cpp
#include <iostream>
#include <limits>
#include "header.h"

using namespace std;

// Definisi variabel global
Barang* daftarBarang = nullptr;
int jumlahBarang = 0;
int kapasitasMaks = 5;

// Fungsi clear buffer input
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
