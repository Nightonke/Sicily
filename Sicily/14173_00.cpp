// Problem#: 14173
// Submission#: 3763597
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

class CAR {
public:
    int catalogP, pick_upP, per_kmP;
    CAR(int catalogP = 0, int pick_upP = 0, int per_kmP = 0) {
        this->catalogP = catalogP;
        this->pick_upP = pick_upP;
        this->per_kmP = per_kmP;
    }
};

class SPY {
public:
    bool consistent;
    int pay;
    CAR * car;
    SPY(bool consistent = true, int pay = 0, CAR * car = NULL) {
        this->consistent = consistent;
        this->pay = pay;
        this->car = car;
    }
};

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {

        int N, M;
        cin >> N >> M;

        map<string, CAR> cars;
        map<string, SPY> spies;

        for (int i = 0; i < N; i++) {
            CAR tempCar;
            string tempS;
            cin >> tempS 
                >> tempCar.catalogP 
                >> tempCar.pick_upP 
                >> tempCar.per_kmP;
            cars[tempS] = tempCar;
        }

        for (int i = 0; i < M; i++) {
            int time;
            string spyName, operation;
            cin >> time >> spyName >> operation;

            if (spies.find(spyName) == spies.end()) spies[spyName] = SPY();
            
            if (operation[0] == 'p') {
                string carName;
                cin >> carName;
                SPY * theSpy = &spies[spyName];
                CAR * theCar = &cars[carName];

                if (!theSpy->consistent);
                else if (theSpy->car) theSpy->consistent = false;
                else theSpy->car = theCar;
            }
            else if (operation[0] == 'r') {
                int km;
                cin >> km;
                SPY * theSpy = &spies[spyName];

                if (!theSpy->consistent);
                else if (!theSpy->car) theSpy->consistent = false;
                else {
                    theSpy->pay += km * theSpy->car->per_kmP
                        + theSpy->car->pick_upP;
                    theSpy->car = NULL;
                }
            }
            else {
                int percent;
                cin >> percent;
                SPY * theSpy = &spies[spyName];

                if (!theSpy->consistent);
                else if (!theSpy->car) theSpy->consistent = false;
                else theSpy->pay += (int)ceil(percent * theSpy->car->catalogP / 100.0);
            }
        }

        for (map<string, SPY>::iterator iter = spies.begin(); iter != spies.end(); iter++) {
            cout << iter->first << " ";
            if (iter->second.consistent && !iter->second.car) cout << iter->second.pay << endl;
            else cout << "INCONSISTENT" << endl;
        }

    }

    return 0;
}                                 