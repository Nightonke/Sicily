// Problem#: 1564
// Submission#: 3239971
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
#include <set>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int ans[] = {1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 9, 10, 13, 15, 18, 21, 26, 30, 36, 42, 50, 58, 70, 80, 95, 110, 129, 150, 176, 202, 236, 272, 317, 364, 423, 484, 560, 643, 740, 847, 975, 1112, 1277, 1456, 1666, 1897, 2168, 2464, 2809, 3189, 3627, 4112, 4673, 5287, 5995, 6778, 7671, 8662, 9791, 11037, 12457, 14029, 15810, 17782, 20015, 22482, 25270, 28360, 31833, 35683, 40010, 44795, 50170, 56116, 62772, 70140, 78381, 87490, 97663, 108913, 121450, 135310, 150747, 167788, 186747, 207681, 230927, 256590, 285063, 316460, 351267, 389642, 432126};

    int temp;
    cin >> temp;
    cout << ans[temp-5] << endl;
        
    //getchar();
    getchar();
    
    return 0;
}                                 