#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  pracownicy-orm.py

from peewee import *
from dane import * # import z dane.py

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
    stanowisko = ForeignKeyField(Premia, related_name = 'pracownicy') # pole związane z premią 
    data_zatr = CharField()
    placa = DecimalField(decimal_places = 2) # ograniczenie
    id_dzial = ForeignKeyField(Dzial, related_name = 'pracownicy')
    premia = DecimalField(decimal_places = 2, default = 0)

    

baza.connect()
baza.create_tables([Premia, Dzial, Pracownik], True)

premia = dane_z_pliku('premia.txt')
premia = wyczysc_dane(premia, 1)

pracownicy = dane_z_pliku('pracownicy.txt')
pracownicy = wyczysc_dane(pracownicy, 5)
pracownicy = wstaw_premie(pracownicy, dict(premia))

dzial = dane_z_pliku('dział.txt')

premia = [dict(zip(Premia._meta.sorted_field_names, row)) for row in premia]

dzial = [dict(zip(Dzial._meta.sorted_field_names, row)) for row in dzial]

pracownicy = [dict(zip(Pracownik._meta.sorted_field_names, row)) for row in pracownicy]


with baza.atomic():
    Premia.insert_many(premia).execute()
    Dzial.insert_many(dzial).execute()
    Pracownik.insert_many(pracownicy).execute()

#tworzenie instalacji klasy
#obiekt = Premia(id = "Sprzątaczka", premia = 0.2)
#print(obiekt.id, obiekt.premia)
#obiekt.save()

#obiekt = Premia(id = "Sekretarka", premia = 0.35)
#print(obiekt.id, obiekt.premia)
#obiekt.save()


















