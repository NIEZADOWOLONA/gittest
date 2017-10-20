#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  zapytania.py  

import sqlite3

def kw_a(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT Imie, Nazwisko, tbKlasy.Klasa
        FROM tbUczniowie, tbKlasy
        WHERE tbUczniowie.KlasaID = tbKlasy.IDKlasy
        AND Klasa LIKE ('1A')
    """)
    
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_b(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT MAX(EgzHum)
        FROM tbUczniowie
        """)
        
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def kw_c(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT AVG(EgzMat)
        FROM tbUczniowie
        """)
        
    wyniki = cur.fetchall()  #feth - pobierz; fethall - pobierz wszystko
    for row in wyniki:# row - zmienna
        print(tuple(row)) # przekształć i wydrukuj

def main(args):
    con = sqlite3.connect('szkola.db') # połączenie z bazą
    cur = con.cursor() #utworzenie kursora(gdy coś robię w bazie)
    con.row_factory = sqlite3.Row #możliwość odwoływania się do nazwy kolumn
    
    kw_c(cur)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
