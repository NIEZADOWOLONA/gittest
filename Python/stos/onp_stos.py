#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    stos = [] # stos jako lista
    onp = input("Podaj wyrażenie ONP, oddzielając opanty i operatory spacjami:\n")

    onp = onp.split(" ")

    for wyraz in onp:
        if wyraz.isdigit():
            stos.append(wyraz)
        else:
            a = stos.pop()
            b = stos.pop()
            stos.append(eval(str(b) + wyraz + str(a)))
    print("Wynik: ", stos.pop())
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
