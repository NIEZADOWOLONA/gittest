#include <iostream>
#include "drzewo.hpp"

using namespace std;

Wezel* stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel;
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    
    return nowyWezel;
}

void Drzewo::dodajWezel(Wezel *wezel, int wartosc) {
    if (korzen == NULL) { 
        korzen = stworzWezel(wartosc);
    } else {
        if (wartosc < wezel->wartosc) {
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc);
            } else { 
                wezel->lewy = stworzWezel(wartosc);
            }
        } else { 
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc); 
            } else { 
                wezel->prawy = stworzWezel(wartosc);
            }    
        }
    }
}

void Drzewo::wyswietlRosnaco(Wezel *wezel) {
    if (wezel != NULL) { 
        wyswietlRosnaco(wezel->lewy);
        cout << wezel->wartosc << ", ";
        wyswietlRosnaco(wezel->prawy);
    }
}

