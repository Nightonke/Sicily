// Problem#: 1899
// Submission#: 3590584
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 1000;
const int HASH_SIZE = 4096;

struct Point {
    int x, y;
    Point (int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
}stars[MAXN];

int head[HASH_SIZE];
int ptr[MAXN];

int hash(Point p) {
    return ((p.x * 20001 + p.y) % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

int find(int x, int y) {
    int f = hash(Point(x, y));
    for (int i = head[f]; i >= 0; i = ptr[i])
        if (stars[i].x == x && stars[i].y == y) return 1;
    return 0;
}

int main() {
    int ts;
    scanf("%d", &ts);
    while (ts--) {
        int n;
        scanf("%d", &n);
        memset(head, -1, sizeof(head));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &stars[i].x, &stars[i].y);
            int f = hash(stars[i]);
            ptr[i] = head[f];
            head[f] = i;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(stars[i].x < stars[j].x)) continue;
                if (stars[i].x - stars[j].x != stars[i].y - stars[j].y) continue;
                if (!find(stars[i].x, stars[j].y)) continue;
                if (!find(stars[j].x, stars[i].y)) continue;
                ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}                                 