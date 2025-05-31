#include <iostream>
#include <iomanip>
#include "getAllItems.h"

using namespace std;

void tampilkanSemuaBarang(int jumlahBarang, Barang* daftarBarang) {
    if (jumlahBarang == 0) {
        cout << "Belum ada barang yang terdaftar." << endl;
        return;
    }

    cout << "\nDaftar Semua Barang:\n";
    cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
    cout << left
         << setw(4)  << "No"
         << setw(18) << "Kode Barang"
         << setw(30) << "Nama Barang"
         << setw(8)  << "Stok"
         << setw(15) << "Harga Satuan" << endl;
    cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
    for (int i = 0; i < jumlahBarang; ++i) {
        cout << left
             << setw(4)  << (i + 1)
             << setw(18) << daftarBarang[i].kodeBarang
             << setw(30) << daftarBarang[i].namaBarang
             << setw(8)  << daftarBarang[i].jumlahStok
             << setw(15) << daftarBarang[i].hargaSatuan
             << endl;
    }
    cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
}