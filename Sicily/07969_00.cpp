// Problem#: 7969
// Submission#: 3593648
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Digit Sum
// Author: Thomas Beuman

// Time complexity: O(log b)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

Compute the digitsum from 0 to b and from 0 to a-1, and subtract the two

Determine the digitsum from 0 to n-1 recursively:
Example:
digitsum(125) = digitsum(120) + sumofdigits(120) + sumofdigits(121) + ... + sumofdigits(124)
  digitsum(120) = 10 * digitsum(12) + (0+1+2+3+4+5+6+7+8+9) * 12
  sumofdigits(120) + sumofdigits(121) + ... + sumofdigits(124) = 5 * sumofdigits(12) + (0+1+2+3+4)
*/

#include <cstdio>
using namespace std;

typedef long long i64;

// Returns the sum of the digits of n
i64 sumofdigits (i64 n)
{ return n ? n%10 + sumofdigits(n/10) : 0;
}

// Returns the sum of all digits from 0 to n-1
i64 digitsum (i64 n)
{ return n < 10 ? n*(n-1)/2
                : digitsum(n%10) + 45 * (n/10) // Last digit
                  + (n%10) * sumofdigits(n/10) + 10 * digitsum(n/10); // Other digits
}

int main()
{ int cases, casenr;
  i64 a, b;
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%lld %lld", &a, &b);
    printf("%lld\n", digitsum(b+1) - digitsum(a));
  }
  return 0;
}                                 