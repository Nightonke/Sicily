// Problem#: 7907
// Submission#: 2822885
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <stdio.h>
using namespace std;

int n;
int game_counter;
char temp_card[101];
char temp_do[101];
int r_most = n;    
int l_most = 1;
int r_num = 1;
int l_num = 1;

short v[101][101];

void add(char control, int pos) {
    if (control == 'r') {
        int length = 0;
        for (int i = 0; i < 101; i++, length++) {
            if (!v[pos - 1][i]) {
                break;
            }
        }
        for (int i = 0; i < r_num; i++) {
            if (v[pos][r_num - i - 1] & 1) {
                v[pos][r_num - i - 1] = v[pos][r_num - i - 1] / 10 * 10;
            } else {
                v[pos][r_num - i - 1] = v[pos][r_num - i - 1] / 10 * 10 + 1;
            }
            v[pos - 1][length + i] = v[pos][r_num - i - 1];
        }
        r_num += length;
    } else {
        int length = 0;
        for (int i = 0; i < 101; i++, length++) {
            if (!v[pos + 1][i]) {
                break;
            }
        }
        for (int i = 0; i < l_num; i++) {
            if (v[pos][l_num - i - 1] & 1) {
                v[pos][l_num - i - 1] = v[pos][l_num - i - 1] / 10 * 10;
            } else {
                v[pos][l_num - i - 1] = v[pos][l_num - i - 1] / 10 * 10 + 1;
            }
            v[pos + 1][length + i] = v[pos][l_num - i - 1];
        }
        l_num += length;
    }
}

void play() {
    
    memset(v, 0, sizeof(v));
    
    r_most = n;
    l_most = 1;
    r_num = 1;
    l_num = 1;
    for (int i = 1; i <= n; i++) {
        v[i][0] = i * 10 + (temp_card[i - 1] & 1);
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
    if (l_num < r_num) {
        l_num = r_num;
    }
    int ques;
    scanf("%d", &ques);
    int temp;
    printf("Pile %d\n", game_counter);
    for (int i = 0; i < ques; i++) {
        scanf("%d", &temp);
        printf("Card %d is a face ", temp);
        if (v[l_most][l_num - temp] & 1) {
            printf("up ");
        } else {
            printf("down ");
        }
        printf("%d.\n", v[l_most][l_num - temp] / 10);
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