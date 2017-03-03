/*
 * szyfr_cezara.cpp
 *
 * Copyright 2017 user <user@lap79>
 *
 *
 */


#include <iostream>

using namespace std;

void szyfruj(char tekst[100], int klucz) {
    klucz = klucz % 26;
    int i = 0; // indeks
    while (tekst[i] != '\0') {
        if ((int)tekst[i] + klucz > 122)
            tekst[i] = (char)((int)tekst[i] + klucz - 26)
        else
            ;
        i++;
    }
}

int main(int argc, char **argv) {
	char tekst[100];
    int klucz = 3;
    cout << "Podaj tekst: " << endl;
    cin >> tekst;
    cout << "Podaj klucz: " << endl;
    cin >> klucz;
    szyfruj(tekst, klucz);
    cout << tekst;

	return 0;
}

