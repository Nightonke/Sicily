// Problem#: 1282
// Submission#: 2725399
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#define max_char 256
#define size 256
#define code_length 60005
using namespace std;

char code[60005], text[1000000];

int max(int a, int b) {
    return a > b ? a : b;
}

void prebmbc(int length_code, int bmbc[]) {
    int i;
    
    for (i = 0; i < max_char; i++) {
        bmbc[i] = length_code;
    }
    
    for (i = 0; i < length_code - 1; i++) {
        bmbc[code[i]] = length_code - 1 - i;
    }
    
}

void suffix(int length_code, int suff[]) {
    int f, g, i;
    suff[length_code - 1] = length_code;
    g = length_code - 1;
    for (i = length_code - 2; i >= 0; i--) {
        if (i > g && suff[i + length_code - 1 - f] < i - g)
            suff[i] = suff[i + length_code - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && code[g] == code[g + length_code - 1 - f])
                g--;
            suff[i] = f - g;
        }
    }
}

void prebmgs(int length_code, int bmgs[]) {
    int i, j;
    int suff[code_length];
    
    suffix(length_code, suff);
    
    for (i = 0; i < length_code; i++) {
        bmgs[i] = length_code;
    }
    
    j = 0;
    for (i = length_code - 1; i>= 0; i--) {
        if (suff[i] == i + 1) {
            for (; j < length_code - 1 - i; j++) {
                if (bmgs[j] == length_code) {
                    bmgs[j] = length_code - 1 - i;
                }
            }
        }
    }
    
    for (i = 0; i <= length_code - 2; i++) {
        bmgs[length_code - 1 - suff[i]] = length_code - 1 - i;
    }
    
}

void Boyer_Moore(int length_code, int length_text) {
    int i, j, bmbc[code_length], bmgs[code_length];
    
    prebmbc(length_code, bmbc);
    prebmgs(length_code, bmgs);
    
    j = 0;
    while (j <= length_text - length_code) {
        for (i = length_code - 1; i >= 0 && code[i] == text[i + j]; i--);
        if (i < 0) {
            cout << j << endl;
            j += bmgs[0];
            return;
        } else {
            //j += max(bmbc[(int)text[i + j]] - length_code + 1 + i, bmgs[i]);
            j += bmgs[i];
        }
    }
    
    cout << "no solution" << endl;
}

int main() {
    int i, temp, length_code, length_text;
    while (cin >> length_code) {
        for (i = 0; i < length_code; i++) {
            cin >> temp;
            code[i] = temp;
        }
        cin >> length_text;
        for (i = 0; i < length_text; i++) {
            cin >> temp;
            text[i] = temp;
        }
        Boyer_Moore(length_code, length_text);
    }
    return 0;
}                                 