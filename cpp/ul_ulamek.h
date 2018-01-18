/*
 * plik nagłówkowy klasy Ulamek
 * 
 */

class Ulamek {
private:
    int licznik;  
    int mianownik;
public:
    Ulamek(int, int);
    void zapisz(int, int); 
    void wypisz();
    int get_l();
    int get_m();
    void skracaj();
};

