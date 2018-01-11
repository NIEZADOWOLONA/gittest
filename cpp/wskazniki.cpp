/*
 * wskazniki.cpp
 */


#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int x = 11;
    cout << x << endl; // wartość zmiennej
    cout << &x << endl; // adres zmiennej w pamięci 0x-wartość szesnastkowa
    cout << * &x << endl; // *-operator dereferencji/wskaźnikowy; odczytuje wartość z adresu podanej zmiennej
	
    int *px; // definicja wskaźnika do typu całkowitego
    px = &x; // do wskaźnika px przypisz wartość pamięci; inicjacja wskaźnika
    // wskaźnik zawsze zawiera adres pamięci
    cout << px << endl; // wyświetla się adres x
    cout << *px << endl; // wyświetla się wartość x

    int y = 100;
    px = &y;
    cout << px << endl;
    cout << *px << endl;
    
    return 0;
}

