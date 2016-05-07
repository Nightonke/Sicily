// Problem#: 1035
// Submission#: 2693102
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char dna[110][110];
int is_vis[110];

int dna_judge(char c1, char c2) {
    if (c1 == 'A' && c2 == 'T' || c1 == 'T' && c2 == 'A' || c1 == 'C' && c2 == 'G' || c1 == 'G' && c2 == 'C')
        return 1;
    else
        return 0;
}

int judge(int i, int j) {
    if (strlen(dna[j]) != strlen(dna[i]))
        return 0;
    for (int k = 0; k < (int)strlen(dna[i]); k++) {
        if (dna_judge(dna[i][k], dna[j][k]) == 0)
            return 0;
    }
    return 1;
}

int main() {
    int t, n, i, j, counter;
    scanf("%d", &t);
    while(t--) {
        counter = 0;
        memset(is_vis, 0, sizeof(is_vis));
        memset(dna, '\0', sizeof(dna));
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%s", dna[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n && is_vis[i] == 0; j++) {
                if (judge(i, j) && is_vis[j] == 0) {
                    counter++;
                    is_vis[i] = is_vis[j] = 1;
                    break;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 