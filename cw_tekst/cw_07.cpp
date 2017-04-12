/*
 * cw_07.cpp
 *
 */


#include <iostream>

using namespace std;

float suma(float a, float b){
    return a+b;
}
float roznica(float a,float b){
    return a-b;
}

float iloraz( float a, float b){
    return a/b;
}

float iloczyn( float a, float b){
    return a*b;
}


int main() {

    float a= 0;
    float b= 0;
    int n= 0;

    cout << "Ile par liczb chcesz wyliczyc: " << endl;
    cin >> n;

    for( int i=0; i<n; i++){
        cout << "Wpisz kolejno dwie liczby" << endl;
        cin >> a >> b;
        cout << endl;

    char znak;
    cout << "Rodzaj dzialania" << endl;
    cout << "+ Dodawanie" << endl;
    cout << "- Odejmowanie" << endl;
    cout << "/ Iloraz" << endl;
    cout << "* Iloczyn" << endl;
    cin >> znak;
    cout << endl;
        switch(znak) {
            case '+':
                cout << "Suma " << suma(a,b) << endl;
            break;
            case '-':
                cout << "Roznica " << roznica(a,b) << endl;
            break;
            case '*':
                cout << "Mnozenie " << iloczyn(a,b) << endl;
           case '/':
            if (b == 0)
                cout << "Nie dziel przez zero!!" << endl;
            else
                cout << "Dzielenie " << iloraz(a,b) << endl;
            break;
    cout << "Suma: " << suma(a,b) << endl;
    cout << "roznica: " << roznica(a,b) << endl;
    cout << "mnozenie: " << iloczyn(a,b) << endl;
    cout << "iloczyn" << iloczyn(a,b) << endl;

        }
    }

	return 0;
}

