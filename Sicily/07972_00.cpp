// Problem#: 7972
// Submission#: 3593656
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Good Coalition
// Author: Thomas Beuman

// Time complexity: O(150*n)
// Memory: O(150)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: Dynamic Programming

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int S = 150; // # seats

int Seats[S], Prob[S];
double MaxProb[S+1];

int main()
{ int cases, casenr, n, p, s;
  double m;
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { // Read input
    scanf("%d", &n);
    for (p = 0; p < n; p++)
      scanf("%d %d", &Seats[p], &Prob[p]);
    memset(MaxProb, 0, sizeof(MaxProb));
    MaxProb[0] = 1;
    // DP over parties and seats
    for (p = 0; p < n; p++)
      for (s = S; s >= Seats[p]; s--)
      // ^ Process in reverse to avoid using party p more than once
        // See if using party p is an improvement
        MaxProb[s] = max(MaxProb[s], Prob[p] / 100.0 * MaxProb[s-Seats[p]]);
    // Look for best majority
    m = 0;
    for (s = S; s > S/2; s--)
      m = max(m, MaxProb[s]);
    printf("%.6lf\n", m * 100.0);
  }
  return 0;
}                                 