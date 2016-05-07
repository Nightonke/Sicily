// Problem#: 1797
// Submission#: 2807341
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string>
using namespace std;

int x, y;
int dir;


void gogogo(int a, int b) {
    if (a > 0 && b > 0) {
        if (dir == 0) {
            y++;
        } else if (dir == 1) {
            x++;
        } else if (dir == 2) {
            y--;
        } else {
            x--;
        }
    } else {
        return;
    }
    gogogo(a - b, b);
    dir = (dir + 1) % 4;
    gogogo(b - a, a);
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int a, b;
        x = y = dir = 0;
        scanf("%d%d", &a, &b);
        gogogo(a, b);
        printf("%d %d\n", x, y);
    }
    return 0;
}                                 