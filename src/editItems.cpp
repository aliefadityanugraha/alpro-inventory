#include <iostream>
#include "header.h"
#include "searchItems.cpp"

using namespace std;

// Prosedur: Mengedit data barang yang sudah ada
void editBarang() {
    int kodeEdit;
    cout << "\n--- Edit Barang ---" << endl;
    cout << "Masukkan Kode Barang yang akan diedit: ";
    cin >> kodeEdit;
    clearInputBuffer();

    int index = cariBarangByKode(kodeEdit);
    if (index != -1) {
        cout << "Barang ditemukan. Masukkan data baru:" << endl;
        
        cout << "Nama Barang (" << daftarBarang[index].namaBarang << "): ";
        cin.getline(daftarBarang[index].namaBarang, 50);
        
        cout << "Jumlah Stok (" << daftarBarang[index].jumlahStok << "): ";
        cin >> daftarBarang[index].jumlahStok;
        
        cout << "Harga Satuan (" << daftarBarang[index].hargaSatuan << "): ";
        cin >> daftarBarang[index].hargaSatuan;
        clearInputBuffer();

        cout << "Barang berhasil diupdate!" << endl;
    } else {
        cout << "Barang dengan Kode " << kodeEdit << " tidak ditemukan." << endl;
    }
}