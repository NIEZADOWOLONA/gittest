#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  czesc.py
#  

ROK_TERAZ = 2017
ROK_PYTHON = 1991

def parzyste():
    ile = list(range(0, n+1, 2))
    print(ile)
    return len(ile)

def main(args):
    imie = input("Jak się nazywasz? ")
    print ("Cześć", imie)
    wiek = int(input("Ile masz lat "))
    rok_urodzenia = ROK_TERAZ - wiek
    print ("Urodziłaś się w ", 2017 - wiek)
    
    if rok_urodzenia < ROK_PYTHON:
        print("Jestem starszy")
    elif rok_urodzenia > ROK_PYTHON:
        print("Jestem młodszy")
    else:
        print("Jesteśmy tak samo starzy")
        
    n = int(input("Podaj liczbę: "))
    print("Parzystych:", parzyste(n))
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
