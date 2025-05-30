#include "header.h"
#include <iostream>
#include <cstring>

using namespace std;

// Fungsi Sorting: Bubble Sort berdasarkan Kode Barang (Ascending)
void urutkanBarangByKode() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            if (daftarBarang[j].kodeBarang > daftarBarang[j+1].kodeBarang) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Kode Barang." << endl;
}

// Fungsi Sorting: Bubble Sort berdasarkan Nama Barang (Ascending)
void urutkanBarangByNama() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            // Menggunakan strcmp untuk membandingkan nama barang
            if (strcmp(daftarBarang[j].namaBarang, daftarBarang[j+1].namaBarang) > 0) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Nama Barang." << endl;
}

// Fungsi Sorting: Bubble Sort berdasarkan Jumlah Stok (Ascending)
void urutkanBarangByStok() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            if (daftarBarang[j].jumlahStok > daftarBarang[j+1].jumlahStok) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Jumlah Stok." << endl;
}