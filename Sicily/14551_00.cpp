// Problem#: 14551
// Submission#: 3744939
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const short DIR[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    printf("%d\n", caseNum);
    while (caseNum--) {
        char map[105][105], Move[20000];
        scanf("%s", Move);
        short minI = 105, minJ = 0, maxI = -1, maxJ = -1, pi = 0, pj = 0, dir = 0, P[20000][2], p = 1;
        P[0][0] = 0, P[0][1] = 0;
        for (int i = 0; Move[i] != '\0'; i++) {
            if (Move[i] == 'R') dir = (dir + 1) & 3;
            else if (Move[i] == 'L') dir = (dir + 3) & 3;
            else if (Move[i] == 'B') dir = (dir + 2) & 3;
            pi += DIR[dir][0];
            pj += DIR[dir][1];
            P[p][0] = pi;
            P[p][1] = pj;
            p++;
            if (pi < minI) minI = pi;
            if (pi > maxI) maxI = pi;
            if (pj > maxJ) maxJ = pj;
        }
        int width = maxJ - minJ + 1 + 1;
        int height = maxI - minI + 1 + 2;
        printf("%d %d\n", height, width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) map[i][j] = '#';
            map[i][width] = '\0';
        }
        if (minI < 0) minI = -minI;
        if (minJ < 0) minJ = -minJ;
        for (int i = 0; i < p; i++) map[P[i][0] + minI + 1][P[i][1] + minJ] = '.';
        for (int i = 0; i < height; i++) printf("%s\n", map[i]);
    }

    return 0;
}                                 