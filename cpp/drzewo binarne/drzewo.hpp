#ifndef DRZEWO_HPP
#define DRZEWO_HPP

struct Wezel { 
    int wartosc;
    Wezel *prawy; 
    Wezel *lewy; 
};

class Drzewo {
    private: 
        Wezel *korzen;
        Wezel* stworzWezel(int);
    public:
        Drzewo ();
        ~Drzewo ();
        void dodajWezel(int);
        void wyswietlRosnaco(Wezel *wezel);
        void wyswietlMalejaco(Wezel *wezel);
};

#endif
