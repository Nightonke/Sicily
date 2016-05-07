// Problem#: 13859
// Submission#: 3652545
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<set<string> > adj;  // all adjectives
vector<int> adjNum;  // adjective number
set<vector<string> > nonExist;  // the nonexisted adjectives

int main() {
    std::ios::sync_with_stdio(false);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string temp;
        vector<string> adjTemps;  // adj in a sentence, horizontal
        int pos = 0;
        while (temp != "no") cin >> temp;
        while (1) {
            cin >> temp;
            if (temp == "cow.") break;
            adjTemps.push_back(temp);
            if (pos >= adj.size()) {
                set<string> adjEachPos;  // adj at a position, vertical
                adjEachPos.insert(temp);
                adj.push_back(adjEachPos);
            }
            else {
                adj[pos].insert(temp);
            }
            pos++;
        }
        nonExist.insert(adjTemps);
    }

    if (n == 1) return 0;
    
    adjNum.resize(adj.size());
    for (int i = adj.size() - 1, num = 1; i >= 0; i--) {
        adjNum[i] = num;
        num *= adj[i].size();
    }

    vector<int> nonExistPos;
    for (set<vector<string> >::iterator iter = nonExist.begin(); iter != nonExist.end(); iter++) {
        int num = 0;  // the order number of a string of adj which is nonexisted
        for (int i = 0; i < iter->size(); i++) {
            int pos = 0;
            for (set<string>::iterator iter2 = adj[i].begin(); iter2 != adj[i].end(); iter2++) {
                if (*iter2 != (*iter)[i]) pos++;
                else break;
            }
            num += pos * adjNum[i];
        }
        nonExistPos.push_back(num);
    }
    k--;  // NO.1 is at the 0 position
    sort(nonExistPos.begin(), nonExistPos.end());
    for (int i = 0; i < nonExistPos.size(); i++) {
        if (nonExistPos[i] <= k) k++;
    }

    for (int i = 0; i < adj.size(); i++) {
        int pos = k / adjNum[i];
        k %= adjNum[i];
        for (set<string>::iterator iter = adj[i].begin(); iter != adj[i].end(); iter++) {
            if (pos == 0) {
                if (i) cout << " ";
                cout << *iter;
                break;
            }
            pos--;
        }
    }
    cout << endl;

    return 0;
}                                 