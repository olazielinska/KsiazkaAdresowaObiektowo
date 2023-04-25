#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = stoi(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustalId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustalIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustalImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustalNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustalNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustalEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustalAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty()) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata = stoi(liniaZDanymiAdresata);
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    return MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunAdresataZPliku(int idAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int numerWczytanejLinii = 1, numerUsuwanejLinii = 0;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if(odczytywanyPlikTekstowy.good() && idAdresata != 0) {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idAdresata == stoi(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                numerUsuwanejLinii = numerWczytanejLinii;
            } else {
                idOstatniegoAdresata = stoi(daneJednegoAdresataOddzielonePionowymiKreskami);
                if (numerWczytanejLinii == numerUsuwanejLinii) {}
                else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            numerWczytanejLinii++;
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik();
        zmienNazwePliku();
    }
}

void PlikZAdresatami::usunPlik() {
    if (remove(pobierzNazwePliku().c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << pobierzNazwePliku() << endl;
}

void PlikZAdresatami::zmienNazwePliku() {
    if (rename(nazwaTymczasowegoPlikuZAdresatami.c_str(), pobierzNazwePliku().c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nazwaTymczasowegoPlikuZAdresatami << endl;
}

void PlikZAdresatami::edytujAdresataWPliku(Adresat adresat) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int liczbaLiniiWPliku = 0, numerWczytanejLiniiWPliku = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if(odczytywanyPlikTekstowy.good()) {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
            liczbaLiniiWPliku++;
    }

    odczytywanyPlikTekstowy.clear();
    odczytywanyPlikTekstowy.seekg(0, odczytywanyPlikTekstowy.beg);

    if(odczytywanyPlikTekstowy.good() && adresat.pobierzId() != 0) {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(adresat.pobierzId() == stoi(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
            } else
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            if(!(numerWczytanejLiniiWPliku == liczbaLiniiWPliku)) {
                tymczasowyPlikTekstowy << endl;
            }
            numerWczytanejLiniiWPliku++;
        }
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    usunPlik();
    zmienNazwePliku();
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
