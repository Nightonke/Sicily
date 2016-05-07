// Problem#: 1090
// Submission#: 2778939
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
#define INF 99999
#define MAX 500
int n, roads[MAX][MAX], ans_max;
void Prim() {
    bool used[n];
    fill(used, used + n, 0);
    int mincost[n];
    fill(mincost, mincost + n, INF);
    ans_max = mincost[0] = 0;
    int min_pos;
    while (1) {
        min_pos = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && (min_pos == -1 || mincost[min_pos] > mincost[i])) {
                min_pos = i;
            }
        }
        if (min_pos == -1) {
            break;
        }
        used[min_pos] = true;
        ans_max = ans_max > mincost[min_pos] ? ans_max : mincost[min_pos];
        for (int i = 0; i < n; i++) {
            mincost[i] = mincost[i] < roads[min_pos][i] ? mincost[i] : roads[min_pos][i];
        }
    }
}

int main() {
    std :: ios :: sync_with_stdio(false);
    int case_num;
    bool control_blank = false;
    cin >> case_num;
    while (case_num--) {
        if (control_blank)cout << endl;
        control_blank = true;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> roads[i][j];
        
        Prim();
        cout << ans_max << endl;
    }
    return 0;
}                                 