// Problem#: 2011
// Submission#: 2758192
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int target;
int fac[9] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};//阶乘的值，用来康托的
int ans[362880 + 1];//存放答案

int make_num(int a[]) {//将数字数组转化为数字
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum = sum * 10 + a[i];
    }
    return sum;
}

void make_permutation(int pre, int a[], int pos) {//读入一个数字，然后返回下一变化的数组
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

int cantor(int a[]) {//康托
    int pos = 0, count, i, j;
    for (i = 0; i < 8; i++) {
        count = 0;
        for (j = i + 1; j < 9; j++) {
            if (a[i] > a[j])
                count++;
        }
        pos += count * fac[i];
    }
    return pos;
}

bool print(int step) {
    int pos, sum[9];
    printf("%d\n", step);
    while (~scanf("%d", &sum[0])) {
        for (int i = 1; i < 9; i++) {
            scanf("%d", &sum[i]);
        }
        target = make_num(sum);
        pos = cantor(sum);
        if (ans[pos] == 0 && pos != 0)
            return true;
        if (ans[pos] != 0 || pos == 0) {
            printf("%d\n", ans[pos]);
        }
    }
    return false;
}

void bfs() {
    
    queue<int> Q;
    Q.push(123456789);
    int step = 0;
    int i, next[9];
    int pos;
    int now_size;
    int new_num;
    int sum[9];
    ans[0] = 0;
    
    while (1) {
        if (scanf("%d", &sum[0]) == EOF)
            return;
        for (i = 1; i < 9; i++) {
            scanf("%d", &sum[i]);
        }
        target = make_num(sum);
        if (target == 123456789) {
            printf("0\n");
        } else {
            break;
        }
    }
    
    while (!Q.empty()) {
        
        step++;//每次更新都是要走多一步的
        now_size = Q.size();//记录当前的size，然后走完它（又会生成新的size）
        
        while (now_size--) {
            for (i = 1; i <= 4; i++) {//遍历四种转化
                make_permutation(Q.front(), next, i);
                new_num = make_num(next);
                pos = cantor(next);//通过康托获取位置   
                if (ans[pos] == 0 && pos != 0) {//如果为0就是没有用过
                    ans[pos] = step;
                    Q.push(new_num);
                    if (target == new_num) {
                        if (!print(ans[pos])) {
                            return;
                        }
                    }
                }
            }
            Q.pop();//队首已经用过了
        }
    }
}
    
int main() {
    bfs();
    return 0;
}                                 