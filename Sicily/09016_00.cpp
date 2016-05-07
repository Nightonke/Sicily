// Problem#: 9016
// Submission#: 2751629
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>
using namespace std;

struct Square {
    int pos_i;
    int pos_j;
}s[205];

int main() {
    int n, i, dir, temp, max_i, min_i, max_j, min_j;
    while (scanf("%d", &n) && n != 0) {
        s[0].pos_i = 0;
        s[0].pos_j = 0;
        min_i = max_i = min_j = max_j = 0;
        for (i = 1; i < n; i++) {
            scanf("%d %d", &temp, &dir);
            if (dir == 0) {
                s[i].pos_i = s[temp].pos_i;
                s[i].pos_j = s[temp].pos_j - 1;
            } else if (dir == 1) {
                s[i].pos_i = s[temp].pos_i + 1;
                s[i].pos_j = s[temp].pos_j;
            } else if (dir == 2) {
                s[i].pos_i = s[temp].pos_i;
                s[i].pos_j = s[temp].pos_j + 1;
            } else {
                s[i].pos_i = s[temp].pos_i - 1;
                s[i].pos_j = s[temp].pos_j;
            }
            
            if (s[i].pos_i < min_i)
                min_i = s[i].pos_i;
            if (s[i].pos_i > max_i)
                max_i = s[i].pos_i;
            if (s[i].pos_j < min_j)
                min_j = s[i].pos_j;
            if (s[i].pos_j > max_j)
                max_j = s[i].pos_j;
        }
        
        printf("%d %d\n", max_j - min_j + 1, max_i - min_i + 1);
    }
        
    return 0;
}                                 