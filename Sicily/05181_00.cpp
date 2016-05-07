// Problem#: 5181
// Submission#: 2655037
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, counter, i;
    char a[1001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, a);
        counter = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == '<')
                counter--;
            if (counter < 0)
                break;
            if (a[i] == '>')
                counter++;
            if (counter < 0)
                break;
        }
        if (counter == 0)
            printf("legal\n");
        else
            printf("illegal\n");
    }
    return 0;
}                                 