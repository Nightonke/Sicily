// Problem#: 2011
// Submission#: 2757112
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int fac[9] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};
int ans[362880 + 1];

int make_num(int a[]) {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum = sum * 10 + a[i];
    }
    return sum;
}

void make_permutation(int pre, int a[], int pos) {
    int i = 8;
    while (pre) {
        a[i--] = pre % 10;
        pre /= 10;
    }
    if (pos == 1) {
        int temp = a[0];
        a[0] = a[1];
        a[1] = a[4];
        a[4] = a[3];
        a[3] = temp;
        return;
    } else if (pos == 2) {
        int temp = a[1];
        a[1] = a[2];
        a[2] = a[5];
        a[5] = a[4];
        a[4] = temp;
        return;
    } else if (pos == 3) {
        int temp = a[3];
        a[3] = a[4];
        a[4] = a[7];
        a[7] = a[6];
        a[6] = temp;
        return;
    } else {
        int temp = a[4];
        a[4] = a[5];
        a[5] = a[8];
        a[8] = a[7];
        a[7] = temp;
        return;
    }
}

int cantor(int a[]) {
    int pos = 0;
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = i + 1; j < 9; j++) {
            if (a[i] > a[j])
                count++;
        }
        pos += count * fac[i];
    }
    return pos;
}

void bfs() {
    
    queue<int> Q;
    Q.push(123456789);
    ans[0] = 0;
    int step = 0;
    
    while (!Q.empty()) {
        
        step++;
        int now_size = Q.size();
        
        while (now_size--) {
            for (int i = 1; i <= 4; i++) {
                int next[9];
                make_permutation(Q.front(), next, i);
                int pos = cantor(next);
                if (ans[pos] == 0) {
                    ans[pos] = step;
                    Q.push(make_num(next));
                }
            }
            Q.pop();
        }
    }
    ans[0] = 0;
}
    
int main() {
    //std::ios::sync_with_stdio(false);
    bfs();
    int sum[9];
    while(~scanf("%d", &sum[0])) {
        for (int i = 1; i < 9; i++) {
            scanf("%d", &sum[i]);
        }
        printf("%d\n", ans[cantor(sum)]);
    }
    return 0;
}                                 