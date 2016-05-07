// Problem#: 1299
// Submission#: 2760951
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char films[1005][85];
int main() {
    bool found;
    int blocks, names, m, i, times[1005], max, pos;
    char temp[85];
    while (scanf("%d", &blocks) && blocks) {
        memset(times, 0, sizeof(times));
        memset(films, '\0', sizeof(films));
        names = 0;
        while (blocks--) {
            scanf("%s", temp);
            scanf("%d", &m);
            while (m--) {
                memset(temp, '\0', sizeof(temp));
                scanf("%s", temp);
                for (i = 0, found = false; i < names; i++) {
                    if (!strcmp(temp, films[i])) {
                        times[i]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    strcpy(films[names], temp);
                    times[names++] = 1;
                }
            }
        }
        for (max = 0, pos = 0, i = 0; i < names; i++) {
            if (times[i] > max) {
                max = times[i];
                pos = i;
            }
        }
        printf("%s\n", films[pos]);
    }
    return 0;
}                                 