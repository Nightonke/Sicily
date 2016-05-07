// Problem#: 1048
// Submission#: 2803712
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

int d[10];
int ans[512];
vector<char> ans_step[512];

int opp[9][9] = {1, 2, 4, 5, 0, 0, 0, 0, 0,
                 1, 2, 3, 4, 5, 6, 0, 0, 0,
                 2, 3, 5, 6, 0, 0, 0, 0, 0,
                 1, 2, 4, 5, 7, 8, 0, 0, 0,
                 1, 2, 3, 4, 5, 6, 7, 8, 9,
                 2, 3, 5, 6, 8, 9, 0, 0, 0,
                 4, 5, 7, 8, 0, 0, 0, 0, 0,
                 4, 5, 6, 7, 8, 9, 0, 0, 0,
                 5, 6, 8, 9, 0, 0, 0, 0, 0};

bool ok() {
    for (int i = 0; i < 9; i++) {
        if (d[i] == 1)
            return false;
    }
    return true;
}

struct step {
    int num;
    vector<char> v;
    step(){}
    step(int n) {
        num = n;
    }
    step(int n, char next_step) {
        num = n;
        v.push_back(next_step);
    }
    step(int n, vector<char> temp) {
        num = n;
        for (int i = 0; i < (int)temp.size(); i++) {
            v.push_back(temp[i]);
        }
    }
};

int change(bool test[], int op) {
    bool test_next_step[10];
    for (int i = 0; i < 9; i++) {
        test_next_step[i] = test[i];
    }
    for (int i = 0; i < 9 && opp[op][i]; i++) {
        test_next_step[opp[op][i] - 1] = test[opp[op][i] - 1] ^ 1;
    }
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += test_next_step[i] * (int)pow(2, i);
    }
    return sum;
}

void BFS() {
    
    queue<step> q;
    q.push(step(0));
    int size;
    step temp, next;
    
    while (!q.empty()) {
        size = q.size();
        while (size--) {
            
            temp = q.front();
            q.pop();
            
            bool test[10];
            int temp_num = temp.num;
            for (int i = 0; i < 9; i++) {
                test[i] = temp_num % 2;
                temp_num /= 2;
            }
            for (int i = 8; i >= 0; i--) {
                int next_num = change(test, i);
                if (ans_step[next_num].empty()) {
                    for (int j = 0; j < (int)temp.v.size(); j++) {
                        ans_step[next_num].push_back(temp.v[j]);
                    }
                    ans_step[next_num].push_back(i + '1');
                    q.push(step(next_num, ans_step[next_num]));
                }
            }
        }
    }
}

int main() {
    int case_num;
    BFS();
    ans_step[0].clear();
    ans_step[0].push_back('1');
    ans_step[0].push_back('1');
    char temp[10];
    scanf("%d\n", &case_num);
    while (case_num--) {
        int index = 0;
        gets(temp);
        for (int i = 0; i < 9; i++) {
            index += (temp[i] == 'w' ? 0 : 1) * (int)pow(2, i);
        }
        for (int i = (int)ans_step[index].size() - 1; i >= 0; i--) {
            printf("%c", ans_step[index][i]);
        }
        printf("\n");
    }
    return 0;
}                                 