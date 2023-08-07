#ifndef YETKILIISLEM_H
#define YETKILIISLEM_H
#include "MusteriBilgi.h"

class Yetkiliislem{
    private:
    MusteriBilgi m1;
    public:
    Yetkiliislem();
    ~Yetkiliislem();

    void musteriEkle();
    void musteriSil();
    void musteriAra();
    void musteriGuncelle();
    int YetkiliMenu();
    void YetkiliGiris();
};



#endif