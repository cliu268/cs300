// Lemonade Line
// https://xjoi.net/contest/4849/problem/2
// http://www.usaco.org/index.php?page=viewproblem2&cpid=835
/*
It's a hot summer day out on the farm, and Farmer John is serving lemonade to his N cows! All N cows (conveniently numbered 1…N) 
like lemonade, but some of them like it more than others. In particular, cow i is willing to wait in a line behind at most wi cows 
to get her lemonade. Right now all N cows are in the fields, but as soon as Farmer John rings his cowbell, the cows will immediately 
descend upon FJ's lemonade stand. They will all arrive before he starts serving lemonade, but no two cows will arrive at the 
same time. Furthermore, when cow i arrives, she will join the line if and only if there are at most wi cows already in line.

Farmer John wants to prepare some amount of lemonade in advance, but he does not want to be wasteful. The number of cows who join 
the line might depend on the order in which they arrive. Help him find the minimum possible number of cows who join the line.

INPUT FORMAT (file lemonade.in):
The first line contains N, and the second line contains the N space-separated integers w1,w2,…,wN. It is guaranteed that 1≤N≤10^5, 
and that 0≤wi≤10^9 for each cow i.

OUTPUT FORMAT (file lemonade.out):
Print the minimum possible number of cows who might join the line, among all possible orders in which the cows might arrive.

SAMPLE INPUT:
5
7 1 400 2 2

SAMPLE OUTPUT:
3

In this setting, only three cows might end up in line (and this is the smallest possible). Suppose the cows with w=7 and w=400 
arrive first and wait in line. Then the cow with w=1 arrives and turns away, since 2 cows are already in line. The cows with w=2 
then arrive, one staying and one turning away.

Problem credits: Dhruv Rohatgi

Hint:
Lemonade Line: find the minimum possible number of cows, not the maximum!
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  vector<int> wait(n);
  for (int i=0; i<n; i++) {
    cin>>wait[i];
  }
  sort(wait.begin(), wait.end(), greater<int> ());
  queue<int> line;
  int i=0;
  while (i<n) {
    if (line.size()<=wait[i]) {
      line.push(i);
    }
    i++;
  }
  cout<<line.size();
}