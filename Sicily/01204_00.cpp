// Problem#: 1204
// Submission#: 3467963
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

const int MAX_POS = 27;
const int MAX_C = 24;
const int CHAR_PER_LINE = 50;

char children[MAX_POS];
int totalPos, rightGoodBoy, leftGoodGirl, nBadGirls, nBadBoys, spaceLoc;
int altLeft, altRight;
int maxMoves;

char moves[625];
int nMoves;

void initPos(int nGirls, int nBoys) {
    int i;
    children[0] = 'B';
    rightGoodBoy = 0;
    for(i = 1; i <= nGirls ; i++) {
        children[i] = 'G';
    }
    nBadGirls = nGirls;
    children[nGirls+1] = ' ';
    spaceLoc = nGirls+1;
    for(i = spaceLoc+1 ; i <= spaceLoc+nBoys ; i++) {
        children[i] = 'B';
    }
    nBadBoys = nBoys;
    children[spaceLoc + nBoys + 1] = 'G';
    leftGoodGirl = spaceLoc + nBoys + 1;
    totalPos = nGirls + nBoys + 1;
    maxMoves = nGirls * nBoys + nGirls + nBoys;
    nMoves = 0;
}

inline int SlideLeft() {
    if(spaceLoc >= totalPos) {
        return -1;
    }
    children[spaceLoc] = children[spaceLoc+1];
    spaceLoc++;
    children[spaceLoc] = ' ';
    moves[nMoves++] = 's';
    if(nMoves > maxMoves) {
        return -2;
    }
    return 0;
}

inline int SlideRight() {
    if(spaceLoc <= 1) {
        return -1;
    }
    children[spaceLoc] = children[spaceLoc-1];
    spaceLoc--;
    children[spaceLoc] = ' ';
    moves[nMoves++] = 'S';
    if(nMoves > maxMoves) {
        return -2;
    }
    return 0;
}

inline int HopLeft() {
    if(spaceLoc >= (totalPos - 1)) {
        return -1;
    }
    children[spaceLoc] = children[spaceLoc+2];
    spaceLoc += 2;
    children[spaceLoc] = ' ';
    moves[nMoves++] = 'h';
    if(nMoves > maxMoves) {
        return -2;
    }
    return 0;
}

inline int HopRight() {
    if(spaceLoc <= 2) {
        return -1;
    }
    children[spaceLoc] = children[spaceLoc-2];
    spaceLoc -= 2;
    children[spaceLoc] = ' ';
    moves[nMoves++] = 'H';
    if(nMoves > maxMoves) {
        return -2;
    }
    return 0;
}

inline int HopGirls() {
    while (spaceLoc >= (altLeft + 2)) HopRight();
    altLeft = spaceLoc + 1;
    return 0;
}

inline int HopBoys() {
    while (spaceLoc <= (altRight - 2)) HopLeft();
    altRight = spaceLoc - 1;
    return 0;
}

void output(int probNum) {
    cout << probNum << " " << nMoves << endl;
    for (int i = 0, j = 0; i < nMoves; i++, j++) {
        if (j == CHAR_PER_LINE) {
            j = 0;
            cout << endl;
        }
        cout << moves[i];
    }
    cout << endl << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    for (int probNum = 1; probNum <= caseNum; probNum++) {
        int nGirls, nBoys;
        cin >> nGirls >> nGirls >> nBoys;
        initPos(nGirls, nBoys);
        if (nGirls == 0) {
            int i = 0;
            while (i < nBoys) {
                if (i < (nBoys - 1)) {
                    HopLeft();
                    i += 2;
                } else {
                    SlideLeft();
                    i++;
                }
            }
        } else if (nBoys == 0) {
            int i = 0;
            while (i < nGirls) {
                if (i < (nGirls - 1)) {
                    HopRight();
                    i += 2;
                } else {
                    SlideRight();
                    i++;
                }
            }
        } else {
            char tChild;
            SlideLeft();
            altRight = spaceLoc - 1;
            altLeft = spaceLoc - 2;
            nBadBoys--;
            nBadGirls--;
            while (altRight >= altLeft) {
                if (spaceLoc == (altRight + 1)) {
                    if (children[altRight] == 'B') {
                        tChild = children[spaceLoc + 1];
                        HopGirls();
                        if (tChild == 'B') altRight += 2;
                        else leftGoodGirl--;
                    } else {
                        if (children[spaceLoc + 1] == 'B') {
                            SlideLeft();
                            altRight++;
                        } else {
                            SlideRight();
                            altRight--;
                            leftGoodGirl--;
                        }
                    }
                } else if (spaceLoc == (altLeft - 1)) {
                    if (children[altLeft] == 'G') {
                        tChild = children[spaceLoc - 1];
                        HopBoys();
                        if (tChild == 'G') altLeft -= 2;
                        else rightGoodBoy++;
                    } else {
                        if (children[spaceLoc - 1] == 'G') {
                            SlideRight();
                            altLeft--;
                        } else {
                            SlideLeft();
                            altLeft++;
                            rightGoodBoy++;
                        }
                    }
                }
            }
        }
        output(probNum);
    }

    return 0;
}                                 