// Problem#: 1022
// Submission#: 3185161
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

#define MAX_N 100005

char m[MAX_N][15];

int main() {

    //std::ios::sync_with_stdio(false);

    int caseNum;
    scanf("%d", &caseNum);
    bool firstTime = true;
    char temp[30];

    while (caseNum--) {

        priority_queue<int, vector<int>, greater<int> > bigger;
        priority_queue<int, vector<int>, less<int> > smaller;

        if (!firstTime) {
            printf("\n");
        }
        
        
        firstTime = false;

        while (1) {
            
            gets(temp);
            
            if (temp[0] == 'A') {
                char name[15];
                int num = 0;
                int i;
                for (i = 4; temp[i] != ' '; i++) {
                    name[i - 4] = temp[i];
                }
                name[i - 4] = '\0';
                for (i++; temp[i] != '\0'; i++) {
                    num = num * 10 + temp[i] - '0';
                }
                for (i = 0; name[i] != '\0'; i++) {
                    m[num][i] = name[i];
                }
                m[num][i] = '\0';
                if ((bigger.size() + smaller.size()) % 2) {
                    if (num > smaller.top()) {
                        bigger.push(num);
                    } else {
                        bigger.push(smaller.top());
                        smaller.pop();
                        smaller.push(num);
                    }
                } else {
                    if (bigger.size() && num > bigger.top()) {
                        smaller.push(bigger.top());
                        bigger.pop();
                        bigger.push(num);
                    } else {
                        smaller.push(num);
                    }
                }
            } else if (temp[0] == 'Q') {
                if ((bigger.size() + smaller.size()) % 2) {
                    printf("%s\n", m[smaller.top()]);
                } else {
                    printf("No one!\n");
                }
            } else if (temp[0] == 'E') {
                if ((bigger.size() + smaller.size()) % 2) printf("%s is so poor.\n", m[smaller.top()]);
                else printf("Happy BG meeting!!\n");
                break;
            }
        }
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 