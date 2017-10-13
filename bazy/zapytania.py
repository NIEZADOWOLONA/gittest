#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  zapytania.py  

import sqlite3

def kw_d(cur):
    cur.execute(""" 
        SELECT siedziba, 
        FROM pracownicy, dzial
    """)

def kw_c(cur):# gdy """ """ przygotowanie zapytania
    cur.execute(""" 
        SELECT siedziba, SUM(placa) AS pensja
        FROM pracownicy, dzial
        WHERE pracownicy.id_dzial=dzial.id
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
    
    kw_c(cur)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
