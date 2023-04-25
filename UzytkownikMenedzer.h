#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikUZUzytkownikami) : plikZUzytkownikami(nazwaPlikUZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };

    void zarejestrujUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zalogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
