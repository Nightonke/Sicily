// Problem#: 1797
// Submission#: 2807298
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string>
using namespace std;

string z(int a, int b) {
    string s = "s";
    if (a - b > 0 && b > 0) {
        s += z(a - b, b);
    }
    s += "r";
    if (b - a > 0 && a > 0) {
        s += z(b - a, a);
    }
    return s;
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 || b == 0) {
            printf("0 0\n");
            continue;
        }
        string s = z(a, b);
        int dir = 0;
        int x, y;
        x = y = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'r') {
                dir = (dir + 1) % 4;
            } else {
                if (dir == 0) {
                    y++;
                } else if (dir == 1) {
                    x++;
                } else if (dir == 2) {
                    y--;
                } else {
                    x--;
                }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}                                 