// Problem#: 1028
// Submission#: 2737143
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
char a[110];
int ac[110] = {0};
bool is_ok;

void change(int length) {
    for (int i = 0; i < length; i++) {
        ac[i] = a[i] - '0';
    }
}

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
    int t, i, length, counter, kongzhi = 0, first_pos;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        is_ok = true;
        if (kongzhi)
            printf("\n");
        memset(a, '\0', sizeof(a));
        memset(ac, 0, sizeof(ac));
        scanf("%s", a);
        length = strlen(a);
        change(length);
        counter = 0;
        first_pos = 0;
        while (1) {
            first_pos = divi(first_pos, length);
            if (is_ok)
                counter++;
            else
                break;
        }
        printf("Case %d: %d\n", i, counter + 1);
        kongzhi = 1;
    }
    return 0;
}                                 