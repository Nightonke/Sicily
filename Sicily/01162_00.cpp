// Problem#: 1162
// Submission#: 2741397
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

//数独题，深搜，这是剪枝的

char ans[10][10];//用来储存最终答案
bool num_in_row[10][10], num_in_col[10][10], num_in_blo[10][10];//这里的数组[i][j]表示在第i行/列/块里面已经有了j这个数字（有的时候为true）
bool is_ok;//是否找到了答案
int blank_num;

struct Blank {
    int pos_row, pos_col, pos_blo, possibility;
}blank[85];

int find_block(int x, int y) {//返回属于的块编号
    
    int block[10][10] = 
    {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9
    };
    
    return block[x][y];
}

void dfs(int blank_now) {//blank_now指当前要填的空的编号
    
    if (is_ok == true)//找到答案了就返回
        return;
    if (blank_now == blank_num) {//如果blank_now超过了总的空白数，也就是说空白都填完了那就返回
        is_ok = true;
        return;
    }
    
    for (int possible = 1; possible <= 9; possible++) {//在一个空上有9种可能
        
        if (!num_in_row[blank[blank_now].pos_row][possible] && !num_in_col[blank[blank_now].pos_col][possible] && !num_in_blo[blank[blank_now].pos_blo][possible]) {
                
            ans[blank[blank_now].pos_row][blank[blank_now].pos_col] = possible + '0';//先填入答案中，就算不对，后来填的也可以覆盖
            
            num_in_row[blank[blank_now].pos_row][possible] = true;//并更新这个空白的限制信息
            num_in_col[blank[blank_now].pos_col][possible] = true;
            num_in_blo[blank[blank_now].pos_blo][possible] = true;
                
            dfs(blank_now + 1);//深搜
            
            if (is_ok)//找到答案直接返回完事
                return;
                
            num_in_row[blank[blank_now].pos_row][possible] = false;//程序运行到这说明前面的假设没找到答案，因此还原这个空白的限制信息
            num_in_col[blank[blank_now].pos_col][possible] = false;
            num_in_blo[blank[blank_now].pos_blo][possible] = false;
        }
    }
}

void set_blank(int k, int i, int j) {
    
    blank[k].possibility = 0;
    blank[k].pos_row = i;
    blank[k].pos_col = j;
    blank[k].pos_blo = find_block(i, j);
}

void calculate(int k) {
    for (int temp = 1; temp <= 9; temp++) {
        if (!num_in_row[blank[k].pos_row][temp] && !num_in_col[blank[k].pos_col][temp] && !num_in_blo[blank[k].pos_blo][temp]) {
            blank[k].possibility++;
        }
    }
}

bool cmp(const Blank &a, const Blank &b) {
    return a.possibility < b.possibility;
}

int main() {
    
    int case_num, i, j;
    scanf("%d", &case_num);
    
    while (case_num--) {
        
        blank_num = 0;
        is_ok = false;
        memset(num_in_row, false, sizeof(num_in_row));
        memset(num_in_col, false, sizeof(num_in_col));
        memset(num_in_blo, false, sizeof(num_in_blo));
        
        for (i = 1; i <= 9; i++) {
            scanf("%s", ans[i] + 1);
        }
        
        for (i = 1; i <= 9; i++) {
            for (j = 1; j <= 9; j++) {
                if (ans[i][j] != '0') {//不是空白就更新限制信息
                    
                    num_in_row[i][ans[i][j] - '0'] = true;//更新限制信息
                    num_in_col[j][ans[i][j] - '0'] = true;
                    num_in_blo[find_block(i, j)][ans[i][j] - '0'] = true;
                    
                } else {
                    
                    set_blank(blank_num, i, j);
                    blank_num++;
                
                }
            }
        }
        
        for (i = 0; i < blank_num; i++) {
            calculate(i);
        }
        
        sort(blank, blank + blank_num, cmp);
        
        dfs(0);
        
        for (i = 1; i <= 9; i++) {
            for (j = 1; j <= 9; j++) {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
        
    }
        
    return 0;
}                                 