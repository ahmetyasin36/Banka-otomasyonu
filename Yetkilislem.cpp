#include "Yetkilislem.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
#include <thread>   
using namespace std;

Yetkiliislem::Yetkiliislem()
{
}
Yetkiliislem::~Yetkiliislem()
{
}

void Yetkiliislem::musteriEkle()
{   
    char kelime[100];
    float sayi;
    cout<<"Musteri ekle islemi.."<<endl<<endl;
    cin.ignore();
    cout<<"Musteri TcNo: "; cin.getline(kelime,100); m1.SetTcno(kelime);
    cout<<"Musteri Ad soyad: "; cin.getline(kelime,100); m1.SetAdSoyad(kelime);
    cout<<"Musteri Adres: "; cin.getline(kelime,100); m1.SetAdres(kelime);
    cout<<"Musteri Telefon: "; cin.getline(kelime,100); m1.SetTel(kelime);
    m1.SetSifre(m1.getTcno());
    cout<<"Bakiye: "; cin>>sayi; m1.Setbakiye(sayi);

    string dosyaAdi=m1.getTcno();
    //strcpy(dosyaAdi,m1.getTcno);
    dosyaAdi.append(".txt");
    
    ofstream file(dosyaAdi);
    file.write((char *)&m1,sizeof(MusteriBilgi));
    file.close();
    cout<<"Musteri kaydi tamam"<<endl;
    cin.get();

}
void Yetkiliislem::musteriSil()
{
    char kelime[100];
    float sayi;
    cout<<"Musteri Silme islemi.."<<endl<<endl;
    cin.ignore();
    cout<<"Silinecek Musteri TcNo: "; cin.getline(kelime,100); m1.SetTcno(kelime);
    string dosyaAdi=kelime;
    dosyaAdi.append(".txt");
    ifstream file(dosyaAdi);
    if(!file.is_open()){
        cout<<kelime<<" numarali musteri kaydi yok!"<<endl;
    }
    else{
    file.read((char *)&m1,sizeof(MusteriBilgi));
    cout<<"Musteri No/TcNo: "<<m1.getTcno()<<endl;
    cout<<"Musteri Ad soyad: "<<m1.getAdSoyad()<<endl;
    cout<<"Musteri Adres: "<<m1.getAdres()<<endl;
    cout<<"Musteri Telefon: "<<m1.getTel()<<endl;;
    cout<<"Bakiye: "<<m1.getBakiye()<<endl<<endl;
    char karar;
    cout<<"Musteri kaydini silmek istediginize eminmisiniz? [E/H]"<<endl; cin>>karar;
    if(karar=='E' || karar=='e')
    {
        file.close();
        remove(dosyaAdi.c_str());
        cout << "Musteri kaydi basariyla silindi." << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    else if(karar=='H' || karar=='h')
    {
        cout<<"Silme islemi iptal edildi"<<endl;
    }

    }
    file.close();
    cin.get();
}
void Yetkiliislem::musteriAra()
{
    char kelime[100];
    float sayi;
    cout<<"Musteri arama islemi.."<<endl<<endl;
    cin.ignore();
    cout<<"Musteri TcNo: "; cin.getline(kelime,100); m1.SetTcno(kelime);
    string dosyaAdi=kelime;
    dosyaAdi.append(".txt");

    ifstream file(dosyaAdi);
    if(file.is_open()==0){
        cout<<kelime<<" numarali musteri kaydi yok!"<<endl;
    }
    else{
    file.read((char *)&m1,sizeof(MusteriBilgi));
    cout<<"Musteri No/TcNo: "<<m1.getTcno()<<endl;
    cout<<"Musteri Ad soyad: "<<m1.getAdSoyad()<<endl;
    cout<<"Musteri Adres: "<<m1.getAdres()<<endl;
    cout<<"Musteri Telefon: "<<m1.getTel()<<endl;;
    cout<<"Bakiye: "<<m1.getBakiye()<<endl<<endl;
    }
    file.close();
    cin.get();
}
void Yetkiliislem::musteriGuncelle()
{
    char kelime[100];
    float sayi;
    cout<<"Musteri Guncelleme islemi.."<<endl<<endl;
    cin.ignore();
    cout<<"Musteri TcNo: "; cin.getline(kelime,100); m1.SetTcno(kelime);
    string dosyaAdi=kelime;
    dosyaAdi.append(".txt");

    ifstream file(dosyaAdi);
    if(file.is_open()==0){
        cout<<kelime<<" numarali musteri kaydi yok!"<<endl;
    }
    else{
    file.read((char *)&m1,sizeof(MusteriBilgi));
    cout<<"Musteri No/TcNo: "<<m1.getTcno()<<endl;
    cout<<"Musteri Ad soyad: "<<m1.getAdSoyad()<<endl;
    cout<<"Musteri Adres: "<<m1.getAdres()<<endl;
    cout<<"Musteri Telefon: "<<m1.getTel()<<endl;;
    cout<<"Bakiye: "<<m1.getBakiye()<<endl<<endl;

    cout<<"Bilgilerini guncelleyiniz"<<endl;
    cout<<"Musteri Adres: "; cin.getline(kelime,100); m1.SetAdres(kelime);
    cout<<"Musteri Telefon: "; cin.getline(kelime,100); m1.SetTel(kelime);
    file.close();
    
    ofstream file(dosyaAdi);
    file.write((char *)&m1,sizeof(MusteriBilgi));
    file.close();
    cout<<"Musteri bilgileri guncellendi!!!"<<endl;

    }
    file.close();
    cin.get();
}

int Yetkiliislem::YetkiliMenu()
{
    system("cls");
    int secim;
    cout<<"..Sayin Admin Hosgeldiniz.."<<endl;
    cout<<"1-)Musteri Ekle"<<endl;
    cout<<"2-)Musteri Sil"<<endl;
    cout<<"3-)Musteri Ara"<<endl;
    cout<<"4-)Musteri Guncelle"<<endl;
    cout<<"0-)Cikis"<<endl;
    cout<<"Seciminiz: "; cin>>secim;
    return secim;
}
void Yetkiliislem:: YetkiliGiris()
{
    int secim= YetkiliMenu();
    while(secim!=0)
    {
        switch(secim)
        {
            case 1: musteriEkle(); break;
            case 2: musteriSil(); break;
            case 3: musteriAra(); break;
            case 4: musteriGuncelle(); break;
            case 0: break;
            default : cout<<"Hatali tuslama yaptiniz"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        secim=YetkiliMenu();  
    }
    
}
