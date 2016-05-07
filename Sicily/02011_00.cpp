// Problem#: 2011
// Submission#: 2758261
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
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
int i_per, temp_per;

int make_num(int a[]) {//将数字数组转化为数字
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum = sum * 10 + a[i];
    }
    return sum;
}

void make_permutation_1(int pre, int a[]) {
    i_per = 8;
    while (pre) {
        a[i_per--] = pre % 10;
        pre /= 10;
    }
    temp_per = a[0];
    a[0] = a[1];
    a[1] = a[4];
    a[4] = a[3];
    a[3] = temp_per;
    return;
}

void make_permutation_2(int pre, int a[]) {
    i_per = 8;
    while (pre) {
        a[i_per--] = pre % 10;
        pre /= 10;
    }
    temp_per = a[1];
    a[1] = a[2];
    a[2] = a[5];
    a[5] = a[4];
    a[4] = temp_per;
    return;
}

void make_permutation_3(int pre, int a[]) {
    i_per = 8;
    while (pre) {
        a[i_per--] = pre % 10;
        pre /= 10;
    }
    temp_per = a[3];
    a[3] = a[4];
    a[4] = a[7];
    a[7] = a[6];
    a[6] = temp_per;
    return;
}

void make_permutation_4(int pre, int a[]) {
    i_per = 8;
    while (pre) {
        a[i_per--] = pre % 10;
        pre /= 10;
    }
    temp_per = a[4];
    a[4] = a[5];
    a[5] = a[8];
    a[8] = a[7];
    a[7] = temp_per;
    return;
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
    int next[9];
    int pos;
    int now_size;
    
    while (!Q.empty()) {
        
        step++;//每次更新都是要走多一步的
        now_size = Q.size();//记录当前的size，然后走完它（又会生成新的size）
        
        while (now_size--) {
            
            make_permutation_1(Q.front(), next);
            pos = cantor(next);//通过康托获取位置   
            if (ans[pos] == 0) {//如果为0就是没有用过
                ans[pos] = step;
                Q.push(make_num(next));
            }
            
            make_permutation_2(Q.front(), next);
            pos = cantor(next);//通过康托获取位置   
            if (ans[pos] == 0) {//如果为0就是没有用过
                ans[pos] = step;
                Q.push(make_num(next));
            }
                
            make_permutation_3(Q.front(), next);
            pos = cantor(next);//通过康托获取位置   
            if (ans[pos] == 0) {//如果为0就是没有用过
                ans[pos] = step;
                Q.push(make_num(next));
            }
            
            make_permutation_4(Q.front(), next);
            pos = cantor(next);//通过康托获取位置   
            if (ans[pos] == 0) {//如果为0就是没有用过
                ans[pos] = step;
                Q.push(make_num(next));
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