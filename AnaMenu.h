#ifndef ANAMENU_H
#define ANAMENU_H
#include"MusteriBilgi.h"

class AnaMenu{
    private:
    MusteriBilgi m1;
    public:
    AnaMenu();
    ~AnaMenu();
    void YetkiliGiris();
    void MusteriGiris();
    int menu();
    void giris();

};



#endif