// Problem#: 1213
// Submission#: 3586094
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int n, m, q;
char num2str[30];
char words[205][11];
int wl[205];
char senChar[205];
int senNum[205];
int deli;
bool wordLength[11];
int answerNum;
bool anAns;
char ansNum2str[30];

int w[205][2];
int wn;

bool check() {
    int sp = 0;
    wn = 0;
    if (senNum[0] == deli || senNum[m - 1] == deli) return false;
    for (int i = 0; i < m; i++) {
        if (senNum[i] == deli) {
            if (!wordLength[i - sp]) return false;
            w[wn][0] = sp;
            w[wn][1] = i - 1;
            wn++;
            sp = i + 1;
        }
    }
    if (!wordLength[m - sp]) return false;
    w[wn][0] = sp;
    w[wn][1] = m - 1;
    wn++;
    return true;
}

bool isOK(int numNow, int charNow) {
    
    bool existChar[30];
    memset(existChar, false, sizeof(existChar));
    for (int i = 1; i <= n; i++) if (num2str[i] != '\0') existChar[num2str[i] - 'a'] = true;
    for (int i = 0; i < wl[charNow]; i++) {
        if (!((num2str[senNum[w[numNow][0] + i]] == '\0' && !existChar[words[charNow][i] - 'a']) || num2str[senNum[w[numNow][0] + i]] == words[charNow][i])) return false;
    }
    return true;
    
}

bool isOK2() {
    int charNum[30];
    memset(charNum, 0, sizeof(charNum));
    for (int i = 1; i <= n; i++) if (num2str[i] != '\0') charNum[num2str[i] - 'a']++;
    for (int i = 0; i < 30; i++) if (charNum[i] > 1) return false;
    return true;
}

void DFS(int now) {
    if (now == wn) {
        for (int i = 0; i < 30; i++) ansNum2str[i] = num2str[i];
        answerNum++;
        return;
    }
    int nowLength = w[now][1] - w[now][0] + 1;
    for (int i = 0; i < q; i++) {
        if (wl[i] == nowLength && isOK(now, i)) {
            char lastNum2str[30];
            for (int j = 1; j <= n; j++) lastNum2str[j] = num2str[j];
            for (int j = 0; j < wl[i]; j++) num2str[senNum[w[now][0] + j]] = words[i][j];
            if (!isOK2()) {
                for (int j = 1; j <= n; j++) num2str[j] = lastNum2str[j];
                continue;
            }
            DFS(now + 1);
            for (int j = 1; j <= n; j++) num2str[j] = lastNum2str[j];
        }
    }
}

int main() {

    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) scanf("%d", senNum + i);
        scanf("%d", &q);
        memset(wordLength, false, sizeof(wordLength));
        for (int i = 0; i < q; i++) {
            scanf("%s", words[i]);
            wl[i] = strlen(words[i]);
            wordLength[wl[i]] = true;
        }

        answerNum = 0;

        for (int i = 1; i <= n; i++) {
            deli = i;
            if (check()) {
                memset(num2str, 0, sizeof(num2str));
                anAns = false;
                DFS(0);
                if (answerNum >= 2) break;
            }
        }

        if(answerNum == 0) printf("No solution\n");
        else if (answerNum >= 2) printf("Cannot determine\n");
        else {
            for (int i = 0; i < m; i++) {
                if (ansNum2str[senNum[i]] == '\0') printf(" ");
                else printf("%c", ansNum2str[senNum[i]]);
            }
            printf("\n");
        }

    }
    return 0;
}                                 