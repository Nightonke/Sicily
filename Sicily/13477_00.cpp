// Problem#: 13477
// Submission#: 3516696
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k = 2;
        bool increase = true;
        printf("1");
        for (int j = 1; j < 2 * i + 1; j++) {
            printf(" %d", k);
            if (k == i + 1) increase = false;
            if (increase) k++;
            else k--;
        }
        printf("\n");
    }
    
    return 0;
}                                 