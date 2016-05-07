// Problem#: 2368
// Submission#: 2752940
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
    int hhtt[8], temp, i, case_num;
    char ht[55];
    scanf("%d", &case_num);
    while (case_num--) {
        memset(hhtt, 0, sizeof(hhtt));
        memset(ht, '\0', sizeof(ht));
        scanf("%d", &temp);
        scanf("%s", ht);
        for (i = 0; i < (int)strlen(ht) - 2; i++) {
            if (ht[i] == 'T' && ht[i + 1] == 'T' && ht[i + 2] == 'T')
                hhtt[0]++;
            else if (ht[i] == 'T' && ht[i + 1] == 'T' && ht[i + 2] == 'H')
                hhtt[1]++;
            else if (ht[i] == 'T' && ht[i + 2] == 'T' && ht[i + 1] == 'H')
                hhtt[2]++;
            else if (ht[i] == 'T' && ht[i + 1] == 'H' && ht[i + 2] == 'H')
                hhtt[3]++;
            else if (ht[i] == 'H' && ht[i + 1] == 'T' && ht[i + 2] == 'T')
                hhtt[4]++;
            else if (ht[i] == 'H' && ht[i + 2] == 'H' && ht[i + 1] == 'T')
                hhtt[5]++;
            else if (ht[i] == 'H' && ht[i + 1] == 'H' && ht[i + 2] == 'T')
                hhtt[6]++;
            else
                hhtt[7]++;
        }
        printf("%d", temp);
        for (int i = 0; i < 8; i++) {
            printf(" %d", hhtt[i]);
        }
        printf("\n");
    }
    return 0;
}                                 