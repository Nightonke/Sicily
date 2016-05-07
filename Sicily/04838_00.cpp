// Problem#: 4838
// Submission#: 3533269
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_N = 200005;

struct man {
    int score, strength, num;
}M[2][MAX_N];

bool cmp(const man & m1, const man & m2) {
    if (m1.score != m2.score) return m1.score > m2.score;
    else return m1.num < m2.num;
}

int winnerPos[MAX_N / 2], loserPos[MAX_N / 2];
char text[2000000];

int main() {

    //std::ios::sync_with_stdio(false);

    int N, R, Q, num;
    scanf("%d%d%d\n", &N, &R, &Q);

    gets(text);  // if there is a lot of data in a line, gets() and then process is faster than scanf()
    int sum = 0;
    int counter = 1;
    for (int i = 0; text[i] != '\0'; i++)
        if (text[i] == ' ') {
            M[0][counter++].score = sum;
            sum = 0;
        } else sum = sum * 10 + text[i] - '0';
    M[0][counter++].score = sum;
    gets(text);
    sum = 0;
    counter = 1;
    for (int i = 0; text[i] != '\0'; i++)
        if (text[i] == ' ') {
            M[0][counter++].strength = sum;
            sum = 0;
        } else sum = sum * 10 + text[i] - '0';
    M[0][counter++].strength = sum;

    num = 2 * N;
    for (int i = 1; i <= num; i++) M[0][i].num = i;
    sort(M[0] + 1, M[0] + num + 1, cmp);  // use quicksort just one time

    int now = 0, next = 1;  // change indexs rather than change data in M-array
    while (R--) {
        int winners = 0, losers = 0;  // the numbers of winners and losers
        for (int i = 2; i <= num; i += 2) {
            if (M[now][i].strength > M[now][i - 1].strength) {
                M[now][i].score++;
                winnerPos[winners++] = i;
                loserPos[losers++] = i - 1;
            } else {
                M[now][i - 1].score++;
                winnerPos[winners++] = i - 1;
                loserPos[losers++] = i;
            }
        }
        int i = 0, j = 0, k = 1;
        while (i < winners && j < losers)  // sort in this way
            if (M[now][winnerPos[i]].score > M[now][loserPos[j]].score)
                M[next][k++] = M[now][winnerPos[i++]];
            else if (M[now][winnerPos[i]].score < M[now][loserPos[j]].score)
                M[next][k++] = M[now][loserPos[j++]];
            else
                if (M[now][winnerPos[i]].num < M[now][loserPos[j]].num) M[next][k++] = M[now][winnerPos[i++]];
                else M[next][k++] = M[now][loserPos[j++]];
        while (i < winners) M[next][k++] = M[now][winnerPos[i++]];
        while (j < losers) M[next][k++] = M[now][loserPos[j++]];
        now = 1 - now;
        next = 1 - next;
    }

    printf("%d\n", M[now][Q].num);

    return 0;
}                                 