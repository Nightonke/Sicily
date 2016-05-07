// Problem#: 10392
// Submission#: 2757403
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct Move {
    int num;
    char dir;
};

int main() {
    int b, e, i, j, b_pos, e_pos, counter;
    bool last_is_88 = false;
    Move bm[50005], em[50005];
    scanf("%d %d", &b, &e);
    for (i = 0; i < b; i++) {
        scanf("%d %c", &bm[i].num, &bm[i].dir);
    }
    for (i = 0; i < e; i++) {
        scanf("%d %c", &em[i].num, &em[i].dir);
    }
    b_pos = e_pos = i = j = counter = 0;
    while (1) {
        if (i == b && j == e)
            break;
        if (bm[i].num && i < b) {
            if (bm[i].dir == 'L')
                b_pos--;
            else 
                b_pos++;
            bm[i].num--;
        }
        if (bm[i].num == 0) {
            i = i < b ? i + 1 : i;
        }
        if (em[j].num && j < e) {
            if (em[j].dir == 'L')
                e_pos--;
            else 
                e_pos++;
            em[j].num--;
        }
        if (em[j].num == 0) {
            j = j < e ? j + 1 : j;
        }
        if (b_pos == e_pos && last_is_88) {
            counter++;
            last_is_88 = false;
        }
        if (b_pos != e_pos)
            last_is_88 = true;
    }
    printf("%d\n", counter);
    return 0;
}                                 