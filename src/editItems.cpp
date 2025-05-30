#include <iostream>
#include <cstring>
#include <string>
#include "editItems.h"
#include "searchItems.h"

using namespace std;

void editBarang(int jumlahBarang, Barang* daftarBarang) {
    if (jumlahBarang == 0) {
        cout << "Belum ada barang yang terdaftar." << endl;
        return;
    }

    string keyword;
    cout << "Masukkan keyword yang akan diedit (kode atau nama barang): ";
    getline(cin >> ws, keyword);

    int index = sequentialSearchBarang(daftarBarang, jumlahBarang, keyword);

    if (index == -1) {
        cout << "Barang dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    cout << "Data barang saat ini:" << endl;
    cout << "Kode Barang   : " << daftarBarang[index].kodeBarang << endl;
    cout << "Nama Barang   : " << daftarBarang[index].namaBarang << endl;
    cout << "Jumlah Stok   : " << daftarBarang[index].jumlahStok << endl;
    cout << "Harga Satuan  : " << daftarBarang[index].hargaSatuan << endl;

    cout << "\nMasukkan data baru (tekan enter jika tidak ingin mengubah):" << endl;

    cout << "Nama Barang [" << daftarBarang[index].namaBarang << "]: ";
    char namaBaru[50];
    cin.getline(namaBaru, 50);
    if (strlen(namaBaru) > 0) {
        strcpy(daftarBarang[index].namaBarang, namaBaru);
    }

    cout << "Jumlah Stok [" << daftarBarang[index].jumlahStok << "]: ";
    string stokInput;
    getline(cin, stokInput);
    if (!stokInput.empty()) {
        int stokBaru = stoi(stokInput);
        daftarBarang[index].jumlahStok = stokBaru;
    }

    cout << "Harga Satuan [" << daftarBarang[index].hargaSatuan << "]: ";
    string hargaInput;
    getline(cin, hargaInput);
    if (!hargaInput.empty()) {
        double hargaBaru = stod(hargaInput);
        daftarBarang[index].hargaSatuan = hargaBaru;
    }

    cout << "Barang berhasil diedit." << endl;
}
