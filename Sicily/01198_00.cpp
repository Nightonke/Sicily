// Problem#: 1198
// Submission#: 2569638
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char a[8][110];
int length[8];
void swap(int b1, int b2) {
    char temp[110];
    int temp1;
    strcpy(temp, a[b1]);
    strcpy(a[b1], a[b2]);
    strcpy(a[b2], temp);
    temp1 = length[b1];
    length[b1] = length[b2];
    length[b2] = temp1;
}

int main() {
    int t, n, i, j;
    char temp;
    scanf("%d", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        memset(length, 0, sizeof(length));
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%s", a[i]);
            length[i] = strlen(a[i]);
            temp = a[i][length[i] - 1];
            for (j = length[i]; j < 109; j++)
                a[i][j] = temp;
        }
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (strcmp(a[j], a[j + 1]) > 0) {
                    swap(j, j + 1);
                }
            }
        }
        for (i = 0; i < n; i++) {
            a[i][length[i]] = '\0';
        }
        for (i = 0; i < n; i++) {
            printf("%s", a[i]);
        }
        printf("\n");
    }
    return 0;
}                                 