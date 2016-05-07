// Problem#: 1006
// Submission#: 2736776
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//注意为了比较方便我将ABCDE转化为12345

int num[105][6];//用来储存题目中给定的字符串

struct EVERY {
    bool a[6][6];//在a[i][j]中，如果i在j的前面，就是true，否则为false
    int d, b[6];//d为相差值，b为字符串顺序
}p[125];//最多有5 * 4 * 3 * 2 * 1种可能

bool judge(int i1, int i2, int i3, int i4, int i5) {//用来判断构建120种可能的时候是否出现了重复
    
    bool i[6];
    memset(i, false, sizeof(i));
    
    i[i1] = true;
    i[i2] = true;
    i[i3] = true;
    i[i4] = true;
    i[i5] = true;
    
    for (int j = 1; j <= 5; j++) {
        if (!i[j])
            return false;//假如重复必然有12345中的一个或多个数字没有用上
    }
    return true;
}

void ready_b(int k) {
    for (int i = 1; i <= 5; i++) {
        for (int j = i + 1; j <= 5; j++) {//在这里这种循环可以保证i必然在j的前面
            p[k].a[p[k].b[i]][p[k].b[j]] = true;//那么i在j的前面自然就是true（true表i在j前面）
        }
    }
}

void ready() {//构建120种可能
    
    int k = 0;
    int i[6];
    
    for (i[1] = 1; i[1] <= 5; i[1]++) {
        
        for (i[2] = 1; i[2] <= 5; i[2]++) {
            
            for (i[3] = 1; i[3] <= 5 && i[1] != i[2]; i[3]++) {
                
                for (i[4] = 1; i[4] <= 5 && i[2] != i[3]; i[4]++) {
                    
                    for (i[5] = 1; i[5] <= 5 && i[3] != i[4]; i[5]++) {//在这里的i[3] != i[4]主要是为了提高效率，有重复的直接不循环
                        
                        if (judge(i[1], i[2], i[3], i[4], i[5])) {
                            
                            for (int i6 = 1; i6 <= 5; i6++) {
                                p[k].b[i6] = i[i6];//构建120种可能的排列
                            }
                            
                            p[k].d = 0;//刚开始的差值为零
                            ready_b(k);
                            k++;//下一个
                        }
                    }
                }
            }
        }
    }
}

int main() {
    
    ready();
    int n, i, k, j, k1, k2, min, flag;
    char temp[6];
    bool num_a[6][6];//num_a用来像p.a一样存储题目中给的字符串的位置关系，进行判断
    
    while (cin >> n && n) {
        
        for (i = 0, k = 0; i < n; i++) {
            cin >> temp;
            for (j = 0; j < 5; j++) {
                num[k][j + 1] = temp[j] - 'A' + 1;//转化为12345储存
            }
            k++;
        }
        
        for (i = 0; i < n; i++) {//每次拿出一个字符串，跟120种可能比较出差值
            memset(num_a, false, sizeof(num_a));//初始化
            for (k1 = 1; k1 <= 5; k1++) {
                for (k2 = k1 + 1; k2 <= 5; k2++) {
                    num_a[num[i][k1]][num[i][k2]] = true;//k1必然在k2的前面，构建当前字符串的位置关系
                }
            }
            
            for (j = 0; j < 120; j++) {//
                for (k1 = 1; k1 <= 5; k1++) {
                    for (k2 = k1 + 1; k2 <= 5; k2++) {//注意这里k2=k1 + 1是保证不重复，因为12只用比较一次，12true就是21false
                        if ((p[j].a[k1][k2] == false &&  num_a[k1][k2] == true) || (p[j].a[k1][k2] == true &&  num_a[k1][k2] == false)) {//两者不同，差值加一
                            p[j].d++;
                        }
                    }
                }
            }
        }
        
        for (i = 0, min = 9999999; i < 120; i++) {
            if (min > p[i].d) {
                flag = i;
                min = p[i].d;//找出差值最小的
            }
        }
        
        for (char temp1, i = 1; i <= 5; i++) {
            temp1 = 'A' + p[flag].b[i] - 1;
            cout << temp1;//转化为字符串输出
        }
        
        cout << " is the median ranking with value " << min << "." << endl;
        
        for (i = 0; i < 120; i++) {
            p[i].d = 0;//注意将120种可能的差值初始化
        }
    }
    return 0;
}                                 