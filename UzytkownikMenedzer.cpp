#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::zarejestrujUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login, haslo;
    do {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()));

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
    system("pause");
}

void  UzytkownikMenedzer::zalogujUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;
                if(uzytkownicy[i].pobierzHaslo() == haslo) {
                   idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                   cout << "Zalogowales sie.";
                   Sleep(1500);
                   return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            Sleep(1500);
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem." << endl << endl;
    Sleep(1500);
    return;
}

void UzytkownikMenedzer::zmienHasloZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika) {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
    cout << "Zostales wylogowany." << endl;
    system("pause");
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
