// Problem#: 1511
// Submission#: 2519061
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, counter = 0;
    float input;
    char a[3];
    scanf("%d", &t);
    while (t--) {
        counter++;
        scanf("%f %s", &input, a);
        if (strcmp(a, "kg") == 0) {
            printf("%d %.4f lb\n", counter, input * 2.2046);
            continue;
        }
        if (strcmp(a, "l") == 0) {
            printf("%d %.4f g\n", counter, input * 0.2642);
            continue;
        }
        if (strcmp(a, "lb") == 0) {
            printf("%d %.4f kg\n", counter, input * 0.4536);
            continue;
        }
        if (strcmp(a, "g") == 0) {
            printf("%d %.4f l\n", counter, input * 3.7854);
            continue;
        }
    }
    return 0;
}                                 