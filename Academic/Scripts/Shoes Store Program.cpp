#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#define MAX 100

using namespace std;

char key[MAX];

struct User{
    string usn;
    string pass;
    string telp;
};

struct JumlahSepatu{
    int jumlahh;
    JumlahSepatu* nextJumlah;
};

struct BrandSepatu{
    string merk, jenis, sera;
    long int harga;
    char pil, pilihanjenis, pilihanmerk, pilihansera;
    JumlahSepatu* firstJumlah;
    BrandSepatu* next;
};

struct BanyakPinjam{
    int banyak;
    BanyakPinjam* nextBanyak;
};

struct BolehPinjam{
    string kategori, merk1,seru,lama;
    long int hargai;
    char pilih, pilihankategori, pilihanmerk1,pilihanseru,pilihanlama;
    BanyakPinjam* firstBanyak;
    BolehPinjam* next;
};

typedef JumlahSepatu* pointerJumlah;
typedef BrandSepatu* pointerBrand;
typedef pointerBrand ListBrand;
ListBrand listBrand;
typedef BanyakPinjam* pointerBanyak;
typedef BolehPinjam* pointerPinjam;
typedef pointerPinjam ListPinjam;
ListPinjam listPinjam;
void masuk();
void abudganteng();
void PembeliMasuk();
void Signup();
void Login();
void menuawal();
void PegawaiMasuk();
void menuPegawai();
void createListBrand();
void createElementBrand(pointerBrand& pBaru);
void createElementJumlah(pointerJumlah& pBaru);
void insertLastBrand(pointerBrand pBaru);
void insertLastJumlah(pointerJumlah pBaru);
void traversal();
void hapusBrand();
void menupesan();
void bayarbeli();
void createListBolehPinjam();
void createElementBolehPinjam(pointerPinjam& pBaru);
void createElementBanyak(pointerBanyak& pBaru);
void insertLastBolehPinjam(pointerPinjam pBaru);
void insertLastBanyakPinjam(pointerBanyak pBaru);
void insertFirstBanyakPinjam(pointerPinjam pBaru);
void deleteFirstPinjam();
void traversalPinjam();
void hapusPinjam();
void menupinjam();
void bayarpinjam();
void deleteFirstPegawai();
void lihatAntrian(pointerBrand& pBrand);

int jumlahUser(){
    int jumlah = 0;
    fstream file;
	file.open("jumlah_user.txt", ios::in);
	if (file) {
		file >> jumlah;
		file.close();
	}
	return jumlah;
}

void simpanJumlahUser(int jumlah){
    fstream my_file;
	my_file.open("jumlah_user.txt", ios::out);
	if (!my_file) {
		cout << "File not readed!" << endl;
	}else {
		my_file << jumlah;
		my_file.close();
	}
}

void bacaDataUser(User hasil[]){
    int index = 0;
    fstream file;
	file.open("user.txt", ios::in);
	if(file.is_open()){
        string baris;
        while(getline(file, baris)){
            char char_array[baris.length() + 1];
            strcpy(char_array, baris.c_str());
            char *pointer = strtok(char_array, "|");
            string temp;
            int idx = 0;
            User user;
            while (pointer != NULL){
                if(idx == 0){
                    user.usn = pointer;
                    user.telp = pointer;
                }else if(idx == 1){
                    user.pass = pointer;
                }
                pointer = strtok(NULL, "|");
                idx++;
            }
            idx = 0;
            hasil[index] = user;
            index++;
        }
        file.close();
    }
}

void gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void abudganteng(){
	int a;
	//f
	for(a=0;a<=5;a++)
	cout<<"F";Sleep(80);
	for(a=0;a<=5;a++)
	{gotoxy(0,1+a);cout<<"F";Sleep(80);}
	for(a=0;a<=4;a++)
    {gotoxy(1+a,2);cout<<"F";Sleep(80);}

	//e
	for(a=0;a<=6;a++)
	{gotoxy(8,0+a);cout<<"E";Sleep(80);}
	for(a=0;a<=5;a++)
	{gotoxy(9+a,0);cout<<"E";Sleep(80);}
	for(a=0;a<=5;a++)
	{gotoxy(9+a,3);cout<<"E";Sleep(80);}
	for(a=0;a<=5;a++)
	{gotoxy(9+a,6);cout<<"E";Sleep(80);}

	//l
    for(a=0;a<=6;a++)
    {gotoxy(17,0+a);cout<<"L";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(18+a,6);cout<<"L";Sleep(80);}

    //t
	for(a=0;a<=7;a++)
	{gotoxy(26+a,0);cout<<"T";Sleep(80);}
	for(a=0;a<=5;a++)
	{gotoxy(29,1+a);cout<<"T";Sleep(80);}

	//y
    gotoxy(36,0);cout<<"Y";Sleep(80);
    gotoxy(37,1);cout<<"Y";Sleep(80);
    gotoxy(38,2);cout<<"Y";Sleep(80);
    for(a=0;a<=3;a++)
    {gotoxy(39,3+a);cout<<"Y";Sleep(80);}
    gotoxy(40,2);cout<<"Y";Sleep(80);
    gotoxy(41,1);cout<<"Y";Sleep(80);
    gotoxy(42,0);cout<<"Y";Sleep(80);

     //o
    for(a=0;a<=6;a++)
    {gotoxy(45+a,0);cout<<"O";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(45,1+a);cout<<"O";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(51,1+a);cout<<"O";Sleep(80);}
    for(a=0;a<=4;a++)
    {gotoxy(50-a,6);cout<<"O";Sleep(80);}

    //u
    for(a=0;a<=6;a++)
    {gotoxy(54,0+a);cout<<"U";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(55+a,6);cout<<"U";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(60,5-a);cout<<"U";Sleep(80);}

    //n
    for(a=0;a<=6;a++)
    {gotoxy(63,0+a);cout<<"N";Sleep(80);}
    gotoxy(64,0);cout<<"N";Sleep(80);
    gotoxy(65,1);cout<<"N";Sleep(80);
    gotoxy(66,2);cout<<"N";Sleep(80);
    gotoxy(67,3);cout<<"N";Sleep(80);
    gotoxy(68,4);cout<<"N";Sleep(80);
    gotoxy(69,5);cout<<"N";Sleep(80);
    for(a=0;a<=6;a++)
    {gotoxy(70,6-a);cout<<"N";Sleep(80);}

    //g
    for(a=0;a<=6;a++)
    {gotoxy(79-a,0);cout<<"G";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(73,1+a);cout<<"G";Sleep(80);}
    for(a=0;a<=5;a++)
    {gotoxy(74+a,6);cout<<"G";Sleep(80);}
    for(a=0;a<=2;a++)
    {gotoxy(79,5-a);cout<<"G";Sleep(80);}
    for(a=0;a<=4;a++)
    {gotoxy(78-a,3);cout<<"G";Sleep(80);}

	//PROGRAM
	cout<<endl<<endl;
	cin.get();cin.get();
	system("cls");
}

void simpanDataUser(User user){
    int jumlah = jumlahUser();
    User dataUser[jumlah + 1];
    bacaDataUser(dataUser);
    dataUser[jumlah] = user;
    jumlah++;
    fstream file;
	file.open("user.txt", ios::out);
	if(file.is_open()){
	    for(int i=0; i<jumlah; i++){
            string baris = dataUser[i].usn+"|"+dataUser[i].pass+"|"+dataUser[i].telp+"\n";
            file << baris;
        }
        file.close();
    }
    simpanJumlahUser(jumlah);
}

int main(){

    //abudganteng();
    createListBrand();
    createListBolehPinjam();
    masuk();
}

void createListBrand(){
    listBrand=NULL;
}

void createListBolehPinjam(){
    listPinjam=NULL;
}

///////////// PEMBELIAN
void createElementBrand(pointerBrand& pBaru)
{
    menu1:
    pBaru=new BrandSepatu;
    cout<<"\t================="<<endl;
    cout<<"\t   BELI SEPATU   "<<endl;
    cout<<"\t================="<<endl<<endl;
    cout<<"\t1. Patrobas"<<endl;
    cout<<"\t2. Yezzy"<<endl;
    cout<<"\t3. Jordan"<<endl<<endl;
    cout<<"\tMasukkan merk sepatu yang ingin dipilih (1/2/3) : "; cin>>pBaru->pilihanmerk;

    if(pBaru->pilihanmerk=='1'){
        pBaru->merk = "Patrobas";}
    else if(pBaru->pilihanmerk=='2'){
        pBaru->merk = "Yezzy";}
    else if(pBaru->pilihanmerk=='3'){
        pBaru->merk = "Jordan";}
    else{
        cout<<"\n\tPilihan yang Anda masukkan salah"<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        system("cls");
        goto menu1;}
    cout<<"\n\tAnda memilih sepatu "<<pBaru->merk<<endl;
    cout<<"\t=> Klik Enter untuk lanjut"<<endl;
    cin.get(); cin.get();
    system("cls");

    if(pBaru->merk=="Patrobas"){
        menu2:
        cout<<"\t=================="<<endl;
        cout<<"\t   JENIS SEPATU   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. PATROBAS RUNNING"<<endl;
        cout<<"\t2. PATROBAS CASUAL"<<endl;
        cout<<"\t3. PATROBAS BASKET"<<endl<<endl;
        cout<<"\tMasukkan jenis sepatu (1/2/3) : "; cin>>pBaru->pilihanjenis;
        if(pBaru->pilihanjenis=='1'){
            sera1:
            pBaru->jenis="PATROBAS RUNNING";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  PR21"<<endl;
            cout<<"\t2.  PF22"<<endl;
            cout<<"\t3.  PC23"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Patrobas (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="PR21";
                pBaru->harga=279000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="PF22";
                pBaru->harga=469000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="PC23";
                pBaru->harga=329000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera1;}
        }
        else if(pBaru->pilihanjenis=='2'){
            sera2:
            pBaru->jenis="PATROBAS CASUAL";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  PNV1"<<endl;
            cout<<"\t2.  PCW2"<<endl;
            cout<<"\t3.  PWR3"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Patrobas (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="PNV1";
                pBaru->harga=289900;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="PCW2";
                pBaru->harga=320900;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="PWR3";
                pBaru->harga=299900;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera2;}
        }
        else if(pBaru->pilihanjenis=='3'){
            sera3:
            pBaru->jenis="PATROBAS BASKET";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  PBC2"<<endl;
            cout<<"\t2.  PBF1"<<endl;
            cout<<"\t3.  PBR9"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Patrobas (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="PBC2";
                pBaru->harga=599000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="PBF1";
                pBaru->harga=498000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="PBR9";
                pBaru->harga=578900;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera3;}
        }
        else{
            cout<<"\n\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto menu2;
        }
        cout<<"\tAnda memilih sepatu dengan jenis "<<pBaru->jenis<<" dan seri "<<pBaru->sera<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }

    else if(pBaru->merk=="Yezzy"){
        menu3:
        cout<<"\t=================="<<endl;
        cout<<"\t   JENIS SEPATU   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. YZY 350"<<endl;
        cout<<"\t2. YZY 700"<<endl;
        cout<<"\t3. YZY 500"<<endl<<endl;
        cout<<"\tMasukkan jenis sepatu (1/2/3) : "; cin>>pBaru->pilihanjenis;
        if(pBaru->pilihanjenis=='1'){
            sera4:
            pBaru->jenis="YZY 350";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1. YS1"<<endl;
            cout<<"\t2. YE35"<<endl;
            cout<<"\t3. YE75"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Yezzy (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="YS1";
                pBaru->harga=1600000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="YE35";
                pBaru->harga=2900000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="YE75";
                pBaru->harga=4450000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera4;}
        }
        else if(pBaru->pilihanjenis=='2'){
            sera5:
            pBaru->jenis="YZY 700";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  YB00"<<endl;
            cout<<"\t2.  YK73"<<endl;
            cout<<"\t3.  YL64"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Yezzy (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="YB00";
                pBaru->harga=4000000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="YK73";
                pBaru->harga=3850000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="YL64";
                pBaru->harga=4450000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera5;}
        }
        else if(pBaru->pilihanjenis=='3'){
            sera6:
            pBaru->jenis="YZY 500";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  YHT5"<<endl;
            cout<<"\t2.  YHS3"<<endl;
            cout<<"\t3.  YBV7"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Yezzy (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="YHT5";
                pBaru->harga=5400000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="YHS3";
                pBaru->harga=4850000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="YBV7";
                pBaru->harga=7350000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera6;}
        }
        else{
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto menu3;
        }
        cout<<"\tAnda memilih sepatu dengan jenis "<<pBaru->jenis<<" dan seri "<<pBaru->sera<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }

    else if(pBaru->merk=="Jordan"){
        menu4:
        cout<<"\t=================="<<endl;
        cout<<"\t   JENIS SEPATU   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. AIR JORDAN 1"<<endl;
        cout<<"\t2. AIR JORDAN 4"<<endl;
        cout<<"\t3. AIR JORDAN 12"<<endl<<endl;
        cout<<"\tMasukkan jenis sepatu (1/2/3) : "; cin>>pBaru->pilihanjenis;
        if(pBaru->pilihanjenis=='1'){
            sera7:
            pBaru->jenis="AIR JORDAN 1";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1. AJ1B"<<endl;
            cout<<"\t2. AJ1O"<<endl;
            cout<<"\t3. AJ12"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Jordan (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="AJ1B";
                pBaru->harga=2250000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="AJ10";
                pBaru->harga=3199000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="AJ12";
                pBaru->harga=3099000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera7;}
        }
        else if(pBaru->pilihanjenis=='2'){
            sera8:
            pBaru->jenis="AIR JORDAN 4";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1. AJR4"<<endl;
            cout<<"\t2. AJC1"<<endl;
            cout<<"\t3. AJL7"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Jordan (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="AJR4";
                pBaru->harga=5250000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="AJC1";
                pBaru->harga=4750000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="AJL7";
                pBaru->harga=48000002;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera8;}
        }
        else if(pBaru->pilihanjenis=='2'){
            sera9:
            pBaru->jenis="AIR JORDAN 12";
            cout<<"\n\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  AJT2"<<endl;
            cout<<"\t2.  AJJ5"<<endl;
            cout<<"\t3.  AJN1"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu Jordan (1/2/3) : "; cin>>pBaru->pilihansera;
            if(pBaru->pilihansera=='1'){
                pBaru->sera="AJT2";
                pBaru->harga=3950000;}
            else if(pBaru->pilihansera=='2'){
                pBaru->sera="AJJ5";
                pBaru->harga=3350000;}
            else if(pBaru->pilihansera=='3'){
                pBaru->sera="AJN1";
                pBaru->harga=4350000;}
            else{
                cout<<"\tBrand tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto sera9;}
        }
        else{
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto menu4;
        }
        cout<<"\tAnda memilih sepatu dengan jenis "<<pBaru->jenis<<" dan seri "<<pBaru->sera<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }
    pBaru->next=NULL;
    pBaru->firstJumlah=NULL;
}

void createElementJumlah(pointerJumlah& pBaru)
{
    pBaru=new JumlahSepatu;
    cout<<"\tMasukkan jumlah yang ingin dibeli : "; cin>>pBaru->jumlahh;
    pBaru->nextJumlah=NULL;
}

void traversal(){
    pointerBrand pBantuBrand=listBrand;
    pointerJumlah pBantuJumlah;

    if(pBantuBrand==NULL){
        cout<<"\n\tKeranjang pembelian Anda kosong"<<endl;
        cin.get(); cin.get();
    }
    else{
        cout<<"\t-----------------------------------------------------------------"<<endl;
        cout<<"\t------------------------- D I S P L A Y -------------------------"<<endl;
        cout<<"\t================================================================="<<endl;
        cout<<"\t BRAND             JENIS                 SERI WARNA      JUMLAH  "<<endl;
        cout<<"\t================================================================="<<endl;
        while(pBantuBrand!=NULL&&pBantuJumlah!=NULL){
            cout<<"\t"<<setiosflags(ios::left)<<setw(19)<<pBantuBrand->merk;
            cout<<setiosflags(ios::left)<<setw(22)<<pBantuBrand->jenis;
            cout<<setiosflags(ios::left)<<setw(16)<<pBantuBrand->sera;
            pBantuJumlah=pBantuBrand->firstJumlah;
            cout<<setiosflags(ios::left)<<setw(8)<<pBantuJumlah->jumlahh<<endl;
            pBantuBrand=pBantuBrand->next;
        }
        cout<<"\t-----------------------------------------------------------------"<<endl;
    }
}

void insertLastBrand(pointerBrand pBaru){
    pointerBrand last;
    if (listBrand==NULL){
        listBrand=pBaru;
    }
    else{
        last=listBrand;
        while (last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void insertLastJumlah(pointerJumlah pBaru){
    pointerBrand pBrand=listBrand;
    int found=0;
    pointerJumlah last;

    while(pBrand!=NULL && found==0){
        if(pBrand->merk==key)
            found=1;
        else
            pBrand=pBrand->next;
    }
    if(found==1){
        cout<<"\n\tBrand ditemukan"<<endl;
        if(pBrand->firstJumlah==NULL){
			pBrand->firstJumlah=pBaru;
		}
		else{
			last=pBrand->firstJumlah;
			while(last->nextJumlah!=NULL){
				last=last->nextJumlah;
			}
			last->nextJumlah=pBaru;
		}
        cout<<"\tJumlah sepatu berhasil ditambah ke data"<<endl;
    }
    else{
    	cout<<endl;
        cout<<"\n\tBrand tidak ditemukan"<<endl;
        cout<<"\tJumlah sepatu tidak berhasil ditambah ke data"<<endl;
    }
}

void hapusBrand(){
    pointerBrand phapus=listBrand, listbrand1, listbrand2;
    string key1;
    int found=0;

    cout<<"\n\tMasukkan seri sepatu yang ingin dihapus : "; cin>>key1;
    while(phapus!=NULL&&found==0){
        if(phapus->sera==key1){
            found=1;}
        else{
            listbrand2=phapus;
            phapus=phapus->next;}
    }
    if(found==1){
        listbrand1 = phapus;
        cout<<"Sepatu dengan seri " << listbrand1->sera << " sudah dihapus dari keranjang";
        if(listbrand1->next==NULL){
            listbrand2->next=NULL;
            delete listbrand1;
        }
        else{
            listbrand2->next=phapus->next;
            delete listbrand1;
        }getch();
        menupesan();
    }
}

void bayarbeli(){
    string nama,alamat,penerima,bank,metode;
    char nomor[20],pil;
    pointerBrand pBantuBrand=listBrand;
    pointerJumlah pBantuJumlah;
    long int HargaBeli = 0;

    if(pBantuBrand==NULL){
        cout<<"\n\tKeranjang Anda kosong"<<endl<<endl;
        cin.get(); cin.get();
        menupesan();
    }
    else{
        system("cls");
        cout <<"\t+---------------------+"<<endl;
        cout << "\t|      FELTYOUNG      |"<<endl;
        cout << "\t+---------------------+"<<endl<<endl;
        cout << "\tData Pembeli Sepatu"; cin.ignore(); getline(cin,nama);
        cout << "\tNama Lengkap \t: ";   getline(cin,nama);
        cout << "\tAlamat \t\t: ";       getline(cin,alamat);
        cout << "\tNomor HP \t: +62 ";   cin >> nomor;

        system("cls");
        cout << "\tData Anda" << endl;
        cout << "\tNama Lengkap \t: "   << nama << endl;
        cout << "\tAlamat \t\t: "       << alamat << endl;
        cout << "\tNomor HP \t: +62 "   << nomor << endl;
        cout << "\tMetode Pembayaran : " << metode << endl;
        cout << endl;
        cout << endl;
        cout<<"\t-----------------------------------------------------------------"<<endl;
        cout<<"\t----------------------- F E L T Y O U N G -----------------------"<<endl;
        cout<<"\t================================================================="<<endl;
        cout<<"\t BRAND             JENIS                 SERI WARNA      JUMLAH  "<<endl;
        cout<<"\t================================================================="<<endl;
        pBantuJumlah=pBantuBrand->firstJumlah;
        while(pBantuBrand!=NULL){
            cout<<"\t"<<setiosflags(ios::left)<<setw(19)<<pBantuBrand->merk;
            cout<<setiosflags(ios::left)<<setw(22)<<pBantuBrand->jenis;
            cout<<setiosflags(ios::left)<<setw(16)<<pBantuBrand->sera;
            cout<<setiosflags(ios::left)<<setw(8)<<pBantuJumlah->jumlahh;
            HargaBeli= HargaBeli + pBantuJumlah->jumlahh * pBantuBrand->harga;
            pBantuJumlah=pBantuJumlah->nextJumlah;
            pBantuBrand=pBantuBrand->next;
        }
            cout<<"\n\t-----------------------------------------------------------------"<<endl;
            cout<<"\tHarga Beli Sepatu Anda : "<<HargaBeli<<endl;
            cout<<endl;
            cout<<"\tNotes: Bawa Struk ini saat COD" << endl;
            cout<<endl;
            cout<<"\tTerima kasih banyak sudah berbelanja di FELTYOUNG"<<endl;
            cin.get(); cin.get();
            cout<<endl;
    }
}

///////////// PEMINJAMAN
void createElementBolehPinjam(pointerPinjam& pBaru){
    pinjam1:
    pBaru=new BolehPinjam;
    cout<<"\t=================="<<endl;
    cout<<"\t   PINJAM SEPATU  "<<endl;
    cout<<"\t=================="<<endl<<endl;
    cout<<"\t1. Trail"<<endl;
    cout<<"\t2. Football"<<endl;
    cout<<"\t3. Running"<<endl<<endl;
    cout<<"\tMasukkan merk sepatu yang ingin dipilih : "; cin>>pBaru->pilihankategori;

    if(pBaru->pilihankategori=='1'){
        pBaru->kategori = "Trail";}
    else if(pBaru->pilihankategori=='2'){
        pBaru->kategori = "Football";}
    else if(pBaru->pilihankategori=='3'){
        pBaru->kategori = "Running";}
    else{
        cout<<"\tPilihan yang Anda masukkan salah"<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        system("cls");
        goto pinjam1;}

    cout<<"\n\tAnda memilih sepatu "<<pBaru->kategori<<endl;
    cout<<"\t=> Klik Enter untuk lanjut"<<endl;
    cin.get(); cin.get();
    system("cls");

    if(pBaru->kategori=="Trail"){
        kategori1:
        cout<<"\t=================="<<endl;
        cout<<"\t    Merk Sepatu   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. ASICS"<<endl;
        cout<<"\t2. HOKA"<<endl;
        cout<<"\tMasukkan merk sepatu (1/2) : "; cin>>pBaru->pilihanmerk1;
        if(pBaru->pilihanmerk1=='1'){
            merkk1:
            pBaru->merk1="ASICS";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  ASICS GEL 2"<<endl;
            cout<<"\t2.  ASICS GEL PRO"<<endl;
            cout<<"\t3.  ASICS GEL X"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="ASICS GEL 2";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        25.000 "<<endl;
                cout<<"\t2.  7  HARI        35.000"<<endl;
                cout<<"\t3.  14 HARI        65.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ASICS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=25000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=65000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk1;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="ASICS GEL PRO";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        40.000"<<endl;
                cout<<"\t3.  14 HARI        75.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ASICS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=40000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=75000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk1;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="ASICS GEL X";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        20.000 "<<endl;
                cout<<"\t2.  7  HARI        40.000"<<endl;
                cout<<"\t3.  14 HARI        80.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ASICS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=20000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=40000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=80000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk1;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk1;}
        }

        else if(pBaru->pilihanmerk1=='2'){
            merkk2:
            pBaru->merk1="HOKA";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  HOKA ATR 6"<<endl;
            cout<<"\t2.  HOKA TECTON"<<endl;
            cout<<"\t3.  HOKA SPEED 2"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="HOKA ATR 6";

                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        20.000 "<<endl;
                cout<<"\t2.  7  HARI        30.000"<<endl;
                cout<<"\t3.  14 HARI        55.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu HOKA (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=20000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=30000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=55000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk2;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="HOKA TECTON";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        40.000"<<endl;
                cout<<"\t3.  14 HARI        75.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu HOKA (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=40000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=75000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk2;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="HOKA SPEED 2";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        65.000"<<endl;
                cout<<"\t3.  14 HARI        100.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu HOKA (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=65000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=100000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk2;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk2;}
        }
        else{
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto kategori1;
        }
        cout<<"\tAnda meminjam sepatu dengan kategori "<<pBaru->kategori<<" dan seri "<<pBaru->seru<<" dengan lama pinjam "<<pBaru->lama<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }

    if(pBaru->kategori=="Football"){
        kategori2:
        cout<<"\t=================="<<endl;
        cout<<"\t    Merk Sepatu   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. NIKE"<<endl;
        cout<<"\t2. ADIDAS"<<endl;
        cout<<"\tMasukkan merk sepatu (1/2) : "; cin>>pBaru->pilihanmerk1;
        if(pBaru->pilihanmerk1=='1'){
            merkk3:
            pBaru->merk1="NIKE";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  NIKE MERCURIAL"<<endl;
            cout<<"\t2.  NIKE PHANTOM"<<endl;
            cout<<"\t3.  NIKE TIEMPO"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="NIKE MERCURIAL";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        45.000 "<<endl;
                cout<<"\t2.  7  HARI        80.000"<<endl;
                cout<<"\t3.  14 HARI        150.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=45000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=80000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=150000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk3;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="NIKE PHANTOM";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        70.000"<<endl;
                cout<<"\t3.  14 HARI        130.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=70000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=130000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk3;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="NIKE TIEMPO";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        30.000 "<<endl;
                cout<<"\t2.  7  HARI        60.000"<<endl;
                cout<<"\t3.  14 HARI        120.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=30000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=60000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=120000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk3;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk3;}
        }

        else if(pBaru->pilihanmerk1=='2'){
            merkk4:
            pBaru->merk1="ADIDAS";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  ADIDAS PREDATOR"<<endl;
            cout<<"\t2.  ADIDAS SPEEDPORTAL"<<endl;
            cout<<"\t3.  ADIDAS COPASENSE"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="ADIDAS PREDATOR";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        25.000 "<<endl;
                cout<<"\t2.  7  HARI        50.000"<<endl;
                cout<<"\t3.  14 HARI        95.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ADIDAS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=25000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=50000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=95000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk4;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="ADIDAS SPEEDPORTAL";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        50.000 "<<endl;
                cout<<"\t2.  7  HARI        100.000"<<endl;
                cout<<"\t3.  14 HARI        150.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ADIDAS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=50000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=100000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=150000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk4;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="ADIDAS COPASENSE";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        65.000"<<endl;
                cout<<"\t3.  14 HARI        95.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu ADIDAS (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=65000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=95000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk4;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk4;
            }
        }
        else{
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto kategori2;
        }
        cout<<"\tAnda meminjam sepatu dengan kategori "<<pBaru->kategori<<" dan seri "<<pBaru->seru<<" dengan lama pinjam "<<pBaru->lama<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }

    if(pBaru->kategori=="Running"){
        kategori3:
        cout<<"\t=================="<<endl;
        cout<<"\t    Merk Sepatu   "<<endl;
        cout<<"\t=================="<<endl<<endl;
        cout<<"\t1. NIKE"<<endl;
        cout<<"\t2. NINETEN"<<endl;
        cout<<"\tMasukkan merk sepatu (1/2) : "; cin>>pBaru->pilihanmerk1;
        if(pBaru->pilihanmerk1=='1')
        {
            merkk5:
            pBaru->merk1="NIKE";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  NIKE FLYEASE"<<endl;
            cout<<"\t2.  NIKE PEGASUS"<<endl;
            cout<<"\t3.  NIKE FLY5"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="NIKE FLYEASE";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        45.000 "<<endl;
                cout<<"\t2.  7  HARI        80.000"<<endl;
                cout<<"\t3.  14 HARI        150.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=45000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=80000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=150000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk5;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="NIKE PEGASUS";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        35.000 "<<endl;
                cout<<"\t2.  7  HARI        70.000"<<endl;
                cout<<"\t3.  14 HARI        130.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=35000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=70000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=130000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk5;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="NIKE FLY5";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        30.000 "<<endl;
                cout<<"\t2.  7  HARI        60.000"<<endl;
                cout<<"\t3.  14 HARI        120.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NIKE (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=30000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=60000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=120000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk5;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk5;}
        }

        else if(pBaru->pilihanmerk1=='2'){
            merkk6:
            pBaru->merk1="NINETEN";
            system("CLS");
            cout<<"\t================="<<endl;
            cout<<"\t   SERI SEPATU   "<<endl;
            cout<<"\t================="<<endl<<endl;
            cout<<"\t1.  910 YUKA"<<endl;
            cout<<"\t2.  910 KISHI"<<endl;
            cout<<"\t3.  910 GEIST"<<endl<<endl;
            cout<<"\tMasukkan seri sepatu (1/2/3) : "; cin>>pBaru->pilihanseru;
            if(pBaru->pilihanseru=='1'){
                pBaru->seru="910 YUKA";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        25.000 "<<endl;
                cout<<"\t2.  7  HARI        50.000"<<endl;
                cout<<"\t3.  14 HARI        95.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NINETEEN (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=25000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=50000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=95000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk6;}
            }
            else if(pBaru->pilihanseru=='2'){
                pBaru->seru="910 KISHI";

                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        15.000 "<<endl;
                cout<<"\t2.  7  HARI        30.000"<<endl;
                cout<<"\t3.  14 HARI        50.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NINETEEN (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=15000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=30000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=50000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk6;}
            }
            else if(pBaru->pilihanseru=='3'){
                pBaru->seru="910 GEIST";
                cout<<"\n\t========================="<<endl;
                cout<<"\t   LAMA PINJAM     HARGA " <<endl;
                cout<<"\t========================="<<endl<<endl;
                cout<<"\t1.  3  HARI        15.000 "<<endl;
                cout<<"\t2.  7  HARI        25.000"<<endl;
                cout<<"\t3.  14 HARI        50.000"<<endl<<endl;
                cout<<"\tMasukkan seri sepatu NINETEEN (1/2/3) : "; cin>>pBaru->pilihanlama;
                if(pBaru->pilihanlama=='1'){
				   pBaru->lama="3 HARI";
                   pBaru->hargai=15000;}
                else if(pBaru->pilihanlama=='2'){
				   pBaru->lama="7 HARI";
                   pBaru->hargai=25000;}
                else if(pBaru->pilihanlama=='3'){
				   pBaru->lama="14 HARI";
                   pBaru->hargai=50000;}
                else{
                    cout<<"\tJasa tidak ditemukan, pilih kembali"<<endl;
                    cin.get();
                    system("cls");
                    goto merkk6;}
            }
            else{
                cout<<"\tSeri tidak ditemukan, pilih seri kembali"<<endl;
                cin.get();
                system("cls");
                goto merkk2;}
        }
        else if(pBaru->pilihanmerk1!=1 && pBaru->pilihanmerk1!=2 && pBaru->pilihanmerk1!=3){
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("cls");
            goto kategori3;
        }
        cout<<"\tAnda meminjam sepatu dengan kategori "<<pBaru->kategori<<" dan seri "<<pBaru->seru<<" dengan lama pinjam "<<pBaru->lama<<endl<<endl;
        cin.get(); cin.get();
        system("CLS");
    }
    pBaru->next=NULL;
    pBaru->firstBanyak=NULL;
}

void createElementBanyak(pointerBanyak& pBaru){
    pBaru=new BanyakPinjam;
    cout<<"\tMasukkan jumlah yang ingin dipinjam : "; cin>>pBaru->banyak;
    pBaru->nextBanyak=NULL;
}

void traversalPinjam(){
    pointerPinjam pBantuPinjam=listPinjam;
    pointerBanyak pBantuBanyak;

    if(pBantuPinjam!=NULL){
        cout<<"\t--------------------------------------------------------------------"<<endl;
        cout<<"\t------------------------- D I S P L A Y ----------------------------"<<endl;
        cout<<"\t====================================================================="<<endl;
        cout<<"\t KATEGORI             MERK           SERI       LAMA PINJAM   JUMLAH "<<endl;
        cout<<"\t====================================================================="<<endl;

        while(pBantuPinjam!=NULL && pBantuBanyak!=NULL){
            cout<<"\t"<<setiosflags(ios::left)<<setw(22)<<pBantuPinjam->kategori;
            cout<<setiosflags(ios::left)<<setw(15)<<pBantuPinjam->merk1;
            cout<<setiosflags(ios::left)<<setw(11)<<pBantuPinjam->seru;
            cout<<setiosflags(ios::left)<<setw(14)<<pBantuPinjam->lama;
            pBantuBanyak=pBantuPinjam->firstBanyak;
            cout<<setiosflags(ios::left)<<setw(6)<<pBantuBanyak->banyak;
            cout<<endl;
            pBantuPinjam=pBantuPinjam->next;
            cout<<endl;
        }
        cout<<"\t--------------------------------------------------------------------"<<endl;
    }
    else{
        cout<<"\n\tKeranjang peminjaman Anda kosong"<<endl;
        cin.get(); cin.get();
    }
}

void insertLastBolehPinjam(pointerPinjam pBaru){
    pointerPinjam last;
    if(listPinjam==NULL){
        listPinjam=pBaru;}
    else{
        last=listPinjam;
        while (last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void insertLastBanyakPinjam(pointerBanyak pBaru){
    pointerPinjam pPinjam=listPinjam;
    int found=0;
    pointerBanyak last;

    while(pPinjam!=NULL && found==0){
        if(pPinjam->kategori==key)
            found=1;
        else
            pPinjam=pPinjam->next;
    }
    if(found==1){
        cout<<"\n\tKategori ditemukan"<<endl;
        if(pPinjam->firstBanyak==NULL){
			pPinjam->firstBanyak=pBaru;}
		else{
			last=pPinjam->firstBanyak;
			while(last->nextBanyak!=NULL){
				last=last->nextBanyak;
			}
			last->nextBanyak=pBaru;
		}
        cout<<"\tSeri berhasil ditambah ke data"<<endl;
    }
    else{
    	cout<<endl;
        cout<<"\n\tKategori tidak ditemukan"<<endl;
        cout<<"\tSeri tidak berhasil ditambah ke data"<<endl;
    }
}

void hapusPinjam(){
    pointerPinjam phapus=listPinjam, listpinjam1, listpinjam2;
    string key2;
    int found=0;

    cout<<"\n\tMasukkan seri sepatu yang ingin dihapus : "; cin>>key2;
    while(phapus!=NULL&&found==0){
        if(phapus->seru==key2){
            found=1;
        }
        else{
            listpinjam2=phapus;
            phapus=phapus->next;
        }
    }
    if(found==1){
        listpinjam1 = phapus;
        cout<<"Sepatu dengan seri " << listpinjam1->seru << " sudah dihapus dari keranjang";
        if(listpinjam1->next==NULL)        {
            listpinjam2->next=NULL;
            delete listpinjam1;
        }
        else{
            listpinjam2->next=phapus->next;
            delete listpinjam1;
        }getch();
        menupinjam();
    }
}

void masuk(){
    system("CLS");
    char pilihanmasuk;
    system("color 8F");
    cout<<"\t+===============+"<<endl;
    cout<<"\t|   FELTYOUNG   |"<<endl;
    cout<<"\t+===============+"<<endl<<endl;
    cout<<"\tMasuk sebagai?"<<endl;
    cout<<"\t1. Pembeli"<<endl;
    cout<<"\t2. Pegawai"<<endl<<endl;
    cout<<"\tPilihan : "; cin>>pilihanmasuk;
    cout<<endl;

    if(pilihanmasuk=='1'){
        cout<<"\tAnda masuk sebagai pembeli"<<endl;
        cout<<"\t=> Klik Enter untuk lanjut"<<endl;
        cin.get(); cin.get();
        system("CLS");
        PembeliMasuk();}
    else if(pilihanmasuk=='2'){
        cout<<"\tAnda masuk sebagai pegawai"<<endl;
        cout<<"\t=> Klik Enter untuk lanjut"<<endl;
        cin.get(); cin.get();
        system("CLS");
        PegawaiMasuk();}
    else{
        cout<<"\tPilihan yang Anda masukkan salah"<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        masuk();}
}

void PembeliMasuk(){
    char pilihan;
    system("cls");
    system("color B0");
    cout<<"\t+=================================+"<<endl;
    cout<<"\t|   SELAMAT DATANG DI FELTYOUNG   |"<<endl;
    cout<<"\t+=================================+"<<endl<<endl;
    cout<<"\t1. Sign Up"<<endl;
    cout<<"\t2. Login"<<endl;
    cout<<"\t3. Kembali"<<endl<<endl;
    cout<<"\tPilihan : "; cin>>pilihan;
    cout<<endl;
    if(pilihan=='1'){
        Signup();}
    else if(pilihan=='2'){
        Login();
        menuawal();}
    else if(pilihan=='3'){
        masuk();}
    else{
        cout<<"\tTidak ada pilihan tersebut"<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        PembeliMasuk();}
}

void Signup(){
    char usn[20], pw[20], konfirmpw[20], telp[20];
    cin.get(); cin.get();
    system("CLS");
    system("color F9");
    cout<<"\t+=============+"<<endl;
    cout<<"\t|   SIGN UP   |"<<endl;
    cout<<"\t+=============+"<<endl<<endl;
    cout<<"\tMasukkan username Anda   : "; cin>>usn;
    cout<<"\tMasukkan nomor telepon   : "; cin>>telp;
    cout<<"\tRekomendasi password     : ("<< usn << "123)" <<endl;
    cout<<"\tMasukkan password        : "; cin>>pw;
    cout<<"\tKonfirmasi password      : "; cin>>konfirmpw;
    if(strcmp(pw,konfirmpw)==0){
        cout<<endl<<endl;
        User user;
        user.pass = pw;
        user.usn = usn;
        user.telp = telp;
        simpanDataUser(user);
        cout<<"\tAnda berhasil Sign Up, data anda telah kami simpan"<<endl;
        cout<<"\tSilakan Login pada menu awal"<<endl<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        system ("CLS");
        PembeliMasuk();}
    else{
        cout<<"\n\tMaaf Password yang anda masukkan salah"<<endl;
        cout<<"\tSilakan Sign Up kembali"<<endl<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        system ("CLS");
        PembeliMasuk();}
}

void Login(){
    int i = 1;
    string login = "gagal";
    char usn[20], pw[20];

    cin.get();
    system("CLS");
    int jumlah = jumlahUser();
    User dataUser[jumlah];
    bacaDataUser(dataUser);
    do {
        cout<<"\t+===========+"<<endl;
        cout<<"\t|   LOGIN   |"<<endl;
        cout<<"\t+===========+"<<endl<<endl;
        cout<<"\tMasukkan username    : "; cin>>usn;
        cout<<"\tMasukkan password    : "; cin>>pw;
        for(int i=0; i<jumlah; i++){
            int n = dataUser[i].usn.length();
            char username[n + 1];
            strcpy(username, dataUser[i].usn.c_str());
            n = dataUser[i].pass.length();
            char password[n + 1];
            strcpy(password, dataUser[i].pass.c_str());
            if(strcmp(username, usn) == 0 && strcmp(password, pw) == 0){
                login = "berhasil";
                cout<<"\n\tAnda berhasil login"<<endl;
                cout<<"\tSelamat Datang di FELTYOUNG"<<endl;
                cout<<"\n\t=> Klik Enter untuk lanjut"<<endl;
                cin.get(); cin.get();
                break;}
        }
        if(login == "gagal"){
            cout<<"\tUsername/Password yang Anda masukkan salah! ("<<i<<"x)"<<endl;
            cout<<"\tPastikan Anda telah melakukan Sign Up dan Username/Password yang Anda masukkan sudah benar"<<endl;
            cout<<"\tJika sudah 3x melakukan kesalahan, Anda harus sign up kembali"<<endl<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            system("CLS");
            i = i + 1;
        }
        else{
            i = 4;}
    }while (i <= 3);

    if(login != "berhasil"){
        cout<<"\t==========="<<endl;
        cout<<"\t   LOGIN   "<<endl;
        cout<<"\t==========="<<endl<<endl;
        cout<<"\tAnda telah 3x salah login"<<endl;
        cout<<"\tSilakan sign up kembali. Terima kasih"<<endl<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        system("CLS");
        PembeliMasuk();}
}

void menuawal(){
    system("CLS");
    pointerBrand pBrand;
    pointerJumlah pJumlah;
    char pilihanpembeli;
    do{
        system("color 70");
        system("CLS");
        cout<<"\t==============="<<endl;
        cout<<"\t   MENU AWAL   "<<endl;
        cout<<"\t==============="<<endl<<endl;
        cout<<"\t1. Pesan sepatu"<<endl;
        cout<<"\t2. Pinjam dan kembalikan"<<endl;
        cout<<"\t3. Riwayat pesanan"<<endl;
        cout<<"\t4. Log out sebagai pembeli"<<endl<<endl;
        cout<<"\tPilihan : "; cin>>pilihanpembeli;
        cout<<endl;
        if(pilihanpembeli=='1'){
            system("CLS");
            menupesan();}
        else if(pilihanpembeli=='2'){
            system("CLS");
            menupinjam();}
        else if(pilihanpembeli=='3'){
            traversal();
            traversalPinjam();
            system("CLS");}
        else if(pilihanpembeli=='4'){
            system("CLS");
            masuk();}
        else{
            cout<<"\tPilihan yang Anda masukkan salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            menuawal();}
    } while(pilihanpembeli!='4');
}

void menupesan(){
    char pilihanmenu,jawab;
    pointerBrand pBrand,pHapus;
    pointerJumlah pJumlah;
    do{
        system("color DF");
        pesann:
        system("CLS");
        cout<<"\t============================"<<endl;
        cout<<"\t         MENU PESAN         "<<endl;
        cout<<"\t============================"<<endl<<endl;
        cout<<"\t1. Beli sepatu"<<endl;
        cout<<"\t2. Cek keranjang"<<endl;
        cout<<"\t3. Hapus barang di keranjang"<<endl;
        cout<<"\t4. Bayar pesanan"<<endl;
        cout<<"\t5. Batalkan pesanan"<<endl;
        cout<<"\t6. Kembali"<<endl<<endl;
        cout<<"\tMasukkan pilihan : "; cin>>pilihanmenu;
        switch(pilihanmenu)
        {
        case '1':
            system("CLS");
            createElementBrand(pBrand);
            insertLastBrand(pBrand);

            cout<<"\n\tMasukkan kembali nama brand : "; cin>>key;
            createElementJumlah(pJumlah);
            insertLastJumlah(pJumlah);
            cin.get(); cin.get();
            break;
        case '2':
            traversal();
            cin.get(); cin.get();
            break;
        case '3':
            hapusBrand();
            break;
        case '4':
            cout<<"\tApakah Anda masih ingin menambah pesanan lagi?"<<endl;
            cout<<"\t>>>> Jawab (Y/T) : "; cin>>jawab;

            if(jawab=='Y' || jawab=='y'){
                menupesan();}
            else if(jawab=='T' || jawab=='t'){
                bayarbeli();}
            break;
        case '5':
            cout<<"\tApakah Anda yakin ingin membatalkan pesanan?"<<endl;
            cout<<"\tCatatan: Pesanan yang telah dipesan sebelumnya akan terhapus. Jika terhapus, dapat kembali dan memesan lagi"<<endl<<endl;

            cout<<"\t>>>> Jawab (Y/T) : "; cin>>jawab;

            if(jawab=='Y' || jawab=='y'){
                createListBrand();
                menupesan();}
            else if(jawab=='T' || jawab=='t'){
                masuk();}
            break;
        case '6':
            menuawal();
            break;
        default:
            cout<<"\n\tPilihan Anda salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            goto pesann;
            break;
        }
    }while(pilihanmenu!='6');
}

void menupinjam(){
    char pilihanmanu,jawab2;
    pointerPinjam pPinjam, pHapus;
    pointerBanyak pBanyak;
    do{
        system("color DF");
        pinjamm:
        system("CLS");
        cout<<"\t==========================="<<endl;
        cout<<"\t        MENU PINJAM        "<<endl;
        cout<<"\t==========================="<<endl<<endl;
        cout<<"\t1. Pinjam sepatu"<<endl;
        cout<<"\t2. Cek keranjang"<<endl;
        cout<<"\t3. Hapus barang di keranjang"<<endl;
        cout<<"\t4. Bayar pesanan"<<endl;
        cout<<"\t5. Kembalikan sepatu"<<endl;
        cout<<"\t6. Kembali"<<endl<<endl;
        cout<<"\tMasukkan pilihan : "; cin>>pilihanmanu;
        switch(pilihanmanu)
        {
        case '1':
            system("CLS");
            createElementBolehPinjam(pPinjam);
            insertLastBolehPinjam(pPinjam);

            cout<<"\n\tMasukkan kembali kategori sepatu : "; cin>>key;
            createElementBanyak(pBanyak);
            insertLastBanyakPinjam(pBanyak);
            cin.get(); cin.get();
            break;
        case '2':
            traversalPinjam();
            cin.get();
            break;
        case '3':
            hapusPinjam();
            break;
        case '4':
            cout<<"\tApakah Anda masih ingin meminjam lagi?"<<endl;
            cout<<"\t>>>> Jawab (Y/T) : "; cin>>jawab2;

            if(jawab2=='Y' || jawab2=='y'){
                menupinjam();}
            else if(jawab2=='T' || jawab2=='t'){
                bayarpinjam();}
            break;
        case '5':
            deleteFirstPinjam();
            traversalPinjam();
            break;
        case '6':
            menuawal();
            break;
        default:
            cout<<"\tPilihan Anda salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            goto pinjamm;
            break;
        }
    }while(pilihanmanu!='6');
}

void bayarpinjam(){
    string nama2,alamat2,penerima,bank2,metode2;
    char nomor2[20],pil2;
    pointerPinjam pBantuPinjam=listPinjam;
    pointerBanyak pBantuBanyak;
    long int BayarPinjam = 0;

    if(pBantuPinjam==NULL){
        cout<<"\n\tKeranjang Anda kosong"<<endl;
        cin.get(); cin.get();
        menupinjam();}
    else{
        system("cls");
        cout <<"\t+---------------------+"<<endl;
        cout << "\t|      FELTYOUNG      |"<<endl;
        cout << "\t+---------------------+"<<endl<<endl;
        cout << "Data Peminjam Sepatu"; cin.ignore(); getline(cin,nama2);
        cout << "\nNama Lengkap \t: "; getline(cin,nama2);
        cout << "Alamat \t\t: "; getline(cin,alamat2);
        cout << "Nomor HP \t: +62 "; cin >> nomor2;

        system("cls");
        cout << "\tData Anda" << endl;
        cout << "\tNama Lengkap \t: " << nama2 << endl;
        cout << "\tAlamat \t\t: " << alamat2 << endl;
        cout << "\tNomor HP \t: +62 " << nomor2 << endl;
        cout << endl;
        cout << endl;
        cout<<"\t---------------------------------------------------------------------"<<endl;
        cout<<"\t------------------------ F E L T Y O U N G --------------------------"<<endl;
        cout<<"\t======================================================================"<<endl;
        cout<<"\t KATEGORI             SERI           SERI       LAMA PINJAM    JUMLAH" <<endl;
        cout<<"\t======================================================================"<<endl;
        pBantuBanyak=pBantuPinjam->firstBanyak;
        while(pBantuPinjam!=NULL && pBantuBanyak!=NULL){
            cout<<setiosflags(ios::left)<<setw(22)<<pBantuPinjam->kategori;
            cout<<setiosflags(ios::left)<<setw(15)<<pBantuPinjam->merk1;
            cout<<setiosflags(ios::left)<<setw(11)<<pBantuPinjam->seru;
            cout<<setiosflags(ios::left)<<setw(14)<<pBantuPinjam->lama;
            cout<<setiosflags(ios::left)<<setw(6)<<pBantuBanyak->banyak;
            BayarPinjam = BayarPinjam + pBantuBanyak->banyak * pBantuPinjam->hargai;
            pBantuBanyak=pBantuBanyak->nextBanyak;
            pBantuPinjam=pBantuPinjam->next;
        }
            cout<<"\t---------------------------------------------------------------------"<<endl;
            cout << "\tHarga Pinjam Sepatu Anda : " << BayarPinjam << endl;
            cout << endl;
            cout << "Notes: Bawa Struk ini saat COD" << endl;
            cout << endl;
            cout << "\tTerima kasih banyak sudah meminjam sepatu di FELTYOUNG" << endl;
            cin.get(); cin.get();
            cout<<endl;
    }
}

void PegawaiMasuk(){
    char h;
    string pwtoko, p;
    string loginpegawai = "gagal";

    cout<<"\t==========="<<endl;
    cout<<"\t   LOGIN   "<<endl;
    cout<<"\t==========="<<endl<<endl;
    cout<<"\tMasukkan password: "; h=_getch();

    while(h!=13){
        pwtoko.push_back(h);
        cout<<'*';
        h = _getch();}

    if(pwtoko == "FELTxxyoung"){
        loginpegawai = "berhasil";
        cout<<"\n\n\tAnda berhasil login sebagai pegawai"<<endl;
        cout<<"\t=> Klik Enter untuk lanjut"<<endl;
        cin.get();
        menuPegawai();}
    else if(pwtoko != "FELTxxyoung"){
        loginpegawai = "gagal";
        cout<<"\n\tPassword toko yang Anda masukkan salah"<<endl<<endl;
        cout<<"\tSilakan sign up kembali"<<endl;
        cout<<"\t=> Klik Enter untuk kembali"<<endl;
        cin.get(); cin.get();
        masuk();}
}

void menuPegawai(){
    char pilihanmenu,pilihAntri,jawab;
    pointerBrand pBrand,pHapus;
    pointerJumlah pJumlah;
    do{
        pesann:
        system("CLS");
        cout<<"\t============================"<<endl;
        cout<<"\t         MENU PEGAWAI       "<<endl;
        cout<<"\t============================"<<endl<<endl;
        cout<<"\t1. Lihat antrian"<<endl;
        cout<<"\t2. Konfirmasi pesanan"<<endl;
        cout<<"\t3. Kembali"<<endl<<endl;
        cout<<"\tMasukkan pilihan : "; cin>>pilihanmenu;
        switch(pilihanmenu)
        {
        case '1':
            system("CLS");
            cout<<"\t+===================+"<<endl;
            cout<<"\t|   LIHAT ANTRIAN   |"<<endl;
            cout<<"\t+===================+"<<endl<<endl;
            cout<<"\t1. Pemesanan"<<endl;
            cout<<"\t2. Peminjaman"<<endl;
            cout<<"\t3. Kembali"<<endl;
            cout<<"\tPilihan : "; cin>>pilihAntri;
            if(pilihAntri == '1'){
                traversal();
                cin.get();
                break;}
            if(pilihAntri == '2'){
                traversalPinjam();
                cin.get();
                break;}
            if(pilihAntri == '3'){
                goto pesann;
            }
            break;
        case '2':
            deleteFirstPegawai();
            cin.get();
            break;
        case '3':
            masuk();
            break;
        default:
            cout<<"\tPilihan Anda salah"<<endl;
            cout<<"\t=> Klik Enter untuk kembali"<<endl;
            cin.get(); cin.get();
            goto pesann;
            break;
        }
    }while(pilihanmenu!='3');
}

void deleteFirstPinjam(){
    pointerPinjam pHapus;
    if(listPinjam==NULL){
        pHapus = NULL;
        cout << "\tTidak ada sepatu yang dipinjam" << endl;
        cout << "\tTidak ada sepatu yang dikembalikan" << endl;
        cin.get(); cin.get();}
    else if(listPinjam->next==NULL){
        pHapus = listPinjam;
        listPinjam= NULL;
        cout << "\tSepatu berhasil dikembalikan" << endl;
        cout << "\tDisplay list sepatu kosong" << endl;
        cin.get(); cin.get();}
    else{
        pHapus = listPinjam;
        listPinjam = listPinjam->next;
        pHapus -> next = NULL;
        cout << "\tSepatu berhasil dikembalikan" << endl;
        cin.get(); cin.get();}
}

void deleteFirstPegawai(){
	pointerBrand pHapus=listBrand, najibgj;
	if(listBrand==NULL){
		pHapus=NULL;
		listBrand=NULL;
		cout<<"\n\tAntrian pesanan kosong"<<endl;
		cout<<"\tTidak ada pesanan yang dikirim"<<endl<<endl;
		cin.get();}
    else if(listBrand->next==NULL){
		pHapus=listBrand;
		listBrand=NULL;
		cout<<"\n\tPesanan pertama telah dikirim"<<endl;
		cout<<"\tAntrian pesanan kosong" << endl<<endl;
		cin.get();}
	else{
        pHapus=listBrand;
        listBrand=listBrand->next;
        pHapus->next=NULL;
		cout<<"\n\tPesanan pertama telah dikirim"<<endl;
		cout<<endl;
		cin.get();}
}
