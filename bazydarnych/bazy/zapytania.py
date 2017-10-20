#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  zapytania.py  

import sqlite3

def kw_g(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT imie, nazwisko, stanowisko,
        (JulianDay())
        FROM pracownicy
    """)
    
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_f(cur):# gdy """ """ przygotowanie zapytania
    kobiety = cur.execute(""" 
        SELECT AVG (placa)
        FROM pracownicy
        WHERE imie LIKE('%a')
    """)
    
    wyniki = kobiety.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj
    
    
    men = cur.execute(""" 
        SELECT AVG (placa)
        FROM pracownicy
        WHERE imie NOT LIKE('%a')
    """)
        
    wyniki = men.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_e(cur):
    cur.execute(""" 
        SELECT nazwisko, stanowisko,
        pracownicy.placa *        
        (SELECT premia.premia
        FROM premia
        WHERE pracownicy.stanowisko = premia.id) 
        AS premia
        FROM pracownicy
        ORDER BY premia DESC
    """)
    # (...) mechanizm podzapytań
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_d(cur):
    nazwa = input("Podaj nazwę działu: ")
    siedziba = input("Podaj nazwę siedziba: ")
    print(nazwa)
    
    cur.execute(""" 
        SELECT nazwisko, imie, id_dzial, dzial.nazwa, dzial.siedziba
        FROM pracownicy, dzial
        WHERE pracownicy.id_dzial = dzial.id 
        AND dzial.nazwa = ? 
        AND siedziba = ? 
    """, (nazwa, siedziba))
    
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_c(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT siedziba, SUM(placa) AS pensja
        FROM pracownicy, dzial
        WHERE pracownicy.id_dzial = dzial.id
        GROUP BY siedziba
        ORDER BY pensja ASC
    """)
    
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def main(args):
    con = sqlite3.connect('pracownicy.sqlite3') # połączenie z bazą
    cur = con.cursor() #utworzenie kursora(gdy coś robię w bazie)
    con.row_factory = sqlite3.Row #możliwość odwoływania się do nazwy kolumn
    
    kw_g(cur)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
