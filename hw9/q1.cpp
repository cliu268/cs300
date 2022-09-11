// Mice and holes https://xjoi.net/contest/4661/problem/1
/*
Description of the topic
There are n mice and m mouse holes. It is now stipulated that all mice can only go to the left, and only one mouse can enter 
one hole, ensuring that the number of holes is more than that of mice and that the position is not repeated and that each mouse 
has at least one hole.  
What is the minimum total distance for all the mice to enter the hole.

Input format
The first line contains two integers n, m (n <= 300000, n <= m <= 500000), the second line has n positive integers, 
and each positive integer represents the position of a mouse p (1 <= p <=109), the third line has m positive integers, 
and each positive integer represents the position q of a hole (1 <= q <= 109).

Output format
A number indicates the answer.

Sample input
3 5
6 7 10
1 2 5 8 9

Sample output
7
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
typedef long long ll;
using namespace std;
 
int main(void) {
    int n,m; scanf("%d %d", &n, &m);
    vector<int> mice(n);
    vector<int> holes(m);
    for (int i=n-1; i>=0; i--) {
        scanf("%d", &mice[i]);
    }
    for (int i=m-1; i>=0; i--) {
        scanf("%d", &holes[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto lower = lower_bound(holes.begin(), holes.end(), mice[i], greater<ll> ());
        ans += mice[i] - *lower;
        holes.erase(lower);
    }
    printf("%d", ans);
}