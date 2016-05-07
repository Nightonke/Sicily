// Problem#: 14515
// Submission#: 3739560
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <queue>
#include <vector>
#include <functional>
#include <stdio.h>
using namespace std;

int main() {

    priority_queue<int> FirstHalfPart;
    priority_queue<int, vector<int>, greater<int> > SecondHalfPart;
    char c[20];

    while (~scanf("%s", c)) {
        if (c[0] == '#') {
            printf("%d\n", FirstHalfPart.top());
            FirstHalfPart.pop();
            if (!SecondHalfPart.empty()
                && FirstHalfPart.size() <= SecondHalfPart.size()) {
                FirstHalfPart.push(SecondHalfPart.top());
                SecondHalfPart.pop();
            }
        }
        else {
            int size = 0;
            for (int i = 0; c[i] != '\0'; i++) size = 10 * size + c[i] - '0';
            if (!FirstHalfPart.empty() && size > FirstHalfPart.top()) {
                SecondHalfPart.push(size);
                if (!SecondHalfPart.empty()
                    && FirstHalfPart.size() <= SecondHalfPart.size()) {
                    FirstHalfPart.push(SecondHalfPart.top());
                    SecondHalfPart.pop();
                }
            }
            else {
                FirstHalfPart.push(size);
                if (FirstHalfPart.size() > SecondHalfPart.size() + 2)
                {
                    SecondHalfPart.push(FirstHalfPart.top());
                    FirstHalfPart.pop();
                }
            }
        }
    }

    return 0;
}                                 