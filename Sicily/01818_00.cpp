// Problem#: 1818
// Submission#: 2754583
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <map>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

void print(int a) {
    if (a < 0 || a > 100)
        cout << "Score is error!" << endl;
    else if (0 <= a && a < 60)
        cout << "E" << endl;
    else if (60 <= a && a < 70)
        cout << "D" << endl;
    else if (70 <= a && a  < 80)
        cout << "C" << endl;
    else if (80 <= a && a  < 90)
        cout << "B" << endl;
    else if (90 <= a && a  <= 100)
        cout << "A" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    int case_num, man_num, ques_num, temp_p;
    
    cin >> case_num;
    
    while (case_num--) {
        
        string name;
        map<string, int> m_m;
        map<string, int> :: iterator mm;
        cin >> man_num >> ques_num;
        
        while (man_num--) {
            
            cin >> name >> temp_p;
            if (m_m.find(name) == m_m.end())
                m_m.insert(pair<string, int>(name, temp_p));
            else
                (*m_m.find(name)).second = temp_p;
            
        }
        while (ques_num--) {
            cin >> name;
            print(m_m[name]);
        }
        
    }
    return 0;
}                                 