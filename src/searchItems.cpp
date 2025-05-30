#include <iostream>
#include "searchItems.h"

using namespace std;

int sequentialSearchBarang(Barang* daftarBarang, int jumlahBarang) {
    string keyword;
    cout << "Masukkan keyword yang akan dicari (kode atau nama barang): ";
    getline(cin >> ws, keyword); // ws untuk mengabaikan whitespace sisa input sebelumnya

    for (int i = 0; i < jumlahBarang; ++i) {
        string kode = daftarBarang[i].kodeBarang;
        string nama = daftarBarang[i].namaBarang;
        if (kode == keyword || nama == keyword) {
            return i;
        }
    }
    return -1;
}