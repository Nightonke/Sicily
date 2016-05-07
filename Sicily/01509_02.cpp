// Problem#: 1509
// Submission#: 2763325
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int after[1005], n;
    while (scanf("%d", &n) && n) {
        while (scanf("%d", &after[0]) && after[0]) {
            stack<int> s;
            for (int i = 1; i < n; i++) {
                scanf("%d", &after[i]);
            }
            for (int i = 0, j = 1; i < n; i++) {
            
                while ((s.empty() || after[i] != s.top()) && j <= n) {
                    s.push(j++);
                }
            
                if (after[i] == s.top())
                    s.pop();
            }
            if (s.empty()) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}                                 