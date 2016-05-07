// Problem#: 1904
// Submission#: 3590534
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;
const int MAXN = 105;

bool edge_exist[MAXN][MAXN];
bool edge_used[MAXN][MAXN][MAXN];
short edge_num[MAXN][MAXN];
vector<int> edge[MAXN];
short Medge[3005][2];
int sum[MAXN];
int N, M;
int ans;
bool connect;

int BFS(int s, bool control) {
    int counter = 1, S = 0;
    bool vis[MAXN];
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(s, 0));
    while (!q.empty()) {
        int from = q.front().first, step = q.front().second, size = edge[from].size();
        q.pop();
        for (int i = 0; i < size; i++) {
            int to = edge[from][i];
            if (edge_exist[from][to] && !vis[to]) {
                counter++;
                S += step + 1;
                q.push(make_pair(to, step + 1));
                vis[to] = true;
                if (control) edge_used[s][from][to] = edge_used[s][to][from] = true;
            }
        }
    }
    if (counter != N) return INF;
    else return S;
}

void input() {
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &Medge[i][0], &Medge[i][1]);
        if (!edge_exist[Medge[i][0]][Medge[i][1]]) {
            edge[Medge[i][0]].push_back(Medge[i][1]);
            edge[Medge[i][1]].push_back(Medge[i][0]);
        }
        edge_exist[Medge[i][0]][Medge[i][1]] = true;
        edge_exist[Medge[i][1]][Medge[i][0]] = true;
        edge_num[Medge[i][0]][Medge[i][1]]++;
        edge_num[Medge[i][1]][Medge[i][0]]++;
    }
}

void process() {
    for (int i = 1; i <= N; i++) sum[i] = INF;
    for (int i = 1; i <= N; i++) {
        sum[i] = BFS(i, true);
        if (sum[i] == INF) {
            connect = false;
            break;
        } else ans += sum[i];
    }
    if (!connect) {
        while (M--) printf("INF\n");
    } else {
        for (int i = 0; i < M; i++) {
            if (edge_num[Medge[i][0]][Medge[i][1]] > 1) printf("%d\n", ans);
            else {
                int from = Medge[i][0], to = Medge[i][1], new_ans = 0;
                edge_exist[from][to] = false;
                edge_exist[to][from] = false;
                for (int j = 1; j <= N; j++) {
                    if (edge_used[j][from][to]) {
                        int temp = BFS(j, false);
                        if (temp == INF) {
                            new_ans = INF;
                            printf("INF\n");
                            break;
                        } else {
                            new_ans += temp;
                        }
                    } else {
                        new_ans += sum[j];
                    }
                }
                if (new_ans != INF) printf("%d\n", new_ans);
                edge_exist[from][to] = true;
                edge_exist[to][from] = true;
            }
        }
    }
}

void init() {
    ans = 0;
    connect = true;
    memset(edge_exist, false, sizeof(edge_exist));
    memset(edge_num, 0, sizeof(edge_num));
    memset(edge_used, false, sizeof(edge_used));
    for (int i = 1; i <= N; i++) edge[i].clear();
}

int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
        init();
        input();
        process();
    }
    return 0;
}                                 