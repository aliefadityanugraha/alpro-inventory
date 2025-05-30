#include <iostream> // Untuk input/output
#include <string>   // Untuk std::string
#include <limits>   // Untuk std::numeric_limits
#include <windows.h> // Atau <unistd.h> untuk Linux/macOS jika menggunakan system("clear")

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    // Periksa OS untuk menggunakan perintah yang benar
    #ifdef _WIN32
        system("cls"); // Untuk Windows
    #else
        system("clear"); // Untuk Linux/macOS
    #endif
}

// Fungsi untuk menjeda eksekusi dan menunggu tombol
void pressAnyKeyToContinue() {
    std::cout << "\nTekan tombol apa saja untuk kembali ke menu utama...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bersihkan buffer input
    std::cin.get(); // Menunggu input dari pengguna
}

// Fungsi untuk menampilkan pesan selamat datang
void showWelcomeMessage() {
    clearScreen();
    std::cout << "===================================\n";
    std::cout << "        SELAMAT DATANG!\n";
    std::cout << "===================================\n";
    std::cout << "Ini adalah contoh UI sederhana di konsol C++.\n";
    std::cout << "Semoga Anda menikmati pengalaman ini!\n";
    pressAnyKeyToContinue();
}

// Fungsi untuk meminta nama pengguna
void getUserName() {
    clearScreen();
    std::cout << "===================================\n";
    std::cout << "        MINTA NAMA PENGGUNA\n";
    std::cout << "===================================\n";
    std::string name;
    std::cout << "Masukkan nama Anda: ";
    // Membersihkan buffer input sebelum membaca string dengan spasi
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name); // Membaca seluruh baris input
    std::cout << "Halo, " << name << "! Senang bertemu dengan Anda.\n";
    pressAnyKeyToContinue();
}

// Fungsi untuk menghitung luas persegi
void calculateSquareArea() {
    clearScreen();
    std::cout << "===================================\n";
    std::cout << "        HITUNG LUAS PERSEGI\n";
    std::cout << "===================================\n";
    double side = 0;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Masukkan panjang sisi persegi: ";
        std::string input;
        std::cin >> input; // Baca input sebagai string dulu

        try {
            side = std::stod(input); // Konversi string ke double
            if (side >= 0) {
                validInput = true;
            } else {
                std::cout << "Input tidak valid. Harap masukkan angka positif.\n";
                // Tidak perlu clearScreen di sini, biarkan pesan error terlihat
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Input tidak valid. Harap masukkan angka.\n";
        } catch (const std::out_of_range& e) {
            std::cout << "Angka terlalu besar atau terlalu kecil.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bersihkan buffer input
    }

    double area = side * side;
    std::cout << "Luas persegi dengan sisi " << side << " adalah: " << area << "\n";
    pressAnyKeyToContinue();
}

// Fungsi utama untuk menjalankan menu
int main() {
    int choice;
    bool running = true;

    while (running) {
        clearScreen(); // Bersihkan layar setiap kali menu ditampilkan
        std::cout << "-----------------------------------\n";
        std::cout << "        APLIKASI CONSOLE SEDERHANA\n";
        std::cout << "-----------------------------------\n";
        std::cout << "1. Tampilkan Pesan Selamat Datang\n";
        std::cout << "2. Minta Nama Pengguna\n";
        std::cout << "3. Hitung Luas Persegi (Contoh)\n";
        std::cout << "4. Keluar\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Pilih opsi (1-4): ";

        // Membaca input pilihan
        std::cin >> choice;

        // Memastikan buffer input bersih setelah membaca angka
        // Ini penting jika Anda akan membaca string setelahnya
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                showWelcomeMessage();
                break;
            case 2:
                getUserName();
                break;
            case 3:
                calculateSquareArea();
                break;
            case 4:
                running = false; // Menghentikan loop dan keluar dari aplikasi
                std::cout << "\nTerima kasih telah menggunakan aplikasi ini. Sampai jumpa!\n";
                // Tidak perlu pressAnyKeyToContinue() di sini karena aplikasi akan keluar
                break;
            default:
                std::cout << "\nPilihan tidak valid. Tekan tombol apa saja untuk mencoba lagi...\n";
                pressAnyKeyToContinue(); // Tunggu input pengguna
                break;
        }
    }

    return 0; // Menunjukkan program berakhir dengan sukses
}
