/*
 * cw_04.cpp
 *
 * Copyright 2017 user <user@lap79>
 *
 */



#include <cstdlib>
#include <iostream>


using namespace std;

int main( int argc, char * argv[] )
{

    char txt[ 80 ], odwrocony[ 80 ];
    int w = 0;
    char max;
    cout << "Podaj ciag znakow:" << endl;
    cin.getline( txt, 80 );

    int ile;

    for( int i = 0; i < 80; i++ )
    {
        if( txt[ i ] == 0 )
        {
            ile = i;
            break;
        }
    }
    for( ile; ile > 0; ile-- )
    {
        odwrocony[ ile ] = txt[ ile - 1 ];
        cout << odwrocony[ ile ];
    }
    cout << endl;
    system( "pause" );
    return 0;
}
