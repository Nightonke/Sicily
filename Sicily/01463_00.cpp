// Problem#: 1463
// Submission#: 3313665
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    bool first = true;
    string s;
    while ( getline( cin, s ) ) {
        for ( int i = 0; i < s.size(); i++ ) {
            if ( i == 0 && !first ) {
                while ( i < s.size() && ( s[ i ] == '(' || s[ i ] == ')' ) )
                    i++;
                s[ i ] = toupper( s[ i ] );
            }
            else if ( s[ i ] == '.' || s[ i ] == '?' || s[ i ] == '!' ) {
                do {
                    i++;
                } while ( i < s.size() && ( s[ i ] == ' ' || s[ i ] == '(' || s[ i ] == ')' ) );
                if ( i == s.size() )
                    break;
                s[ i ] = toupper( s[ i ] );
            }
            else
                s[ i ] = tolower( s[ i ] );
        }
        first = false;
        cout << s << endl;
    }

    return 0;

}                                 