// Problem#: 7967
// Submission#: 3593635
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to John's Book Stack
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

Look for topmost unsorted book, put it in its correct place, calculate how many steps this takes.
Repeat until the entire stack is sorted.

This solution uses a list.
*/

#include <cstdio>
#include <list>
using namespace std;

typedef long long i64;

int main()
{ int cases, casenr, n, i, k, b;
  i64 steps, s;
  list<int>::iterator p, q, p2, q2;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d\n", &n);
    list<int> Stack;
    for (i = 0; i < n; i++)
    { scanf("%d", &b);
      Stack.push_back(b);
    }
    steps = 0;
    while (true)
    { for (p = p2 = Stack.begin(), p++; p != Stack.end() && *p >= *p2; p++, p2++); // Look for topmost unsorted book
      if (p == Stack.end()) // Done
        break;
      // Compute number of steps needed to put it in the right place
      s = 1ll;
      k = 2;
      for (q = q2 = Stack.begin(), q2++; *q < *p; q++, q2++)
      { if (*q == *q2)
          k++;
        else
        { s *= k;
          k = 2;
        }
      }
      steps += s;
      // Put it (p) in its correct place (q)
      Stack.insert(q, *p);
      Stack.erase(p);
    }
    printf("%lld\n", steps);
  }
  return 0;
}                                 