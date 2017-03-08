#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  Szyfr Cezara
#
def szyfruj(tekst, klucz):

    szyfogram = ""
    for i in range(len(tekst)):
        if spacja:
            szyfogram += " "
            continue
        if ord(tekst[i]) + klucz > 122:
            szyfrogram += chr(ord(tekst[i].lower()) + klucz - 26)
        else:
            szyfogram += chr(ord(tekst[i].lower()) + klucz)
    print szyfogram

def main(args):
    tekst = raw_input("Podaj tekst: ")
    klucz = int(raw_input("Podaj klucz: "))
    szyfruj(tekst, klucz)
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
