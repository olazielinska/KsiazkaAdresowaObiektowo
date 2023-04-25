#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::zarejestrujUzytkownika() {
    uzytkownikMenedzer.zarejestrujUzytkownika();
}

void KsiazkaAdresowa::zalogujUzytkownika() {
    uzytkownikMenedzer.zalogujUzytkownika();

    if(czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer -> dodajAdresata();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresatMenedzer -> wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
    adresatMenedzer -> wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    adresatMenedzer -> wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::usunAdresata() {
    adresatMenedzer -> usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {
    adresatMenedzer -> edytujAdresata();
}

void KsiazkaAdresowa::zmienHasloZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmienHasloZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}
