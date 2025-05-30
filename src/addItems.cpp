#include <iostream>
#include "header.h"

using namespace std;

// Prosedur: Menambah barang baru ke inventaris
void tambahBarang() {
    if (jumlahBarang >= kapasitasMaks) {
        // Re-alokasi memori (dynamic array resizing)
        int newKapasitas = kapasitasMaks * 2;
        //membuat varibale baru bernama temp berdasarkan struct Barang yang ukuranya sama dengan new Barang[newKapasitas]
        Barang* temp = new Barang[newKapasitas];
        for (int i = 0; i < jumlahBarang; ++i) {
            temp[i] = daftarBarang[i];
        }
        delete[] daftarBarang; // Bebaskan memori lama
        daftarBarang = temp;
        kapasitasMaks = newKapasitas;
        cout << "Kapasitas inventaris diperbesar menjadi " << kapasitasMaks << " barang." << endl;
    }

    cout << "\n--- Tambah Barang ---" << endl;
    cout << "Kode Barang: ";
    cin >> daftarBarang[jumlahBarang].kodeBarang;
    clearInputBuffer(); // Membersihkan buffer setelah input int
    
    cout << "Nama Barang: ";
    cin.getline(daftarBarang[jumlahBarang].namaBarang, 50);
    
    cout << "Jumlah Stok: ";
    cin >> daftarBarang[jumlahBarang].jumlahStok;
    
    cout << "Harga Satuan: ";
    cin >> daftarBarang[jumlahBarang].hargaSatuan;
    clearInputBuffer(); // Membersihkan buffer setelah input double

    jumlahBarang++;
    cout << "Barang berhasil ditambahkan!" << endl;
}