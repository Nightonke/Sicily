// Problem#: 1351
// Submission#: 3286198
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

const int MAX_C = 1000005;
bool lastSort[MAX_C];
int sortCol[MAX_C];
char text[3000000 + 4 * MAX_C];
int C, N, M;

int main() {

    //std::ios::sync_with_stdio(false);

    while (scanf("%d%d\n", &C, &N) != EOF) {

        gets(text);

        M = 0;

        int endPos = 0, sum = 0, counter = 1;
        while (text[endPos++] != '\0');

        for (int i = endPos - 2; i >= 0; i--) {
            if (text[i] == ' ') {
                if (!lastSort[sum]) sortCol[M++] = sum;
                lastSort[sum] = true;
                sum = 0;
                counter = 1;
            } else {
                sum += counter * (text[i] - '0');
                counter *= 10;
            }
        }

        if (!lastSort[sum]) sortCol[M++] = sum;
        lastSort[sum] = true;

        printf("%d\n", M);
        for (int i = M - 1; i > 0; i--) {
            printf("%d ", sortCol[i]);
            lastSort[sortCol[i]] = false;
        }
        printf("%d\n", sortCol[0]);
        lastSort[sortCol[0]] = false;
    }

    return 0;
}                                 