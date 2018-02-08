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
} *korzen = NULL; // definicja struktury i utworzenie wskaźnika korzen dostępna globalnie nie w funkcji

Wezel* stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel; // struktura -> zmienna wskaźnikowa -> nowa struktura
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    
    return nowyWezel;
}

void dodajWezel(Wezel *wezel, int wartosc) {
    if (korzen == NULL) { // jeśli drzewo jest puste
        korzen = stworzWezel(wartosc); // utworzenie pierwszego węzła  przy tworzeniu klasy instrukcja zostaje przeniesiona do 
    } else {
        if (wartosc < wezel->wartosc) { // wartość mniejsza od węzła; wstawiamy wartość do lewego poddrzewa
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc); // wywołanie rekurencyjne dodawania do lewego poddrzewa 
            } else { // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc); // tworzymy nowy wezel
            }
        } else { // wartość większa od węzła; wstawiamy wartość do prawego poddrzewa
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc); // wywołanie rekurencyjne dodawania do prawego poddrzewa 
            } else { // prawy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc); // tworzymy nowy wezel
            }    
        }
    }
}

// funkcja rekurencyjnie przeglądająca drzewo - funkcja wyświetl
void wyswietlRosnaco(Wezel *wezel) {
    if (wezel != NULL) { // jeżeli węzeł nie jest pusty
        // rekrencyjnie wyświetl lewe poddrzewo
        wyswietlRosnaco(wezel->lewy);
        // wypisz wartość aktualnego węzła
        cout << wezel->wartosc << ", ";
        // rekurencyjnie wyświetl prawe poddrzewo
        wyswietlRosnaco(wezel->prawy);
    }
}


int main(int argc, char **argv) {
	dodajWezel(korzen, 10);
	dodajWezel(korzen, 8);
	dodajWezel(korzen, 4);
	dodajWezel(korzen, 20);
	dodajWezel(korzen, 30);
	dodajWezel(korzen, 16);
	dodajWezel(korzen, 9);
    
    cout << "Posortowane drzewo (niemalejąco): " << endl;
    wyswietlRosnaco(korzen);
    
    delete korzen; // zwolnienie wykorzystywanej pamieci
	return 0;
}

