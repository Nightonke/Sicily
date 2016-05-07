// Problem#: 1006
// Submission#: 2736821
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//next_permutation()全排列的下一个
//prev_permutation()全排列的前一个，括号中都为数组的起始结束位置的指针

int main() {
    
    int n, len, i, j, k, min, difference, pos[100];
    string ranking[105], ans;
    char possible[100];
    
    while (cin >> n && n) {
        
        for (i = 0; i < n; i++) {
            cin >> ranking[i];//注意这里的ranking是二维数组
        }
        
        len = ranking[0].length();//计算出长度以构建最开始的possible数组
        
        for (i = 0; i < len; i++) {
            possible[i] = 'A' + i;//构建
        }
        
        min = 999999;
        
        while (1) {
            
            for (i = 0; i < len; i++) {
                pos[possible[i] - 'A'] = i;//这里的pos是用来记录possible的位置，比如B的位置是第一位就是pos[1] = 0，C的位置是最后一位就是pos[2] = 4
            }
            
            for (i = 0, difference = 0; i < n; i++) {
                for (j = 0; j < len; j++) {
                    for (k = j + 1; k < len; k++) {
                        
                        if (pos[ranking[i][j] - 'A'] > pos[ranking[i][k] - 'A']) {
                            difference++;//在ranking中由于j总比k小，即ranking[i][j] - 'A'总在ranking[i][k] - 'A'前，若在pos对应中是后（也就是大于），则说明位置不同
                        }
                        
                    }
                }
            }
            
            if (difference < min) {
                min = difference;
                ans = possible;//更新
            }
            
            if (!next_permutation(possible, possible + len)) {
                break;//全排列排完了
            }
            
        }
        
        cout << ans <<  " is the median ranking with value " << min << "." << endl;
    }
    return 0;
}                                 