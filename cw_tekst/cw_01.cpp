/*
 * cw_01.cpp
 *
 * Copyright 2017 user <user@lap79>
 *
 */


#include <iostream>

using namespace std;

int main() {
    char slowo[15];

    cout << "Podaj slowo do wypisania od tylu:\n";
    cin >> slowo;

    for(int i=15; i>=0; i--) {

    cout << slowo[i]; }
}
