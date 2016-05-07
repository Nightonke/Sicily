// Problem#: 1890
// Submission#: 3258640
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct bottle {
    int maxNum;
    int maxVal;
};

bottle b[205];
int ball[205];

bool cmp(const bottle & b1, const bottle & b2) {
    return b1.maxVal > b2.maxVal;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        int N, M;
        cin >> N >> M;
        if (cin.eof()) break;

        for (int i = 0; i < N; i++) cin >> ball[i];
        for (int i = 0; i < M; i++) cin >> b[i].maxNum >> b[i].maxVal;

        sort(ball, ball + N);
        sort(b, b + M, cmp);

        int counter = 0, sum = 0;

        for (int i = N - 1, j = 0; i >= 0 && j < M; ) {

            if (ball[i] <= b[j].maxVal && b[j].maxNum > 0) {
                b[j].maxNum--;
                counter++;
                sum += ball[i];
                i--;
            } else if (b[j].maxNum == 0) {
                j++;
            } else if (ball[i] > b[j].maxVal) {
                i--;
            }

        }

        cout << counter << " " << sum << endl;

    }

    //getchar();
    //getchar();
    
    return 0;
}                                 