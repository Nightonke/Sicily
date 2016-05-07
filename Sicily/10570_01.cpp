// Problem#: 10570
// Submission#: 2811106
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    int now, n;
    scanf("%d", &now);
    scanf("%d", &n);
    int all_time = 0;
    bool is_print = false;
    while (n--) {
        int times;
        char control;
        scanf("%d %c", &times, &control);
        all_time += times;
        if (all_time >= 210 && !is_print) {
            is_print = true;
            printf("%d\n", now);
        }
        if (control == 'T') {
            now = now + 1 == 9 ? 1 : now + 1;
        }
    }
    return 0;
}                                 