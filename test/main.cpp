// Inventaris.cpp
#include <iostream>
#include <iomanip> // Untuk setw, left, right, fixed, setprecision
#include <limits>  // Untuk numeric_limits
#include <cstring> // Untuk strcpy, strcmp

#include "Inventaris.h" // Sertakan header inventaris
#include "Barang.h"     // Sertakan definisi Barang

// Menggunakan namespace std untuk meringkas penulisan
using namespace std;

// Definisi variabel global yang dideklarasikan di Inventaris.h
Barang* daftarBarang = nullptr;
int jumlahBarang = 0;
int kapasitasMaks = 5; // Kapasitas awal, bisa diubah

// Prosedur: Membersihkan buffer input setelah cin >> int/double
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prosedur: Menginisialisasi array dinamis untuk inventaris
void inisialisasiInventaris() {
    daftarBarang = new Barang[kapasitasMaks]; // Alokasi memori awal
    cout << "Inventaris diinisialisasi dengan kapasitas " << kapasitasMaks << " barang." << endl;
}

// Prosedur: Menambah barang baru ke inventaris
void tambahBarang() {
    if (jumlahBarang >= kapasitasMaks) {
        // Re-alokasi memori (dynamic array resizing)
        int newKapasitas = kapasitasMaks * 2;
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
    cin.getline(daftarBarang[jumlahBarah].namaBarang, 50);
    
    cout << "Jumlah Stok: ";
    cin >> daftarBarang[jumlahBarang].jumlahStok;
    
    cout << "Harga Satuan: ";
    cin >> daftarBarang[jumlahBarang].hargaSatuan;
    clearInputBuffer(); // Membersihkan buffer setelah input double

    jumlahBarang++;
    cout << "Barang berhasil ditambahkan!" << endl;
}

// Prosedur: Menampilkan semua barang dalam format tabel
void tampilkanSemuaBarang() {
    if (jumlahBarang == 0) {
        cout << "Inventaris kosong." << endl;
        return;
    }

    cout << "\n--- Daftar Semua Barang ---" << endl;

    // Menentukan lebar kolom
    const int width_kode = 8;
    const int width_nama = 35; // Cukup lebar untuk nama barang
    const int width_stok = 8;
    const int width_harga = 15;

    // Header tabel
    cout << left // Rata kiri untuk header
              << setw(width_kode) << "KODE"
              << setw(width_nama) << "NAMA BARANG"
              << setw(width_stok) << "STOK"
              << right // Rata kanan untuk harga
              << setw(width_harga) << "HARGA SATUAN"
              << endl;
    
    // Garis pemisah header dan data
    cout << setfill('-') << setw(width_kode + width_nama + width_stok + width_harga) << "" << endl;
    cout << setfill(' '); // Kembalikan fill character ke spasi

    // Data barang
    for (int i = 0; i < jumlahBarang; ++i) {
        cout << left // Rata kiri untuk kode, nama, stok
                  << setw(width_kode) << daftarBarang[i].kodeBarang
                  << setw(width_nama) << daftarBarang[i].namaBarang
                  << setw(width_stok) << daftarBarang[i].jumlahStok
                  << right // Rata kanan untuk harga
                  << fixed << setprecision(2) // Format harga dengan 2 desimal
                  << setw(width_harga) << daftarBarang[i].hargaSatuan
                  << endl;
    }
    // Garis penutup tabel
    cout << setfill('-') << setw(width_kode + width_nama + width_stok + width_harga) << "" << endl;
    cout << setfill(' ');
}

// Fungsi: Mencari barang berdasarkan kode dan mengembalikan indeksnya
int cariBarangByKode(int kode) {
    for (int i = 0; i < jumlahBarang; ++i) {
        if (daftarBarang[i].kodeBarang == kode) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Tidak ditemukan
}

// Fungsi: Mencari barang berdasarkan nama dan mengembalikan indeksnya
int cariBarangByNama(const char* nama) {
    for (int i = 0; i < jumlahBarang; ++i) {
        // Menggunakan strcmp untuk membandingkan string char array
        if (strcmp(daftarBarang[i].namaBarang, nama) == 0) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Tidak ditemukan
}

// Prosedur: Meminta input untuk pencarian dan menampilkan hasil
void cariBarang() {
    int pilihanCari;
    cout << "\n--- Cari Barang ---" << endl;
    cout << "1. Cari berdasarkan Kode Barang" << endl;
    cout << "2. Cari berdasarkan Nama Barang" << endl;
    cout << "Pilih opsi pencarian: ";
    cin >> pilihanCari;
    clearInputBuffer();

    int index = -1;
    if (pilihanCari == 1) {
        int kodeCari;
        cout << "Masukkan Kode Barang yang dicari: ";
        cin >> kodeCari;
        clearInputBuffer();
        index = cariBarangByKode(kodeCari);
    } else if (pilihanCari == 2) {
        char namaCari[50];
        cout << "Masukkan Nama Barang yang dicari: ";
        cin.getline(namaCari, 50);
        index = cariBarangByNama(namaCari);
    } else {
        cout << "Pilihan tidak valid." << endl;
        return;
    }
    
    if (index != -1) {
        cout << "Barang ditemukan:" << endl;
        cout << "Kode: " << daftarBarang[index].kodeBarang << endl;
        cout << "Nama: " << daftarBarang[index].namaBarang << endl;
        cout << "Stok: " << daftarBarang[index].jumlahStok << endl;
        cout << "Harga: " << fixed << setprecision(2) << daftarBarang[index].hargaSatuan << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}

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

// Prosedur: Menghapus barang dari inventaris
void hapusBarang() {
    int kodeHapus;
    cout << "\n--- Hapus Barang ---" << endl;
    cout << "Masukkan Kode Barang yang akan dihapus: ";
    cin >> kodeHapus;
    clearInputBuffer();

    int index = cariBarangByKode(kodeHapus);
    if (index != -1) {
        // Geser elemen setelah yang dihapus untuk menutupi celah
        for (int i = index; i < jumlahBarang - 1; ++i) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlahBarang--;
        cout << "Barang berhasil dihapus!" << endl;
    } else {
        cout << "Barang dengan Kode " << kodeHapus << " tidak ditemukan." << endl;
    }
}

// Fungsi Sorting: Bubble Sort berdasarkan Kode Barang (Ascending)
void urutkanBarangByKode() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            if (daftarBarang[j].kodeBarang > daftarBarang[j+1].kodeBarang) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Kode Barang." << endl;
}

// Fungsi Sorting: Bubble Sort berdasarkan Nama Barang (Ascending)
void urutkanBarangByNama() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            // Menggunakan strcmp untuk membandingkan nama barang
            if (strcmp(daftarBarang[j].namaBarang, daftarBarang[j+1].namaBarang) > 0) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Nama Barang." << endl;
}

// Fungsi Sorting: Bubble Sort berdasarkan Jumlah Stok (Ascending)
void urutkanBarangByStok() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - 1 - i; ++j) {
            if (daftarBarang[j].jumlahStok > daftarBarang[j+1].jumlahStok) {
                // Tukar posisi
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j+1];
                daftarBarang[j+1] = temp;
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan Jumlah Stok." << endl;
}

// Prosedur: Memilih kriteria pengurutan
void urutkanBarang() {
    cout << "\n--- Urutkan Barang ---" << endl;
    cout << "1. Berdasarkan Kode Barang" << endl;
    cout << "2. Berdasarkan Nama Barang" << endl;
    cout << "3. Berdasarkan Jumlah Stok" << endl;
    cout << "Pilih opsi pengurutan: ";
    int pilihan;
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1: urutkanBarangByKode(); break;
        case 2: urutkanBarangByNama(); break;
        case 3: urutkanBarangByStok(); break;
        default: cout << "Pilihan tidak valid." << endl; break;
    }
    tampilkanSemuaBarang(); // Tampilkan hasil setelah diurutkan
}