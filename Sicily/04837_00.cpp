// Problem#: 4837
// Submission#: 3587617
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char text[1000005], target[15];

void newStrlwr(char * s) {
    int i = 0, k = 'a' - 'A';
    while (s[i] != '\0') {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] += k;
        i++;
    }
}

int main() {
    gets(target + 1);
    gets(text + 1);
    target[0] = text[0] = ' ';
    strcat(target, " ");
    strcat(text, " ");
    newStrlwr(target);
    newStrlwr(text);
    int ans = 0, p = -1;
    char * pos, * startPos = text;
    while (1) {
        pos = strstr(startPos, target);
        if (pos == NULL) break;
        startPos = pos + 1;
        ans++;
        if (p == -1) p = pos - text;
    }
    if (ans) printf("%d %d\n", ans, p);
    else printf("-1\n");
    return 0;
}                                 