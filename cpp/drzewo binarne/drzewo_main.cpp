#include <iostream>
#include "drzewo.hpp"

using namespace std;

int main(int argc, char **argv) {
    Drzewo drzewo;
	drzewo.dodajWezel(10);
	drzewo.dodajWezel(8);
	drzewo.dodajWezel(4);
	drzewo.dodajWezel(20);
	drzewo.dodajWezel(30);
	drzewo.dodajWezel(16);
	drzewo.dodajWezel(9);
    
    cout << "Posortowane drzewo (niemalejąco): " << endl;
    drzewo.wyswietlRosnaco();

	return 0;
}

