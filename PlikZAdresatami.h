#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <fstream>
#include <vector>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {

    string nazwaTymczasowegoPlikuZAdresatami;
    int idOstatniegoAdresata;

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik();
    void zmienNazwePliku();

    public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void usunAdresataZPliku(int idAdresata);
    void edytujAdresataWPliku(Adresat adresat);
};

#endif
