// Problem#: 1150
// Submission#: 2799113
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char b[8];
char target[8];
char step[11];
int max_step;
bool is_ok;

bool can_do(int i, int num) {
    if (i == 1) {
        if (step[num - 1] == 'A') {
            return false;
        } else {
            return true;
        }
    } else if (i == 2) {
        if (num >= 3 && step[num - 1] == 'B' && step[num - 2] == 'B' && step[num - 3] == 'B') {
            return false;
        } else {
            return true;
        }
    } else {
        if (num >= 3 && step[num - 1] == 'C' && step[num - 2] == 'C' && step[num - 3] == 'C') {
            return false;
        } else {
            return true;
        }
    }
}

void do_i(int i) {
    if (i == 1) {
        for (int j = 0; j < 4; j++) {
            swap(b[j], b[j + 4]);
        }
    } else if (i == 2) {
        int temp1 = b[3];
        int temp2 = b[7];
        for (int j = 3; j >= 1; j--) {
            b[j] = b[j - 1];
            b[j + 4] = b[j + 3];
        }
        b[0] = temp1;
        b[4] = temp2;
    } else {
        swap(b[1], b[5]);
        swap(b[5], b[6]);
        swap(b[2], b[6]);
    }
}

bool is_same() {
    for (int i = 0; i < 8; i++) {
        if (b[i] != target[i])
            return false;
    }
    return true;
}

void DFS(int num) {
    if (is_same()) {
        is_ok = true;
        step[num] = '\0';
        return;
    }
    if (num >= max_step) {
        return;
    }
    char temp[8];
    for (int i = 0; i < 8; i++) {
        temp[i] = b[i];
    }
    for (int i = 1; i <= 3; i++) {
        if (can_do(i, num)) {
            do_i(i);
            step[num] = i - 1 + 'A';
            DFS(num + 1);
        }
        if (is_ok) {
            return;
        } else {
            for (int i = 0; i < 8; i++) {
                b[i] = temp[i];
            }
        }
    }
}

int main() {
    while (scanf("%d", &max_step) && max_step != -1) {
        scanf("\n");
        char temp[10];
        for (int i = 1; i < 5; i++) {
            b[i - 1] = i + '0';
            b[8 - i] = i + '4';
        }
        is_ok = false;
        gets(temp);
        for (int i = 0; i <= 6; i += 2) {
            target[i / 2] = temp[i];
        }
        gets(temp);
        for (int i = 0; i <= 6; i += 2) {
            target[i / 2 + 4] = temp[i];
        }
        DFS(0);
        if (is_ok)
            printf("%d %s\n", (int)strlen(step), step);
        else
            printf("-1\n");
    }
    return 0;
}                                 