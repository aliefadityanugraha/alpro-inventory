#include <iostream>
#include "searchItems.h"

using namespace std;

int sequentialSearchBarang(Barang* daftarBarang, int jumlahBarang, string keyword) {
    for (int i = 0; i < jumlahBarang; ++i) {
        string kode = daftarBarang[i].kodeBarang;
        string nama = daftarBarang[i].namaBarang;
        if (kode == keyword || nama == keyword) {
            return i;
        }
    }
    return -1;
}

void cariBarang(Barang* daftarBarang, int jumlahBarang) {
    string keyword;
    cout << "Masukkan keyword yang akan dicari (kode atau nama barang): ";
    getline(cin >> ws, keyword);

    int index = sequentialSearchBarang(daftarBarang, jumlahBarang, keyword);
    if (index != -1) {
        cout << "Barang ditemukan:" << endl;
        cout << "Kode Barang   : " << daftarBarang[index].kodeBarang << endl;
        cout << "Nama Barang   : " << daftarBarang[index].namaBarang << endl;
        cout << "Jumlah Stok   : " << daftarBarang[index].jumlahStok << endl;
        cout << "Harga Satuan  : " << daftarBarang[index].hargaSatuan << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}
