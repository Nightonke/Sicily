// Problem#: 7966
// Submission#: 3593634
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Another Dice Game
// Author: Thomas Beuman

// Time complexity: O((n * dice * 2^6) * bin(n+5,5) *    6   )
//                  O(     states      *   throws   * options)
// Memory: O(n * dice * 2^6)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: DFS with memorization

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef double dbl; // Use long double for greater accuracy

dbl Prob[41][9][64];
bool Seen[41][9][64];
int Points[6] = {1,2,3,4,5,5};
int Factorial[9] = {1,1,2,6,24,120,720,5040,40320};

// Returns probability of reaching target, given number of dice and values not yet put aside
dbl prob (int target, int dice, int available)
{ if (target <= 0 && !(available & 32)) // Target reached and worm put aside
    return 1.0;
  if (dice == 0) // Failed
    return 0;
  if (target < 0) // Only a worm left to get
    target = 0;
  if (Seen[target][dice][available]) // Already calculated
    return Prob[target][dice][available];
  int Number[6];
  int i, perm;
  dbl best, p = 0;
  // Consider all possible outcomes of the throw
  // First possibility: all ones
  Number[0] = dice;
  for (i = 1; i < 6; i++)
    Number[i] = 0;
  while (true)
  { // Determine number of permutations (= weight factor)
    perm = Factorial[dice];
    for (i = 0; i < 6; i++)
      perm /= Factorial[Number[i]];
    // Look for best strategy: try all options
    best = 0;
    for (i = 0; i < 6; i++)
      if ((available & (1 << i)) && Number[i] > 0)
        best = max(best, prob(target - Number[i]*Points[i], dice - Number[i], available ^ (1 << i)));
    p += perm * best;
    // Next possible outcome
    for (i = 0; Number[i] == 0; i++); // Look for smallest value
    if (i == 5)
      break; // Done
    Number[i+1]++; // Increase value of one die with smallest value by one
    Number[0] = Number[i]-1; // Turn others into ones
    if (i > 0)
      Number[i] = 0;
  }
  Seen[target][dice][available] = true;
  return Prob[target][dice][available] = p / pow(6.0, dice);
}

int main()
{ int cases, casenr, n;
  scanf("%d\n", &cases);
  memset(Seen, false, sizeof(Seen));
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d", &n);
    printf("%.10lf\n", prob(n, 8, 63));
  }
  return 0;
}                                 