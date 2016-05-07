// Problem#: 2386
// Submission#: 2811528
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

int c[5];

bool boy_win(int key) {
    for (int i = 0; i < 5; i++) {
        if (key == c[i]) {
            return false;
        }
    }
    int bb[3], gg[3];
    int per[3] = {0, 1, 2};
    bb[0] = c[3];
    bb[1] = c[4];
    bb[2] = key;
    gg[0] = c[0];
    gg[1] = c[1];
    gg[2] = c[2];
    while (1) {
        int counter = 0;
        for (int i = 0; i < 3; i++) {
            if (gg[per[i]] > bb[i]) {
                counter++;
            }
        }
        if (counter >= 2) {
            return false;
        }
        if (!next_permutation(per, per + 3)) {
            break;
        }
    }
    return true;
}

int main() {
    while (scanf("%d", &c[0]) && c[0]) {
        for (int i = 1; i < 5; i++) {
            scanf("%d", &c[i]);
        }
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