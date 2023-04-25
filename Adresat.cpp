#include "Adresat.h"

void Adresat::ustalId (int noweId) {
    if(noweId >= 0)
        id = noweId;
}

void Adresat::ustalIdUzytkownika (int noweIdUzytkownika) {
    idUzytkownika = noweIdUzytkownika;
}

void Adresat::ustalImie(string noweImie) {
    imie = noweImie;
}

void Adresat::ustalNazwisko(string noweNazwisko) {
    nazwisko = noweNazwisko;
}

void Adresat::ustalNumerTelefonu(string nowyNumerTelefonu) {
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustalEmail(string nowyEmail) {
    email = nowyEmail;
}

void Adresat::ustalAdres(string nowyAdres) {
    adres = nowyAdres;
}

int Adresat::pobierzId() {
    return id;
}

int Adresat::pobierzIdUzytkownika() {
    return idUzytkownika;
}

string Adresat::pobierzImie() {
    return imie;
}

string Adresat::pobierzNazwisko() {
    return nazwisko;
}

string Adresat::pobierzNumerTelefonu() {
    return numerTelefonu;
}

string Adresat::pobierzEmail() {
    return email;
}

string Adresat::pobierzAdres() {
    return adres;
}
