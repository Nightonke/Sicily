// Problem#: 1444
// Submission#: 2796905
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
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
        for (int j = i + 1; j < prime_num; j++) {
            if (only_one_digit_dif(prime[i], prime[j])) {
                road[i].push_back(j);
                road[j].push_back(i);
            }
        }
    }
}

struct step {
    int point;
    int num;
    step(int p, int n) {
        point = p;
        num = n;
    }
};

int BFS(int sp, int ep) {
    sp = prime_is_index[sp];
    ep = prime_is_index[ep];
    memset(used, false, sizeof(used));
    queue<step> q;
    q.push(step(sp, 0));
    used[sp] = true;
    step temp(0, 0);
    int size;
    
    while (!q.empty()) {
        size = q.size();
        while (size--) {
            temp = q.front();
            q.pop();
            if (temp.point == ep)
                return temp.num;
            for (int i = 0; i < (int)road[temp.point].size(); i++) {
                if (!used[road[temp.point][i]]) {
                    q.push(step(road[temp.point][i], temp.num + 1));
                    used[road[temp.point][i]] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    int case_num, sp, ep;
    make_prime();
    make_road();
    make_prime_is_index();
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d%d", &sp, &ep);
        printf("%d\n", BFS(sp, ep));
    }
    return 0;
}                                 