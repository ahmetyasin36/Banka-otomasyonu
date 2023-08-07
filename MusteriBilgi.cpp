#include "MusteriBilgi.h"
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
MusteriBilgi::MusteriBilgi()
{
    strcpy(Tcno,"");
    strcpy(AdSoyad,"");
    strcpy(adres,"");
    strcpy(tel,"");
    strcpy(sifre,"");
    bakiye=0;
}

MusteriBilgi::~MusteriBilgi()
{
}

MusteriBilgi::MusteriBilgi(const char *tc,const char *adsyd,const char *adr,const char *tlf,const char *sfr,float bk)
{
    strcpy(Tcno,tc); 
    strcpy(AdSoyad,adsyd);
    strcpy(adres,adr);
    strcpy(tel,tlf); 
    strcpy(sifre,sfr);
    /*
    Tcno=tc;
    AdSoyad=adsyd;
    adres=adr;  
    tel=tlf;
    sifre=sfr;
    bakiye=bk;
    */
}

    void MusteriBilgi::SetTcno(char *ptr){
        strcpy(Tcno,ptr);
    }
    char * MusteriBilgi::getTcno(){
        return Tcno;
    }

    void MusteriBilgi::SetAdSoyad(char *ptr){
        strcpy(AdSoyad,ptr);
    }
    char * MusteriBilgi::getAdSoyad(){
        return AdSoyad;
    }

    void MusteriBilgi::SetAdres(char *ptr){
        strcpy(adres,ptr);
    }
    char * MusteriBilgi::getAdres(){
        return adres;

    }

    void MusteriBilgi::SetTel(char *ptr){
        strcpy(tel,ptr);
    }
    char * MusteriBilgi::getTel(){
        return tel;

    }

    void MusteriBilgi::SetSifre(char *ptr){
        strcpy(sifre,ptr);
    }
    char * MusteriBilgi::getSifre(){
        return sifre;
    }

    void MusteriBilgi::Setbakiye(float bk){
        bakiye=bk;
    }
    float MusteriBilgi::getBakiye (){
        return bakiye;
    }
/*
    void DosyaAdi(char *dosya){
        string dosyaAdi=dosya;
        dosyaAdi.append(".txt");
    }proje sonunda tüm bu satır olanları buraya bağla!!!
    */