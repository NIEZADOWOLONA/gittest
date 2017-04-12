#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

void oczysc(string & docT, string zrT, string & K)
{
	for (int i = 0; i < zrT.length(); i++)
		if (zrT[i] != ' ')
			docT += toupper(zrT[i]);

	size_t poz = K.find(' ');
	if (poz != string::npos)
	{
		K.erase(poz, 1);
		do {
			poz = K.find(' ', poz + 1);
			if (poz != string::npos)
				K.erase(poz, 1);
		} while (poz != string::npos);
	}

	for (int i = 0; i < K.length(); i++)
		K[i] = toupper(K[i]);
}

void szyfruj(string tekst, string klucz)
{
	string tekstPop = "";
	string szyfrogram = "";

	oczysc(tekstPop, tekst, klucz);

	for (int i = 0; i < tekstPop.length(); i++)
		if (tekstPop[i] != ' ')
			szyfrogram += char(((int(tekstPop[i]) - 65) + ((int(klucz[i % klucz.length()])) - 65)) % 26 + 65);

	cout << szyfrogram << endl;
}

int main()
{
	string tekst;
	string klucz;

	cout << "Podaj tekst do zaszyfrowania: ";
	getline(cin, tekst);

	cout << "Podaj klucz szyfrowania: ";
	getline(cin, klucz);

	szyfruj(tekst, klucz);
	system("Pause");
}
