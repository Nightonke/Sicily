// Problem#: 1681
// Submission#: 2698431
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

void get_min(int t) {
    int min[] = {0, 0, 1, 7, 4, 2, 6}, i;
    if (t < 7) {
        printf("%d", min[t]);
    } else {
        if (t % 7 == 0)
            for (i = 0; i < t / 7; i++)
                printf("8");
        if (t % 7 == 1) {
            printf("10");
            for (i = 0; i < t / 7 - 1; i++)
                printf("8");
        }
        if (t % 7 == 2) {
            printf("1");
            for (i = 0; i < t / 7; i++)
                printf("8");
        }
        if (t % 7 == 3) {
            if (t == 10)
                printf("22");
            else {
                printf("200");
                for (i = 0; i < t / 7 - 2; i++)
                    printf("8");
            }
        }
        if (t % 7 == 4) {
            printf("20");
            for (i = 0; i < t / 7 - 1; i++)
                printf("8");
        }
        if (t % 7 == 5) {
            printf("2");
            for (i = 0; i < t / 7; i++)
                printf("8");
        }
        if (t % 7 == 6) {
            printf("6");
            for (i = 0; i < t / 7; i++)
                printf("8");
        }
    }
}

void get_max(int t) {
    int i;
    printf(" ");
    if (t % 2) {
        printf("7");
        for (i = 0; i < t / 2 - 1; i++)
            printf("1");
    } else {
        for (i = 0; i < t / 2; i++)
            printf("1");
    }
    printf("\n");
}

int main() {
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        get_min(t);
        get_max(t);
    }
    return 0;
}                                 