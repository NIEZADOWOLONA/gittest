/*
 * cw_02.cpp
 *
 */


#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    char slowo[3];
    cout << "Podaj slowo(ilosc znakow 4): ";
    cin >> slowo;

    for(int i=3; i>=0; i--){
    cout << slowo[i];
}

	return 0;
}

