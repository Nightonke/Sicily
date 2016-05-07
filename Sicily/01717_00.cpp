// Problem#: 1717
// Submission#: 3585103
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
struct node {
    int start, len;
};

node arr[50100];

bool cmp(const node & n1, const node & n2) {
    if (n1.start != n2.start) return n1.start < n2.start;
    return n1.len < n2.len;
}

void process() {
    int i;
    long long time, sum = 0;
    for (i = 0; i < n; i++) scanf("%d%d", &arr[i].start, &arr[i].len);
    sort(arr, arr + n, cmp);
    time = arr[0].start;
    
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(arr[0].len);
    
    int index = 1;
    while (1) {
        while (!q.empty()) {
            i = q.top();
            q.pop();
            if (index >= n) {
                time += i;
                sum += time;
                continue;
            }
            if (time + i <= arr[index].start) {
                time += i;
                sum += time;
                continue;
            }
            i = i - (arr[index].start - time);
            q.push(i);
            i = index;
            time = arr[index].start;
            while (1) {
                if (arr[index].start != arr[i].start) break;
                q.push(arr[index].len);
                index++;
                if (index >= n) break;
            }
        }
        if (index < n) {
            time = arr[index].start;
            q.push(arr[index].len);
            index++;
        } else break;
    }
    printf("%lld\n", sum);
}

int main() {
    while (scanf("%d", &n) != EOF) process();
    return 0;
}                                 