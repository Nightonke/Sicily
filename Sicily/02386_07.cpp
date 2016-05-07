// Problem#: 2386
// Submission#: 2811520
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

int g[3], b[3];

bool boy_win(int key) {
    if (key == b[0] || key == b[1] || key == g[0] || key == g[1] || key == g[2])
        return false;
    int bb[3], gg[3];
    int per[3] = {0, 1, 2};
    bb[0] = b[0];
    bb[1] = b[1];
    bb[2] = key;
    gg[0] = g[0];
    gg[1] = g[1];
    gg[2] = g[2];
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        if (gg[per[i]] > bb[i]) {
            counter++;
        }
    }
    if (counter >= 2) {
        return false;
    }
    while (next_permutation(per, per + 3)) {
        counter = 0;
        for (int i = 0; i < 3; i++) {
            if (gg[per[i]] > bb[i]) {
                counter++;
            }
        }
        if (counter >= 2) {
            return false;
        }
    }
    return true;
}

int main() {
    while (scanf("%d%d%d%d%d", &g[0], &g[1], &g[2], &b[0], &b[1]) && g[0]) {
        int key;
        bool is_win = false;
        for (key = 1; key <= 52; key++) {
            if (boy_win(key)) {
                is_win = true;
                printf("%d\n", key);
                break;
            }
        }
        if (!is_win) {
            printf("-1\n");
        }
    }
    return 0;
}                                 