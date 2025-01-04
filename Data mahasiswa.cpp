#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

struct Mahasiswa {
    std::string NIM;
    std::string nama;
    float nilaiAkhir;
};

void tambahData(std::vector<Mahasiswa>& data) {
    int jumlah;
    std::cout << "Masukkan jumlah mahasiswa: ";
    std::cin >> jumlah;

    for (int i = 0; i < jumlah; ++i) {
        Mahasiswa mhs;
        std::cout << "\nMahasiswa ke-" << i + 1 << ":\n";
        std::cout << "NIM: ";
        std::cin >> mhs.NIM;
        std::cout << "Nama: ";
        std::cin.ignore();
        std::getline(std::cin, mhs.nama);
        std::cout << "Nilai Akhir: ";
        std::cin >> mhs.nilaiAkhir;
        data.push_back(mhs);
    }
}

void tampilkanData(const std::vector<Mahasiswa>& data) {
    std::cout << "\nData Mahasiswa:\n";
    std::cout << std::left << std::setw(15) << "NIM" << std::setw(25) << "Nama" << "Nilai Akhir" << "\n";
    std::cout << std::string(50, '-') << "\n";
    for (const auto& mhs : data) {
        std::cout << std::left << std::setw(15) << mhs.NIM << std::setw(25) << mhs.nama << mhs.nilaiAkhir << "\n";
    }
}

void cariData(const std::vector<Mahasiswa>& data) {
    std::string nim;
    std::cout << "Masukkan NIM yang dicari: ";
    std::cin >> nim;

    bool ditemukan = false;
    for (const auto& mhs : data) {
        if (mhs.NIM == nim) {
            std::cout << "\nData ditemukan:\n";
            std::cout << "NIM: " << mhs.NIM << "\n";
            std::cout << "Nama: " << mhs.nama << "\n";
            std::cout << "Nilai Akhir: " << mhs.nilaiAkhir << "\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        std::cout << "\nData dengan NIM " << nim << " tidak ditemukan.\n";
    }
}

void urutkanData(std::vector<Mahasiswa>& data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j].nilaiAkhir < data[j + 1].nilaiAkhir) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
    std::cout << "\nData berhasil diurutkan berdasarkan Nilai Akhir secara menurun.\n";
}

void simpanKeBerkas(const std::vector<Mahasiswa>& data, const std::string& namaBerkas) {
    std::ofstream file(namaBerkas);
    if (!file) {
        std::cerr << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }

    for (const auto& mhs : data) {
        file << mhs.NIM << "," << mhs.nama << "," << mhs.nilaiAkhir << "\n";
    }
    file.close();
    std::cout << "\nData berhasil disimpan ke dalam file \"" << namaBerkas << "\".\n";
}

void bacaDariBerkas(std::vector<Mahasiswa>& data, const std::string& namaBerkas) {
    std::ifstream file(namaBerkas);
    if (!file) {
        std::cerr << "Gagal membuka file untuk membaca data.\n";
        return;
    }

    data.clear();
    std::string line;
    while (std::getline(file, line)) {
        Mahasiswa mhs;
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');

        mhs.NIM = line.substr(0, pos1);
        mhs.nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
        mhs.nilaiAkhir = std::stof(line.substr(pos2 + 1));

        data.push_back(mhs);
    }
    file.close();
    std::cout << "\nData berhasil dibaca dari file \"" << namaBerkas << "\".\n";
}

int main() {
    std::vector<Mahasiswa> dataMahasiswa;
    std::string namaBerkas = "data_mahasiswa.txt";
    int pilihan;

    do {
        std::cout << "\nMenu Utama:\n";
        std::cout << "1. Tambah Data Mahasiswa\n";
        std::cout << "2. Tampilkan Semua Data\n";
        std::cout << "3. Cari Data Mahasiswa (berdasarkan NIM)\n";
        std::cout << "4. Urutkan Data (berdasarkan Nilai Akhir)\n";
        std::cout << "5. Simpan Data ke Berkas\n";
        std::cout << "6. Baca Data dari Berkas\n";
        std::cout << "7. Keluar\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(dataMahasiswa);
                break;
            case 2:
                tampilkanData(dataMahasiswa);
                break;
            case 3:
                cariData(dataMahasiswa);
                break;
            case 4:
                urutkanData(dataMahasiswa);
                break;
            case 5:
                simpanKeBerkas(dataMahasiswa, namaBerkas);
                break;
            case 6:
                bacaDariBerkas(dataMahasiswa, namaBerkas);
                break;
            case 7:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}