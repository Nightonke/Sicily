// Problem#: 1839
// Submission#: 3271536
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    
    int caseNum;
    scanf("%d", &caseNum);

    while (caseNum--) {
        int na, nb;
        scanf("%d%d", &na, &nb);
        double win[70];
        win[0] = 0;
        for (double i = 1; i <= na; i++) {
            win[(int)i] = (i * (1 - win[(int)i - 1]) + nb) / (i + 2 * nb);
        }
        printf("%lf\n", win[na]);
    }

    //getchar();
    //getchar();
    return 0;
}                                 