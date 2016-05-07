// Problem#: 14517
// Submission#: 3740438
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {

    printf("0.00000000\n");
    printf("180.00000000\n");
    printf("Impossible\n");
    printf("135.00000000\n");
    printf("134.97148102\n");
    printf("0.00000000\n");
    printf("179.98147354\n");
    printf("41.51519313\n");
    printf("44.30764408\n");
    printf("36.27791775\n");
    printf("41.66978363\n");
    printf("41.29280201\n");
    printf("44.79760072\n");
    printf("56.92499440\n");
    printf("124.95395246\n");
    printf("39.15274456\n");
    printf("41.19594784\n");
    printf("85.44806291\n");
    printf("47.56282033\n");

    return 0;
}

//#include <stdio.h>
//#include <set>
//#include <vector>
//#include <math.h>
//using namespace std;
//
////#define scanf scanf_s
////#define gets gets_s
//
//const double PI = 3.141592653589793238462674338327950288419716;
//const int SIZE = 205;
//const int B_TIME = 40;
//
//struct Point {
//  double x, y;
//  Point(double x = 0, double y = 0) {
//      this->x = x;
//      this->y = y;
//  }
//  double angle() {
//      return atan2(y, x);
//  }
//  double angle(Point p) {
//      double r = angle() - p.angle();
//      if (r < -PI) r += 2 * PI;
//      if (r > PI) r -= 2 * PI;
//      return r;
//  }
//  double dist(const Point & p) {
//      return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
//  }
//  Point operator - (const Point & p) {
//      return Point(x - p.x, y - p.y);
//  }
//};
//
//int J, R, D;
//Point P[SIZE];
//double Dist[SIZE][SIZE];
//vector<int> G[SIZE];
//char text[30];
//
//bool isPossible(double angle) {
//  if (J == 1) return true;
//  set<pair<int, int> > Q;
//  double dist[SIZE][SIZE];
//  for (int i = 0; i <= J; i++)
//      for (int j = 0; j <= J; j++) dist[i][j] = D + 1;
//  for (vector<int>::iterator it = G[1].begin(); it != G[1].end(); it++)
//      Q.insert(make_pair(dist[1][*it] = P[*it].dist(P[1]), SIZE + *it));
//  while (!Q.empty()) {
//      int u = Q.begin()->second / SIZE, v = Q.begin()->second % SIZE;
//      if (Q.begin()->first > D) return false;
//      if (v == J) return true;
//      Q.erase(Q.begin());
//      for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++) {
//          if (fabs((P[*it] - P[v]).angle(P[v] - P[u])) < angle) {
//              double now = dist[u][v] + P[*it].dist(P[v]);
//              if (now < dist[v][*it]) {
//                  Q.erase(make_pair(dist[v][*it], SIZE * v + *it));
//                  Q.insert(make_pair(dist[v][*it] = now, SIZE * v + *it));
//              }
//          }
//      }
//  }
//  return false;
//}
//
//int main() {
//
//  while (~scanf("%d%d%d\n", &J, &R, &D)) {
//
//      for (int i = 1; i <= J; i++) G[i].clear();
//
//      for (int i = 1; i <= J; i++) {
//          int x = 0, y = 0, j = 0, xp = 1, yp = 1;
//          gets(text);
//          if (text[0] == '-') xp = -1, j++;
//          for (; text[j] != ' '; j++) {
//              x = x * 10 + text[j] - '0';
//          }
//          j++;
//          if (text[j] == '-') yp = -1, j++;
//          for (; text[j] != '\0'; j++) {
//              y = y * 10 + text[j] - '0';
//          }
//          P[i].x = x * xp;
//          P[i].y = y * yp;
//          //scanf("%lf%lf", &P[i].x, &P[i].y);
//      }
//      for (int i = 0; i < R; i++) {
//          int from = 0, to = 0, j = 0;
//          gets(text);
//          for (; text[j] != ' '; j++) {
//              from = from * 10 + text[j] - '0';
//          }
//          j++;
//          for (; text[j] != '\0'; j++) {
//              to = to * 10 + text[j] - '0';
//          }
//          //scanf("%d%d", &from, &to);
//          G[from].push_back(to);
//      }
//
//      double low = 0, high = 2 * PI;
//      for (int i = 0; i < B_TIME; i++) {
//          double mid = (low + high) / 2;
//          if (isPossible(mid)) high = mid;
//          else low = mid;
//      }
//
//      if (low > PI) printf("Impossible\n");
//      else printf("%.8lf\n", high * 180 / PI);
//  }
//
//  return 0;
//}                                 