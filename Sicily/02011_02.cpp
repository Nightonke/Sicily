// Problem#: 2011
// Submission#: 2757898
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

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

void bfs() {
    
    queue<int> Q;
    Q.push(123456789);
    int step = 0;
    int i, next[9];
    int pos;
    int now_size;
    
    while (!Q.empty()) {
        
        step++;//每次更新都是要走多一步的
        now_size = Q.size();//记录当前的size，然后走完它（又会生成新的size）
        
        while (now_size--) {
            for (i = 1; i <= 4; i++) {//遍历四种转化
                make_permutation(Q.front(), next, i);
                pos = cantor(next);//通过康托获取位置   
                if (ans[pos] == 0) {//如果为0就是没有用过
                    ans[pos] = step;
                    Q.push(make_num(next));
                }
            }
            Q.pop();//队首已经用过了
        }
    }
    ans[0] = 0;
}
    
int main() {
    bfs();
    int sum[20];
    while(~scanf("%d", &sum[0])) {
        for (int i = 1; i <= 8; i++) {
            scanf("%d", &sum[i]);
        }
        printf("%d\n", ans[cantor(sum)]);
    }
    return 0;
}                                 