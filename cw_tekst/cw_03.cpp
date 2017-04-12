/*
 * cw_03.cpp
 *
 * Copyright 2017 user <user@lap79>
 *
 *
 */


#include <iostream>

using namespace std;

int main() {
    string tekst;
    int dlugosc, wyr = 0;

    cout << "Podaj wyraz: ";
    getline(cin, tekst);
    dlugosc = tekst.length();

    for(int i = 0; i < dlugosc; i++) {
            if(tekst[i] == ' ')
            wyr++;
    }

    cout << "Ilośc wyrazów: " << wyr+1 << endl;
    cout << "Wyrazy: " << endl;

    for(int i = 0; i < dlugosc; i++) {
        cout << tekst[i];
        if(tekst[i] == ' ')
        cout << endl;
    }

	return 0;
}

