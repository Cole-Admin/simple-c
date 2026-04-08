#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

typedef struct Slika
{
    char naziv[50];
    char stil[30];
    int godina;
    int cena;
    float dijagonala;

}Slika;

void sredi_novi_red(char tekst[]);
int unos_iz_fajla(Slika niz[], const char naziv_fajla[]);
Slika unos_iz_konzole();
void ispis_u_konzolu(Slika s);
void ispis_niza_u_konzolu(Slika niz[], int n);
void ispis_u_fajl(Slika niz[], int n, const char naziv_fajla[]);
void najjeftinija_slika(Slika niz[], int n);
void najjstarija_slika(Slika niz[], int n, const char stil[]);
void pretraga_po_nazivu_slike(Slika niz[], int n, const char naziv_slike[]);
void pretraga_po_stilu_slike(Slika niz[], int n, const char tip_slike[]);
void sortiranje_slika(Slika niz[], int n);

#endif // BIBLIOTEKA_H_INCLUDED
