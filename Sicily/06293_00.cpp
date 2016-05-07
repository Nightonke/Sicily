// Problem#: 6293
// Submission#: 3264952
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

int ul[3][3] = {1, 2, 0,
                3, 0, 1,
                0, 0, 0};

int ur[3][3] = {3, 0, 0,
                0, 2, 0,
                2, 3, 1};

int dl[3][3] = {0, 1, 3,
                0, 3, 2,
                2, 0, 0};

int dr[3][3] = {0, 0, 2,
                1, 0, 0,
                0, 1, 3};

int G5[5][5] = {0, 1, 0, 2, 3, 
                0, 2, 3, 0, 1,
                1, 3, 0, 0, 2,
                3, 0, 2, 1, 0,
                2, 0, 1, 3, 0};

int G6[6][6] = {1, 2, 0, 3, 0, 0,
                3, 0, 1, 0, 2, 0,
                0, 0, 0, 2, 3, 1,
                0, 1, 3, 0, 0, 2,
                0, 3, 2, 1, 0, 0,
                2, 0, 0, 0, 1, 3};

int G7[7][7] = {1, 2, 3, 0, 0, 0, 0,
                3, 1, 0, 0, 0, 2, 0,
                0, 0, 1, 2, 3, 0, 0,
                0, 0, 2, 3, 0, 0, 1,
                0, 0, 0, 1, 0, 3, 2,
                0, 3, 0, 0, 2, 1, 0,
                2, 0, 0, 0, 1, 0, 3};

int G8[8][8] = {1, 2, 3, 0, 0, 0, 0, 0,
                3, 1, 2, 0, 0, 0, 0, 0,
                0, 3, 1, 0, 0, 2, 0, 0,
                0, 0, 0, 0, 2, 0, 3, 1,
                0, 0, 0, 3, 0, 0, 1, 2,
                0, 0, 0, 1, 3, 0, 2, 0,
                0, 0, 0, 2, 1, 3, 0, 0,
                2, 0, 0, 0, 0, 1, 0, 3};

int G9[9][9] = {1, 2, 3, 0, 0, 0, 0, 0, 0,
                3, 0, 1, 0, 0, 0, 0, 2, 0,
                0, 0, 0, 0, 0, 0, 2, 3, 1,
                0, 0, 0, 3, 0, 1, 0, 0, 2,
                0, 1, 0, 0, 3, 2, 0, 0, 0,
                0, 0, 0, 2, 1, 3, 0, 0, 0,
                0, 0, 2, 1, 0, 0, 3, 0, 0,
                0, 3, 0, 0, 2, 0, 1, 0, 0,
                2, 0, 0, 0, 0, 0, 0, 1, 3};

int G10[10][10] = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0,
                   3, 0, 1, 0, 0, 0, 0, 0, 2, 0,
                   0, 0, 0, 0, 0, 0, 0, 2, 3, 1,
                   0, 0, 0, 0, 3, 1, 0, 0, 0, 2,
                   0, 0, 0, 1, 2, 3, 0, 0, 0, 0,
                   0, 1, 0, 3, 0, 0, 2, 0, 0, 0,
                   0, 0, 0, 2, 1, 0, 3, 0, 0, 0,
                   0, 0, 2, 0, 0, 0, 1, 3, 0, 0,
                   0, 3, 0, 0, 0, 2, 0, 1, 0, 0,
                   2, 0, 0, 0, 0, 0, 0, 0, 1, 3};

int G[205][205];

int main() {

    std::ios::sync_with_stdio(false);

    int N;
    cin >> N;
    pair<int, int> p1(0, 0), p2(0, N - 1), p3(N - 1, 0), p4(N - 1, N - 1);
    while (!(5 <= p2.second - p1.second + 1 && p2.second - p1.second + 1 <= 10)) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                G[p1.first + i][p1.second + j] = ul[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                G[p2.first + i][p2.second - (2 - j)] = ur[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                G[p3.first - (2 - i)][p3.second + j] = dl[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                G[p4.first - (2 - i)][p4.second - (2 - j)] = dr[i][j];
            }
        }
        p1.first += 3, p1.second += 3;
        p2.first += 3, p2.second -= 3;
        p3.first -= 3, p3.second += 3;
        p4.first -= 3, p4.second -= 3;
    }
    if (p2.second - p1.second + 1 == 5) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                G[p1.first + i][p1.second + j] = G5[i][j];
            }
        }
    }
    if (p2.second - p1.second + 1 == 6) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                G[p1.first + i][p1.second + j] = G6[i][j];
            }
        }
    }
    if (p2.second - p1.second + 1 == 7) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                G[p1.first + i][p1.second + j] = G7[i][j];
            }
        }
    }
    if (p2.second - p1.second + 1 == 8) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                G[p1.first + i][p1.second + j] = G8[i][j];
            }
        }
    }
    if (p2.second - p1.second + 1 == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                G[p1.first + i][p1.second + j] = G9[i][j];
            }
        }
    }
    if (p2.second - p1.second + 1 == 10) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                G[p1.first + i][p1.second + j] = G10[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) printf(" ");
            printf("%d", G[i][j]);
        }
        printf("\n");
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 