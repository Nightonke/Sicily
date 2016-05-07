// Problem#: 6137
// Submission#: 2811408
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string c[1050];
char ori_in[205];
char in[205];
int b_pos[11];
int to_b_pos[11];
int counter = 0;
int brackets = 0;

bool was_here(int pos) {
    for (int i = 0; i < pos; i++) {
        if (c[i] == c[pos]) {
            return true;
        }
    }
    return false;
}

void push_in() {
    for (int i = 0; i < (int)strlen(in); i++) {
        if (in[i] != ' ') {
            c[counter].push_back(in[i]);
        }
    }
    if (!was_here(counter)) {
        counter++;
    } else {
        c[counter].clear();
    }
}

void DFS(int pos) {
    
    if (pos == brackets) {
        if (strcmp(ori_in, in))
            push_in();
        return;
    }

    DFS(pos + 1);
        
    in[b_pos[pos]] = ' ';
    in[to_b_pos[pos]] = ' ';
    DFS(pos + 1);
    in[b_pos[pos]] = '(';
    in[to_b_pos[pos]] = ')';
}

bool is_new(int pos, int count) {
    for (int i = 0; i < count; i++) {
        if (b_pos[i] == pos) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> in;
    strcpy(ori_in, in);
    brackets = 0;
    for (int i = 0; i < (int)strlen(in); i++) {
        if (in[i] == '(') {
            brackets++;
        }
    }
    int k = 0;
    for (int i = 0; i < (int)strlen(in); i++) {
        if (in[i] == ')') {
            for (int j = i - 1; j >= 0; j--) {
                if (in[j] == '(' && is_new(j, k)) {
                    b_pos[k] = j;
                    to_b_pos[k++] = i;
                    break;
                }
            }
        }
    }
    DFS(0);
    sort(c, c + counter);
    for (int i = 0; i < counter; i++) {
        cout << c[i] << endl;
    }
    return 0;
}                                 