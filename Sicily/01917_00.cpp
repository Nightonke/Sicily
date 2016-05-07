// Problem#: 1917
// Submission#: 3591560
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int STOP = 5002;
const int LINE = 100;
const int LENGTH = 30;
const int NAME = 21;
const int STR = 8;
const int WALK = 2000;
const int BUS = 1000;
const int DIMENSION = 10240;

int x[STOP], y[STOP];
char name[STOP][NAME];
int n;
int length[LINE];
int line[LINE][LENGTH];
int m;
int counter[STOP];
int pass_by[STOP][LINE];
int distant[STOP];
int queue[STOP];

void calc(int & l, int & u, int f) {
    int m = (l + u) / 2;
    if (f == 0) u = m;
    else l = m;
}

void get_position(int p) {
    char buf[STR + 1];
    int lx, ux, ly, uy, dx, dy;
    scanf("%s%d%d", buf, &dx, &dy);
    lx = ly = 0;
    ux = uy = DIMENSION;
    for (int i = 0; i < STR; i++) {
        char ch = buf[i] - '0';
        calc(lx, ux, ch & 2);
        calc(ly, uy, ch & 1);
    }
    x[p] = lx + dx * 4;
    y[p] = ly + dy * 4;
}

int sqr(int x) {
    return x * x;
}

int in_range(int i, int j, int ds) {
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= ds * ds;
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        get_position(0);
        get_position(1);
        scanf("%d", &n);
        for (int i = 2; i < n + 2; i++) scanf("%s%d%d", name[i], x + i, y + i);
        memset(counter, 0, sizeof(int) * (n + 2));
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", length + i);
            for (int j = 0; j < length[i]; j++) {
                char buf[NAME];
                scanf("%s", buf);
                for (int id = 2; id < n + 2; id++) {
                    if (strcmp(name[id], buf) == 0) {
                        line[i][j] = id;
                        pass_by[id][counter[id]] = i;
                        counter[id]++;
                        break;
                    }
                }
            }
        }
        if (in_range(0, 1, WALK)) {
            printf("walk there\n");
            continue;
        }
        for (int i = 2; i < n + 2; i++) distant[i] = n + 1;
        int back = 0;
        for (int i = 2; i < n + 2; i++) {
            if (in_range(0, i, BUS)) {
                queue[back++] = i;
                distant[i] = 0;
            }
        }
        for (int front = 0; front < back; front++) {
            int s = queue[front];
            int d = distant[s];
            for (int ptr = 0; ptr < counter[s]; ptr++) {
                int line_id = pass_by[s][ptr];
                for (int i = 0; i < length[line_id]; i++) {
                    int t = line[line_id][i];
                    if (distant[t] > n) {
                        distant[t] = d + 1;
                        queue[back++] = t;
                    }
                }
            }
        }
        int ret = n + 1;
        for (int i = 2; i < n + 2; i++) {
            if (in_range(1, i, BUS) && distant[i] < ret) ret = distant[i];
        }
        if (ret < n + 1) printf("%d\n", ret);
        else printf("take a taxi\n");
    }
    return 0;
}                                 