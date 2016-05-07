// Problem#: 1940
// Submission#: 3567442
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

int in_degree[100005];
vector<int> edge[100005];

int main() {
    
    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) edge[i].clear();
        for (int i = 1; i <= n; i++) in_degree[i] = 0;
        while (m--) {
            int from, to;
            scanf("%d%d", &from, &to);
            in_degree[to]++;
            edge[from].push_back(to);
        }
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 1; i <= n; i++) if (in_degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int now = q.top();
            printf("%d ", now);
            q.pop();
            int s = edge[now].size();
            for (int i = 0; i < s; i++) {
                in_degree[edge[now][i]]--;
                if (in_degree[edge[now][i]] == 0) q.push(edge[now][i]);
            }
        }
        printf("\n");
    }
    return 0;
}                                 