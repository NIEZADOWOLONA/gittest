#ifndef LISTA_HPP
#define LISTA_HPP

struct ELEMENT { // rekurencyjny sposób deklarowania listy
    int wartosc;
    ELEMENT *nast; // wkaźnik do następnego elementu listy    
};

class Lista {
    private: // właściwości prywatne są po to aby nie można było ich zmienić; hermetyzacja danych
        ELEMENT *head;
        ELEMENT *tail;
    public: // interfejs publiczny (API klsy)
        Lista(); // konstruktor
        ~Lista(); // destruktor, posprzątanie po klasie
        // memeory leaks - wycieki pamięci - program nie informuje że wcześniej wykorzystywana pamięć nie jest już potrzebna
        void Dodaj(int);
        void Wyswietl();
        bool Usun();
        void Wstaw();
};

#endif
