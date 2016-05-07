// Problem#: 1633
// Submission#: 2498349
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int sum, lengtha, lengthb, weishua, weishub, i, number, weishusum, j;
    char a[40], b[40], all[200];
    while (scanf("%s", all), all[0] != 'B') {
        j = 0;
        for (i = 0; i < 200; i++) {
            if (all[i] == '+')
                break;
            a[j++] = all[i];
        }
        a[j] = '\0';
        j = 0;
        for (i = i + 1; i < 200; i++) {
            if (all[i] == '=')
                break;
            b[j++] = all[i];
        }
        b[j] = '\0';
        sum = 0;
        lengtha = strlen(a);
        lengthb = strlen(b);
        weishua = lengtha / 3;
        weishub = lengthb / 3;
        for (i = 0; i < lengtha; i += 3) {
            if (a[i] == '0' && a[i + 1] == '6' && a[i + 2] == '3')
                number = 0;
            if (a[i] == '0' && a[i + 1] == '1' && a[i + 2] == '0')
                number = 1;
            if (a[i] == '0' && a[i + 1] == '9' && a[i + 2] == '3')
                number = 2;
            if (a[i] == '0' && a[i + 1] == '7' && a[i + 2] == '9')
                number = 3;
            if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '6')
                number = 4;
            if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '3')
                number = 5;
            if (a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '9')
                number = 6;
            if (a[i] == '0' && a[i + 1] == '1' && a[i + 2] == '1')
                number = 7;
            if (a[i] == '1' && a[i + 1] == '2' && a[i + 2] == '7')
                number = 8;
            if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '7')
                number = 9;
            sum = sum + number * (int)pow(10, --weishua);
        }
        for (i = 0; i < lengthb; i += 3) {
            if (b[i] == '0' && b[i + 1] == '6' && b[i + 2] == '3')
                number = 0;
            if (b[i] == '0' && b[i + 1] == '1' && b[i + 2] == '0')
                number = 1;
            if (b[i] == '0' && b[i + 1] == '9' && b[i + 2] == '3')
                number = 2;
            if (b[i] == '0' && b[i + 1] == '7' && b[i + 2] == '9')
                number = 3;
            if (b[i] == '1' && b[i + 1] == '0' && b[i + 2] == '6')
                number = 4;
            if (b[i] == '1' && b[i + 1] == '0' && b[i + 2] == '3')
                number = 5;
            if (b[i] == '1' && b[i + 1] == '1' && b[i + 2] == '9')
                number = 6;
            if (b[i] == '0' && b[i + 1] == '1' && b[i + 2] == '1')
                number = 7;
            if (b[i] == '1' && b[i + 1] == '2' && b[i + 2] == '7')
                number = 8;
            if (b[i] == '1' && b[i + 1] == '0' && b[i + 2] == '7')
                number = 9;
            sum = sum + number * (int)pow(10, --weishub);
        }
        printf("%s+%s=", a, b);
        for (i = 9; i >= 0; i--) {
            if (sum == 0)
                weishusum = 1;
            if (sum / (int)pow(10, i) != 0) {
                weishusum = i + 1;
                break;
            }
        }
        for (i = weishusum; i > 0; i--) {
            if (sum / (int)pow(10, i - 1) == 0)
                printf("063");
            if (sum / (int)pow(10, i - 1) == 1)
                printf("010");
            if (sum / (int)pow(10, i - 1) == 2)
                printf("093");
            if (sum / (int)pow(10, i - 1) == 3)
                printf("079");
            if (sum / (int)pow(10, i - 1) == 4)
                printf("106");
            if (sum / (int)pow(10, i - 1) == 5)
                printf("103");
            if (sum / (int)pow(10, i - 1) == 6)
                printf("119");
            if (sum / (int)pow(10, i - 1) == 7)
                printf("011");
            if (sum / (int)pow(10, i - 1) == 8)
                printf("127");
            if (sum / (int)pow(10, i - 1) == 9)
                printf("107");
            sum = sum % (int)pow(10, i - 1);
        }
        printf("\n");
    }
    return 0;
}                                 