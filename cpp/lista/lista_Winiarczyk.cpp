/*
 * lista.cpp
 * 
 * Copyright 2018  <>
 */


#include <iostream>
#include "lista.hpp"

Lista::Lista(){
    head = NULL;
    tail = NULL;
}

Lista::~Lista(){
    while(Usun()) {;}; // nic sie tu nie wykonuje ponieważ wszystko robi funkcja usuń
}

void Lista::Dodaj(int wartosc) {
    ELEMENT *el = new ELEMENT; // el - wskaźnik
    el->wartosc = wartosc; // gdy urzytkownik podaje wartość zostaje zapisana do listy
    el->nast = NULL; 
    if (head == NULL) { // dodanie pierwszego elementu na liście
        head = el; // head zawiera adres komórki pierwszej dodanej do listy, ustawiamy go tylko raz
        tail = el;
    } else {
        tail->nast = el; // zapisuje w poprzednim następny element
        tail = el; // od tej pory adres zawiera adres nowododanego elementu
    }
}

void Lista::Wyswietl() {
    ELEMENT *el = head; // el - wskaźnik zainicjowany wartością pierwszego elementu
    while (el != NULL) { // sprawdzam czy nie jest wartością NULL
        std::cout << el->wartosc << " "; // using namespace std - używam z przestrzeni nazw
        el = el->nast;
    } // funkcja wykonuje się dopóki el nie będzie NULL
    std::cout << std:: endl;
}

bool Lista::Usun() {
    if (head != NULL) {// jeżeli head nie jest Null to cały czas jest coś do usunięcia
        if(head == tail) {
            delete head; // usuwam element
            head = NULL;
            tail = NULL;
        } else {
            ELEMENT *el = head;
            while(el->nast != tail) { // szukam przedosatatniego elementu
                el = el->nast; // zapis adresu przedostatniego
            }
            delete el->nast;
            el->nast = NULL;
            tail = el;
        }
        return true;
    }
    return false;
}

void Lista::Wstaw(int pozycja, int wartosc){
    if (pozycja < 0)    pozycja *= (-1);	// wartosc bezwzgledna
    if(pozycja != 0){
        if(pozycja > i){
        Dodaj(wartosc);				// definicja powiekdzenia listy
        } else if (pozycja == 1) {		// zmiana na head
            ELEMENT *el = new ELEMENT;
            el -> wartosc = wartosc;
            el -> wskaznik = head;
            head = el;
            i++;
        } else {
            ELEMENT *el = new ELEMENT;
            el -> wartosc = wartosc;	// przypisanie nowej wartosci
            
            ELEMENT *p = head;		// wskaznik pomocniczy

            for (int j = 1; j != pozycja - 1; j++)
                p = p -> wskaznik;	// dotarcie do poprzedniej pozycji

            el -> wskaznik = p -> wskaznik;
            p -> wskaznik = el;
            
            i++;
        }
    }
}

