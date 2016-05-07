// Problem#: 1628
// Submission#: 2699149
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;



void ready( char s[] ) {
    int i, j;
    static char temp[ 1000 ];

    for ( i = 0, j = 0; i < (int)strlen( s ); i++, j++ ) {
        if ( isdigit( s[ i ] ) ) {
            if ( i == 0 || ( s[ i - 1 ] != '+' && s[ i - 1 ] != '-' ) )
                temp[ j++ ] = '+';//
            while ( s[ i ] == '0' )
                i++;//
            while ( isdigit( s[ i ] ) )
                temp[ j++ ] = s[ i++ ];
            if ( temp[ j - 1 ] == '+' || temp[ j - 1 ] == '-' )
                j--;
        }
        temp[ j ] = ( s[ i ] >= 'a' && s[ i ] <= 'z' ? s[ i ] - 32: s[ i ] );
    }
    temp[ j ] = '\0';
    strcpy( s, temp );
}

bool issign( char s[] , int i ) {
    return ( i == 0 || !isdigit( s[ i - 1] ) ) && ( s[ i ] == '+' || s[ i ] == '-' ) && isdigit( s[ i + 1 ] );
}

int compare( char a[], char b[] ) {
    static int len1, len2;

    ready( a );
    ready( b );
    for ( int i = 1, j = 1; i < (int)strlen( a ) && j < (int)strlen( b ); i++, j++  ) {
        if ( isdigit( a[ i ] ) && isdigit( b[ j ] ) ) {
            int k = i;
            while ( isdigit( a[ k ] ) )
                k++;
            len1 = k - i;
            k = j;
            while ( isdigit( b[ k ] ) )
                k++;
            len2 = k - j;

            if ( len1 != len2 )
                return ( len1 < len2 ? -1: 1 );
            else {
                while ( i < k && j < k ) {
                    if ( a[ i++ ] != b[ j++ ] )
                        return ( a[ i ] < b[ j ] ? -1: 1 );
                }
            }
        }

        if ( a[ i ] != b[ j ] ) {
            if ( issign( a, i ) && issign( b, j ) )
                return ( a[ i ] == '-' ? -1: 1 );
            return ( a[ i ] < b[ j ] ? -1: 1 );
        }
    }

    return 0;

}


int main()
{
    int N, i;
    char a[ 1000 ], b[ 1000 ];

    cin >> N;
    for ( i = 1; i <= N; i++ ) {
        scanf( "%s%s", a, b );
        cout << i << " " << compare( a, b ) <<  endl;
    }

    return 0;

}                                 