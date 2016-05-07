// Problem#: 1015
// Submission#: 3176449
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

#define INF 999999

struct road {
    int sum;
    vector<int> r;
    bool used[25];
    void init() {
        sum = 0;
        for (int i = 0; i < 25; i++) used[i] = false;
    }
};

int G[25][25];
int n;
int start, endp, Max;
vector<road> ans;

void BFS() {
    ans.clear();
    queue<road> q;
    road temp;
    temp.init();
    temp.r.push_back(start);
    temp.used[start] = true;
    q.push(temp);

    while (!q.empty()) {

        road temp = q.front();
        q.pop();

        if (temp.r[temp.r.size() - 1] == endp && temp.sum <= Max) {
            ans.push_back(temp);
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (G[temp.r[temp.r.size() - 1]][i] != INF && !temp.used[i]) {
                road newtemp = temp;
                newtemp.sum += G[temp.r[temp.r.size() - 1]][i];
                newtemp.r.push_back(i);
                newtemp.used[i] = true;
                if (newtemp.sum <= Max) q.push(newtemp);
            }
        }

    }
}

bool cmp(const road & r1, const road & r2) {
    if (r1.sum != r2.sum) return r1.sum < r2.sum;
    else return r1.r < r2.r;
}

int main() {

    std::ios::sync_with_stdio(false);
    
    int counter = 1;
    while (1) {
        cin >> n;
        if (n == -1) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = INF;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            G[s][e] = G[e][s] = c;
        }
        cin >> start >> endp >> Max;
        BFS();
        sort(ans.begin(), ans.end(), cmp);

        if (counter != 1) cout << endl;

        cout << "Case " << counter << ":" << endl;
        counter++;
        if (ans.size() == 0) {
            cout << " NO ACCEPTABLE TOURS" << endl;
        } else {
            for (int i = 0; i < ans.size(); i++) {
                cout << " " << ans[i].sum << ":";
                for (int j = 0; j < ans[i].r.size(); j++) {
                    cout << " " << ans[i].r[j];
                }
                cout << endl;
            }
        }

    }


    //getchar();
    //getchar();
    
    return 0;
}                                 