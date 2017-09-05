/*
 * czesc.cpp
 */


#include <iostream>


using namespace std;

#define ROK_TERAZ 2017
#define ROK_CPP 1984

int main(int argc, char **argv)
{
    string a;
    int b;
    int rok_urodzenia;
    cout << "Cześć. Jak się nazywasz " << endl;
    cin >> a;
    cout << "Cześć " << a << endl;
    cout << "Ile masz lat? " << endl;
    cin >> b;
    rok_urodzenia = ROK_TERAZ - b;
    cout << "Urodziłeś/Urodziłaś się w " << rok_urodzenia << endl;

    if (rok_urodzenia > ROK_CPP) {
        cout << "Jestem starszy" << endl; }
        
    if (rok_urodzenia < ROK_CPP) {
        cout << "Jestem młodszy" << endl; }
        
    if (rok_urodzenia == ROK_CPP) {
        cout << "Jesteśmy tak samo starzy" << endl; }
    
	return 0;
}

