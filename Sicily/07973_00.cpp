// Problem#: 7973
// Submission#: 3593658
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Hot Dogs in Manhattan
// Author: Thomas Beuman

// Time complexity: O(w*h*log(w+h))
// Memory: O(w*h)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

First determine all current privacies by doing a "floodfill":
The Manhattan distance is the length of the shortest path along the grid.
Starting from all given points, use BFS find the shortest pathlength for all other points.

Do a binary search over the final answer:
Set a target privacy; consider all points that have this privacy or a larger one.
Now we want to see if there are two such points that are far enough apart.
For this, we only need to consider points which have the smallest/largest y-coordinate for each x-coordinate.
These are at most 2w such points; we can then try all pairs.
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int Privacy[1000][1000];
int BFSqueue[1000000][2];
int ToCheck[2000][2];

int main()
{ int cases, casenr, n, w, h, i, j, x, y, x2, y2, p, current, last, m;
  int lowerbound, upperbound, target;
  int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
  bool possible;
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d %d %d", &n, &w, &h);
    memset(Privacy, 127, sizeof(Privacy)); // Set all privacies to "infinity"
    for (i = 0; i < n; i++)
    { scanf("%d %d", &x, &y);
      Privacy[x][y] = 0;
      BFSqueue[i][0] = x;
      BFSqueue[i][1] = y;
    }
    // Calculate all current privacies with BFS
    last = n;
    for (current = 0; current < last; current++)
    { x = BFSqueue[current][0];
      y = BFSqueue[current][1];
      p = Privacy[x][y];
      for (i = 0; i < 4; i++) // Check all neighboring points
      { x2 = x + dx[i];
        y2 = y + dy[i];
        if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && Privacy[x2][y2] > p+1)
        { Privacy[x2][y2] = p+1;
          BFSqueue[last][0] = x2;
          BFSqueue[last][1] = y2;
          last++;
        }
      }
    }
    // Binary search over answer
    lowerbound = 1;
    upperbound = w+h-1;
    while (lowerbound + 1 < upperbound)
    { target = (lowerbound + upperbound) / 2;
      m = 0;
      // For every column, only consider the two points with highest/lowest y-coordinate
      for (x = 0; x < w; x++)
      { for (y = 0; y < h && Privacy[x][y] < target; y++);
        if (y < h)
        { ToCheck[m][0] = x;
          ToCheck[m][1] = y;
          m++;
          for (y = h-1; Privacy[x][y] < target; y--);
          ToCheck[m][0] = x;
          ToCheck[m][1] = y;
          m++;
        }
      }
      // Try every possible combination
      possible = false;
      for (i = 1; i < m; i++)
        for (j = 0; j < i; j++)
          if (abs(ToCheck[i][0] - ToCheck[j][0]) + abs(ToCheck[i][1] - ToCheck[j][1]) >= target)
            possible = true;
      if (possible)
        lowerbound = target;
      else
        upperbound = target;
    }
    printf("%d\n", lowerbound);
  }
  return 0;
}                                 