// Problem#: 1053
// Submission#: 3456571
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
#include <set>
using namespace std;

int move_p[40], move_d[50], move_j[50], move_l[50];
bool pegs[50], allow[50];
int orig;
int num;
int last;
int next_peg, next_dir;

bool forward_helper(int curr, int dir, int & jump, int & land) {
    const int curr_x = curr % 7;
    const int curr_y = curr / 7;
    int jump_x = curr_x;
    int jump_y = curr_y;
    int land_x = curr_x;
    int land_y = curr_y;
    switch (dir)
       {
       case 0: // left
          jump_x = curr_x - 1;
          land_x = curr_x - 2;
          break;
       case 1: // up
          jump_y = curr_y - 1;
          land_y = curr_y - 2;
          break;
       case 2: // right
          jump_x = curr_x + 1;
          land_x = curr_x + 2;
          break;
       case 3: // down
          jump_y = curr_y + 1;
          land_y = curr_y + 2;
          break;
       }

    // Make sure we didn't jump off the board.
    if ((land_x < 0) || (land_x >= 7) ||
        (land_y < 0) || (land_y >= 7)) return false;

    // It's a winning move.
    jump = jump_x + 7 * jump_y;
    land = land_x + 7 * land_y;
    return true;
}

inline void increment_p() {
    next_dir = 0;
    next_peg++;
}

inline void increment() {
    next_dir++;
    if (next_dir == 4) increment_p(); 
}

bool forward(void) {
    const int index = orig - num;
    if (num == 1) return false;
    while (next_peg < 49) {
        int jump, land;
        if (!pegs[next_peg])
            // Current space is empty. Of course we can't do anything.
            increment_p();
        else if (forward_helper(next_peg, next_dir, jump, land)
            // Make sure:
            // (1) position to be jumped is occupied,
            // (2) position we land in is unoccupied,
            // (3) position we land in is allowed.
                 && pegs[jump] && !pegs[land] && allow[land]) {
            // Save the current state.
            move_p[index] = next_peg;
            move_d[index] = next_dir;
            move_j[index] = jump;
            move_l[index] = land;

            // Make the move.
            pegs[next_peg] = false;
            pegs[jump] = false;
            pegs[land] = true;
            --num;
            next_peg = 0;
            next_dir = 0;

            return true;
         } else increment();
    }

    // No more forward moves are possible.
    return false;
}

inline bool win() {return (num == 1) && pegs[last];}

void print() {
    for (int i = 0; i < orig - 1; ++i) {
        const int orig = move_p[i];
        const int land = move_l[i];
        const int orig_x = orig % 7 + 1;
        const int orig_y = orig / 7 + 1;
        const int land_x = land % 7 + 1;
        const int land_y = land / 7 + 1;
        cout << (i+1) << ". (" << orig_x << ", " << orig_y << ") to (" << land_x << ", " << land_y <<")" << endl;
    }
}

bool backward() {
    const int index = orig - num - 1;
    if (index < 0) return false;

    next_peg = move_p[index];
    next_dir = move_d[index];
    const int jump = move_j[index];
    const int land = move_l[index];
    ++num;
    pegs[next_peg] = true;
    pegs[jump] = true;
    pegs[land] = false;
 
    // Increment.
    increment();

    return true;
}

void go() {
    while (1) {
        if (forward()) {
            if (win()) {
                print();
                return;
            }
        } else if (backward()) {
        } else break;
    }
    cout << "No solution." << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    int counter = 1;
    bool firstTime = true;

    while (caseNum--) {
        
        num = 0;
        char c;
        for (int i = 0, index = 0; i < 7; ++i) {
             for (int j = 0; j < 7; ++j, ++index) {
                cin >> c;
                switch (c) {
                   case 'x' : pegs[index] = false; allow[index] = false; break;
                   case 'o' : pegs[index] = true;  allow[index] = true;  break;
                   case 'e' : pegs[index] = false; allow[index] = true;  break;
                   case 'O' : pegs[index] = true;  allow[index] = true;  last = index;
                      break;
                   case 'E' : pegs[index] = false; allow[index] = true;  last = index;
                      break;
                }
            if (pegs[index]) ++num;
            }
        }
        orig = num;
        next_peg = 0;
        next_dir = 0;
        //if (!firstTime) cout << endl;
        cout << "Dataset " << counter++ << ":" << endl;
        go();
        cout << endl;
        firstTime = false;
    }

    return 0;
}                                 