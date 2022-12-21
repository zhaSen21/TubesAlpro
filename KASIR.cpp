#include <iostream>
#include <stdio.h>
#include <math.h>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int akhir,diskon,uang;
int pilihanutama,pilihankedua;

int jumDimensi, jumBaris, jumKolom;
int jumlahBarang;
int tempjumlah;
int pilihanPembayaran;
int uangpelanggan;
int hasilcash;
int hasilconst;
int totalsem[100];
int hasil[100];
int totaljum[100];
int harga[100];
string barang[100];

int dafHar[][4][3]= {
                                {
                                    { 3500, 3500, 4000 },
                                    { 21000, 19000, 23000 },
                                    { 3500, 3500, 4000 },
                                    { 8000, 2500, 5000 }

                                },

                                {
                                    { 8000, 12000, 13000 },
                                    { 4000, 14000, 10000 },
                                    { 14500, 5000, 5000 },
                                    { 6000, 60000, 16900 }
                                },
                        };

string barHar[][4][3]= {
                                {
                                    { "Mie Goreng 1 pcs           ", "Mie Kuah 1 pcs             ", "Mie Kari 1 pcs             " },
                                    { "Samyang Goreng 1 pcs       ", "Samyang Kuah 1 pcs         ", "Samyang Kari 1 pcs         " },

                                    { "Mie Cakalang 1 pcs         ", "Mie Aceh 1 pcs             ", "Mie Padang 1 pcs           " },
                                    { "Mie Lemonilo 1 pcs         ", "Mie Eko 1 pcs              ", "Mie Tasty 1 pcs            " }

                                },

                                {
                                    { "Tepung Terigu 1 Kg         ", "Tepung Tapioka 1 kg        ", "Tepung Roti 500 g          " },
                                    { "Garam 250 g                ", "Gula 1 kg                  ", "Kecap 135 ml               " },
                                    { "Sambal ABC 335 ml          ", "Aqua Botol                 ", "Le Minerale Botol          " },
                                    { "Fruit Tea Strawberry 500 mL", "Aqua Galon 19 Liter        ", "Le Minerale Galon 15 Liter " }
                                },
                        };
int tambahan;

int baris = sizeof(barHar) / sizeof(barHar[0]);
int kolom = sizeof(barHar[0]) / sizeof(barHar[0][0]);
int dimensi = sizeof(barHar[0][0]) / sizeof(barHar[0][0][0]);

char masukanKembali;
char kembali = 'y';
char uatauk;
char terkembali = 'k';
char ulangi = 'u';

void pilihanPertama();
void daftar();
void masukAkun();
void lupa();
void daftarBarang();
void menuKasir();
void metodepembayaran();
void strukpembelian();

int main(){
    system("color 70");
    pilihanPertama();

    switch(pilihanutama){

    case 1 :
        masukAkun();

        menuKasir();

    break;

    case 2 :
        daftar();

    break;

    case 3 :
        lupa();

    break;

    default :
    cout<<"                             ~~~~~~~~~~   Pilihan Tidak Tersedia   ~~~~~~~~~~~"<<endl;
    cout<<"                                         Tekan enter untuk kembali"<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();

    }

return 0;

}

void menuKasir()
{
    system("cls");
    cout<<endl<<endl<<endl<<endl;
    cout<<"                             ~~~~~~~~~~~~~~~~~  Menu Kasir  ~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"                                Halo, Senang Melihat Anda Kembali !"<<endl<<endl;
    cout<<"                             1. Kasir"<<endl;
    cout<<"                             2. Kasir (Semua dari Input User)"<<endl;
    cout<<"                             3. Daftar Barang dan Harga"<<endl;
    cout<<"                             4. Logout"<<endl;
    cout<<"                             Apa yang ingin anda lakukan hari ini ? : ";
    cin>>pilihankedua;
    system("cls");

    switch(pilihankedua)
    {

    case 1 :

        int kodeDimensi,kodeBaris,kodeKolom;

        int a;
    do{
        for(int l = 0;l < 100;l++){
            totalsem[l] = 0;
            hasil[l]= 0;
            totaljum[l]= 0;
            harga[l]= 0;
            hasilconst = 0;
            akhir = 0;
            diskon = 0;
        }
        system("cls");
        a = 0;
        cout<<endl<<endl<<endl;
        cout<<"                             ~~~~~~~~~~~~~~~~~  KASIR  ~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"                             Berapa jenis barang yang dibeli ? : ";
        cin>>jumlahBarang;
        system("cls");
        if(jumlahBarang == 0){
        cout<<endl;
        cout<<"                             Tolong Masukkan Input Yang Benar !"<<endl;
        cout<<"                             Tekan 'Enter' untuk kembali !"<<endl;
        cin.get();
        cin.get();
        menuKasir();
        }
        system("cls");

        daftarBarang();
        cout<<endl;


        for(int i = 0; i < jumlahBarang; i++){
            a++;

            cout<<"                             Masukkan Kode Barang "<< a <<" : ";
            cin>>kodeDimensi;


            cout<<endl;
            cout<<"                             Barang ke "<<a<< " : " <<kodeDimensi<< " _ _ "<<endl;
            cout<<"                             Masukkan Kode Barang "<< a <<" : ";
            cin>>kodeBaris;

            cout<<endl;
            cout<<"                             Barang ke "<<a<< " : " <<kodeDimensi<< " " <<kodeBaris<<" _ "<<endl;
            cout<<"                             Masukkan Kode Barang "<< a <<" : ";
            cin>>kodeKolom;

            cout<<endl;
            cout<<"                             Barang ke "<<a<< " : " <<kodeDimensi<< " " <<kodeBaris<< " " <<kodeKolom<<endl;
            system("cls");
            daftarBarang();
            cout<<endl;
            cout<<"                             Barang "<<a<<" : "<<barHar[kodeDimensi][kodeBaris][kodeKolom]<<" = "<<dafHar[kodeDimensi][kodeBaris][kodeKolom]<<endl;
            cout<<"                             Berapa jumlah barang "<<a<<" ? : ";
            cin>>tempjumlah;
            totaljum[i+1] = tempjumlah;
            barang[i+1] = barHar[kodeDimensi][kodeBaris][kodeKolom];
            harga[i+1] = dafHar[kodeDimensi][kodeBaris][kodeKolom];
            system("cls");
            daftarBarang();


        }
        for(int c = 0; c < jumlahBarang;c++){
            hasil[c+1] = harga[c+1] * totaljum[c+1];
            totalsem[c+1] = hasil[c+1];
        }
        for(int v = 0; v < jumlahBarang;v++){
            hasilconst = hasilconst + totalsem[v+1];
        }

        system("cls");



        strukpembelian();


        metodepembayaran();


        switch(pilihanPembayaran)
        {
        case 1 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"========================= PEMBAYARAN CASH ==========================="<<endl;
            cout<<"                             Jumlah Uang Pembeli : ";
            cin>>uangpelanggan;
            hasilcash = uangpelanggan - akhir;
            if(hasilcash < 0)
            {

                cout<<endl;
                cout<<"                             Uang Tidak Cukup !"<<endl;
                cout<<"                             Tranksaksi Dibatalkan, Tekan 'Enter' untuk kembali"<<endl;
                cin.get();
                cin.get();
                menuKasir();
            }

            break;

        case 2 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================= PEMBAYARAN VIA DANA ========================="<<endl;
            cout<<"                Silahkan Transfer Ke 0888 2222 1112                  "<<endl;
            cout<<"                         Atas Nama DK Ruko                           "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }

            break;

        case 3 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================== PEMBAYARAN VIA OVO ========================="<<endl;
            cout<<"                Silahkan Transfer Ke 0822 2344 5536                  "<<endl;
            cout<<"                        Atas Nama DK Ruko OVO                        "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            break;

        case 4 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================= PEMBAYARAN VIA GOPAY ========================"<<endl;
            cout<<"                Silahkan Transfer Ke 0822 2344 5536                  "<<endl;
            cout<<"                         Atas Nama Ruko DK                           "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            break;

        default :
            system("cls");
            cout<<endl<<endl<<endl;
            cout<<"                             ~~~~~~~~~~   Pilihan Tidak Tersedia   ~~~~~~~~~~~"<<endl;
            cout<<"                                         Tekan enter untuk kembali"<<endl;
            cin.get();
            cin.get();
            system("cls");
            menuKasir();
            break;
        }
        system("cls");

        strukpembelian();
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                                                          KEMBALI    "<<endl;
        cout<<"                                                     |     "<<hasilcash<<"     |"<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                   TERIMA KASIH TELAH BELANJA DISINI !               "<<endl;
        cout<<endl<<endl<<endl;
        cout<<"                             Kembali/Ulangi ? (k/u) :  ";
        cin>>uatauk;

    }while(uatauk == ulangi);
        system("cls");
        menuKasir();

        break;

    case 2 :
    do{
        for(int l = 0;l < 100;l++){
            totalsem[l] = 0;
            hasil[l]= 0;
            totaljum[l]= 0;
            harga[l]= 0;
            hasilconst = 0;
            akhir = 0;
            diskon = 0;
            hasilcash = 0;
        }
        system("cls");
        a = 0;
        cout<<endl<<endl<<endl;
        cout<<"                             ~~~~~~~~~~~~~~  KASIR MANUAL  ~~~~~~~~~~~~~~"<<endl;
        cout<<"                             Berapa jenis barang yang dibeli ? : ";
        cin>>jumlahBarang;
        system("cls");
        if(jumlahBarang == 0){
        cout<<endl;
        cout<<"                             Tolong Masukkan Input Yang Benar !"<<endl;
        cout<<"                             Tekan 'Enter' untuk kembali !"<<endl;
        cin.get();
        cin.get();
        menuKasir();
        }
        for(int i = 0; i < jumlahBarang; i++)
        {
            cout<<"                             ~~~~~~~~~~~~~~  KASIR MANUAL  ~~~~~~~~~~~~~~"<<endl<<endl;
            a++;
            cout<<endl<<endl<<endl;
            cout<<"                             Nama Barang "<<a<<" : ";
            cin.ignore();
            getline(std::cin,barang[i+1]);
            cout<<"                             Harga Barang "<<a<<" : ";
            cin>>harga[i+1];
            cout<<"                             Jumlah Barang "<<a<<" : ";
            cin>>totaljum[i+1];
            system("cls");
        }

        for(int c = 0; c < jumlahBarang;c++){
            hasil[c+1] = harga[c+1] * totaljum[c+1];
            totalsem[c+1] = hasil[c+1];
        }
        for(int v = 0; v < jumlahBarang;v++){
            hasilconst = hasilconst + totalsem[v+1];
        }

        cout<<endl;
        cout<<"                          - STRUK PEMBELIAN -                        "<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"   Nomor              Barang                 Jumlah        Harga     "<<endl;
        cout<<"_____________________________________________________________________"<<endl;

        for(int n = 0; n < jumlahBarang;n++){
        cout<<"|    "<<n+1<<"    | "<<barang[n+1]<<"   |     "<<totaljum[n+1]<<"     |     "<<harga[n+1]<<"    |"<<endl;
        }
        cout<<"______________________________________________________________________"<<endl;
        cout<<"                                                           DISKON     "<<endl;
        if ((hasilconst>=75000) && (hasilconst<100000)){
        diskon=hasilconst*0.10;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      10%     |"<<endl;
        } else if ((hasilconst>=100000) && (hasilconst<500000)){
        diskon=hasilconst*0.2;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      20%     |"<<endl;
        } else if (hasilconst>=500000){
        diskon=hasilconst*0.3;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      30%     |"<<endl;
        }else {

        cout<<"                                                     |      0%      |"<<endl;
            akhir=hasilconst;
        }
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                                                           TOTAL     "<<endl;
        cout<<"                                                     |     "<<akhir<<"    |"<<endl;



        metodepembayaran();


        switch(pilihanPembayaran)
        {
        case 1 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"========================= PEMBAYARAN CASH ==========================="<<endl;
            cout<<"                             Jumlah Uang Pembeli : ";
            cin>>uangpelanggan;
            hasilcash = uangpelanggan - akhir;
            if(hasilcash < 0)
            {

                cout<<endl;
                cout<<"                             Uang Tidak Cukup !"<<endl;
                cout<<"                             Tranksaksi Dibatalkan, Tekan 'Enter' untuk kembali"<<endl;
                cin.get();
                cin.get();
                menuKasir();
            }

            break;

        case 2 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================= PEMBAYARAN VIA DANA ========================="<<endl;
            cout<<"                Silahkan Transfer Ke 0888 2222 1112                  "<<endl;
            cout<<"                         Atas Nama DK Ruko                           "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }

            break;

        case 3 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================== PEMBAYARAN VIA OVO ========================="<<endl;
            cout<<"                Silahkan Transfer Ke 0822 2344 5536                  "<<endl;
            cout<<"                        Atas Nama DK Ruko OVO                        "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            break;

        case 4 :
            system("cls");
            strukpembelian();
            cout<<endl;
            cout<<"======================= PEMBAYARAN VIA GOPAY ========================"<<endl;
            cout<<"                Silahkan Transfer Ke 0822 2344 5536                  "<<endl;
            cout<<"                         Atas Nama Ruko DK                           "<<endl;
            cout<<endl;
            cout<<"                   Apakah Uang Sudah Masuk? (y/t) : ";
            cin>>kembali;
            if(kembali == 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                      Tranksaksi Dibatalkan !                        "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            else if(kembali != 'y' && kembali != 't')
            {
                system("cls");
                cout<<endl;
            cout<<"                    Tolong Input yang benar !!!                      "<<endl;
            cout<<"                    Tekan 'Enter' untuk kembali"<<endl;
            cin.get();
            cin.get();
            menuKasir();
            }
            break;

        default :
            system("cls");
            cout<<endl<<endl<<endl;
            cout<<"                             ~~~~~~~~~~   Pilihan Tidak Tersedia   ~~~~~~~~~~~"<<endl;
            cout<<"                                         Tekan enter untuk kembali"<<endl;
            cin.get();
            cin.get();
            system("cls");
            menuKasir();
            break;
        }
        system("cls");
        strukpembelian();
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                                                          KEMBALI    "<<endl;
        cout<<"                                                     |     "<<hasilcash<<"     |"<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                   TERIMA KASIH TELAH BELANJA DISINI !               "<<endl;
        cout<<endl<<endl<<endl;

        cout<<"                             Kembali/Ulangi ? (k/u) :  ";
        cin>>uatauk;

    }while(uatauk == ulangi);
        system("cls");
        menuKasir();




        cout<<endl;



        break;
    case 3 :

        daftarBarang();

        do{
            cout<<endl;
            cout<<"                             Kembali ? (y) : ";
            cin>>masukanKembali;
            if(masukanKembali == kembali){
            menuKasir();
            }
            else{
                system("cls");

                daftarBarang();
                cout<<endl;
                cout<<"                         ~~~ Tolong Input yang benar ! ~~~"<<endl;
            }
        }while(masukanKembali != kembali);

        break;

    case 4 :

        cout<<"                             Anda berhasil logout !"<<endl;
        cout<<"                             Tekan 'Enter' untuk melanjutkan !"<<endl<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();
        break;



    default :
        cout<<endl<<endl<<endl;
        cout<<"                             ~~~~~~~~~~   Pilihan Tidak Tersedia   ~~~~~~~~~~~"<<endl;
        cout<<"                                         Tekan enter untuk kembali"<<endl;
        cin.get();
        cin.get();
        system("cls");
        menuKasir();
    }

}

void metodepembayaran()
{
        cout<<endl<<endl<<endl;
        cout<<"========================= METODE PEMBAYARAN ========================="<<endl;
        cout<<"                             1. Cash"<<endl;
        cout<<"                             2. Dana"<<endl;
        cout<<"                             3. Ovo"<<endl;
        cout<<"                             4. Gopay"<<endl;
        cout<<"                             Pilih Metode Pembayaran : ";
        cin>>pilihanPembayaran;
}

void strukpembelian()
{
        cout<<endl;
        cout<<"                          - STRUK PEMBELIAN -                        "<<endl;
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"   Nomor              Barang                 Jumlah        Harga     "<<endl;
        cout<<"_____________________________________________________________________"<<endl;

        for(int n = 0; n < jumlahBarang;n++){
        cout<<"|    "<<n+1<<"    | "<<barang[n+1]<<"   |     "<<totaljum[n+1]<<"     |     "<<harga[n+1]<<"    |"<<endl;
        }

        cout<<"______________________________________________________________________"<<endl;
        cout<<"                                                           DISKON     "<<endl;
        if ((hasilconst>=75000) && (hasilconst<100000)){
        diskon=hasilconst*0.10;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      10%     |"<<endl;
        } else if ((hasilconst>=100000) && (hasilconst<500000)){
        diskon=hasilconst*0.2;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      20%     |"<<endl;
        } else if (hasilconst>=500000){
        diskon=hasilconst*0.3;
        akhir=hasilconst-diskon;

        cout<<"                                                     |      30%     |"<<endl;
        }else {

        cout<<"                                                     |      0%      |"<<endl;
            akhir=hasilconst;
        }
        cout<<"_____________________________________________________________________"<<endl;
        cout<<"                                                           TOTAL     "<<endl;
        cout<<"                                                     |     "<<akhir<<"    |"<<endl;
}

void pilihanPertama(){

    cout<<endl<<endl;
    cout<<"                             ~~~~~~~~~~~~~~~~~ PROGRAM KASIR ~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"                             ~~~~~~~~~~~~~~~~~  Menu Utama  ~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"                             1. Masuk"<<endl;
    cout<<"                             2. Daftar"<<endl;
    cout<<"                             3. Lupa Akun"<<endl;
    cout<<"                             Silahkan masukkan pilihan : ";
    cin>>pilihanutama;
    system("cls");
}

void daftar(){
    string daftarUser,daftarPass;
    system("cls");
    cout<<endl<<endl<<endl<<endl;
    cout<<"                             ~~~~~~~~~~~~~~~~~  Daftar Akun  ~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"                             Masukkan Username : ";
    cin>>daftarUser;
    cout<<"                             Masukkan Password : ";
    cin>>daftarPass;

    ofstream daf("database.txt", ios::app);
    daf<<daftarUser<<' '<<daftarPass<<endl;
    system("cls");
    cout<<"                             ~~~~~~~~~~~~~~~~~  Daftar Akun  ~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"                             Pendaftaran Berhasil ! Tekan Enter untuk Kembali"<<endl;
    cin.get();
    cin.get();
    system("cls");
    main();
}

void masukAkun(){

    int terdaftar;
    string Nama,Sandi,u,p;
    system("cls");
    cout<<endl<<endl<<endl<<endl;
    cout<<"                             ~~~~~~~~~~~~~~~~~  Login Akun  ~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"                             Username : ";
    cin>>Nama;
    cout<<"                             Password : ";
    cin>>Sandi;

    ifstream pemasuk("database.txt");

    while(pemasuk>>u>>p){
        if(u == Nama && p == Sandi){
            terdaftar = 1;
        }
    }
    pemasuk.close();
    if(terdaftar == 1){

    }
    else{
        cout<<endl;
        cout<<"                             Maaf, Username atau Password salah (Perhatikan Huruf Kapital)"<<endl;
        cout<<"                             Tekan enter untuk kembali"<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();
    }

}

void lupa(){
    int pilihanLupa;
    system("cls");
    cout<<"                             1. Temukan akun melalui Username"<<endl;
    cout<<"                             2. Temukan akun melalui Password"<<endl;
    cout<<"                             3. Kembali"<<endl;
    cout<<"                             Masukkan Pilihan : ";
    cin>>pilihanLupa;
    system("cls");

    switch(pilihanLupa){
    case 1:{
            int ex = 0;
            string mencariUser,su,sp;
            cout<<"                             Masukkan Username yang diingat : ";
            cin>>mencariUser;

            ifstream mencariu("database.txt");
            while(mencariu>>su>>sp)
            {
                if(su==mencariUser)
                {
                    ex = 1;
                    break;
                }
            }
            mencariu.close();
            if(ex == 1)
            {
                system("cls");
                cout<<endl;
                cout<<"                             Akunmu Ditemukan !"<<endl<<endl;
                cout<<"                             Usernamemu Adalah : "<<su<<endl;
                cout<<"                             Passwordmu Adalah : "<<sp<<endl;
                cout<<"                             Tekan untuk Kembali ke menu awal";
                cin.get();
                cin.get();
                system("cls");
                main();
            }
            else
            {
                system("cls");
                cout<<endl;
                cout<<"                             Maaf Akunmu tidak ditemukan, Tekan untuk Kembali"<<endl;
                cin.get();
                cin.get();
                system("cls");
                main();

            }

            break;
    }
    case 2:{
        int ax = 0;
        string mencariPass, su2,sp2;
        cout<<"                             Masukkan Password yang diingat : ";
        cin>>mencariPass;

        ifstream mencariP("database.txt");
        while (mencariP>>su2>>sp2){
            if(sp2 == mencariPass){
                ax = 1;
                break;
            }
        }
        if(ax == 1){
            system("cls");
            cout<<endl;
            cout<<"                             Akunmu Ditemukan !"<<endl<<endl;
            cout<<"                             Usernamemu Adalah : "<<su2<<endl;
            cout<<"                             Passwordmu Adalah : "<<sp2<<endl<<endl;
            cout<<"                             Tekan enter untuk kembali"<<endl;
            cin.get();
            cin.get();
            system("cls");
            main();

        }
        else
        {
            system("cls");
            cout<<endl;
            cout<<"                             Maaf Akunmu tidak ditemukan, Tekan untuk Kembali"<<endl;
            cin.get();
            cin.get();
            system("cls");
            main();

        }
        break;
    }
    case 3:
    {


        main();
        break;
    default :
        {


        cout<<"                             Pilihan Tidak Tersedia, Silakan tekan Enter"<<endl;
        cin.get();
        cin.get();
        system("cls");
        lupa();
        }
    }
    }


}

void daftarBarang(){

        cout<<"============================ Daftar Barang dan Harga ============================"<<endl;
        cout<<"============================ ======================= ============================"<<endl;
        for (int i = 0; i < baris; ++i) {
            for (int j = 0; j < kolom; ++j) {
                for (int k = 0; k < dimensi; ++k) {
                    cout << "=== " << i << j << k <<" = " << barHar[i][j][k] << " : " << dafHar[i][j][k] <<endl;

                }
            }
        }

}



