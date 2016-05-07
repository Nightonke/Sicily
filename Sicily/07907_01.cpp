// Problem#: 7907
// Submission#: 2822902
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 7907
// Submission#: 2822863
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <vector>
#include <stdio.h>
using namespace std;

int n;
int game_counter;
char temp_card[101];
char temp_do[101];

vector<short> v[101];

void add(char control, int pos) {
    if (control == 'r') {
        for (int i = 0; i < (int)v[pos].size(); i++) {
            if (v[pos][v[pos].size() - i - 1] & 1) {
                v[pos][v[pos].size() - i - 1] = v[pos][v[pos].size() - i - 1] / 10 * 10;
            } else {
                v[pos][v[pos].size() - i - 1] = v[pos][v[pos].size() - i - 1] / 10 * 10 + 1;
            }
            v[pos - 1].push_back(v[pos][v[pos].size() - i - 1]);
        }
    } else {
        for (int i = 0; i < (int)v[pos].size(); i++) {
            if (v[pos][v[pos].size() - i - 1] & 1) {
                v[pos][v[pos].size() - i - 1] = v[pos][v[pos].size() - i - 1] / 10 * 10;
            } else {
                v[pos][v[pos].size() - i - 1] = v[pos][v[pos].size() - i - 1] / 10 * 10 + 1;
            }
            v[pos + 1].push_back(v[pos][v[pos].size() - i - 1]);
        }
    }
}

void play() {
    
    for (int i = 0; i < 101; i++) {
        v[i].clear();
    }
    
    int r_most = n;
    int l_most = 1;
    for (int i = 1; i <= n; i++) {
        v[i].push_back(i * 10 + (temp_card[i - 1] & 1));
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (temp_do[i] == 'R') {
            add('r', r_most);
            r_most--;
        } else {
            add('l', l_most);
            l_most++;
        }
    }
    int ques;
    scanf("%d", &ques);
    int temp;
    printf("Pile %d\n", game_counter);
    for (int i = 0; i < ques; i++) {
        scanf("%d", &temp);
        printf("Card %d is a face ", temp);
        if (v[l_most][v[l_most].size() - temp] & 1) {
            printf("up ");
        } else {
            printf("down ");
        }
        printf("%d.\n", v[l_most][v[l_most].size() - temp] / 10);
    }
}
 
int main() {
    game_counter = 0;
    while (scanf("%d", &n) && n) {
        game_counter++;
        scanf("%s", temp_card);
        scanf("%s", temp_do);
        play();
    }
    return 0;
}                                 