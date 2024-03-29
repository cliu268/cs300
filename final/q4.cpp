// Milk Visits
// https://xjoi.net/contest/4849/problem/4
// http://www.usaco.org/index.php?page=viewproblem2&cpid=968
/*
Farmer John is planning to build N (1≤N≤10^5) farms that will be connected by N−1 roads, forming a tree (i.e., all farms are 
reachable from each-other, and there are no cycles). Each farm contains a cow, whose breed is either Guernsey or Holstein.

Farmer John's M friends (1≤M≤10^5) often come to visit him. During a visit with friend i, Farmer John will walk with his friend 
along the unique path of roads from farm Ai to farm Bi (it may be the case that Ai=Bi). Additionally, they can try some milk 
from any cow along the path they walk. Since most of Farmer John's friends are also farmers, they have very strong preferences 
regarding milk. Some of his friends will only drink Guernsey milk, while the remainder will only drink Holstein milk. Any of Farmer 
John's friends will only be happy if they can drink their preferred type of milk during their visit.

Please determine whether each friend will be happy after visiting.

SCORING:
Test cases 2-5 satisfy N≤10^3,M≤2⋅10^3.

INPUT FORMAT (file milkvisits.in):
The first line contains the two integers N and M.
The second line contains a string of length N. The ith character of the string is 'G' if the cow in the ith farm is a Guernsey, 
or 'H' if the cow in the ith farm is a Holstein.

The next N−1 lines each contain two distinct integers X and Y (1≤X,Y≤N), indicating that there is a road between farms X and Y.

The next M lines contain integers Ai, Bi, and a character Ci. Ai and Bi represent the endpoints of the path walked during 
friend i's visit, while Ci is either G or H if the ith friend prefers Guernsey milk or Holstein milk.

OUTPUT FORMAT (file milkvisits.out):
Print a binary string of length M. The ith character of the string should be '1' if the ith friend will be happy, or '0' otherwise.

SAMPLE INPUT:
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H

SAMPLE OUTPUT:
10110

Here, the path from farm 1 and farm 4 involves farms 1, 2, and 4. All of these contain Holsteins, so the first friend will be 
satisfied while the second one will not.

Problem credits: Spencer Compton
Hint:
Milk visits: DSU
What kind of farms should be unite()’ed into a subset? Connected? Contains cows of the same breed?
Use the DSU implementation we learned in Week 11 class https://replit.com/@HarryLuo/DSU-impl#main.cpp
*/
// Etaw TLE solution 8/100
#include <bits/stdc++.h>
using namespace std;
 
int GetParent(int x, vector<int> vect) {
  if (vect[x]==x) {
    return x;
  }
  return GetParent(vect[x], vect);
}
void Unite(int x, int y, vector<int> &vect) {
  vect[GetParent(x, vect)]=GetParent(y, vect);
}
 
int main() {
  int n, m; scanf("%d %d", &n, &m);
  string s; cin>>s;
  vector<int> parent(n+1);
  vector<int> reverse(n+1);
  for (int i=0; i<=n; i++) {
    parent[i]=i;
    reverse[i]=i;
  }
  for (int i=0; i<n-1; i++) {
    int x, y; scanf("%d %d", &x, &y);
    if (parent[y]!=y) {
      Unite(y, x, parent);
      continue;
    }
    if (parent[x]==x) {
      reverse[x]=y;
    }
    parent[y]=x;
  }
  for (int i=0; i<m; i++) {
    int a, b; scanf("%d %d", &a, &b);
    char c; cin>>c;
    if (a==b) {
      cout<<(s[a-1]==c);
      continue;
    }
    int j=b; bool broke=false;
    while(j<n) {
      if (s[j-1]==c) {
        printf("%d", 1);
        broke=true;
        break;
      }
      if (j==a) {
        break;
      }
      if (parent[j]==j) {
        j=reverse[j];
      }
      j=parent[j];
    }
    if (!broke) {
      printf("%d", 0);
    }
  }
}