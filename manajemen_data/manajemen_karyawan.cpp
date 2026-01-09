#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct karyawan
{
    string nik;
    string nama;
};

void tampilMenu() {
    cout << "==== Menu Manajemen Data Karyawan ====" << endl;
    cout << "1. Tambah Data Karyawan" << endl;
    cout << "2. Tampilkan Data Karyawan" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih opsi (1-3):";
};

int main(){
    vector<karyawan> data;
    int pilihan;

    while (true)
    {
        tampilMenu();

        if (!(cin >> pilihan))
        {
            cout << "Input harus angka!\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        switch (pilihan)
        {
        case 1:{
            karyawan k;
            cout << "\n--- Tambah Data Karyawan ---\n";
            cout << "Masukkan NIK: ";
            cin >> k.nik;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan Nama: ";
            getline(cin, k.nama);

            data.push_back(k);
            cout << "Data karyawan berhasil ditambahkan!\n";
            break;
        }
        case 2:{
            cout << "\n--- Data Karyawan ---\n";
            if (data.empty())
            {
                cout << "Data masih kosong\n";
            }else{
                cout << left << setw(5) << "N0"
                     << setw(15) << "NIK"
                     << setw(25) << "Nama" << endl;
                cout << string(45, '-') << endl;
            
                for (int i = 0; i < (int)data.size(); i++)
                {
                    cout << left << setw(5) << (i+1)
                     << setw(15) << data[i].nik
                     << setw(25) << data[i].nama << endl;
                }
            }
            break;
        }
        case 3:
            cout << "\nKeluar dari program.";
            return 0;
        default:
            cout << "Masukkan input yang valid!";
            break;
        }
    }
    return 0;
}