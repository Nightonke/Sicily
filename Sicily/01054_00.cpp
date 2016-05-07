// Problem#: 1054
// Submission#: 3457623
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

int counter = 1;
string p1, p2, p3;
double rate;
double ansR;
int endMonth, endYear, endDay = 15, startMonth, startDay, startYear;
int ansEM, ansEY, ansSM, ansSD, ansSY;
int poss;
char monthName[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

void judge() {
    //judge part 1
    if (p1[p1.size() - 1] == '%') {
        rate = 0;
        for (int i = 0; i < p1.size() - 1; i++) {
            if (!('0' <= p1[i] && p1[i] <= '9')) return;
            rate = rate * 10 + p1[i] - '0';
        }
    } else {
        if (p1[p1.size() - 1] != '2' && p1[p1.size() - 1] != '4' && p1[p1.size() - 1] != '8') return;
        if ((!('0' <= p1[p1.size() - 3] && p1[p1.size() - 3] <= '9')) || p1[p1.size() - 3] >= p1[p1.size() - 1]) return;
        rate = 0;
        for (int i = 0; i < p1.size() - 3; i++) {
            if (!('0' <= p1[i] && p1[i] <= '9')) return;
            rate = rate * 10 + p1[i] - '0';
        }
        rate += (p1[p1.size() - 3] - '0') * 1.0 / (p1[p1.size() - 1] - '0');
    }
    if (rate > 99.875) return;
    
    //judge part 2 and part 3
    if (p2.size() < 3) return;
    bool part2HasHyphen = false;
    int part2HasHyphenPos;
    for (int i = 0; i < p2.size(); i++) {
        if (p2[i] == '-') {
            part2HasHyphen = true;
            part2HasHyphenPos = i;
        }
    }
    if (part2HasHyphen) {
        endMonth = 0;
        if (part2HasHyphenPos >= p2.size() - 2) return;
        for (int i = 0; i < part2HasHyphenPos; i++) {
            if (p2[i] < '0' || p2[i] > '9') return;
            endMonth = endMonth * 10 + p2[i] - '0';
        }
        endYear = 0;
        for (int i = part2HasHyphenPos + 1; i < p2.size(); i++) {
            if (p2[i] < '0' || p2[i] > '9') return;
            endYear = endYear * 10 + p2[i] - '0';
        }
    } else {
        if (p2.size() > 4) return;
        for (int i = 0; i < p2.size(); i++) 
            if (p2[i] < '0' || p2[i] > '9') return;
        endYear = (p2[p2.size() - 2] - '0') * 10 + p2[p2.size() - 1] - '0';
        if (p2.size() == 3) endMonth = p2[0] - '0';
        else endMonth = (p2[0] - '0') * 10 + p2[1] - '0';
    }
    if (endYear < 3 || endYear > 99) return;
    if (endMonth < 1 || endMonth > 12) return;

    //judge part3
    if (p3.size() < 3) return;
    bool part3HasHyphen = false;
    int part3HasHyphenPos;
    for (int i = 0; i < p3.size(); i++) {
        if (p3[i] == '-') {
            part3HasHyphen = true;
            part3HasHyphenPos = i;
        }
    }
    if (part3HasHyphen) {  // 可以确定part3的值
        startDay = 0;
        if (part3HasHyphenPos >= p3.size() - 2) return;
        for (int i = part3HasHyphenPos + 1; i < p3.size(); i++) {
            if (p3[i] < '0' || p3[i] > '9') return;
            startDay = startDay * 10 + p3[i] - '0';
        }
        startMonth = 0;
        for (int i = 0; i < part3HasHyphenPos; i++) {
            if (p3[i] < '0' || p3[i] > '9') return;
            startMonth = startMonth * 10 + p3[i] - '0';
        }    
    } else {
        if (p3.size() > 4) return;
        for (int i = 0; i < p3.size(); i++) 
            if (p3[i] < '0' || p3[i] > '9') return;
        startDay = (p3[p3.size() - 2] - '0') * 10 + p3[p3.size() - 1] - '0';
        if (p3.size() == 3) startMonth = p3[0] - '0';
        else startMonth = (p3[0] - '0') * 10 + p3[1] - '0';
    }
    if (startDay < 1 || startDay > 31) return;
    if (startMonth < 1 || startMonth > 12) return;
    if (startMonth >= 11) startYear = 3;
    else startYear = 4;

    if (startYear > endYear) return;
    if (startYear == endYear && startMonth > endMonth) return;
    if (startYear == endYear && startMonth == endMonth && startDay >= endDay) return;
    poss++;
    ansEM = endMonth;
    ansEY = endYear;
    ansSD = startDay;
    ansSM = startMonth;
    ansSY = startYear;
    ansR = rate;
}

void output() {
    if (poss == 1) {
        printf("<Kalii Index=%d>\n", counter);
        printf("    <startdate>%02d%s%02d</startdate>\n", ansSD, monthName[ansSM - 1], ansSY);
        printf("    <rate>%.3lf</rate>\n", ansR);
        printf("    <enddate>15%s%02d</enddate>\n", monthName[ansEM - 1], ansEY);
        printf("</Kalii>\n");
    } else {
        printf("<Kalii Index=%d>BAD DATA</Kalii>\n", counter);
    }
    counter++;
}

int main() {

    //std::ios::sync_with_stdio(false);

    char temp[500];

    while (gets(temp)) {
        
        string S(temp);
        int pos1, pos2;
        int s = S.size();
        poss = 0;

        //rate
        bool isOK = false;
        for (int i = 0; i < s; i++) {
            if (S[i] == '%') {
                p1 = S.substr(0, i + 1); 
                pos1 = i + 1;
                isOK = true;
                break;
            }
            if (S[i] == '/') {
                p1 = S.substr(0, i + 2);
                pos1 = i + 2;
                isOK = true;
                break;
            }
        }
        if (!isOK) {
            output();
            continue;
        }

        //endDate
        while (pos1 < s && S[pos1] == ' ') pos1++;
        bool endHasHyphen = false;
        int endHasHyphenPos;
        for (int i = pos1; i < pos1 + 3; i++) {
            if (S[i] == '-') {
                endHasHyphen = true;
                endHasHyphenPos = i;
            }
        }
        int numCounter = 0;
        if (endHasHyphen) {
            p2 = S.substr(pos1, endHasHyphenPos + 2 + 1 - pos1);
            pos2 = endHasHyphenPos + 3;
            while (pos2 < s && S[pos2] == ' ') pos2++;
            p3 = S.substr(pos2, s - pos2);
            judge();
        } else {
            bool existBlank = false;
            for (int i = pos1; i < s; i++) {
                if (S[i] == ' ') {
                    p2 = S.substr(pos1, i - pos1);
                    pos2 = i + 1;
                    while (pos2 < s && S[pos2] == ' ') pos2++;
                    p3 = S.substr(pos2, s - pos2);
                    judge();
                    existBlank = true;
                    break;
                }
            }
            if (!existBlank) {
                //3 number in end
                p2 = S.substr(pos1, 3);
                pos2 = pos1 + 3;
                while (pos2 < s && S[pos2] == ' ') pos2++;
                p3 = S.substr(pos2, s - pos2);
                judge();
                //4 number in end
                p2 = S.substr(pos1, 4);
                pos2 = pos1 + 4;
                while (pos2 < s && S[pos2] == ' ') pos2++;
                p3 = S.substr(pos2, s - pos2);
                judge();
            }
        }
        output();
    }

    return 0;
}                                 