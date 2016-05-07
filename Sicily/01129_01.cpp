// Problem#: 1129
// Submission#: 2489108
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int sum, weight, i;
    char a[20];
    while (scanf("%s", a) != EOF) {
        sum = 0;
        weight = 10;
        for (i = 0; i < (int)strlen(a); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                sum = sum + (a[i] - '0') * weight;
                weight--;
            }
            printf("%c", a[i]);
        }
        for (i = 0; i <= 10; i++) {
            if ((sum + i) % 11 == 0)
                break;
        }
        if (i < 10)
            printf("-%d\n", i);
        else
            printf("-X\n");
    }
    return 0;
}                                 