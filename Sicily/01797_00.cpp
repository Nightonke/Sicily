// Problem#: 1797
// Submission#: 2807579
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string>
using namespace std;

int x, y;
int dir;
int ans_x[1000][1000], ans_y[1000][1000];
bool ans_here[1000][1000];

int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
       r=a%b;
       a=b;
       b=r;
    }
    return a;
}

void gogogo(int a, int b) {
    if (a > 0 && b > 0) {
        if (dir == 0) {
            y++;
        } else if (dir == 1) {
            x++;
        } else if (dir == 2) {
            y--;
        } else {
            x--;
        }
    } else {
        return;
    }
    gogogo(a - b, b);
    dir = (dir + 1) % 4;
    gogogo(b - a, a);
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int a, b;
        x = y = dir = 0;
        scanf("%d%d", &a, &b);
        if (a == 0 || b == 0) {
            printf("0 0\n");
            continue;
        }
        int temp = gcd(a, b);
        a /= temp;
        b /= temp;
        if (a < 1000 && b < 1000 && ans_here[a][b]) {
            printf("%d %d\n", ans_x[a][b], ans_y[a][b]);
            continue;
        }
        gogogo(a, b);
        if (a < 1000 && b < 1000 && !ans_here[a][b]) {
            ans_x[a][b] = x;
            ans_y[a][b] = y;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}                                 