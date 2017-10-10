#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  dane.py
#  

import csv

def dane_z_pliku(plik, delimiter='\t'): 
    dane = []
    with open(plik, 'r') as plikcsv: #otwiera, obsługuje i odrazu zamyka plik r - do odczytu
        tresc = csv.reader(plikcsv, delimiter=delimiter) # treść - zmiena csv.reader - dane oddzielone jednym znakiem
    
        for rekord in tresc: 
            dane.append(rekord)
            
    return(dane)

def wyczysc_dane(dane, pole):
    for i, rekord in enumerate(dane):
        el = rekord[pole]
        el = el.replace('zł', '')
        el = el.replace(' ', '')
        el = el.replace(',', '.')
        
    return ''


def main(args):
    #dane_z_pliku('premia.txt')
    #dane_z_pliku('dział.txt')
    dane = dane_z_pliku('pracownicy.txt')
    pracownicy = wyczysc_dane(dane, 5)
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
