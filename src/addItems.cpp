#include <iostream>
#include "addItems.h"

using namespace std;

void tambahBarang(int& jumlahBarang, Barang*& daftarBarang, int& kapasitasBarang) {
    if (jumlahBarang == kapasitasBarang) {
        int kapasitasBaru = kapasitasBarang * 2;
        Barang* temp = new Barang[kapasitasBaru];
        for (int i = 0; i < jumlahBarang; i++) {
            temp[i] = daftarBarang[i];
        }
        delete[] daftarBarang;
        daftarBarang = temp;
        kapasitasBarang = kapasitasBaru;
    }

    Barang barangBaru;
    cout << "Masukkan kode barang: ";
    cin >> barangBaru.kodeBarang;
    cin.ignore();

    cout << "Masukkan nama barang: ";
    cin.getline(barangBaru.namaBarang, 50);

    cout << "Masukkan jumlah stok: ";
    cin >> barangBaru.jumlahStok;

    cout << "Masukkan harga satuan: ";
    cin >> barangBaru.hargaSatuan;

    daftarBarang[jumlahBarang++] = barangBaru;

    cout << "Barang berhasil ditambahkan!" << endl;
}