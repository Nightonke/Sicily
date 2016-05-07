// Problem#: 1895
// Submission#: 3592777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

const int MAX_POINT = 105 * 105;
const int INF = 1000000000;

struct Node {
    int d, i, j;
    Node(int _d = 0, int _i = 0, int _j = 0) {
        d = _d;
        i = _i;
        j = _j;
    }
};

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, w, h, l, r;
int si, sj, ei, ej;
int d[MAX_POINT][4];
bool G[105][105];
pair<int, Node> arr[4 * MAX_POINT];
int len;

void fix_up_min_heap(int i ) {
	int j = ( i - 1 ) / 2;	// parent index
	pair<int, Node> tmp = arr[i];
    while( j >= 0 && tmp.first < arr[j].first) {
		arr[i] = arr[j]; i = j; 
		if( j > 0 )
			j = ( j - 1 ) / 2;
		else
			break;
	}
	arr[i] = tmp;
}

void fix_down_min_heap(int i ) {
	int j = 2 * i + 1;
	pair<int, Node> tmp = arr[i];
	while( j < len )
	{
		if( j < len - 1 && arr[j + 1].first < arr[j].first) 
			++j;
		if( arr[j].first < tmp.first)
		{
			arr[i] = arr[j]; 
			i = j; 
			j = 2 * i + 1;
		}
		else
		{
			break;
		}
	}
	arr[i] = tmp;
}

void insert_min_heap(pair<int, Node> x) {
	//if( n == *len ) return -1;
	arr[len++] = x;
	fix_up_min_heap(len - 1);
}

void pop_min_heap() {
	// assert( *len > 0 );
	arr[0] = arr[--len];
	fix_down_min_heap(0);
}

inline bool isValid(int & i, int & j) {
    return 0 <= i && i < h && 0 <= j && j < w && G[i][j];
}

void Dijkstra() {
    len = 0;
    for (int i = 0; i < n; i++) d[i][0] = d[i][1] = d[i][2] = d[i][3] = INF;
    for (int i = 0; i < 4; i++) {
        d[si * w + sj][i] = 0;
        insert_min_heap(make_pair(0, Node(i, si, sj)));
    }
    while (len) {
        int now_c = arr[0].first;
        int now_i = arr[0].second.i;
        int now_j = arr[0].second.j;
        int now_d = arr[0].second.d;
        int s = now_i * w + now_j;
        int next_i, next_j, next_d, next_s;
        pop_min_heap();
        if (d[s][now_d] < now_c) continue;
        //1
        next_i = now_i + dir[now_d][0];
        next_j = now_j + dir[now_d][1];
        next_s = next_i * w + next_j;
        if (isValid(next_i, next_j) && d[next_s][now_d] > d[s][now_d]) {
            d[next_s][now_d] = d[s][now_d];
            insert_min_heap(make_pair(d[next_s][now_d], Node(now_d, next_i, next_j)));
        }
        //2 turn left
        next_d = (now_d + 3) % 4;
        next_i = now_i + dir[next_d][0];
        next_j = now_j + dir[next_d][1];
        next_s = next_i * w + next_j;
        if (isValid(next_i, next_j) && d[next_s][next_d] > d[s][now_d] + l) {
            d[next_s][next_d] = d[s][now_d] + l;
            insert_min_heap(make_pair(d[next_s][next_d], Node(next_d, next_i, next_j)));
        }
        //3 turn right
        next_d = (now_d + 1) % 4;
        next_i = now_i + dir[next_d][0];
        next_j = now_j + dir[next_d][1];
        next_s = next_i * w + next_j;
        if (isValid(next_i, next_j) && d[next_s][next_d] > d[s][now_d] + r) {
            d[next_s][next_d] = d[s][now_d] + r;
            insert_min_heap(make_pair(d[next_s][next_d], Node(next_d, next_i, next_j)));
        }
    }
}

int main() {
    while (scanf("%d%d", &l, &r) != EOF) {
        if (l == 0 && r == 0) break;
        scanf("%d%d%d%d%d%d", &h, &w, &si, &sj, &ei, &ej);
        n = w * h;
        si--, sj--, ei--, ej--;
        char temp[105];
        for (int i = 0; i < h; i++) {
            scanf("%s", temp);
            for (int j = 0; temp[j] != '\0'; j++) {
                if (temp[j] == '.') G[i][j] = true;
                else G[i][j] = false;
            }
        }
        Dijkstra();
        int ans = min(d[ei * w + ej][0], min(d[ei * w + ej][1], min(d[ei * w + ej][2], d[ei * w + ej][3])));
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}                                 