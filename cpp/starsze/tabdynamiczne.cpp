/*
 * tabdynamiczne.cpp
 * 
 */
 
 
 
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void wprowadzDane(int *t, int ile) {
    for(int i=0; i< ile; i++) {
        cout << "Podaj liczbę: ";
        //cin >> t[i];
        cout << "Adres komórki: " << (t + i) << endl;
        cin >> *(t + i);
    } 
}

int tab1W() {
    // tworzenie 1-wymiarowej tablicy dynamicznej
    int ile = 0;
    cout << "Ile liczb podasz? " << endl;
    cin >> ile;
    
    try {
        int *tab;
        tab = new int[ile];
        wprowadzDane(tab, ile);
    } catch(bad_alloc) {
        cout << "Za mało pamięci!";
        return 1;
    }
    return 0;
}

void wypelnij2W(int**tab, int w, int k) {
    srand(time(NULL)); // inicjacja generatora liczb pseudo losowych
    for(int i = 0; i < w; i++){ // pętla zewnętrzna od 0 i do góry
        for(int j = 0; j < k; j++){ // pętla wewnętrzna od 0 i do góry
            // cout << i << j << endl; 
            tab[i][j] = rand() % 101; // dzielenie modulo (reszta z dzienia) wartości do 100 zapisane 101
            cout << setw(4) << tab[i][j]; // pole szerokości 4 i w nim jest cyfra z komórki j
        }
        cout << endl;
    }
}

int tab2W(){
    int w, k, i;
    cout << "Ile wierszy i kolumn? ";
    cin >> w >> k;
    int **tab; // deklarackja wskaźnika do wskaźnika  
    
    try {
        tab = new int*[w]; // utworzenie tablicy wskaźników; zarezerwuj nowy obszar o wielkości w, zwierającej wskaźniki do wskaźników zawierającyvh wartości
    } catch(bad_alloc) {
        cout << "Za mało pamięci!";
        return 1;
    }
    
    for(i = 0; i < w; i++){
        try {
            tab[i] = new int[k]; // tablica liczb całkowitych
        } catch(bad_alloc) {
            cout << "Za mało pamięci!";
            return 1;
        }
    }
    wypelnij2W(tab, w, k);
}

int main(int argc, char **argv) {
	tab2W();
    
	return 0;
}

