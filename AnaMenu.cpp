#include"AnaMenu.h" 
#include "MusteriIslem.h"
#include "Yetkilislem.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <thread> 
#include <fstream>
using namespace std;

AnaMenu::AnaMenu(){

}
AnaMenu::~AnaMenu(){

}

void AnaMenu::YetkiliGiris(){
    system("cls");
    string kullaniciAdi,sifre;
    cout<<"..Yetkili Giris Ekrani.."<<endl;
    cout<<"Kullanici adi: "<<endl; cin>>kullaniciAdi;
    cout<<"Sifre: "<<endl; cin>>sifre;

    if((kullaniciAdi=="admin") && (sifre=="123"))
    {
        Yetkiliislem y1;
        y1.YetkiliGiris();
    }
    else
    {
        cout<<"Hatali kullanici adi veya parola"<<endl;
    }
    system("pause");

}
void AnaMenu::MusteriGiris(){
    system("cls");
    string kullaniciAdi,sifre;
    cout<<"..Musteri Giris Ekrani.."<<endl;
    cout<<"Kullanici adi/Tc No: "; cin>>kullaniciAdi;
    cout<<"Sifre: "; cin>>sifre;
    string dosyaAdi=kullaniciAdi;
    dosyaAdi.append(".txt");
    ifstream file(dosyaAdi);
    file.read((char *)&m1,sizeof(MusteriBilgi));

    if(!file.is_open()){
        cout<<"Kullanici adi/Tc No Hatali !!!"<<endl;
    }
    else
    {
    if( (sifre==m1.getSifre()) ) 
        {
            MusteriIslem mi1;
            mi1.musteriGiris(m1);
        }
        else
        {
            cout<<"Hatali TcNo/parola !"<<endl;
        }
    }
    
    file.close();
    system("pause");
    
}
int AnaMenu::menu(){
    system("cls");
    int secim;
    cout<<"\t Bankamatik Otomasyonu"<<endl<<endl;
    cout<<"[1]-Yetkili Giris"<<endl;
    cout<<"[2]-Musteri Giris"<<endl;
    cout<<"[0]-Cikis"<<endl;
    cout<<"Seciminiz: "; cin>>secim;
    return secim;

}
void AnaMenu::giris(){
    int secim=menu();
    while(secim!=0)
    {   
        switch(secim)
        {
            case 1: YetkiliGiris(); break;
            case 2: MusteriGiris(); break;
            case 0: break;
            default : cout<<"Hatali tuslama yaptiniz"<<endl;
            system("pause");
            //this_thread::sleep_for(chrono::seconds(1));
        }
        secim=menu();  
    }
}
