// Problem#: 1264
// Submission#: 3294574
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        int a[n + 1];
        a[0] = 0;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        int r;
        double b,v,e,f;
        cin >> b >> r >> v >> e >> f;
        double t[a[n] + 1]; //t[k] is the total time the car moves k kilometers without changing tires.
        t[0] = 0;
        for(int i = 1;i <= a[n];i++){
            if(i - 1 < r)
                t[i] = t[i - 1] + 1 / (v - f * (r - (i - 1)));
            else
                t[i] = t[i - 1] + 1 / (v - e * ((i - 1) - r));
        }
        double s[n + 1][n + 1]; //s[i][j] is the shortest time move from point ai to aj.
        //calculate s in button-up method.
        for(int i = 0;i < n + 1;i++)
            s[i][i] = 0;
        for(int l = 1;l <= n;l++){//length from 1 to n.
            for(int i = 0;i <= n - l;i++){
                int j = i + l;
                double min = t[a[j] - a[i]];
                for(int k = i + 1;k < j;k++){
                    if(b + s[i][k] + s[k][j] < min){
                        min = b + s[i][k] + s[k][j];
                    }
                }
                s[i][j] = min;
            }
        }
        cout << fixed << setprecision(4) << s[0][n] << endl;
    }
    return 0;
}                                 