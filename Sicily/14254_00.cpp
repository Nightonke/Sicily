// Problem#: 14254
// Submission#: 3670441
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int H, W;
char wall[20][45];
int ans;
bool cleaned[20];

bool isOK() {
    for (int i = 0; i < W; i++) {
        int num = 0;
        for (int j = 0; j < H; j++) {
            if (wall[j][i] == '1') num++;
            if (num > 2) break;
        }
        if (num > 2) return false;
    }
    return true;
}

void dfs(int cleanedPos, int cleanedNum) {
    if (cleanedPos == H) {
        if (isOK() && cleanedNum < ans) ans = cleanedNum;
        return;
    }
    dfs(cleanedPos + 1, cleanedNum);
    char record[45];
    for (int j = 0; j < W; j++) record[j] = wall[cleanedPos][j];
    for (int j = 0; j < W; j++) wall[cleanedPos][j] = '0';
    dfs(cleanedPos + 1, cleanedNum + 1);
    for (int j = 0; j < W; j++) wall[cleanedPos][j] = record[j];
}

int main() {

    while (scanf("%d%d\n", &H, &W) != EOF) {
        for (int i = 0; i < H; i++) gets(wall[i]);
        ans = H;
        memset(cleaned, false, sizeof(cleaned));
        dfs(0, 0);
        printf("%d\n", ans);
    }

    return 0;
}                                 