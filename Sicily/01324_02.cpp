// Problem#: 1324
// Submission#: 3040278
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
using namespace std;

int main() {

    //std::ios::sync_with_stdio(false);

    int caseNum;

    scanf("%d", &caseNum);

    while (caseNum--) {

        char s[100];

        scanf("%s", s);

        bool continue_corret = false;

        int score = 1;

        int sum = 0;

        for (int i = 0; s[i] != '\0'; i++) {

            if (s[i] == 'O') {

                if (continue_corret) {

                    score++;
                    sum += score;

                } else {

                    continue_corret = true;
                    sum += 1;
                
                }

            } else {

                score = 1;
                continue_corret = false;

            }

        }

        printf("%d\n", sum);

    }

    //getchar();
    //getchar();
    
    return 0;
}                                 