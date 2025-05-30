#include <iostream>
using namespace std;

#include "Barang.h"
#include "menuView.h"
#include "addItems.h"
#include "getAllItems.h"
#include "searchItems.h"
#include "editItems.h"
#include "deleteItems.h"
#include "shortingItems.h"

int kapasitasBarang = 5;
Barang* daftarBarang = new Barang[kapasitasBarang];
int jumlahBarang = 0;

int main() {
    int pilihanMenu;

    do {
        menuView();
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tambahBarang(jumlahBarang, daftarBarang, kapasitasBarang);
                break;
            case 2:
                tampilkanSemuaBarang(jumlahBarang, daftarBarang);
                break;
            case 3:
                cariBarang(daftarBarang, jumlahBarang);
                break;
            case 4:
                editBarang(jumlahBarang, daftarBarang);
                break;
            case 5:
                hapusBarang(jumlahBarang, daftarBarang);
                break;
            case 6:
                tampilkanBarangTerurut(jumlahBarang, daftarBarang);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi inventaris" << endl;
                break;
            default:
                cout << "Inputan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihanMenu != 0);

    delete[] daftarBarang;

    return 0;
}
