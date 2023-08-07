#ifndef MUSTERIISLEM_H
#define MUSTERIISLEM_H
#include "MusteriBilgi.h"
#include<iostream>
#include<string.h>

class MusteriIslem{
    private:
    MusteriBilgi m1;
    //string dosyaAdi;
    public:
    MusteriIslem();
    ~MusteriIslem();
    MusteriIslem(MusteriBilgi m1);
    int musteriMenu();
    void musteriGiris(MusteriBilgi m1);
    void paraCek();
    void paraYatir();
    void bakiye();
    void havale();
    void hareketKaydet(char *tcNo,  char * msj);
    void hesapHareketleri();
    void sifreDegistir();
};



#endif