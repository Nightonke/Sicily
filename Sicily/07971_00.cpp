// Problem#: 7971
// Submission#: 3593653
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Solution to Fire
// Author: Thomas Beuman

// Time complexity: O(w*h)
// Memory: O(w*h)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: BFS

#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
#define mpii make_pair<int,int>

char Map[1000][1001];
pii BFSqueue[1000000]; // Breadth-first search queue

int main()
{ int cases, casenr, w, h, i, j, i2, j2, d, current, last, distance, scope;
  int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
  bool exitfound;
  pii start, loc;
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { // Read input
    scanf("%d %d", &w, &h);
    for (i = 0; i < h; i++)
      scanf("%s", Map[i]);
    // Put squares with fire on the BFS queue
    last = 0;
    for (i = 0; i < h; i++)
      for (j = 0; j < w; j++)
      { if (Map[i][j] == '*')
          BFSqueue[last++] = mpii(i, j);
        else if (Map[i][j] == '@')
          start = mpii(i, j);
      }
    BFSqueue[last++] = start; // Add the starting position
    // (The starting position goes after the fire, because the fire moves before you do)
    distance = 0; // The distance to all elements in the BFS queue...
    scope = last; // ...up to element #scope
    exitfound = false;
    for (current = 0; !exitfound && current < last; current++)
    { if (current == scope) // Reached the end of the scope:
      { distance++; // Increase the distance
        scope = last; // Reset the scope to the (current) last element
      }
      loc = BFSqueue[current];
      i = loc.first;
      j = loc.second;
      // Try all four directions
      for (d = 0; d < 4; d++)
      { i2 = i + di[d];
        j2 = j + dj[d];
        if (i2 < 0 || i2 >= h || j2 < 0 || j2 >= w) // Out of bounds
        { if (Map[i][j] == '@') // If it's you...
            exitfound = true; // ...you made it!
        }
        else if (Map[i2][j2] == '.') // Unprocessed square
        { Map[i2][j2] = Map[i][j]; // Expand fire / your possible locations
          BFSqueue[last++] = mpii(i2, j2); // Add to BFS queue
        }
      }
    }
    // Output
    if (exitfound)
      printf("%d\n", distance + 1);
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}                                 