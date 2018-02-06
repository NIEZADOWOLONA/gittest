/*
 * drzewo_bin.cpp
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>

using namespace std;

struct Wezel {
    int wartosc;
    Wezel *lewy; // lewa strona drzewa
    Wezel *prawy; // prawa strona drzewa
} *korzen = NULL; // definicja struktury i utworzenie wskaźnika korzen

Wezel* stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel; // struktura -> zmienna wskaźnikowa -> nowa struktura
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    
    return nowyWezel;
}

void dodajWezel(Wezel *wezel, int wartosc) {
    if (korzen == NULL) { // jeśli drzewo jest puste
        korzen = stworzWezel(wartosc); // utworzenie pierwszego węzła
    } else {
        if (wartosc < wezel->wartosc) { // wartość mniejsza od węzła
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc); // wywołanie rekurencyjne dodawania do lewego poddrzewa 
            } else { // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc); // tworzymy nowy wezel
            }
        } else () { // wartość większa od węzła
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc); // wywołanie rekurencyjne dodawania do prawego poddrzewa 
            } else { // prawy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc); // tworzymy nowy wezel
            }    
        }
    }
}

int main(int argc, char **argv) {
	
	return 0;
}

