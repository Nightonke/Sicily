// Problem#: 1090
// Submission#: 2778931
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
using namespace std;
#define INF 99999999
#define MAX 500

int n, roads[MAX][MAX], ans_max, sum;

typedef pair<int, int> p;

void Prim() {
    ans_max = -INF;
    sum = 0;
    int mincost[n];
    bool used[n];
    fill(used, used + n, false);
    fill(mincost, mincost + n, INF);
    mincost[0] = 0;
    used[0] = true;
    priority_queue<p, vector<p>, greater<p> > q;
    q.push(p(0, 0));
    p top;
    int counter_used = 1;
    while (!q.empty()) {
        top = q.top();
        q.pop();
        
        if (top.first > mincost[top.second])
            continue;
        
        used[top.second] = true;
        
        ans_max = ans_max > mincost[top.second] ? ans_max : mincost[top.second];
        sum += mincost[top.second];
        counter_used++;
        //if (counter_used == n)
        //    return;
        
        for (int i = 0; i < n; i++) {
            if (mincost[i] > roads[top.second][i]) {
                mincost[i] = roads[top.second][i];
                if (!used[i]) {
                    q.push(p(mincost[i], i));
                }
            }
            
        }
        /*
        cout << "step " << counter++ << ": " << endl;
        cout << "the min_pos is " << top.second << endl;
        cout << "the renewed mincost is " << ": " << endl;
        for (int i = 0; i < n; i++) {
            cout << "mincost[ " << i << " ]" << " = " << mincost[i] << ";" << endl;
        }
        cout << "the point has not been used is :  ";
        for (int i = 0; i < n; i++) {
            if (!used[i])
                cout << i << " ";
        }
        cout << endl;
        cout << "now sum = " << sum << endl;
        cout << "now ans_max = " << ans_max;
        cout << endl;
        cout << endl;
        */
        
        
    }
        
        
}

int main() {
    
    std :: ios :: sync_with_stdio(false);
    
    int case_num;
    bool control_blank = false;
    cin >> case_num;
    while (case_num--) {
        if (control_blank) {
            cout << endl;
        }
        control_blank = true;
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> roads[i][j];
            }
        }
        
        Prim();
        //cout << sum << endl;
        cout << ans_max << endl;
    }
    return 0;
}                                 