#include <iostream>

// --- STRUCT ---
struct Barang {
    int kodeBarang;
    char namaBarang[50]; // Menggunakan char array untuk string fixed-size
    int jumlahStok;
    double hargaSatuan;
};