// Problem#: 1305
// Submission#: 2777051
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

long long power2[33], power3[22], power5[15], power7[13];

void make_power() {
    int i;
    for (power2[0] = 1, i = 1; i < 33; power2[i] = 2 * power2[i - 1], i++);
    for (power3[0] = 1, i = 1; i < 22; power3[i] = 3 * power3[i - 1], i++);
    for (power5[0] = 1, i = 1; i < 15; power5[i] = 5 * power5[i - 1], i++);
    for (power7[0] = 1, i = 1; i < 13; power7[i] = 7 * power7[i - 1], i++);
}

bool a[34][23][16][14];  //判断输赢

//下面的循环是设立一个待定者，这个待定者在大于等于target的时候是输的，那么由此推出只要在使得数字大于等于target的上一步就是赢的，然后由此往前推，推到第一个位置

int main() {
    
    make_power();
    
    long long target;
    while (~scanf("%lld", &target)) {
        
        if (target == 1) {
            printf("Nic wins.\n");
            continue;
        }
        
        memset(a, false, sizeof(a));
        
        int p2, p3, p5, p7;
        for (p2 = 32; p2 >= 0; p2--) {
            for (p3 = 21; p3 >= 0; p3--) {
                for (p5 = 14; p5 >= 0; p5--) {
                    for (p7 = 12; p7 >= 0; p7--) {
                        
                        if (power2[p2] * power3[p3] * power5[p5] * power7[p7] < target) {
                            
                            if (p2 < 32 && a[p2 + 1][p3][p5][p7] == false) { //乘2之后是输的，那么这一步就是赢的
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p3 < 21 && a[p2][p3 + 1][p5][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p2 < 31 && a[p2 + 2][p3][p5][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p5 < 14 && a[p2][p3][p5 + 1][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p2 < 32 && p3 < 21 && a[p2 + 1][p3 + 1][p5][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p7 < 12 && a[p2][p3][p5][p7 + 1] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p2 < 30 && a[p2 + 3][p3][p5][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                            
                            if (p3 < 20 && a[p2][p3 + 2][p5][p7] == false) {
                                a[p2][p3][p5][p7] = true;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        
        if (a[0][0][0][0]) {
            printf("Nic wins.\n");
        } else {
            printf("Susan wins.\n");
        }
    }
    return 0;
}                                 