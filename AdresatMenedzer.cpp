#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustalId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustalIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustalImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustalNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustalNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustalEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustalAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i = 0; i < adresaci.size(); i++) {
            cout << "Id:                         " << adresaci[i].pobierzId()  << endl;
            cout << "Imie:                       " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:                   " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:             " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:                      " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:                      " << adresaci[i].pobierzAdres() << endl;
            cout << endl;
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie());

        for(size_t i = 0; i < adresaci.size(); i++) {
            if(adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie());

        for(size_t i = 0; i < adresaci.size(); i++) {
            if(adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;
    bool czyIstniejeAdresat = false;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    for(size_t i = 0; i < adresaci.size(); i++) {
        if(adresaci[i].pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            if (MetodyPomocnicze::wczytajZnak() == 't') {
                plikZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    int idEdytowanegoAdresata = 0;
    bool czyIstniejeAdresat = false;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    for (size_t i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;

            switch (wybierzOpcjeZMenuEdycja()) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustalImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                plikZAdresatami.edytujAdresataWPliku(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustalNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                plikZAdresatami.edytujAdresataWPliku(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustalNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujAdresataWPliku(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustalEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujAdresataWPliku(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustalAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujAdresataWPliku(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

int AdresatMenedzer::podajIdWybranegoAdresata() {
    cout << "Podaj numer ID Adresata: ";
    return MetodyPomocnicze::wczytajLiczbeCalkowita();
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja() {
    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";

    return MetodyPomocnicze::wczytajZnak();
}
