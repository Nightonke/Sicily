// Problem#: 7151
// Submission#: 2751397
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>
using namespace std;

int n, m;

bool will_be_out(int pos_i, int pos_j, char move) {
    if (pos_i == 0 && move == 'W')
        return true;
    if (pos_i == n - 1 && move == 'E')
        return true;
    if (pos_j == 0 && move == 'S')
        return true;
    if (pos_j == m - 1 && move == 'N')
        return true;
    return false;
}

int main() {
    int k, pos_i, pos_j, p, i, j;
    char name[30], move[30];
    while (scanf("%d%d%d", &n, &m, &k) && n != 0) {
        for (j = 0; j < k; j++) {
            memset(name, '\0', sizeof(name));
            memset(move, '\0', sizeof(move));
            scanf("%s%d%d%d%s", name, &pos_i, &pos_j, &p, move);
            for (i = 0; i < (int)strlen(move); i++) {
                if (will_be_out(pos_i, pos_j, move[i])) {
                    if (p < 0) {
                        printf("%s is out of square!\n", name);
                        break;
                    } else if (p == 0) {
                        continue;
                    } else {
                        if (move[i] == 'E')
                            pos_i = 0;
                        else if (move[i] == 'W')
                            pos_i = n - 1;
                        else if (move[i] == 'S')
                            pos_j = m - 1;
                        else
                            pos_j = 0;
                        continue;
                    }
                } else {
                    if (move[i] == 'E')
                        pos_i++;
                    else if (move[i] == 'W')
                        pos_i--;
                    else if (move[i] == 'S')
                        pos_j--;
                    else
                        pos_j++;
                }
            }
            if (i == (int)strlen(move))
                printf("%d %d\n", pos_i, pos_j);
        }
        printf("\n");
    }
    return 0;
}                                 