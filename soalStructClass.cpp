#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    float ipk;

public:
    Mahasiswa(string nama, string nim, float ipk) {
        this->nama = nama;
        this->nim = nim;
        this->ipk = ipk;
    }

    string getNama() { return nama; }
    string getNim()  { return nim; }
    float  getIpk()  { return ipk; }

    void tampilkan() {
        cout << left
             << setw(20) << nama
             << setw(15) << nim
             << fixed << setprecision(2) << ipk << endl;
    }
};

class SistemMahasiswa {
private:
    vector<Mahasiswa> daftarMahasiswa;

public:
    // buat nambah data mahasiswa baru ke dalam daftar
    void tambahMahasiswa() {
        string nama, nim;
        float ipk;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Nama  : ";
        getline(cin, nama);
        cout << "Masukkan NIM   : ";
        getline(cin, nim);
        cout << "Masukkan IPK   : ";
        while (!(cin >> ipk) || ipk < 0.0 || ipk > 4.0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "IPK tidak valid (0.00 - 4.00). Masukkan ulang: ";
        }

        daftarMahasiswa.push_back(Mahasiswa(nama, nim, ipk));
        cout << "\nData mahasiswa berhasil ditambahkan!\n";
    }

    // buat nampilin semua data mahasiswa yang udah disimpan
    void tampilkanSemua() {
        if (daftarMahasiswa.empty()) {
            cout << "\nBelum ada data mahasiswa.\n";
            return;
        }
        cout << "\n" << string(50, '=') << endl;
        cout << left << setw(20) << "Nama"
                     << setw(15) << "NIM"
                     << "IPK" << endl;
        cout << string(50, '-') << endl;
        for (auto& mhs : daftarMahasiswa)
            mhs.tampilkan();
        cout << string(50, '=') << endl;
    }

    // buat ngitung rata-rata IPK dari semua mahasiswa
    void hitungRataRataIPK() {
        if (daftarMahasiswa.empty()) {
            cout << "\nBelum ada data mahasiswa.\n";
            return;
        }
        float total = 0;
        for (auto& mhs : daftarMahasiswa)
            total += mhs.getIpk();
        float rata = total / daftarMahasiswa.size();
        cout << fixed << setprecision(2);
        cout << "\nRata-rata IPK seluruh mahasiswa: " << rata << endl;
    }

    // buat nyari mahasiswa dengan IPK paling tinggi
    void mahasiswaIPKTertinggi() {
        if (daftarMahasiswa.empty()) {
            cout << "\nBelum ada data mahasiswa.\n";
            return;
        }
        Mahasiswa* terbaik = &daftarMahasiswa[0];
        for (auto& mhs : daftarMahasiswa)
            if (mhs.getIpk() > terbaik->getIpk())
                terbaik = &mhs;

        cout << "\nMahasiswa dengan IPK Tertinggi:\n";
        cout << string(40, '-') << endl;
        cout << "Nama : " << terbaik->getNama() << endl;
        cout << "NIM  : " << terbaik->getNim()  << endl;
        cout << fixed << setprecision(2);
        cout << "IPK  : " << terbaik->getIpk()  << endl;
    }

    // buat nyari mahasiswa yang IPK-nya paling rendah
    void mahasiswaIPKTerendah() {
        if (daftarMahasiswa.empty()) {
            cout << "\nBelum ada data mahasiswa.\n";
            return;
        }
        Mahasiswa* terburuk = &daftarMahasiswa[0];
        for (auto& mhs : daftarMahasiswa)
            if (mhs.getIpk() < terburuk->getIpk())
                terburuk = &mhs;

        cout << "\nMahasiswa dengan IPK Terendah:\n";
        cout << string(40, '-') << endl;
        cout << "Nama : " << terburuk->getNama() << endl;
        cout << "NIM  : " << terburuk->getNim()  << endl;
        cout << fixed << setprecision(2);
        cout << "IPK  : " << terburuk->getIpk()  << endl;
    }
};

int main() {
    SistemMahasiswa sistem;
    int pilihan;

    do {
        cout << "\n" << string(35, '=') << endl;
        cout << "           MENU UTAMA" << endl;
        cout << string(35, '=') << endl;
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Seluruh Data Mahasiswa\n";
        cout << "3. Hitung Rata-rata IPK Mahasiswa\n";
        cout << "4. Mahasiswa dengan IPK Tertinggi\n";
        cout << "5. Mahasiswa dengan IPK Terendah\n";
        cout << "6. Keluar\n";
        cout << string(35, '-') << endl;
        cout << "Pilih menu: ";

        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Pilih menu (1-6): ";
        }

        switch (pilihan) {
            case 1: sistem.tambahMahasiswa();       break;
            case 2: sistem.tampilkanSemua();        break;
            case 3: sistem.hitungRataRataIPK();     break;
            case 4: sistem.mahasiswaIPKTertinggi(); break;
            case 5: sistem.mahasiswaIPKTerendah();  break;
            case 6: cout << "\nTerima kasih. Program selesai.\n"; break; // buat keluar dan nutup program
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}


// Adit membuat bagian a sampai c
// Elle bagian membuat fungsi dari d sampai f
