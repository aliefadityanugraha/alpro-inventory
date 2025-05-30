#include <iostream> // Untuk cin, cout
#include <iomanip>  // Untuk setw, left, right, fixed, setprecision
#include <limits>   // Untuk numeric_limits (untuk membersihkan buffer input)
#include <cstring>  // Untuk strcpy (untuk string char array)

#include "menuView.cpp"
#include "addItems.cpp"
#include "getAllItems.cpp"
#include "searchItems.cpp"
#include "editItems.cpp"
#include "deleteItems.cpp"
#include "shortingItems.cpp"

using namespace std;

// Prosedur: Menginisialisasi array dinamis untuk inventaris
void inisialisasiInventaris() {
    daftarBarang = new Barang[kapasitasMaks]; // Alokasi memori awal
    cout << "Inventaris diinisialisasi dengan kapasitas " << kapasitasMaks << " barang." << endl;
}

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

// --- FUNGSI UTAMA ---
int main() {
    inisialisasiInventaris();
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        clearInputBuffer(); // Bersihkan buffer setelah input pilihan menu

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanSemuaBarang(); break;
            case 3: cariBarang(); break;
            case 4: editBarang(); break;
            case 5: hapusBarang(); break;
            case 6: urutkanBarang(); break;
            case 0: cout << "Terima kasih telah menggunakan aplikasi inventaris!" << endl; break;
            default: cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    // Bebaskan memori yang dialokasikan secara dinamis sebelum program berakhir
    delete[] daftarBarang;
    daftarBarang = nullptr; // Set pointer ke nullptr setelah dihapus
    jumlahBarang = 0; // Reset jumlah barang

    return 0;
}