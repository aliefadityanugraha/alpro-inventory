#include <iostream>
#include "header.h"
#include "searchItems.cpp"

using namespace std;

// Prosedur: Menghapus barang dari inventaris
void hapusBarang() {
    int kodeHapus;
    cout << "\n--- Hapus Barang ---" << endl;
    cout << "Masukkan Kode Barang yang akan dihapus: ";
    cin >> kodeHapus;
    clearInputBuffer();

    int index = cariBarangByKode(kodeHapus);
    if (index != -1) {
        // Geser elemen setelah yang dihapus untuk menutupi celah
        for (int i = index; i < jumlahBarang - 1; ++i) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlahBarang--;
        cout << "Barang berhasil dihapus!" << endl;
    } else {
        cout << "Barang dengan Kode " << kodeHapus << " tidak ditemukan." << endl;
    }
}