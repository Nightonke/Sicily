// Problem#: 12259
// Submission#: 3549794
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

short edge[1005];
bool vis[1005];
int N;

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &edge[i]);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(vis, false, sizeof(vis));
        int now = i;
        int isOK = true;
        while (now) {
            if (vis[now] == true) {
                isOK = false;
                break;
            }
            vis[now] = true;
            now = edge[now];
        }
        ans += isOK;
    }
    printf("%d\n", ans);

    return 0;
}                                 