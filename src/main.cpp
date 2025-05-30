#include <iostream>
using namespace std;

#include "Barang.h"
#include "menuView.h"
#include "addItems.h"
#include "getAllItems.h"
#include "searchItems.h"

int kapasitasBarang = 5;
Barang* daftarBarang = new Barang[kapasitasBarang];
int jumlahBarang = 0;


int main() {
    int choiceMenu;

    do {
        menuView();
        cin >> choiceMenu;

        switch (choiceMenu) {
            case 1:
                tambahBarang(jumlahBarang, daftarBarang, kapasitasBarang);
                break;
            case 2:
                tampilkanSemuaBarang(jumlahBarang, daftarBarang);
                break;
            case 3:
                sequentialSearchBarang(daftarBarang, jumlahBarang);
                break;
            // Tambahkan case lainnya nanti
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi inventaris!" << endl;
                break;
            default:
                cout << "Inputan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choiceMenu != 0);

    delete[] daftarBarang; // Dealokasi memori

    return 0;
}
