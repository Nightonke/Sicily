// Problem#: 1447
// Submission#: 3311837
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <set>
using namespace std;

struct P {
    set<string> students;
    string name;
    P(string n) {
        students.clear();
        name = n;
    }
};

vector<P> projects;
set<string> appear;
set<string> toDelete;
int N = -1;

bool cmp(const P & p1, const P & p2) {
    if (p1.students.size() != p2.students.size())
        return p1.students.size() > p2.students.size();
    else
        return p1.name < p2.name;
}

void solve() {
    for (int i = 0; i <= N; i++) {
        for (set<string>::iterator iter = toDelete.begin(); iter != toDelete.end(); iter++) {
            set<string>::iterator pos = projects[i].students.find(*iter);
            if (pos != projects[i].students.end()) {
                projects[i].students.erase(pos);
            }
        }
    }
    sort(projects.begin(), projects.begin() + N + 1, cmp);
    for (int i = 0; i <= N; i++) {
        cout << projects[i].name << " " << projects[i].students.size() << endl;
    }
}

int main() {

    std::cout.sync_with_stdio(false);

    string temp;

    while (1) {
        getline(cin, temp);
        if (temp[0] == '0') break;
        if (temp[0] == '1') {
            solve();
            N = -1;
            projects.clear();
            appear.clear();
            toDelete.clear();
            continue;
        }
        if ('A' <= temp[0] && temp[0] <= 'Z') {
            projects.push_back(P(temp));
            N++;
            continue;
        }
        if ('a' <= temp[0] && temp[0] <= 'z') {
            if (appear.find(temp) != appear.end()) {
                if (projects[N].students.find(temp) == projects[N].students.end()) {
                    toDelete.insert(temp);
                }
            } else {
                projects[N].students.insert(temp);
                appear.insert(temp);
            }
            continue;
        }
    }


    return 0;
}                                 