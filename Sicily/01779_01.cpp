// Problem#: 1779
// Submission#: 2700027
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int a1[3010], a2[3010], a3[3010]; 
char f1[11], f2[11];

void ready() {
    int temp, i;
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    memset(a3, 0, sizeof(a3));
    for (temp = (int)strlen(f1), i = 0; i < temp; i++) {
        a1[i] = f1[temp - 1 - i] - '0';
    }
    for (temp = (int)strlen(f2), i = 0; i < temp; i++) {
        a2[i] = f2[temp - 1 - i] - '0';
    }
}

void multi() {
    int length_a1, length_a2, max_length_a3, i, j;
    for (length_a1 = 3009; length_a1 > 0 && a1[length_a1] == 0; length_a1--);
    for (length_a2 = 3009; length_a2 > 0 && a2[length_a2] == 0; length_a2--);
    length_a1++;
    length_a2++;
    max_length_a3 = length_a1 + length_a2;
    memset(a3, 0, sizeof(a3));
    for (i = 0; i <= length_a1; i++) {
        for (j = 0; j <= length_a2; j++) {
            a3[i + j] += a1[i] * a2[j];
            a3[i + j + 1] += a3[i + j] / 10;
            a3[i + j] %= 10;
        }
    }
    memset(a1, 0, sizeof(a1));
    for (i = 0; i <= length_a2; i++) {
        a1[i] = a2[i];
    }
    memset(a2, 0, sizeof(a2));
    for (i = 0; i <= max_length_a3; i++) {
        a2[i] = a3[i];
    }
}

int check_length_a2() {
    int i;
    for (i = 3009; i > 0 && a2[i] == 0; i--);
    return i + 1;
}
    
int main() {
    int t, temp, n, i;
    scanf("%d", &t);
    while (t--) {
        memset(f1, '\0', sizeof(f1));
        memset(f2, '\0', sizeof(f2));
        scanf("%s %s %d", f1, f2, &n);
        ready();
        if (n == 1) {
            printf("%s\n", f1);
            continue;
        }
        if (n == 2) {
            printf("%s\n", f2);
            continue;
        }
        if (f1[0] == '1' && f1[1] == '\0' && f2[0] == '1' && f2[1] == '\0') {
            printf("1\n");
            continue;
        }
        if (n >= 20) {
            printf("Ooops!\n");
            continue;
        }
        n = n - 2;
        while (check_length_a2() <= 1000 && n--) {
            multi();
        }
        temp = check_length_a2();
        if (temp <= 1000) {
            for (i = temp - 1; i >= 0; i--) {
                printf("%d", a2[i]);
            }
            printf("\n");
        } else {
            printf("Ooops!\n");
        }
    }
    return 0;
}                                 