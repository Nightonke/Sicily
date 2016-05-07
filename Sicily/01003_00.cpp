// Problem#: 1003
// Submission#: 2740080
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX_TIMES 10000

int main() {
    int case_num, i, j, player_num;
    cin >> case_num;
    for (j = 1; j <= case_num; j++) {
        cin >> player_num;
        queue<int> deck[player_num];
        int temp;
        for (i = 0; i < 52; i++) {
            cin >> temp;
            deck[0].push(temp);
        }
        int last_deck[player_num];
        memset(last_deck, 0, sizeof(last_deck));
        int count[player_num];
        memset(count, 0, sizeof(count));
        int times = 0;
        int discard = 0;
        bool is_ok = false;
        while (times <= MAX_TIMES && !is_ok) {
            for (i = 0; i < player_num && !is_ok; i++) {
                if (deck[i].empty())
                    continue;
                count[i] = count[i] == 13 ? 1 : count[i] + 1;
                temp = deck[i].front();
                deck[i].pop();
                if (temp == count[i]) {
                    if (deck[i].empty()) {
                        last_deck[i] = temp;
                    }
                    if (i == player_num - 1) {
                        discard++;
                        if (discard == 52) {
                            is_ok = true;
                        }
                    } else {
                        deck[i + 1].push(temp);
                    }
                } else {
                    deck[i].push(temp);
                }
            }
            times++;
        }
        cout << "Case " << j << ":";
        if (is_ok) {
            for (i = 0; i < player_num; i++) {
                cout << " " << last_deck[i];
            }
        } else {
            cout << " unwinnable";
        }
        cout << endl;
    }
    return 0;
}                                 