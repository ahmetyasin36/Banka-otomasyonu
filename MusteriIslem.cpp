#include "MusteriIslem.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <thread> 
#include <fstream>
using namespace std;

MusteriIslem::MusteriIslem(){

}
MusteriIslem::~MusteriIslem(){

}

MusteriIslem::MusteriIslem(MusteriBilgi mbilg){
    m1=mbilg;
}

int MusteriIslem:: musteriMenu(){
    system("cls");
    int secim;
    cout<<"Sayin "<<m1.getAdSoyad()<<" Hosgeldiniz.."<<endl;
    cout<<"Hesap No: "<<m1.getTcno()<<endl<<endl;

    cout<<"1-)Para Cek"<<endl;
    cout<<"2-)Para Yatir"<<endl;
    cout<<"3-)Bakiye Goruntule"<<endl;
    cout<<"4-)Havele / EFT"<<endl;
    cout<<"5-)Hesap Hareketleri Goruntule"<<endl;
    cout<<"6-)Sifre Degistir"<<endl;
    cout<<"0-)Cikis"<<endl; 
    cout<<"Seciminiz: "; cin>>secim;
    return secim;
}

void MusteriIslem::musteriGiris(MusteriBilgi mPtr)
{
    m1=mPtr;

    int secim=musteriMenu();
    while(secim!=0)
    {
        switch(secim)
        {
            case 1: paraCek(); break;
            case 2: paraYatir(); break;
            case 3: bakiye(); break;
            case 4: havale(); break;
            case 5: hesapHareketleri(); break;
            case 6: sifreDegistir(); break;
            case 0: break;
            default : cout<<"Hatali tuslama yaptiniz"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        secim=musteriMenu();  
    }
}

void MusteriIslem:: paraCek(){
    system("cls");
    float sayi;
    char dosyaAdi[50];
    cout<<"..Para Cekme Ekrani.."<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<"TL"<<endl<<endl;
    cout<<"Cekeceginiz Miktar: ";  cin>>sayi;

    if(sayi>m1.getBakiye()){
        cout<<"Yetersiz Bakiye!"<<endl;
    }
    else
    {
        m1.Setbakiye( m1.getBakiye()-sayi );
        string dosyaAdi=m1.getTcno();
        dosyaAdi.append(".txt");
        ofstream file(dosyaAdi);
        file.write((char *)&m1,sizeof(MusteriBilgi));
        file.close();
        cout<<"Para Cekme Islemi tamam"<<endl;
        char msj[]="Para Cekildi"; 
        hareketKaydet( m1.getTcno(),msj); 
    }

    system("pause");
}
void MusteriIslem::paraYatir(){
    system("cls");
    int sayi;
    cout<<"..Para Yatirma Ekrani.."<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<"TL"<<endl<<endl;
    cout<<"Yatiracaginiz Miktar: ";  cin>>sayi;

    m1.Setbakiye( m1.getBakiye()+sayi );
    string dosyaAdi=m1.getTcno();
    dosyaAdi.append(".txt");
    ofstream file(dosyaAdi);
    file.write((char *)&m1,sizeof(MusteriBilgi));
    file.close();
    cout<<"Para Yatirma Islemi tamam"<<endl;

    char msj[]="Para yatirildi" ; 
	hareketKaydet( m1.getTcno(), msj); 
	system("pause");

}
void MusteriIslem::bakiye(){
    system("cls");
    float bakiye=m1.getBakiye();
    cout<<"..Bakiye Sorgulama Ekrani.."<<endl;
    cout<<"Bakiyeniz: "<<bakiye<<"TL"<<endl;

    char msj[]= "Bakiye Sorgulandi "; 
	hareketKaydet( m1.getTcno(),msj); 
	system("pause"); 	
}

void MusteriIslem::havale()
{
    system("cls");
    float sayi;
    char hesapno[50];
    cout<<"..Havale/EFT Ekrani.."<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<"TL"<<endl<<endl;
    cout<<"Havale edilecek Miktar: ";  cin>>sayi;

    if(sayi>m1.getBakiye()){
        cout<<"Yetersiz Bakiye!"<<endl;
    }
    else
    {
        MusteriBilgi m2;
        cout<<"Alici hesap no: "; cin>>hesapno;
        string dosyaAdi2=hesapno;
        dosyaAdi2.append(".txt");
        ifstream file2(dosyaAdi2);
        if(file2.is_open()==0){
        cout<<hesapno<<" numarali musteri kaydi yok!"<<endl;
        }
        else
        {
        file2.read((char *)&m2,sizeof(MusteriBilgi));
        file2.close();

        m2.Setbakiye( m2.getBakiye()+sayi );
        ofstream file2(dosyaAdi2);
        file2.write((char *)&m2,sizeof(MusteriBilgi));
        file2.close();

        m1.Setbakiye( m1.getBakiye()-sayi );
        string dosyaAdi=m1.getTcno();
        dosyaAdi.append(".txt");
        ofstream file(dosyaAdi);
        file.close();
        cout<<"Havale Islemi tamam"<<endl;

        char msj[]="Havale gonderildi "; 
		char msj2[]="Havale alindi "; 
		hareketKaydet( m1.getTcno(), msj );
		hareketKaydet( m2.getTcno(), msj2 ); 
        }
        file2.close();
    }
    system("pause");    
}

void MusteriIslem::hareketKaydet(char *tcNo,  char * msj)
{
    char dosyaAdi[30]; 
    strcpy(dosyaAdi, tcNo ); 
    strcat(dosyaAdi, "rapor.txt"); 
    ofstream file(dosyaAdi, ios::app); 
    file<< msj<< endl; 
    file.close(); 
}


void MusteriIslem::hesapHareketleri()
{
    system("cls") ; 
	cout<<"\nHesap hareket ekrani ... "<< endl<< endl; 
	
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, m1.getTcno() ) ; 
		strcat(dosyaAdi, "rapor.txt") ; 

		ifstream file(dosyaAdi) ; 
		string harf  ; 
		
		while (getline(file, harf))
        {
        cout << harf << endl;;
        }
		file.close(); 
		cout<<endl; 
		system("pause"); 	
}

void MusteriIslem::sifreDegistir()
{
    system("cls");
    char eskiSifre[20],yeniSifre[20];
    cout<<"..Sifre Degistirme Ekrani.."<<endl<<endl;
    cout<<"Lutfen eski sifrenizi giriniz: "; cin>>eskiSifre;
    string dosyaAdi=m1.getTcno();
    dosyaAdi.append(".txt");
    ifstream file(dosyaAdi);
    file.read((char *)&m1,sizeof(MusteriBilgi));
    if (strcmp(eskiSifre, m1.getSifre()) == 0)    
    {
        file.close();
        cout<<"Yeni sifrenizi giriniz: "; cin>>yeniSifre;
        m1.SetSifre(yeniSifre);
        string dosyaAdi=m1.getTcno();
        dosyaAdi.append(".txt");  
        ofstream file(dosyaAdi);
        file.write((char *)&m1,sizeof(MusteriBilgi));
        cout<<"Sifre degistirildi"<<endl;
        file.close();
        char msj[]="Sifre degistirildi "; 
		hareketKaydet(m1.getTcno(),msj);
    }
    else{
        cout<<"Eski sifrenizi yanlis tusladiniz!"<<endl;
    }
    
    file.close();
    system("pause");
}
