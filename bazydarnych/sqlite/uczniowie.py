#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  zapytania.py

import sqlite3

def wyniki(cur):
    wyniki = cur.fetchall()
    for row in wyniki:
        print(tuple(row))

def dodaj(cur):
    cur.execute("""
        INSERT INTO tbKlasy
        VALUES (?, ?, ?, ?)
    """, [None, '3C', 2015, 2018])
    
def aktualizuj(cur):
    cur.execute(""" 
        UPDATE tbKlasy
        SET klasa = ?
        WHERE idklasy = ?
    """, ['3D', 13])
    
def aktualizuj2(cur):
    cur.execute(""" 
        UPDATE tbUczniowie
        SET EgzJez = ?
        WHERE Imie LIKE 'Paulina'
        AND Nazwisko LIKE 'Dziedzic'
    """, [35])
    
def usun(cur):
    cur.execute('DELETE FROM tbKlasy WHERE klasa = ? AND roknaboru = ?', ['3B', 2015])


def main(args):
    con = sqlite3.connect('szkola.db')
    cur = con.cursor() 
    con.row_factory = sqlite3.Row
    
    
    aktualizuj2(cur)
    con.commit()

    wyniki(cur.execute('SELECT EgzJez FROM tbUczniowie'))
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
