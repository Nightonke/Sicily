// Problem#: 1029
// Submission#: 2495855
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int rabbitnum[101][51];
void initialize(int num, int rabnum) {
    int i;
    for (i = 50; i >= 0 && rabnum; i--) {
        rabbitnum[num][i] = rabnum % 10;
        rabnum /= 10;
    }
}
void highadd(int num, int birthing) {
    int i, start;
    for (i = 50; i >= 1; i--) {
        start = rabbitnum[num][i];
        rabbitnum[num][i] = (start + rabbitnum[num - 1][i] + 
        rabbitnum[num - birthing][i]) % 10;
        rabbitnum[num][i - 1] = (start + rabbitnum[num - 1][i] + 
        rabbitnum[num - birthing][i]) / 10;
    }
}

int main() {
    int birthing, need, i, cutfrontzero;
    while (scanf("%d %d", &birthing, &need), birthing && need) {
        memset(rabbitnum, 0, sizeof(rabbitnum));
        cutfrontzero = 0;
        for (i = 0; i <= need; i++) {
            if (i <= birthing)
                initialize(i, i + 1);
            else
                highadd(i, birthing);
        }
        for (i = 0; i <= 50; i++) {
            if (rabbitnum[need][i] != 0)
                cutfrontzero = 1;
            if (cutfrontzero)
                printf("%d", rabbitnum[need][i]);
        }
        printf("\n");
    }
    return 0;
}                                 