#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();
    static string wczytajLinie();
    static int wczytajLiczbeCalkowita();
};

#endif
