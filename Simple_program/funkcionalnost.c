#include <stdio.h>
#include <string.h>
#include "biblioteka.h"

void sredi_novi_red(char tekst[])
{
    int duzina = strlen(tekst);

    if(duzina > 0 && tekst[duzina - 1] == '\n')
    {
        tekst[duzina - 1] = '\0';
    }
}
int unos_iz_fajla(Slika niz[], const char naziv_fajla[])
{
    FILE *ulaz = fopen(naziv_fajla, "r");

    if(ulaz == NULL)
    {
        printf("Trenutno nema konekcije sa fajlom!\n");
        return 0;
    }

    int brojac = 0;

    while(1)
    {
        Slika s;

        if(!fgets(s.naziv, 50, ulaz)) break;
        sredi_novi_red(s.naziv);

        if(!fgets(s.stil, 30, ulaz)) break;
        sredi_novi_red(s.stil);

        if(fscanf(ulaz, "%d\n", &s.godina) != 1) break;

        if(fscanf(ulaz, "%d\n", &s.cena) != 1) break;

        if(fscanf(ulaz, "%f\n", &s.dijagonala) != 1) break;

        niz[brojac++] = s;
    }

    fclose(ulaz);
    return brojac;
}
Slika unos_iz_konzole()
{
    Slika s;

    printf("Naziv: ");
    fgets(s.naziv, 50, stdin);
    sredi_novi_red(s.naziv);

    printf("Stil: ");
    fgets(s.stil, 30, stdin);
    sredi_novi_red(s.stil);

    printf("Godina: ");
    scanf("%d", &s.godina);
    getchar();

    printf("Cena: ");
    scanf("%d", &s.cena);
    getchar();

    printf("Dijagonala: ");
    scanf("%f", &s.dijagonala);
    getchar();

    return s;
}
void ispis_u_konzolu(Slika s)
{
    printf("Naziv: %s\n", s.naziv);
    printf("Stil: %s\n", s.stil);
    printf("Godina: %d\n", s.godina);
    printf("Cena: %d\n", s.cena);
    printf("Dijagonala %.2f\n", s.dijagonala);
}
void ispis_niza_u_konzolu(Slika niz[], int n)
{
    if(n == 0)
    {
        printf("Trenutno nema unetih slika u fajlu!\n");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        printf("\n==========================\n");
        printf("%d) Slika:\n", i + 1);
        ispis_u_konzolu(niz[i]);
        printf("\n==========================\n");
    }
}
void ispis_u_fajl(Slika niz[], int n, const char naziv_fajla[])
{
    FILE *izlaz = fopen(naziv_fajla, "w");

    if(izlaz == NULL)
    {
        printf("Trenutno nema konekcije sa fajlom!\n");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        fprintf(izlaz, "%s\n", niz[i].naziv);
        fprintf(izlaz, "%s\n", niz[i].stil);
        fprintf(izlaz, "%d\n", niz[i].godina);
        fprintf(izlaz, "%d\n", niz[i].cena);
        fprintf(izlaz, "%.2f\n", niz[i].dijagonala);
    }

    fclose(izlaz);
}
void najjeftinija_slika(Slika niz[], int n)
{
    int index_min = 0;
    int min = niz[0].cena;

    for(int i = 1; i < n; i++)
    {
        if(niz[i].cena < min)
        {
            min = niz[i].cena;
            index_min = i;
        }
    }

    ispis_u_konzolu(niz[index_min]);
}
void najjstarija_slika(Slika niz[], int n, const char stil[])
{
    int najjstarija = niz[0].godina;
    int index_najjstarije = 0;
    int nadjeno = 0;
    for(int i = 0; i < n; i++)
    {
        if(strstr(niz[i].stil, stil) != NULL)
        {
            for(int j = 1; j < n; j++)
            {
                if(niz[i].godina < najjstarija)
                {
                    najjstarija = niz[i].godina;
                    nadjeno++;
                    index_najjstarije = i;
                }
            }
        }
    }

    if(nadjeno == 0)
    {
        printf("Neuspesna pretraga!\n");
    }
    else
    {
        ispis_u_konzolu(niz[index_najjstarije]);
    }
}
void pretraga_po_nazivu_slike(Slika niz[], int n, const char naziv_slike[])
{
    int nadjeno = 0;

    for(int i = 0; i < n; i++)
    {
        if(strstr(niz[i].naziv, naziv_slike) != NULL)
        {
            ispis_u_konzolu(niz[i]);
            nadjeno++;
        }
    }
    if(nadjeno == 0);
    {
        printf("Neuspesna pretraga!\n");
    }
}
void pretraga_po_stilu_slike(Slika niz[], int n, const char tip_slike[])
{
    int nadjeno = 0;

    for(int i = 0; i < n; i++)
    {
        if(strstr(niz[i].stil, tip_slike) != NULL)
        {
            ispis_u_konzolu(niz[i]);
            printf("\n------------------------\n");
            nadjeno++;
        }
    }

    if(nadjeno == 0)
    {
        printf("Neuspesna pretraga!\n");
    }
}
/// void sortiranje_slika(Slika niz[], int n)
///{
    ///for(int i = 0; i < n; i++)
   /// {
        ///for(int j = i + 1; i < n - 1; j++)
       /// {
           /// if(niz[i] < niz[j])
            ///{
               /// Slika pomocna = niz[i];
               /// niz[i] = niz[j];
            ///    niz[j] = pomocna;
         ///   }
      ///  }
   /// }
///}

