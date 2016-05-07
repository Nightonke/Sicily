// Problem#: 1901
// Submission#: 3716018
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const unsigned int MAXN = 1000005;

struct Node {
    int mod, pos;
    Node(int mod = 0, int pos = 0) {
        this->mod = mod;
        this->pos = pos;
    }
};

int Sum[MAXN];
int Ans;
int Num[MAXN], Q[MAXN], N, P, K;
Node Nodes[MAXN];
char Text[MAXN * 10];

bool cmp(const Node & N1, const Node & N2) {
    if (N1.mod != N2.mod) return N1.mod < N2.mod;
    else return N1.pos < N2.pos;
}

void Input() {
    long S = 0;
    gets(Text);
    int pos = 0, k = 1;
    while (Text[pos] != '\0') {
        if (Text[pos] == ' ') {
            Num[k++] = S;
            S = 0;
        }
        else S = S * 10 + Text[pos] - '0';
        pos++;
    }
    Num[k] = S;
}

int main() {

    int CaseNum, NowCase = 1;
    scanf("%d\n", &CaseNum);

    while (CaseNum--) {
        scanf("%d %d %d\n", &N, &P, &K);
        memset(Q, 0, sizeof(int) * (N + 5));
        memset(Nodes, 0, sizeof(Node) * (N + 5));
        Input();
        Sum[0] = 0;
        for (int i = 1; i <= N; i++) {
            Sum[i] = Sum[i - 1] + Num[i];
            Nodes[i].mod = Sum[i] % P;
            Nodes[i].pos = i;
        }
        sort(Nodes, Nodes + N + 1, cmp);
        int head = 1, tail = 0;
        Ans = -1;
        Q[head] = 0;
        for (int i = 0; i <= N; i++) {
            while (head <= tail && Nodes[i].pos < Nodes[Q[tail]].pos) tail--;
            Q[++tail] = i;
            while (head <= tail && Nodes[i].mod - Nodes[Q[head]].mod > K) head++;
            if (head == tail) continue;
            long temp = (Sum[Nodes[i].pos] - Sum[Nodes[Q[head]].pos]) / P;
            if (temp > Ans) Ans = temp;
        }
        printf("Case %d: %I64d\n", NowCase++, Ans);
    }

    return 0;
}                                 