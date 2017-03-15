#!/usr/bin/env python
# -*- coding: utf-8 -*-


def szyfr_vigenere(tekst, klucz):
    i = 0
    for znak in tekst:
        wartosc1 = ord(znak.upper()) - 64
        wartosc2 = ord(klucz[i].upper()) - 64
        print wartosc1, wartosc2
        i += 1  # powiększanie indeksu


def main(args):
    tekst = raw_input("Podaj tekst: ")
    klucz = raw_input("Podaj klucz: ")
    print szyfr_vigenere(tekst, klucz)
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
