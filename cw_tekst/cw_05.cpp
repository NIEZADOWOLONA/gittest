/*
 * cw_05.cpp
 *
 * Copyright 2017 user <user@lap79>
 *
 *
 */

#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
    char znak;
    cin>>znak;

    while(znak!='.') {
        if(znak>96)
        cout<<(char)(znak-32);
    else if (znak > 64 && znak < 91)
        cout << char(znak + 32);

    else
        cout<<znak;

    cin>>znak;
    }

    cout<<endl;

    system("pause");
    return 0;
}
