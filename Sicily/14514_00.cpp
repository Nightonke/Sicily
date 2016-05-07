// Problem#: 14514
// Submission#: 3728278
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 14514
// Submission#: 3727941
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//Sample solution for the Bread Sorting problem in NCPC 2012 by Lukáš Poláček (lukasP)

#include <stdio.h>
#include <string.h>

int n;
char text[600005];
bool seen[100005];
int A[100005], B[100005];

void ReadinA(int * num) {

    gets(text);
    int sum = 0, k = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            num[k++] = sum;
            sum = 0;
        }
        else {
            sum = 10 * sum + (text[i] & 15);
        }
    }
    num[k] = sum;
    //for (int i = 0; i < n; i++) scanf("%d", num + i);
}

void ReadinB(int * num) {

    gets(text);
    int sum = 0, k = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            num[A[k++] - 1] = sum;
            sum = 0;
        }
        else {
            sum = 10 * sum + (text[i] & 15);
        }
    }
    num[A[k] - 1] = sum;
    //for (int i = 0; i < n; i++) scanf("%d", num + i);
}

int main() {

    while (~scanf("%d\n", &n)) {
        ReadinA(A);
        ReadinB(B);
        memset(seen, false, sizeof(bool) * n);
        int swaps = n;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                swaps--;
                for (int j = i; !seen[j]; j = B[j] - 1) seen[j] = true;
            }
        }
        printf("%sossible\n", swaps & 1 ? "Imp" : "P");
    }

    return 0;
}                                 