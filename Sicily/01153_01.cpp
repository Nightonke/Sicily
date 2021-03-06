// Problem#: 1153
// Submission#: 2798428
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1153
// Submission#: 2797996
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

bool is_ok;
int mapp[8][8];
bool vis[8][8];
int ans[65];
int dir[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};

void make_map() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mapp[i][j] = i * 8 + j + 1;
        }
    }
}

bool is_valid(int i, int j) {
    if (i < 0 || j < 0 || i > 7 || j > 7 || vis[i][j]) {
        return false;
    }
    return true;
}

int cal_roads(int ii, int jj) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        int next_i = ii + dir[i][0];
        int next_j = jj + dir[i][1];
        if (is_valid(next_i, next_j)) {
            counter++;
        }
    }
    return counter;
}

struct choose {
    int ii;
    int jj;
    int roads;
    choose() {}
    choose(int i, int j) {
        ii = i;
        jj = j;
        roads = cal_roads(i, j);
    }
};

bool cmp(choose a, choose b) {
    return a.roads < b.roads;
}

void DFS(int from_i, int from_j, int num) {
    
    vector<choose> cho;
    for (int i = 0; i < 8; i++) {
        int next_i = from_i + dir[i][0];
        int next_j = from_j + dir[i][1];
        if (is_valid(next_i, next_j)) {
            cho.push_back(choose(next_i, next_j));
        }
    }
    if (cho.empty())
        return;
    sort(cho.begin(), cho.end(), cmp);
    
    if (num == 63) {
        ans[num] = mapp[cho[0].ii][cho[0].jj];
        is_ok = true;
        return;
    }
    
    for (int i = 0; i < (int)cho.size(); i++) {
        vis[cho[i].ii][cho[i].jj] = true;
        DFS(cho[i].ii, cho[i].jj, num + 1);
        if (is_ok) {
            ans[num] = mapp[cho[i].ii][cho[i].jj];
            return;
        } else {
            vis[cho[i].ii][cho[i].jj] = false;
        }
    }
}

int main() {
    
    int sp;
    make_map();
    
    while (scanf("%d", &sp) && sp != -1) {
        memset(vis, false, sizeof(vis));
        vis[(sp - 1) / 8][(sp - 1) % 8] = true;
        memset(ans, 0, sizeof(ans));
        ans[0] = sp;
        is_ok = false;
        DFS((sp - 1) / 8, (sp - 1) % 8, 1);
        
        for (int i = 0; i < 64; i++) {
            if (i != 0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
        
    return 0;
}                                 