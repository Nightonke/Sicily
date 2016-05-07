// Problem#: 1932
// Submission#: 2759691
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stack>
using namespace std;

int c[200005];

int main() {
    int n, i, t1, t2, case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &t1, &t2);
            c[t1] = t2;
            c[t2] = t1;
        }
        stack<int> cc;
        for (i = 1; i <= 2 * n; i++) {
            if (cc.empty()) {
                cc.push(c[i]);
            } else {
                if (i ^ cc.top()) {
                    cc.push(c[i]);
                } else {
                    cc.pop();
                }
            }
        }
        if (cc.empty()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
        
    return 0;
}                                 