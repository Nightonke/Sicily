// Problem#: 1734
// Submission#: 3584358
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int MAXN = 20000;
long maxy[MAXN], miny[MAXN];
long stUp[MAXN][2], stDn[MAXN][2];
long topUp, topDn;

void input() {
    long n, i, x, y;
    scanf("%ld", &n);
    for (i = 0; i < 20000; i++) maxy[i] = miny[i] = -1;
    for (i = 0; i < n; i++) {
        scanf("%ld%ld", &x, &y);
        if (maxy[x] == -1) maxy[x] = miny[x] = y;
        else {
            if (y > maxy[x]) maxy[x] = y;
            if (y < miny[x]) miny[x] = y;
        }
    }
}

inline long product(long x1, long y1, long x2, long y2, long x3, long y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

void findConvexHull() {
    long i, j;
    for (i = 0; i < 20000; i++) if (maxy[i] != -1) break;
    stUp[0][0] = i;
    stUp[0][1] = maxy[i];
    stDn[0][0] = i;
    stDn[0][1] = miny[i];
    topUp = topDn = 0;
    for (i++; i < 20000; i++) 
        if (maxy[i] == -1) continue;
        else {
            while (topUp >= 1 && product(stUp[topUp - 1][0], stUp[topUp - 1][1], stUp[topUp][0], stUp[topUp][1], i, maxy[i]) >= 0) topUp--;
            ++topUp;
            stUp[topUp][0] = i;
            stUp[topUp][1] = maxy[i];
            while (topDn >= 1 && product(stDn[topDn - 1][0], stDn[topDn - 1][1], stDn[topDn][0], stDn[topDn][1], i, miny[i]) <= 0) topDn--;
            ++topDn;
            stDn[topDn][0] = i;
            stDn[topDn][1] = miny[i];
        }
}

long calArea() {
    long ret = 0, i;
    for (i = 1; i < topUp; i++)
        ret += product(stUp[0][0], stUp[0][1], stUp[i][0], stUp[i][1], stUp[i + 1][0], stUp[i + 1][1]);
    ret += product(stUp[0][0], stUp[0][1], stUp[topUp][0], stUp[topUp][1], stDn[topDn][0], stDn[topDn][1]);
    for (i = topDn; i > 0; i--)
        ret += product(stUp[0][0], stUp[0][1], stDn[i][0],  stDn[i][1], stDn[i - 1][0], stDn[i - 1][1]);
    return -ret;
}

int main() {
    long cases, answer;
    scanf("%ld", &cases);
    while (cases--) {
        input();
        findConvexHull();
        answer = calArea();
        if (answer & 1) printf("%ld.5\n", answer / 2);
        else printf("%ld.0\n", answer / 2);
    }
    return 0;
}                                 