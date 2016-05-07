// Problem#: 1018
// Submission#: 2796097
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#define MAX 5 * 4 * 3 * 2 * 1
using namespace std;

int data[5][2];
int to_check[5][2];
int permutation[MAX][5];

int card_min(int a, int b) {
    if (to_check[a][0] != to_check[b][0]) {
        return to_check[a][0] < to_check[b][0] ? a : b;
    } else {
        return to_check[a][1] < to_check[b][1] ? a : b;
    }
}
    

void make_permutation() {
    int temp[5];
    int j = 1;
    for (int i = 0; i < 5; i++) {
        permutation[0][i] = i;
        temp[i] = i;
    }
    while (next_permutation(temp, temp + 5)) {
        for (int i = 0; i < 5; i++) {
            permutation[j][i] = temp[i];
        }
        j++;
    }
}

void input() {
    char temp[5];
    for (int i = 0; i < 5; i++) {
        scanf("%s", &temp);
        if (temp[0] == '1' && temp[1] == '0') {
            data[i][0] = 9;
            data[i][1] = temp[2];
        } else if (temp[0] == 'A') {
            data[i][0] = 0;
            data[i][1] = temp[1];
        } else if (temp[0] == 'J') {
            data[i][0] = 10;
            data[i][1] = temp[1];
        } else if (temp[0] == 'Q') {
            data[i][0] = 11;
            data[i][1] = temp[1];
        } else if (temp[0] == 'K') {
            data[i][0] = 12;
            data[i][1] = temp[1];
        } else {
            data[i][0] = temp[0] - '1';
            data[i][1] = temp[1];
        }
    }
}

bool check() {
    if (to_check[1][1] != to_check[0][1])
        return false;
    int temp = to_check[1][0];
    int smallest = card_min(card_min(2, 3), 4);
    to_check[1][0] = (to_check[1][0] + smallest - 1) % 13;
    int before = -1, after = -1;
    for (int i = 2; i < 5; i++) {
        if (i != smallest && before == -1) {
            before = i;
            continue;
        }
        if (i != smallest && after == -1) {
            after = i;
        }
    }
    if (card_min(before, after) != before) {
        to_check[1][0] = (to_check[1][0] + 3) % 13;
    }
    if (to_check[0][0] == to_check[1][0] && to_check[0][1] == to_check[1][1]) {
        to_check[1][0] = temp;
        return true;
    }
    else
        return false;
}

void output(int k) {
    printf("Problem %d:", k);
    for (int i = 0; i < 5; i++) {
        if (to_check[i][0] == 0) {
            printf(" A");
        } else if (to_check[i][0] == 10) {
            printf(" J");
        } else if (to_check[i][0] == 11) {
            printf(" Q");
        } else if (to_check[i][0] == 12) {
            printf(" K");
        } else {
            printf(" %d", to_check[i][0] + 1);
        }
        printf("%c", to_check[i][1]);
    }
    printf("\n");
}
    

int main() {
    int case_num;
    make_permutation();
    scanf("%d", &case_num);
    for (int k = 1; k <= case_num; k++) {
        bool is_ok = false;
        input();
        for (int i = 0; i < MAX && !is_ok; i++) {
            for (int j = 0; j < 5; j++) {
                to_check[j][0] = data[permutation[i][j]][0];
                to_check[j][1] = data[permutation[i][j]][1];
            }
            is_ok = check();
        }
        output(k);
    }
    return 0;
}                                 