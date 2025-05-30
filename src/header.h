// header.h
#ifndef HEADER_H
#define HEADER_H

struct Barang {
    int kodeBarang;
    char namaBarang[50];
    int jumlahStok;
    double hargaSatuan;
};

// Deklarasi variabel global
extern Barang* daftarBarang;
extern int jumlahBarang;
extern int kapasitasMaks;

// Fungsi utilitas
void clearInputBuffer();

#endif
