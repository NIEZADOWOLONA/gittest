#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  pracownicy-orm.py

from peewee import *

baza_plik = 'pracownicy.sqlite3' #tworzymy bazę
baza = SqliteDatabase(baza_plik) #połączenie z bazą

class BazaModel(Model): # class - definiuje co obiekt zawiera; tworzy definicje; Model - wzór zaimportowany z peewee
    class Meta: # właściwości dodatkowe
        database = baza # określanie bazy danych
        
        
class Premia(BazaModel): # nazyw klaz z dużej litery
    id = CharField(primary_key = True) # właściwości obiektu, definicja pola które jest kluczem głównym
    premia = DecimalField()


class Dzial(BazaModel):
    id = IntegerField(primary_key = True)# w nawiasie dodatkowa właściwość - klucz główny
    nazwa = CharField() # nazwa - typ tekstowy, bez innych właściwości
    siedziba = CharField() # nazwa właściwości z małej]
    
    
class Pracownik(BazaModel): # tworze pojedyncze obiekty więc liczba poj, nie istotne jak wiele będzie później tych obiektów 
    id = CharField(primary_key = True)
    nazwisko = CharField()
    imie = CharField()
    stanowisko = ForeginKey(Premia, related_name = 'pracownicy') # pole związane z premią 
    data_zatr = CharField()
    placa = DecimalField(decimal_places = 2) # ograniczenie
    premia = DecimalField(decimal_places = 2, default = 0)
    id_dzial = ForeginKey(Dzial, related_name = 'pracownicy')
    

baza.connect()
baza.create_tables([Premia, Dzial, Pracownik], True)

    
