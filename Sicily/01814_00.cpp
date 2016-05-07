// Problem#: 1814
// Submission#: 2434243
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int y1, y2, m1, m2, d1, d2, n, i, tiancha1, tiancha2, tiancha3, zongtiancha, zj;
    scanf("%d", &n);
    while (n--) {
        tiancha1 = tiancha2 = tiancha3 = zongtiancha = 0;
        scanf("%d.%d.%d", &y1, &m1, &d1);
        scanf("%d.%d.%d", &y2, &m2, &d2);
        if (y1 < y2) {
            zj = y2;
            y2 = y1;
            y1 = zj;
            zj = m2;
            m2 = m1;
            m1 = zj;
            zj = d2;
            d2 = d1;
            d1 = zj;
        }
        for (i = y2; i < y1; i++) {
            if (i % 4 == 0 && i % 100 != 0)
                tiancha1 = tiancha1 + 366;
            if (i % 4 != 0)
                tiancha1 = tiancha1 + 365;
            if (i % 100 == 0 && i % 400 == 0)
                tiancha1 = tiancha1 + 366;
            if (i % 100 == 0 && i % 400 != 0)
                tiancha1 = tiancha1 + 365;
        }
        if ((y1 % 4 != 0) || (y1 % 100 == 0 && y1 % 400 != 0))
            tiancha2 = tiancha2 + 0;
        if ((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0))
            if ((m1 >= 3) || (m1 == 2 && d1 > 28))
                tiancha2 = tiancha2 + 1;
        if (m1 == 1)
            tiancha2 = tiancha2 + 0 + d1;
        if (m1 == 2)
            tiancha2 = tiancha2 + 31 + d1;
        if (m1 == 3)
            tiancha2 = tiancha2 + 59 + d1;
        if (m1 == 4)
            tiancha2 = tiancha2 + 90 + d1;
        if (m1 == 5)
            tiancha2 = tiancha2 + 120 + d1;
        if (m1 == 6)
            tiancha2 = tiancha2 + 151 + d1;
        if (m1 == 7)
            tiancha2 = tiancha2 + 181 + d1;
        if (m1 == 8)
            tiancha2 = tiancha2 + 212 + d1;
        if (m1 == 9)
            tiancha2 = tiancha2 + 243 + d1;
        if (m1 == 10)
            tiancha2 = tiancha2 + 273 + d1;
        if (m1 == 11)
            tiancha2 = tiancha2 + 304 + d1;
        if (m1 == 12)
            tiancha2 = tiancha2 + 334 + d1;
        if ((y2 % 4 != 0) || (y2 % 100 == 0 && y2 % 400 != 0))
            tiancha3 = tiancha3 + 0;
        if ((y2 % 4 == 0 && y2 % 100 != 0) || (y2 % 400 == 0))
            if ((m2 >= 3) || (m2 == 2 && d2 > 28))
                tiancha3 = tiancha3 + 1;
        if (m2 == 1)
            tiancha3 = tiancha3 + 0 + d2;
        if (m2 == 2)
            tiancha3 = tiancha3 + 31 + d2;
        if (m2 == 3)
            tiancha3 = tiancha3 + 59 + d2;
        if (m2 == 4)
            tiancha3 = tiancha3 + 90 + d2;
        if (m2 == 5)
            tiancha3 = tiancha3 + 120 + d2;
        if (m2 == 6)
            tiancha3 = tiancha3 + 151 + d2;
        if (m2 == 7)
            tiancha3 = tiancha3 + 181 + d2;
        if (m2 == 8)
            tiancha3 = tiancha3 + 212 + d2;
        if (m2 == 9)
            tiancha3 = tiancha3 + 243 + d2;
        if (m2 == 10)
            tiancha3 = tiancha3 + 273 + d2;
        if (m2 == 11)
            tiancha3 = tiancha3 + 304 + d2;
        if (m2 == 12)
            tiancha3 = tiancha3 + 334 + d2;
        zongtiancha = tiancha1 + tiancha2 - tiancha3;
        if (zongtiancha < 0)
            zongtiancha = zongtiancha * (-1);
        printf("%d\n", zongtiancha);
    }
    return 0;
}                                 