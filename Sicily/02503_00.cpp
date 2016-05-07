// Problem#: 2503
// Submission#: 2701825
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int na, nb, ma, mb;
    scanf("%d%d%d%d", &na, &nb, &ma, &mb);
    if ((na == 0 && nb == 0) || (ma == 0 && mb == 0))
        printf("0\n");
    else if (na == 0 || ma == 0)
        printf("%d\n", nb < mb ? nb : mb);
    else if (nb == 0 || mb == 0)
        printf("%d\n", na < ma ? na : ma);
    else {
        if (na == nb)
            printf("%d\n", na + nb);
        else if (na < nb)
            printf("%d\n", na + (nb < (na + 1) * mb ? nb : (na + 1) * mb));
        else if (nb < na)
            printf("%d\n", nb + (na < (nb + 1) * ma ? na : (nb + 1) * ma));
    }
    return 0;
}                                 