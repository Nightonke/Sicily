// Problem#: 1016
// Submission#: 3585804
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int rule[256][8], m[15];
long long step, length;
char num[20], target[300];
int targetNum[300], pro[2][300];
int answerNum, ans1[300], ans2[300];

int MAX() {
    if (length < 11) return m[length];
    else return 985;
}

void init() {
    for (int i = 0; i < 256; i++) {
        int temp = i;
        for (int j = 0; j < 8; j++) {
            rule[i][j] = temp & 1;
            temp >>= 1;
        }
    }
    m[0] = 1;
    for (int i = 1; i < 11; i++) m[i] = m[i - 1] << 1;
}

bool check() {
    length = strlen(target);
    if (length < 3) return false;
    for (int i = 0; i < length; i++) {
        if (target[i] == 'W') targetNum[i] = 0;
        else if (target[i] == 'B') targetNum[i] = 1;
        else return false;
    }
    if ((targetNum[0] == 1) || (targetNum[length - 1] == 1) || (length & 1 == 0)) return false;
    return true;
}

int main() {
    init();

    int caseNum = 1;

    while (1) {
        
        scanf("%s%s", num, target);
        
        if (strcmp(num, "END") == 0) break;
        
        printf("LINE %d ", caseNum++);

        if (!check()) {
            printf("NONE\n");
            continue;
        }
        
        step = 0;
        for (int i = 0; num[i] != '\0'; i++) step = step * 10 + num[i] - '0';
        if (step > MAX()) step = MAX();

        answerNum = 0;

        for (int i = 0; i < 256; i++) {
            memset(pro, 0, sizeof(pro));
            int last = 0, now = 1;
            int s = 1;
            int jlength = length - 2, ruleNum;
            pro[now][length / 2] = 1;
            while (1) {
                
                if (s > step) break;

                bool isSame = true;
                for (int k = 0; k < length; k++) {
                    if (pro[now][k] != targetNum[k]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    ans1[answerNum] = i;
                    ans2[answerNum] = s;
                    answerNum++;
                    break;
                }
                now ^= 1;
                last ^= 1;
                
                s++;
                for (int j = 0; j < jlength; j++) {
                    ruleNum = pro[last][j];
                    ruleNum <<= 1;
                    ruleNum += pro[last][j + 1];
                    ruleNum <<= 1;
                    ruleNum += pro[last][j + 2];
                    pro[now][j + 1] = rule[i][ruleNum];
                }
                pro[now][0] = pro[now][length - 1] = 0;
            }
        }
        if (answerNum) {
            for (int i = 0; i < answerNum; i++) printf("(%d,%d)", ans1[i], ans2[i]);
            printf("\n");
        } else printf("NONE\n");
    }
    return 0;
}                                 