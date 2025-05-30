#include <iostream>
#include "menuView.h"

using namespace std;

// Prosedur: Menampilkan menu utama aplikasi
void menuView() {
    cout << "\n--- Aplikasi Inventaris Barang ---" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampilkan Semua Barang" << endl;
    cout << "3. Cari Barang" << endl;
    cout << "4. Edit Barang" << endl;
    cout << "5. Hapus Barang" << endl;
    cout << "6. Urutkan Barang" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih opsi: ";
}