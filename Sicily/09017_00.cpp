// Problem#: 9017
// Submission#: 2750923
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 9017
// Submission#: 2749144
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

#define INF 100000000
int w, h;//宽高
int map[65][65], exit_i, exit_j;//构建图形以及终点的ij坐标
int dist[65][65];//图形中各个点离起点的距离
int to_i[4] = {0, 2, 0, -2};//移动方向
int to_j[4] = {2, 0, -2, 0};

typedef pair<int, int> P;//记录点移动

void make_map(int w, int h) {//构建地图
    int i, j;
    memset(map, 0, sizeof(map));
    
    for (i = 0; i <= 2 * h; i++) {
        if (i == 0 || i == 2 * h) {//上下边界
            for (j = 0; j <= 2 * w; j++) {
                map[i][j] = 1;
            }
        } else {
            map[i][0] = map[i][2 * w] = 1;//左右边界
        }
    }
    
    map[0][1] = map[2 * h][2 * w - 1] = 0;//开口，注意这个不要也行，起点不是这个
    
    for (i = 1; i <= 2 * h - 1; i++) {
        if (i % 2 == 1) {//奇数行为实际格子
            for (j = 0; j < w - 1; j++) {
                scanf("%d", &map[i][2 * j + 2]);
            }
        } else {//偶数行为墙壁
            for (j = 0; j < w; j++) {
                scanf("%d", &map[i][2 * j + 1]);
            }
        }
    }
    
    /*for (i = 2; i < 2 * h; i += 2) {
        for (j = 1; j < 2 * w; j++) {
            if (map[i - 1][j] == 1 && map[i + 1][j] == 1)
                map[i][j] = 1;
            if (map[i][j - 1] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
        }
    }
    for (i = 2; i < 2 * h; i += 2) {
        for (j = 1; j < 2 * w; j++) {
            if (map[i - 1][j] == 1 && map[i][j - 1] == 1)
                map[i][j] = 1;
            if (map[i + 1][j] == 1 && map[i][j - 1] == 1)
                map[i][j] = 1;
            if (map[i - 1][j] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
            if (map[i + 1][j] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
        }
    }
    */
    exit_i = 2 * h - 1;//终点坐标，将出口的前一个点设为终点，最少步数要加一
    exit_j = 2 * w - 1;
}

int bfs() {
    
    queue<P> que;
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            dist[i][j] = INF;//设为这样可以判断是否已经访问，走回头路是会无谓增长路途的
        }
    }
    que.push(P(1, 1));//将起点放入队列
    dist[1][1] = 0;//起点步数为0
    
    while (que.size()) {//只要队列非空就还有格子要走完，就要走
        P p = que.front();
        que.pop();//将队头扔掉，相当于这里已经走过了
        if (p.first == exit_i && p.second == exit_j)//走到了终点就结束
            break;
        
        for (int i = 0; i < 4; i++) {
            
            int toi = p.first + to_i[i];//接下来要走到的地方
            int toj = p.second + to_j[i];
            
            if (1 <= toi && toi < 2 * h && 1 <= toj && toj < 2 * w //首先是不能越界
                && map[(toi + p.first) / 2][(toj + p.second) / 2] == 0 //然后是中间的一步要没有墙，注意这里我们是一次走两格，但实际上两个实际格子之间有个墙壁，因此我们是每次走一格加一个墙壁（看上面的图）
                && map[toi][toj] == 0 //而且走到的点也不能是墙壁
                && dist[toi][toj] == INF) {//并且要走的点是没有去过的
                    
                que.push(P(toi, toj));//将走到的点加入队列
                dist[toi][toj] = dist[p.first][p.second] + 1;//要走到的点的距离
            }
        }
    }
    
    return dist[exit_i][exit_j] + 1;//返回终点值
}

int main() {
    
    int i, j, dis; 
    
    while (scanf("%d%d", &w, &h) && w && h) {
        
        make_map(w, h);
        /*
        for (i = 0; i <= 2 * h; i++) {
            for (j = 0; j <= 2 * w; j++) {
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        */
        dis = bfs();
        
        if (dis == INF + 1)//表示没找到
            printf("0\n");
        else
            printf("%d\n", dis);
    }
    return 0;
}                                 