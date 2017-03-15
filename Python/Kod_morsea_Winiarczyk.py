#!/usr/bin/env python
# -*- coding: utf-8 -*-

def koduj(napis):
	morse = {'a': '*-', 'b': '-***', 'c': '-*-*', 'd': '-**', 'e': '*', 'f': '**-*', 'g': '--*', 'h': '****', 'i': '**', 'j': '*---', 'k': '-*-', 'l': '*-**', 'm': '--', 'n': '-*', 'o': '---', 'p': '*--*', 'r': '*-*', 's': '***', 't': '-', 'u': '**-', 'v': '***-', 'w': '*--', 'x': '-**-', 'y': '-*--', 'z': '--**', 'ą': '*-*-', 'ć': '-*-**', 'ę': '**-**', 'ch': '----', 'ł': '*-**-', 'ń': '--*--', 'ó': '---*', 'ś': '***-***', 'ż': '--**-*', 'ź': '--**-'}
	for litera in napis:
		if litera != ' ':
			print morse[litera.lower()]

def main(args):
    raw_input("Podaj wyraz")
	koduj("napis")
    print napis
	return 0


if __name__ == '__main__':
	import sys
	sys.exit(main(sys.argv))
