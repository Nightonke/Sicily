// Problem#: 1336
// Submission#: 3298611
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

double p;
int n;
double x[105];
char text[10000];

double char_to_double(char s[]) {
    double ans;
    sscanf(s, "%lf", &ans);
    return ans;
}

void init() {
    int length = strlen(text);
    for (int i = length - 1; i >= 0; i--) {
        if (text[i] == ' ') text[i] = '\0';
        else break;
    }
    char temp[10000];
    bool lastIsBlank = false;
    int i = 0;
    int j = 0;
    for (; text[i] != '\0'; i++) {
        if (!lastIsBlank || (lastIsBlank && text[i] != ' ')) temp[j++] = text[i];
        if (text[i] == ' ') lastIsBlank = true;
        else lastIsBlank = false;
    }
    temp[j] = '\0';
    while (j >= 0) {
        text[j] = temp[j];
        j--;
    }
}

void readin() {
    init();
    n = 0;
    bool isP = true;
    char s[15];
    int startPos = 0;
    for (int i = 0; 1; i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            s[i - startPos] = '\0';
            if (isP) {
                p = char_to_double(s);
                isP = false;
            } else {
                x[n++] = char_to_double(s);
            }
            if (text[i] == '\0') break;
            startPos = i + 1;
        } else {
            s[i - startPos] = text[i];
        }
    }
}

int main() {

    //std::cout.sync_with_stdio(false);

    while (gets(text)) {
        double ans = 0;
        readin();
        for (int i = 0; i < n; i++) {
            ans += pow(x[i], p);
        }
        printf("%.3lf\n", pow((ans / n), 1 / p));

    }

    return 0;
}                                 