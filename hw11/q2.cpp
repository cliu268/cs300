// Why Did the Cow Cross the Road
// https://xjoi.net/contest/4848/problem/2
// http://www.usaco.org/index.php?page=viewproblem2&cpid=714
/*
Farmer John's cows are trying to learn to cross the road effectively. Remembering the old "why did the chicken cross the road?" 
joke, they figure the chickens must be experts on crossing the road, and go off in search of chickens to help them.

As it turns out, chickens are very busy creatures and have limited time to help the cows. There are C chickens on the farm 
(1≤C≤20,000), conveniently numbered 1…C, and each chicken i is only willing to help a cow at precisely time Ti. The cows, 
never in a hurry, have more flexibility in their schedules. There are N cows on the farm (1≤N≤20,000), conveniently numbered 1…N, 
where cow j is able to cross the road between time Aj and time Bj. Figuring the "buddy system" is the best way to proceed, each 
cow j would ideally like to find a chicken i to help her cross the road; in order for their schedules to be compatible, i and j 
must satisfy Aj ≤ Ti ≤ Bj.

If each cow can be paired with at most one chicken and each chicken with at most one cow, please help compute the maximum number 
of cow-chicken pairs that can be constructed.

INPUT FORMAT (file helpcross.in):
The first line of input contains C and N. The next C lines contain T1…TC, and the next N lines contain Aj and Bj (Aj ≤ Bj) 
for j=1…N. The A's, B's, and T's are all non-negative integers (not necessarily distinct) of size at most 1,000,000,000.

OUTPUT FORMAT (file helpcross.out):
Please compute the maximum possible number of cow-chicken pairs.

SAMPLE INPUT:
5 4
7
8
6
2
9
2 5
4 9
0 3
8 13

SAMPLE OUTPUT:
3

Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
using namespace std;
 
bool sortsecond(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second==b.second) {
    return a.first<b.first;
  }
  return (a.second<b.second);
}
 
int main() {
  int c, n; cin>>c>>n;
  vector<int> chickens(c);
  vector<pair<int, int>> cows;
  for (int i=0; i<c; i++) {
    cin>>chickens[i];
  }
  for (int i=0; i<n; i++) {
    int x, y; cin>>x>>y;
    pair<int, int> temp;
    temp.first=x;
    temp.second=y;
    cows.push_back(temp);
  }
  sort(cows.begin(), cows.end(), sortsecond);
  sort(chickens.begin(), chickens.end());
  int ans=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<chickens.size(); j++) {
      if (chickens[j]>=cows[i].first && chickens[j]<=cows[i].second) {
        ans++;
        chickens.erase(chickens.begin()+j);
        break;
      }
    }
  }
  cout<<ans;
}