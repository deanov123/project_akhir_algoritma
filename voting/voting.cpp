#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string kandidat[3] = {"Andi", "Budi", "Citra"};
    int suara[3] = {0, 0, 0};
    
    int jumlahPemilih;
    cout << "==============================\n";
    cout << "         Program Vote Sederhana\n";
    cout << "==============================\n";
    cout << "Masukkan jumlah pemilih: ";

    while (!(cin >> jumlahPemilih) || jumlahPemilih <= 0) 
    {
        cout << "Input tidak valid";
        cin.ignore(10000, '\n');
    }
    
    for (int i = 0; i <= jumlahPemilih; i++)
    {
        int pilihan;
        bool valid = false;

        while (!valid)
        {
            cout << "\nPemilih ke-" << i << "\n";
            cout << "1. " << kandidat[0] << "\n";
            cout << "2. " << kandidat[1] << "\n";
            cout << "3. " << kandidat[2] << "\n";
            cout << "Piliha kandidat (1-3): "<< "\n";

            cin >> pilihan;

            if (pilihan >= 1 && pilihan <= 3)
            {
                suara[pilihan - 1]++;
                valid = true;
            }else{
                cout << "Pilihan tidak valid";
            }
        }
    }

    cout << "\n=========================\n";
    cout << "      Hasil Voting\n";
    cout << "\n=========================\n";
    cout << left << setw(10) << "No"
         << setw(15) << "Kandidat"
         << setw(10) << "Suara" << '\n';
    cout << string(35, '-') << '\n';

    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(10) << (i+1)
         << setw(15) << kandidat[i]
         << setw(10) << suara[i] << '\n';
        total += suara[i];
    }
    cout << string(35, '-') << '\n';
    cout << "Total suara masuk: " << total << '\n';

    int maxSuara = suara[0];

    for (int i = 0; i < 3; i++)
    {
        if (suara[i] > maxSuara)
        {
            maxSuara = suara[i];
        }   
    }

    int jumlahMax = 0;
    for (int i = 0; i < 3; i++)
    {
        if (suara[i] == maxSuara)
        {
            jumlahMax++;
        }
    }

    if (jumlahMax == 1)
    {
        int idxPemenang = 0;
        for (int i = 0; i < 3; i++)
        {
            if (suara[i] == maxSuara)
            {
                idxPemenang = i;
            }
        }
        cout << "Pemenang: " << kandidat[idxPemenang]
             << " dengan " << maxSuara << " Suara\n";
    } else{
        cout << "Hasil SERI dengan " << maxSuara << " suara";
        cout << "Kandidat seri: ";
        bool pertama = true;
        for (int i = 0; i < 3; i++)
        {
            if (suara[i] == maxSuara)
            {
                if (!pertama)
                {
                    cout << ", ";
                }
                cout << kandidat[i];
                pertama = false;
            }
        }
    }
    return 0;
}
