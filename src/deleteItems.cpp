#include <iostream>
#include <string>
#include "deleteItems.h"
#include "searchItems.h"

using namespace std;

void hapusBarang(int& jumlahBarang, Barang*& daftarBarang) {
    if (jumlahBarang == 0) {
        cout << "Belum ada barang yang dapat dihapus." << endl;
        return;
    }

    string keyword;
    cout << "Masukkan kode atau nama barang yang akan dihapus: ";
    getline(cin >> ws, keyword);

    int index = sequentialSearchBarang(daftarBarang, jumlahBarang, keyword);
    // int index = -1;
    // for (int i = 0; i < jumlahBarang; ++i) {
    //     string kode = daftarBarang[i].kodeBarang;
    //     string nama = daftarBarang[i].namaBarang;
    //     if (kode == keyword || nama == keyword) {
    //         index = i;
    //         break;
    //     }
    // }

    if (index == -1) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    cout << "Barang ditemukan:" << endl;
    cout << "Kode Barang   : " << daftarBarang[index].kodeBarang << endl;
    cout << "Nama Barang   : " << daftarBarang[index].namaBarang << endl;
    cout << "Jumlah Stok   : " << daftarBarang[index].jumlahStok << endl;
    cout << "Harga Satuan  : " << daftarBarang[index].hargaSatuan << endl;
    cout << "Apakah Anda yakin ingin menghapus barang ini? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = index; i < jumlahBarang - 1; ++i) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlahBarang--;
        cout << "Barang berhasil dihapus." << endl;
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}
