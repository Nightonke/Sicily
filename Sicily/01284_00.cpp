// Problem#: 1284
// Submission#: 2827303
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        getchar();
        int head_zero = 0;
        int zero = 0;
        int need = 0;
        char temp;
        while (1) {
            temp = getchar();
            if (temp == '1' || temp == '\n') {
                break;
            } else if (temp == '0') {
                head_zero++;
            }
        }
        if (head_zero == n) {
            printf("%d\n", (n + 1) / 2);
            continue;
        }
        while (1) {
            temp = getchar();
            if (temp == '1') {
                zero = 0;
            }
            if (temp == '0') {
                zero++;
            }
            if (zero == 2) {
                need++;
                zero = 0;
            }
            if (temp == '\n') {
                break;
            }
        }
        for (int i = 0; i < head_zero; i++) {
            zero++;
            if (zero == 2) {
                need++;
                zero = 0;
            }
        }
        printf("%d\n", need);
    }
    return 0;
}                                 