// Problem#: 1128
// Submission#: 2562740
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int i, kongzhi;
    char a[7], judge_r[][7] = {"162534", "164325", "165243", "163452", "612543", "613425", "615234", "614352", "432516", "524316", "345216", "253416", "342561", "254361", "435261", "523461", "521634", "341625", "251643", "431652", "256134", "346152", "526143", "436125"};
    while (scanf("%s", a) == 1) {
        kongzhi = 0;
        for (i = 0; i < 24; i++)
            if (strcmp(a, judge_r[i]) == 0)
            {
                printf("right\n");
                kongzhi = 1;
                break;
            }
        if (kongzhi == 0)
            printf("left\n");
    }
    return 0;
}                                 