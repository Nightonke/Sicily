// Problem#: 1737
// Submission#: 3584444
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <assert.h>

int grid[8][8];
int num, empty[10][2], enable[10];
const int path[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
int cal() {
    int i, j, whitecount = 0, blackcount = 0;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++) {
            if (grid[i][j] == 1) whitecount++;
            else if (grid[i][j] == -1) blackcount++;
            else assert(grid[i][j] == 0);
        }
        if (whitecount > blackcount) return 1;
        else if (whitecount == blackcount) return 0;
        else return -1;
}

int black();

int white() {
    int i, j, k, u, v, loop, temp1, temp2, res = -1, tempres;
    int rem[32][2], remnum;
    int tag = 0;
    for (i = 0; i < num; i++)
        if (enable[i]) {
            enable[i] = 0;
            u = empty[i][0];
            v = empty[i][1];
            grid[u][v] = 1;
            remnum = 0;
            for (loop = 0; loop < 8; loop++) {
                for (j = u, k = v; 0 <= j + path[loop][0] && j + path[loop][0] < 8
                    && 0 <= k + path[loop][1] && k + path[loop][1] < 8
                    && grid[j + path[loop][0]][k + path[loop][1]];) {
                    j += path[loop][0];
                    k += path[loop][1];
                    if (grid[j][k] == grid[u][v]) {
                        for (temp1 = u + path[loop][0], temp2 = v + path[loop][1];
                        (temp1 != j || temp2 != k);
                        temp1 += path[loop][0], temp2 += path[loop][1]) {
                            rem[remnum][0] = temp1;
                            rem[remnum][1] = temp2;
                            remnum++;
                        }
                        break;
                    }
                }
            }
            if (remnum > 0) {
                for (loop = 0; loop < remnum; loop++) {
                    j = rem[loop][0];
                    k = rem[loop][1];
                    grid[j][k] = -grid[j][k];
                }
                tempres = black();
                tag = 1;
                if (tempres > res) res = tempres;
                for (loop = 0; loop < remnum; loop++) {
                    j = rem[loop][0];
                    k = rem[loop][1];
                    grid[j][k] = -grid[j][k];
                }
            }
            grid[u][v] = 0;
            enable[i] = 1;
        }
    if (tag == 0) return cal();
    else return res;
}

int black() {
    int i, j, k, u, v, loop, temp1, temp2, res = 1, tempres;
    int rem[32][2], remnum;
    int tag = 0;
    for (i = 0; i < num; i++)
        if (enable[i]) {
            enable[i] = 0;
            u = empty[i][0];
            v = empty[i][1];
            grid[u][v] = -1;
            remnum = 0;
            for (loop = 0; loop < 8; loop++) {
                for (j = u, k = v; 0 <= j + path[loop][0] && j + path[loop][0] < 8
                    && 0 <= k + path[loop][1] && k + path[loop][1] < 8
                    && grid[j + path[loop][0]][k + path[loop][1]];) {
                    j += path[loop][0];
                    k += path[loop][1];
                    if (grid[j][k] == grid[u][v]) {
                        for (temp1 = u + path[loop][0], temp2 = v + path[loop][1];
                        (temp1 != j || temp2 != k);
                        temp1 += path[loop][0], temp2 += path[loop][1]) {
                            rem[remnum][0] = temp1;
                            rem[remnum][1] = temp2;
                            remnum++;
                        }
                        break;
                    }
                }
            }
            if (remnum > 0) {
                for (loop = 0; loop < remnum; loop++) {
                    j = rem[loop][0];
                    k = rem[loop][1];
                    grid[j][k] = -grid[j][k];
                }
                tempres = white();
                tag = 1;
                if (tempres < res) res = tempres;
                for (loop = 0; loop < remnum; loop++) {
                    j = rem[loop][0];
                    k = rem[loop][1];
                    grid[j][k] = -grid[j][k];
                }
            }
            grid[u][v] = 0;
            enable[i] = 1;
        }
    if (tag == 0) return cal();
    else return res;
}

int main() {
    char ch, str[100];
    int i, j;
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "EndOfInput") == 0) break;
        for (i = 0; i < 8; i++) {
            if (str[i] == 'w') grid[0][i] = 1;
            else if (str[i] == 'b') grid[0][i] = -1;
            else if (str[i] == 'e') grid[0][i] = 0;
        }
        for (i = 1; i < 8; i++) {
            scanf("%s", str);
            for (j = 0; j < 8; j++) {
                ch = str[j];
                if (ch == 'w') grid[i][j] = 1;
                else if (ch == 'b') grid[i][j] = -1;
                else if (ch == 'e') grid[i][j] = 0;
            }
        }
        
        //for (int i = 0; i < 8; i++) {
        //    for (int j = 0; j < 8; j++) {
        //        printf("%d ", grid[i][j]);
        //    }
        //    printf("\n");
        //}
            
        num = 0;
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                if (grid[i][j] == 0) {
                    empty[num][0] = i;
                    empty[num][1] = j;
                    enable[num] = 1;
                    num++;
                }
        scanf("%s", str);
        if (strcmp(str, "White") == 0) {
            i = white();
            if (i == 1) printf("White\n");
            else if (i == 0) printf("Draw\n");
            else if (i == -1) printf("Black\n");
            else assert(0);
        } else if (strcmp(str, "Black") == 0) {
            i = black();
            if (i == 1) printf("White\n");
            else if (i == 0) printf("Draw\n");
            else if (i == -1) printf("Black\n");
            else assert(0);
        } else assert(0);
    }
    return 0;
}                                 