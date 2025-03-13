#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

bool check_string(string &captcha, string &user_captcha){
   return captcha.compare(user_captcha) == 0;
}
string gen_captcha(int n){
   time_t t;
   srand((unsigned)time(&t));
   char *chrs = "abcdefghijklmnopqrstuvwxyz" "0123456789";
   string captcha = "";
   while (n--)
      captcha.push_back(chrs[rand()%62]);
   return captcha;
}

struct laundry{
    int menu;
    char pesan[10];
    int paket;
    int berat;
    int bayar;
    int krr;

};

void label(){
   cout << "+============================================+" <<endl;
   cout << "+    Program Laundry dan Tracking Pesanan    +" <<endl;
   cout << "+============================================+" <<endl;
}

void kurir(){
    cout << "\nPilihan Pengiriman : " <<endl;
    cout << "1. Gosend" <<endl;
    cout << "2. JNE Express" <<endl;
    cout << "3. SiCepat REG" <<endl;
}


int main()
{
laundry lnd;
char nama[20],pass[20],pil,alamat[50];
int h1,h2,h3;
h1 = 13000;
h2 = 10000;
h3 = 7000;
bool login=true;

 do{
    cout <<"\n\nLOGIN"<<endl<<endl;
    cout<<"Masukkan username : "; cin>>nama;
    cout<<"Masukkan password : "; cin>>pass;
    if (strcmp(pass,strrev(nama))==0){
        cout<<"Login Berhasil"<<endl<<endl;
           string captcha = gen_captcha(4);
   cout << captcha;
   string usr_captcha;
   cout << "\nEnter CAPTCHA : " ;cin >> usr_captcha;
   if (check_string(captcha, usr_captcha)){
      printf("\nCAPTCHA Matched");
      login=false;}
   else{
      printf("\nCAPTCHA Not Matched");
        login=true;}
    }
    else{
        cout<<"Login Gagal"<<endl<<endl;
    }
 }while (login);

do{

system("cls");
 label();

   cout << "\n1. Pendaftaran" << endl;
   cout << "2. Price List" << endl;
   cout << "3. Tracking" << endl;
   cout << "\nMasukkan Pilihan : "; cin >>lnd.menu;
   if(lnd.menu==1){
    system("cls");
    label();
    cout << "\nPesanan Atas Nama : "; cin>>lnd.pesan;
    cout << "\nSilakan memilih paket Laundry" <<endl;
    cout << "\n1. Paket Express" <<endl;
    cout << "2. Paket Ekonomi" <<endl;
    cout << "3. Paket Reguler" <<endl;
    cout << "\nMasukkan Pilihan : "; cin >> lnd.paket;
    if(lnd.paket==1){
        system("cls");
        label();
        cout << "\nAnda memilih paket Express \nHarga per-kilogram paket express sebesar Rp. 13.000  \nProses laundry akan berlangsung selama 2 hari \nLaundry akan dikirimkan ke tujuan" <<endl;
        cout << "\nMasukkan total berat pakaian anda (satuan kilogram) : "; cin>> lnd.berat;
        kurir();
        cout << "\nMasukkan Pilihan Pengiriman : " ; cin>>lnd.krr;
        cout << "\nMasukkan Alamat Anda : "; gets(alamat);
        gets(alamat);
        if(lnd.berat>=10){
        system("cls");
        label();
        cout << "\nSelamat Anda Mendapat Diskon Sebesar 15% \nTotal Biaya Laundry Anda Sebesar : Rp." << (h1*lnd.berat*0.85)<<endl;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 "<<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 "<<endl;
        }
        }else{
        system("cls");
        label();
        cout <<"\nTotal Biaya Laundry Anda Sebesar : Rp." << h1*lnd.berat;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 "  <<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 " <<endl;
        }
        }
    }else if(lnd.paket==2){
    system("cls");
    label();
    cout << "\nAnda memilih paket Ekonomi \nHarga per-kilogram paket Ekonomi sebesar Rp. 10.000  \nProses laundry akan berlangsung selama 2 hari \nLaundry akan dikirimkan ke tujuan" <<endl;
    cout << "\nMasukkan total berat pakaian anda (satuan kilogram) : "; cin>> lnd.berat;
    kurir();
    cout << "\nMasukkan Pilihan Pengiriman : " ; cin>>lnd.krr;
    cout << "\nMasukkan Alamat Anda : "; gets(alamat);
    gets(alamat);
    kurir();
    cout << "\nMasukkan Pilihan Pengiriman : " << lnd.krr <<endl;
    if(lnd.berat>=10){
        system("cls");
        label();
        cout << "\nSelamat Anda Mendapat Diskon Sebesar 12% \nTotal Biaya Laundry Anda Sebesar : Rp." << h2*lnd.berat*0.88<<endl;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 "<<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 " <<endl;
        }
        }else{
        system("cls");
        label();
        cout <<"\nTotal Biaya Laundry Anda Sebesar : Rp." << h2*lnd.berat;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 " <<endl;
        }
        }
    }else if(lnd.paket==3) {
    cout << "\nAnda memilih paket Reguler \nHarga per-kilogram paket Reguler sebesar Rp. 7.000  \nProses laundry akan berlangsung selama 4 hari \nLaundry Harus Diambil di Tempat" <<endl;
    cout << "\nMasukkan total berat pakaian anda (satuan kilogram) : "; cin>> lnd.berat;
    if(lnd.berat>=10){
        system("cls");
        label();
        cout << "\nSelamat Anda Mendapat Diskon Sebesar 10% \nTotal Biaya Laundry Anda Sebesar : Rp." << h3*lnd.berat*0.9<<endl;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 " <<endl;
        }
        }else{
        system("cls");
        label();
        cout <<"\nTotal Biaya Laundry Anda Sebesar : Rp." << h3*lnd.berat;
        cout << "\nBerikut Opsi Pembayaran : \n1. Dana \n2. Ovo \n3. BCA" <<endl;
        cout << "\nPilihan Pembayaran : " ;cin >> lnd.bayar;
        cout << "\nTerimakasih "<<lnd.pesan<<", Pesanan Anda Akan Segera Kami Proses.\nSilakan menyelesaikan proses pembayaran dengan melakukan transfer." <<endl;
        if(lnd.bayar==1){
            cout <<"\nTransfer melalui Dana ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==2){
            cout <<"\nTransfer melalui OVO ke Nomor berikut : 088802181589 " <<endl;
        }else if(lnd.bayar==3){
            cout <<"\nTransfer melalui BCA ke Nomor rekening berikut : 6293211914 " <<endl;
        }
        }
    }
   }else if(lnd.menu==2){
   system("cls");
   label();
   cout << "\nPrice List Paket Laundry" <<endl;
   cout << "\n1. Paket Express : Rp. 13.000 per-Kg  (termasuk ongkir)\nProses Laundry Selama 2 Hari \nLaundry Akan dikirim ke Tujuan" << endl;
   cout << "\n2. Paket Ekonomi : Rp. 10.000 per-Kg (termasuk ongkir) \nProses Laundry Selama 4 Hari \nLaundry Akan dikirim ke Tujuan" << endl;
   cout << "\n3. Paket Reguler : Rp. 7.000 per-Kg \nProses Laundry Selama 4 Hari \nLaundry Harus Diambil di Tempat" << endl;
       }
       else if(lnd.menu==3){
       if(strlen(lnd.pesan)==0){
        system ("cls");
        label();
        cout << "\nMohon maaf, Anda belum melakukan pemesanan"<<endl;
        }else
        {
        cout << "\nPesanan Atas Nama : " << lnd.pesan << endl;
        if(lnd.paket==1){
        cout << "Paket Yang Dipilih : Paket Express " <<endl;
        cout << "Alamat Pemesan : " << alamat <<endl;
        }else if(lnd.paket==2){
        cout << "Paket Yang Dipilih : Paket Ekonomi " <<endl;
        cout << "Alamat Pemesan : " << alamat <<endl;
        }else if(lnd.paket==3){
        cout << "Paket Yang Dipilih : Paket Reguler " <<endl;
        }
        cout << "Berat Laundry : " << lnd.berat << " Kilogram"<<endl;
        if (lnd.paket==1){
            if(lnd.berat>=10){
                cout<<"Total Harga : Rp."<<h1*lnd.berat*0.85;
            }else{
                cout<<"Total Harga : Rp."<<h1*lnd.berat;
            }
        }
        else if(lnd.paket==2){
            if(lnd.berat>=10){
                cout<<"Total Harga : Rp."<<h2*lnd.berat*0.88;
            }else{
                cout<<"Total Harga : Rp."<<h2*lnd.berat;
            }
        }
        else if(lnd.paket==3){
            if(lnd.berat>=10){
                cout<<"Total Harga : Rp."<<h3*lnd.berat*0.9;
            }else{
                cout<<"Total Harga : Rp."<<h3*lnd.berat;
            }
        }
        if (lnd.krr==1)
            cout << "\nJasa Pengiriman :  Gosend" <<endl;
        else if (lnd.krr == 2)
            cout << "\nJasa Pengiriman :  JNE Express" <<endl;
        else if (lnd.krr ==3 )
            cout << "\nJasa Pengiriman :  SiCepat REG" <<endl;
            }
        }

   else{
   cout << "Mohon Maaf Pilihan Tidak Tersedia."<<endl;
   }

   cout<<"\nApakah Anda Ingin Logout? (Y/T) : "; cin>>pil;
 }while (pil!='Y' && pil!='y');
    cout << endl;
    system("cls");
    cout << "Anda telah Logout."<<endl;
    getch();
}

