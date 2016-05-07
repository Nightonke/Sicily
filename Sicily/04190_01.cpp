// Problem#: 4190
// Submission#: 2752619
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int k = 1;
    int Prime_Palindromes[781];
    Prime_Palindromes[0] = 11;
    for (int i = 2; i <= 10000; i++) {
        int temp = i / 10, sum;
        for (sum = i; temp != 0; ) {
            sum = sum * 10 + temp % 10;
            temp /= 10;
        }
        int j;
        for (j = 2; j * j <= sum; j++) {
            if (sum % j == 0)
                break;
        }
        if (j * j > sum)
            Prime_Palindromes[k++] = sum;
    }
    sort(Prime_Palindromes, Prime_Palindromes + k);
    int a, b;
    while (scanf("%d%d", &a, &b) && a) {
        int i;
        for (i = 0; Prime_Palindromes[i] < a; i++);
        for (; Prime_Palindromes[i] <= b && i <= k - 1; i++)
            printf("%d\n", Prime_Palindromes[i]);
    }
    return 0;
}                                 