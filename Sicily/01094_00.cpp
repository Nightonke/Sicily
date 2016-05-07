// Problem#: 1094
// Submission#: 3591551
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

bool isOK;

char b[11][11];
char t[3][4];
char ans[10][3][4] = {{{'r', '.', '.', '.'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'r', '.', '.', '.'}}, 
                      
                      {{'.', 'r', '.', '.'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'r', '.', '.', '.'}}, 

                      {{'.', '.', 'r', '.'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'r', '.', '.', '.'}}, 

                      {{'.', '.', '.', 'r'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'r', '.', '.', '.'}}, 

                      {{'.', 'r', '.', '.'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'.', 'r', '.', '.'}}, 

                      {{'.', '.', 'r', '.'}, 
                       {'r', 'r', 'r', 'r'}, 
                       {'.', 'r', '.', '.'}}, 

                      {{'r', '.', '.', '.'}, 
                       {'r', 'r', 'r', '.'}, 
                       {'.', '.', 'r', 'r'}}, 
                      
                      {{'r', 'r', '.', '.'}, 
                       {'.', 'r', 'r', 'r'}, 
                       {'.', '.', 'r', '.'}}, 
 
                      {{'r', 'r', '.', '.'}, 
                       {'.', 'r', 'r', 'r'}, 
                       {'.', 'r', '.', '.'}}, 

                      {{'r', 'r', '.', '.'}, 
                       {'.', 'r', 'r', '.'}, 
                       {'.', '.', 'r', 'r'}}};

bool same(int k) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (ans[k][i][j] != t[i][j]) return false;
    return true;
}

bool check() {
    if (isOK) return true;
    for (int i = 0; i < 10; i++)
        if (same(i)) return true;
    return false;
}

void lr() {
    for (int i = 0; i < 3; i++) {
        swap(t[i][0], t[i][3]);
        swap(t[i][1], t[i][2]);
    }
}

void ud() {
    for (int i = 0; i < 4; i++) swap(t[0][i], t[2][i]);
}

void rotate() {
    lr();
    ud();
}

int main() {
    int cases = 1;
    while (scanf("%s", b[0]) != EOF) {
        for (int i = 1; i < 10; i++) scanf("%s", b[i]);
        int min_i = 10, min_j = 10, max_i = 0, max_j = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (b[i][j] == 'r') {
                    min_i = min(i, min_i);
                    min_j = min(j, min_j);
                    max_i = max(i, max_i);
                    max_j = max(j, max_j);
                }
        isOK = false;
        if ((max_i - min_i == 3 && max_j - min_j == 2) || (max_i - min_i == 2 && max_j - min_j == 3)) {
            if (max_i - min_i == 3 && max_j - min_j == 2)
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 4; j++)
                        t[i][j] = b[min_i + j][min_j + i];
            if (max_i - min_i == 2 && max_j - min_j == 3)
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 4; j++)
                        t[i][j] = b[min_i + i][min_j + j];
            isOK = check();
            lr(), isOK = check(), lr();
            ud(), isOK = check(), ud();
            rotate();
            isOK = check();
        }
        if ((max_i - min_i == 4 && max_j - min_j == 1) || (max_i - min_i == 1 && max_j - min_j == 4)) {
            char t1[6], t2[6];
            if (max_i - min_i == 4 && max_j - min_j == 1)
                for (int i = 0; i < 5; i++) {
                    t1[i] = b[min_i + i][min_j];
                    t2[i] = b[min_i + i][max_j];
                }
            if (max_i - min_i == 1 && max_j - min_j == 4)
                for (int i = 0; i < 5; i++) {
                    t1[i] = b[min_i][min_j + i];
                    t2[i] = b[max_i][min_j + i];
                }
            t1[5] = t2[5] = '\0';
            isOK = (strcmp("rrr..", t1) == 0 && strcmp("..rrr", t2) == 0) || (strcmp("rrr..", t2) == 0 && strcmp("..rrr", t1) == 0);
        }
        if (isOK) printf("Board %d: red squares can be folded into a cube\n", cases);
        else printf("Board %d: impossible\n", cases);
        cases++;
    }
    return 0;
}                                 