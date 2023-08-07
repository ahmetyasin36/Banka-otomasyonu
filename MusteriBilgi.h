#ifndef MUSTERIBILGI_H
#define MUSTERIBILGI_H


class MusteriBilgi
{
private:
    char Tcno[20],AdSoyad[30],adres[30],tel[20],sifre[20];
    float bakiye;
public:
    MusteriBilgi();
    ~MusteriBilgi();

    MusteriBilgi(const char *tc,const char *adsyd,const char *adr,const char *tlf,const char *sfr,float bk);

    void SetTcno(char *ptr);
    char * getTcno();

    void SetAdSoyad(char *ptr);
    char * getAdSoyad();

    void SetAdres(char *ptr);
    char * getAdres();

    void SetTel(char *ptr);
    char * getTel();

    void SetSifre(char *ptr);
    char * getSifre();

    void Setbakiye(float bk);
    float getBakiye() ;
};




#endif