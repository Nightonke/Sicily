// Problem#: 1444
// Submission#: 2796971
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#define INF 0x7f7f7f
using namespace std;

vector<int> road[1200];
bool is_prime[10000];
int prime[10000], prime_num, prime_is_index[10000];
bool used[1200];

void make_prime() {
    prime_num = 0;
    memset(is_prime, 1, sizeof(is_prime));
    for (int i = 2; i < 10000; i++) {
        if (is_prime[i]) {
            for (int j = 2; j * i < 10000; j++) {
                is_prime[j * i] = false;
            }
            if (i >= 1000)
                prime[prime_num++] = i;
        }
    }
}

void make_prime_is_index() {
    for (int i = 0; i < prime_num; i++) {
        prime_is_index[prime[i]] = i;
    }
}

bool only_one_digit_dif(int a, int b) {
    int dif_num = 0, i;
    char aa[4], bb[4];
    
    i = 0;
    while (a) {
        aa[i++] = a % 10 + '0';
        a /= 10;
    }
    i = 0;
    while (b) {
        bb[i++] = b % 10 + '0';
        b /= 10;
    }
    
    for (i = 0; i < 4; i++) {
        if (aa[i] != bb[i])
            dif_num++;
        if (dif_num >= 2) {
            return false;
        }
    }
    if (dif_num == 1)
        return true;
    return false;
}

void make_road() {
    for (int i = 0; i < prime_num; i++) {
        int temp[4];
        int temp_prime = prime[i], j = 3;
        while (temp_prime) {
            temp[j--] = temp_prime % 10;
            temp_prime /= 10;
        }
        for (j = 0; j < 4; j++) {
            int save = temp[j];
            int new_temp;
            for (int k = 0; k <= 9; k++) {
                if (save != k) {
                    temp[j] = k;
                    if (j == 0 && k == 0) {
                        continue;
                    }
                    new_temp = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
                    if (is_prime[new_temp]) {
                        road[i].push_back(prime_is_index[new_temp]);
                        road[prime_is_index[new_temp]].push_back(i);
                    }
                }
            }
            temp[j] = save;
        }
    }
}

typedef pair<int, int> p;

int Dijkstra(int sp, int ep) {
    if (sp == ep)
        return 0;
    if (!is_prime[sp] || !is_prime[ep])
        return -1;
    sp = prime_is_index[sp];
    ep = prime_is_index[ep];
    int d[1200];
    memset(d, INF, sizeof(d));
    memset(used, false, sizeof(used));
    d[sp] = 0;
    priority_queue<p, vector<p>, greater<p> > q;
    q.push(p(0, sp));
    p top;
    while (!q.empty()) {
        top = q.top();
        q.pop();
        if (top.second == ep)
            return d[ep];
        if (used[top.second] || d[top.second] < top.first)
            continue;
        used[top.second] = true;
        for (int i = 0; i < (int)road[top.second].size(); i++) {
            if (d[road[top.second][i]] > d[top.second] + 1) {
                d[road[top.second][i]] = d[top.second] + 1;
                q.push(p(d[road[top.second][i]], road[top.second][i]));
            }
        }
    }
    return -1;
}

int main() {
    int case_num, sp, ep;
    make_prime();
    make_prime_is_index();
    make_road();
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d%d", &sp, &ep);
        int temp = Dijkstra(sp, ep);
        if (temp == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", temp);
        }
    }
    return 0;
}                                 