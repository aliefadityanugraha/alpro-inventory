#include "header.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Prosedur: Menampilkan semua barang dalam format tabel
void tampilkanSemuaBarang() {
    if (jumlahBarang == 0) {
        cout << "Inventaris kosong." << endl;
        return;
    }

    cout << "\n--- Daftar Semua Barang ---" << endl;

    // Menentukan lebar kolom
    const int width_kode = 8;
    const int width_nama = 35; // Cukup lebar untuk nama barang
    const int width_stok = 8;
    const int width_harga = 15;

    // Header tabel
    cout << left // Rata kiri untuk header
              << setw(width_kode) << "KODE"
              << setw(width_nama) << "NAMA BARANG"
              << setw(width_stok) << "STOK"
              << right
              << setw(width_harga) << "HARGA SATUAN"
              << endl;
    
    // Garis pemisah header dan data
    cout << setfill('-') << setw(width_kode + width_nama + width_stok + width_harga) << "" << endl;
    cout << setfill(' '); // Kembalikan fill character ke spasi

    for (int i = 0; i < jumlahBarang; ++i) {
        cout << left // Rata kiri untuk kode, nama, stok
                  << setw(width_kode) << daftarBarang[i].kodeBarang
                  << setw(width_nama) << daftarBarang[i].namaBarang
                  << setw(width_stok) << daftarBarang[i].jumlahStok
                  << right
                  << fixed << setprecision(2) // Format harga dengan 2 desimal
                  << setw(width_harga) << daftarBarang[i].hargaSatuan
                  << endl;
    }
    // Garis penutup tabel
    cout << setfill('-') << setw(width_kode + width_nama + width_stok + width_harga) << "" << endl;
    cout << setfill(' ');
}