Struktur Data

struct Mahasiswa {
    string nim;
    string nama;
    double nilaiAkhir;
};
Mahasiswa: Struktur ini digunakan untuk menyimpan data mahasiswa, yang terdiri dari NIM (Nomor Induk Mahasiswa), Nama, dan Nilai Akhir.
Fungsi-Fungsi
void tambahDataMahasiswa(vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini meminta pengguna untuk memasukkan data mahasiswa baru (NIM, Nama, dan Nilai Akhir) dan menambahkannya ke dalam daftar mahasiswa (mahasiswaList).
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Mengambil input dari pengguna dan menyimpannya dalam objek Mahasiswa.
Menambahkan objek tersebut ke dalam vector mahasiswaList.
void tampilkanSemuaData(const vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini menampilkan semua data mahasiswa yang tersimpan dalam mahasiswaList.
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Melakukan iterasi melalui vector dan mencetak setiap data mahasiswa ke layar.
void cariDataMahasiswa(const vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini mencari data mahasiswa berdasarkan NIM yang dimasukkan oleh pengguna.
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Mengambil input NIM dari pengguna.
Melakukan pencarian linear dalam vector untuk menemukan mahasiswa dengan NIM yang sesuai.
Jika ditemukan, mencetak data mahasiswa; jika tidak, menampilkan pesan bahwa data tidak ditemukan.
void urutkanData(vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini mengurutkan data mahasiswa berdasarkan Nilai Akhir secara menurun menggunakan algoritma Bubble Sort.
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Melakukan dua loop bersarang untuk membandingkan dan menukar elemen dalam vector berdasarkan nilai akhir.
Setelah pengurutan selesai, menampilkan pesan bahwa data telah diurutkan.
void simpanDataKeBerkas(const vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini menyimpan data mahasiswa ke dalam berkas teks.
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Membuka berkas dengan nama "data_mahasiswa.txt" untuk ditulis.
Melakukan iterasi melalui vector dan menulis setiap data mahasiswa ke dalam berkas dengan format yang ditentukan.
Menutup berkas setelah selesai.
void bacaDataDariBerkas(vector<Mahasiswa>& mahasiswaList)

Deskripsi: Fungsi ini membaca data mahasiswa dari berkas dan memuatnya kembali ke dalam program.
Parameter:
mahasiswaList: Referensi ke vector yang menyimpan data mahasiswa.
Proses:
Membuka berkas "data_mahasiswa.txt" untuk dibaca.
Membaca setiap baris dari berkas, memisahkan NIM, Nama, dan Nilai Akhir, dan menambahkannya ke dalam vector mahasiswaList.
Menutup berkas setelah selesai.
void tampilkanMenu()

Deskripsi: Fungsi ini menampilkan menu utama program kepada pengguna.
Proses:
Mencetak opsi menu yang tersedia, termasuk menambah data, menampilkan data, mencari data, mengurutkan data, menyimpan data, dan membaca data.
Contoh Penggunaan
Setelah mendefinisikan fungsi-fungsi di atas, Anda dapat menggunakan fungsi-fungsi tersebut dalam main() untuk mengelola data mahasiswa. Berikut adalah contoh struktur main() yang menggunakan fungsi-fungsi tersebut:

int main() {
    vector<Mahasiswa> mahasiswaList;
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih opsi (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
