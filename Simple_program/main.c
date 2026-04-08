#include <stdio.h>
#include <stdlib.h>
#include "biblioteka.h"
int main()
{
    Slika niz[30];
    int opcija = -1;
    int n = unos_iz_fajla(niz, "grupaB.txt");

    while(opcija != 0)
    {
        /// pretraga stil slike sredi izgled
        printf("\n=== MENI ===\n");
        printf("1) Unos slike\n");
        printf("2) Ispis svih slika\n");
        printf("3) Sacuvaj u fajl\n");
        printf("4) Najjeftinija slika\n");
        printf("5) Najjstarija slika(odredjenog stila)\n");
        printf("6) Pretraga po nazivu slike\n");
        printf("7) Pretraga po stilu slike\n");
        printf("8) Sortiranje po ceni slike opadajuce\n");
        printf("\nIzaberite opciju: ");
        scanf("%d", &opcija);
        getchar();

        if(opcija == 1)
        {
            niz[n++] = unos_iz_konzole();
        }
        else if(opcija == 2)
        {
            ispis_niza_u_konzolu(niz, n);
        }
        else if(opcija == 3)
        {
            ispis_u_fajl(niz, n, "grupaB.txt");
        }
        else if(opcija == 4)
        {
            najjeftinija_slika(niz, n);
        }
        else if(opcija == 5)
        {
            char stil[30];
            printf("\nUnesite po kom stilu zelite najjastariju sliku: ");
            fgets(stil, 30, stdin);
            sredi_novi_red(stil);
            najjstarija_slika(niz, n, stil);
        }
        else if(opcija == 6)
        {
            char naziv_slike[50];
            printf("\nUnesite naziv slike: ");
            fgets(naziv_slike, 50, stdin);
            sredi_novi_red(naziv_slike);
            pretraga_po_nazivu_slike(niz, n, naziv_slike);
        }
        else if(opcija == 7)
        {
            char tip_slike[30];
            printf("Unesite stil slike: ");
            fgets(tip_slike, 30, stdin);
            sredi_novi_red(tip_slike);
            printf("\n");
            pretraga_po_stilu_slike(niz, n, tip_slike);
        }
        else if(opcija == 8)
        {
            printf("\n-NE RADI OPCIJA-\n");
        }
        else if(opcija == 0)
        {
            printf("\n-KRAJ PROGRAMA-\n");
        }
        else
        {
            printf("Uneli ste nepostojecu opciju!\n");
        }

    }
}
