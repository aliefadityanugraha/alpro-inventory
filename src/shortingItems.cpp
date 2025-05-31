#include <iostream>
#include <iomanip>
#include "shortingItems.h"

using namespace std;

void urutkanBarang(int jumlahBarang, Barang* daftarBarang) {
    if (jumlahBarang == 0) {
        cout << "Belum ada barang yang dapat diurutkan." << endl;
        return;
    }

    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - i - 1; ++j) {
            if (daftarBarang[j].kodeBarang > daftarBarang[j + 1].kodeBarang) {
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j + 1];
                daftarBarang[j + 1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan kode barang." << endl;
}

void tampilkanBarangTerurut(int jumlahBarang, Barang* daftarBarang) {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang untuk ditampilkan." << endl;
        return;
    }

    urutkanBarang(jumlahBarang, daftarBarang);

    cout << "\nDaftar Barang Setelah Diurutkan:" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    cout << left
         << setw(5)  << "No"
         << setw(15) << "Kode Barang"
         << setw(25) << "Nama Barang"
         << setw(10) << "Stok"
         << setw(15) << "Harga" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;

    for (int i = 0; i < jumlahBarang; ++i) {
        cout << left
             << setw(5)  << (i + 1)
             << setw(15) << daftarBarang[i].kodeBarang
             << setw(25) << daftarBarang[i].namaBarang
             << setw(10) << daftarBarang[i].jumlahStok
             << setw(15) << daftarBarang[i].hargaSatuan
             << endl;
    }
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
}


