// Problem#: 7974
// Submission#: 3593659
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Integer Lists
// Author: Thomas Beuman

// Time complexity: O(p+n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: use array, with pointers to first and last element

#include <cstdio>
using namespace std;

int L[100000];

int main()
{ int cases, casenr, n, i, first, last;
  bool reversed;
  char p[100001];
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { // Read input
    scanf("%s\n%d\n[", p, &n);
    for (i = 0; i < n; i++)
      scanf("%d%*c", &L[i]);
    scanf("%*c "); // Read redundant characters (']', newline)
    first = 0;
    last = n-1;
    reversed = false;
    // Process program
    for (i = 0; p[i] != '\0'; i++)
    { if (p[i] == 'R')
        reversed = !reversed;
      else if (reversed)
        last--;
      else
        first++;
    }
    // Output
    if (first > last+1)
      printf("error\n");
    else if (first == last+1) // Empty list
      printf("[]\n");
    else
    { if (reversed)
        for (i = last; i >= first; i--)
          printf("%c%d", i == last ? '[' : ',', L[i]);
      else
        for (i = first; i <= last; i++)
          printf("%c%d", i == first ? '[' : ',', L[i]);
      printf("]\n");
    }
  }
  return 0;
}                                 