#include "header.h"
#include <iostream>
#include <iomanip>

using namespace std;


// Fungsi: Mencari barang berdasarkan kode dan mengembalikan indeksnya
int cariBarangByKode(int kode) {
    for (int i = 0; i < jumlahBarang; ++i) {
        if (daftarBarang[i].kodeBarang == kode) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Tidak ditemukan
}

// Fungsi: Mencari barang berdasarkan nama dan mengembalikan indeksnya
int cariBarangByNama(const char* nama) {
    for (int i = 0; i < jumlahBarang; ++i) {
        // Menggunakan strcmp untuk membandingkan string char array
        if (strcmp(daftarBarang[i].namaBarang, nama) == 0) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Tidak ditemukan
}