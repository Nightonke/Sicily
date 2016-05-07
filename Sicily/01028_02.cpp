// Problem#: 1028
// Submission#: 2737168
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1028
// Submission#: 2572101
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int ac[110] = {0};
bool is_ok;

int divi(int first_pos, int length) {
    for (int i = first_pos; i < length; i++) {
        if (ac[i] > 0) {
            if (ac[i] % 2 == 1) {
                ac[i + 1] += 10;
            }
            ac[i] /= 2;
        }
    }
    if (ac[length] > 0) {
        is_ok = false;
        return 0;
    }
    if (ac[first_pos] == 0)
        return first_pos + 1;
    else
        return first_pos;
}

int main() {
    int t, i, length, counter, kongzhi = 0, first_pos, j;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        char a[105] = {'\0'};
        is_ok = true;
        if (kongzhi)
            printf("\n");
        kongzhi = 1;
        memset(ac, 0, sizeof(ac));
        scanf("%s", a);
        length = strlen(a);
        if ((a[length - 1] - '0') % 2 == 1) {
            printf("Case %d: 1\n", i, 1);
            continue;
        }
        counter = 0;
        if (length <= 20) {
            char judge[] = "18446744073709551615";
            if (strcmp(a, judge) <= 0 || length <= 19) {
                unsigned long long sum = 0;
                for (j = 0; j < length; j++) {
                    sum = sum * 10 + a[j] - '0' ;
                }
                while (sum % 2 == 0) {
                    counter++;
                    sum /= 2;
                }
                printf("Case %d: %d\n", i, counter + 1);
                continue;
            }
        }
        for (j = 0; j < length; j++) {
            ac[j] = a[j] - '0';
        }
        first_pos = 0;
        while (1) {
            first_pos = divi(first_pos, length);
            if (is_ok)
                counter++;
            else
                break;
        }
        printf("Case %d: %d\n", i, counter + 1);
    }
    return 0;
}                                 