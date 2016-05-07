// Problem#: 1914
// Submission#: 3591441
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
const int MAXK = 1001;

int n, m, k, r;
int matrix[MAXN][MAXN];

int s0_input() {
    if (scanf("%d%d\n", &n, &m) != 2) return 0;
    scanf("%d%d\n", &k, &r);
    char temp[10000];
    for (int i = 0; i < n; i++) {
        int j = 0, sum = 0;
        gets(temp);
        for (int k = 0; temp[k] != '\0'; k++) {
            if (temp[k] == ' ') {
                matrix[i][j++] = sum;
                sum = 0;
            } else sum = sum * 10 + temp[k] - '0';
        }
        matrix[i][j++] = sum;
    }
    return 1;
}

int x1[MAXK], x2[MAXK], y1[MAXK], y2[MAXK];

void s1_king_pos() {
    for (int i = 1; i <= k; i++) {
        x1[i] = y1[i] = MAXN;
        x2[i] = y2[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int king = matrix[i][j];
            x1[king] = min(x1[king], i);
            x2[king] = max(x2[king], i);
            y1[king] = min(y1[king], j);
            y2[king] = max(y2[king], j);
        }
    }
}

struct Border {
    int id, type;
    int row() const {
        if (type == 1) return x1[id];
        return x2[id] + 1;
    }
    int col() const {
        if (type == 1) return y1[id];
        return y2[id] + 1;
    }
    Border(int i = 0, int j = 0) {
        id = i;
        type = j;
    }
}border[MAXK * 2];

bool cmp_row(const Border & a, const Border & b) {
    return a.row() < b.row();
}

bool cmp_col(const Border & a, const Border & b) {
    return a.col() < b.col();
}

int left[MAXN + 1][MAXN + 1];
int up[MAXN + 1][MAXN + 1];

void s2_outline() {
    for (int i = 0; i < k; i++) {
        border[i] = Border(i + 1, 1);
        border[i + k] = Border(i + 1, -1);
    }
    sort(border, border + k * 2, cmp_col);
    for (int i = 1; i < n; i++) {
        int c = 0, p = 0;
        left[i][0] = 0;
        for (int j = 0; j < m; j++) {
            for (; p < k * 2 && border[p].col() == j; p++) {
                int u = border[p].id;
                if (x1[u] < i && x2[u] >= i) c += border[p].type;
            }
            if (c > 0) left[i][j + 1] = 0;
            else left[i][j + 1] = left[i][j] + 1;
        }
    }
    for (int i = 0; i <= m; i++) left[0][i] = left[n][i] = i;
    sort(border, border + k * 2, cmp_row);
    for (int i = 1; i < m; i++) {
        int c = 0, p = 0;
        up[0][i] = 0;
        for (int j = 0; j < n; j++) {
            for (; p < k * 2 && border[p].row() == j; p++) {
                int u = border[p].id;
                if (y1[u] < i && y2[u] >= i) c += border[p].type;
            }
            if (c > 0) up[j + 1][i] = 0;
            else up[j + 1][i] = up[j][i] + 1;
        }
    }
    for (int i = 0; i <= n; i++) up[i][0] = up[i][m] = i;
}

int counter[MAXN][MAXN];

void s3_pre_count() {
    for (int i = 0; i < n; i++) memset(counter[i], 0, sizeof(int) * m);
    for (int i = 1; i <= k; i++) {
        if (x2[i] >= 0) counter[x1[i]][y1[i]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int & t = counter[i][j];
            if (i > 0) t += counter[i - 1][j];
            if (j > 0) t += counter[i][j - 1];
            if (i > 0 && j > 0) t -= counter[i - 1][j - 1];
        }
    }
}

int s4_enumerate() {
    int ret = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (x2[i] < 0 || x2[j] < 0) continue;
            int height = x2[j] - x1[i] + 1;
            int width = y2[j] - y1[i] + 1;
            if (height <= 0 || width <= 0) continue;
            if (up[x2[j] + 1][y1[i]] < height) continue;
            if (up[x2[j] + 1][y2[j] + 1] < height) continue;
            if (left[x1[i]][y2[j] + 1] < width) continue;
            if (left[x2[j] + 1][y2[j] + 1] < width) continue;
            int c = counter[x2[j]][y2[j]];
            if (x1[i] > 0) c -= counter[x1[i] - 1][y2[j]];
            if (y1[i] > 0) c -= counter[x2[j]][y1[i] - 1];
            if (x1[i] > 0 && y1[i] > 0) c += counter[x1[i] - 1][y1[i] - 1];
            if (c > r) continue;
            ret = max(ret, height * width);
        }
    }
    return ret;
}

int main() {
    while (s0_input()) {
        s1_king_pos();
        s2_outline();
        s3_pre_count();
        printf("%d\n", s4_enumerate());
    }
    return 0;
}                                 