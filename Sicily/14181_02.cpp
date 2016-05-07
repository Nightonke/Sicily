// Problem#: 14181
// Submission#: 3705495
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    int CaseNum;
    char C[30];
    scanf("%d\n", &CaseNum);
    while (CaseNum--) {
        int n, m;
        scanf("%d%d\n", &n, &m);
        printf("%d\n", n - 1);
        for (int i = 0; i < m; i++) gets(C);
    }
    return 0;
}                                 