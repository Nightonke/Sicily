// Problem#: 1905
// Submission#: 3590699
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAXC = 108;
const int MAXP = 10;
const char color_chr[] = "RGBY";

char stock[MAXC][3];
int sp;
char hand[MAXP][MAXC][3];
int count[MAXP];
int uno[MAXP];
int color[MAXP];
char cur[3];
int pl;
int dir;
int fst;
int n;

int draw(int p, int t) {
    while (t--) {
        if (sp >= MAXC) return 0;
        strcpy(hand[p][count[p]], stock[sp]);
        count[p]++;
        sp++;
    }
    return 1;
}

int value(char c[]) {
    if (c[0] == 'W') return 50;
    if (!isdigit(c[1])) return 20;
    return c[1] - '0';
}

int one_turn() {
    int i, j, k;
    if (fst) {
        j = count[pl];
        draw(pl, 1);
        fst = 0;
    } else {
        for (j = k = -1, i = 0; i < count[pl]; i++) {
            char * card = hand[pl][i];
            if (card[1] == 'F') {
                k = i;
            } else {
                if (card[0] != cur[0] && card[1] != cur[1]) {
                    if (card[0] != 'W') continue;
                } 
                if (j < 0) {
                    j = i;
                } else {
                    int vj = value(hand[pl][j]);
                    int vi = value(card);
                    if (vj < vi || vj == vi && strcmp(hand[pl][j], card) > 0)
                        j = i;
                }
            }
        }
    }
    if (j < 0) j = k;
    if (j < 0) {
        if (!draw(pl, 1)) return 0;
    } else {
        strcpy(cur, hand[pl][j]);
        strcpy(hand[pl][j], hand[pl][count[pl] - 1]);
        count[pl]--;
        int p = pl;
        if (count[pl] == 1) uno[pl]++;
        if (cur[0] == 'W') {
            int & c = color[pl];
            cur[0] = color_chr[c];
            c = (c + 1) % 4;
        }
        if (cur[1] == 'R') dir = n - dir;
        else if (cur[1] == 'S') pl = (pl + dir) % n;
        else if (cur[1] == 'D') {
            pl = (pl + dir) % n;
            if (!draw(pl, 2)) return 0;
        } else if (cur[1] == 'F') {
            pl = (pl + dir) % n;
            if (!draw(pl, 4)) return 0;
        }
        if (count[p] == 0) return 0;
    }
    pl = (pl + dir) % n;
    return 1;
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d", &n);
        for (int i = 0; i < MAXC; i++) scanf("%s", stock[i]);
        sp = 0;
        for (int i = 0; i < n; i++) {
            count[i] = uno[i] = color[i] = 0;
            draw(i, 7);
        }
        fst = 1;
        pl = 0;
        dir = 1;
        while (one_turn());
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < count[i]; j++) 
                s += value(hand[i][j]);
            printf("%d%c", s, i + 1 < n ? ' ' : '\n');
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", uno[i], i + 1 < n ? ' ' : '\n');
    }
    return 0;
}                                 