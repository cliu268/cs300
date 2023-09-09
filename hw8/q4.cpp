// Wormhole Sort
// https://xjoi.net/contest/4660/problem/4
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6461&fragments=12041&problemId=15442
/*
Farmer John's cows have grown tired of his daily request that they sort themselves before leaving the barn each morning. They 
have just completed their PhDs in quantum physics, and are ready to speed things up a bit.

This morning, as usual, Farmer John's N cows (1≤N≤10^5), conveniently numbered 1…N, are scattered throughout the barn at N 
distinct locations, also numbered 1…N, such that cow i is at location pi. But this morning there are also M wormholes (1≤M≤10^5), 
numbered 1…M, where wormhole i bidirectionally connects location ai with location bi, and has a width 
wi (1≤ai,bi≤N,ai≠bi,1≤wi≤10^9).

At any point in time, two cows located at opposite ends of a wormhole may choose to simultaneously swap places through the 
wormhole. The cows must perform such swaps until cow i is at location i for 1≤i≤N.

The cows are not eager to get squished by the wormholes. Help them maximize the width of the least wide wormhole which they 
must use to sort themselves. It is guaranteed that it is possible for the cows to sort themselves.

SCORING:
Test cases 3-5 satisfy N,M≤1000.
Test cases 6-10 satisfy no additional constraints.

INPUT FORMAT (file wormsort.in):
The first line contains two integers, N and M.
The second line contains the N integers p1,p2,…,pN. It is guaranteed that p is a permutation of 1…N.
For each i between 1 and M, line i+2 contains the integers ai, bi, and wi.

OUTPUT FORMAT (file wormsort.out):
A single integer: the maximum minimal wormhole width which a cow must squish itself into during the sorting process. If the cows 
do not need any wormholes to sort themselves, output −1.

SAMPLE INPUT:
4 4
3 2 1 4
1 2 9
1 3 7
2 3 10
2 4 3

SAMPLE OUTPUT:
9
Here is one possible way to sort the cows using only wormholes of width at least 9:
Cow 1 and cow 2 swap positions using the third wormhole.
Cow 1 and cow 3 swap positions using the first wormhole.
Cow 2 and cow 3 swap positions using the third wormhole.

SAMPLE INPUT:
4 1
1 2 3 4
4 2 13

SAMPLE OUTPUT:
-1
No wormholes are needed to sort the cows.

Problem credits: Dhruv Rohatgi
For wormhole search, you do not have to use binary search. Linear search with DSU will be fine.
*/
// Etaw wrong answer 10/100
#include <algorithm>
#include <iostream>
using namespace std;
 
int n, m;
const int MAXN = 100001;
struct Wormhole {
  int a, b, width;
};
bool CompareWormhole(Wormhole w1, Wormhole w2) { return w1.width > w2.width; }
 
// Global array initialized to zeros.
int swap_groups[MAXN], l[MAXN];
// Standard DSU implementation of find() and unite().
int find(int x) {
  return x == swap_groups[x] ? x : swap_groups[x] = find(swap_groups[x]);
}
void unite(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);
  if (root_x != root_y)
    swap_groups[root_x] = root_y;
}
 
bool verify() {
  for (int i = 1; i <= n; i++) {
    if (i != l[i] && find(i) != find(l[i]))
      return false;
  }
  return true;
}
 
int main() {
  cin >> n >> m;
  int out_space_cow_count = 0;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    if (l[i] != i)
      out_space_cow_count++;
  }
 
  Wormhole wormholes[m];
  for (int i = 0; i < m; i++) {
    cin >> wormholes[i].a >> wormholes[i].b >> wormholes[i].width;
  }
  if (out_space_cow_count == 0) {
    cout << -1 << endl;
    return 0;
  }
 
  // Sort all wormholes by width from widest to narrowest.
  sort(wormholes, wormholes + m, CompareWormhole);
 
  // Initial swap group membership.
  for (int i = 1; i <= n; i++)
    swap_groups[i] = i;
 
  int max_wormhole_width = -1;
 
  // Linear search for max wormhole width.
  // for (int i = 0; i < m; i++) {
  //   // DSU unite of swap group membership.
  //   unite(wormholes[i].a, wormholes[i].b);
  //   max_wormhole_width = wormholes[i].width;
  //   if (verify())
  //     break;
  // }
  int left=0; int right=m-1;
  while (left<=right) {
    int middle=(left+right)/2;
    unite(wormholes[middle].a, wormholes[middle].b);
    if (verify()) {
      max_wormhole_width=wormholes[middle].width;
      left=middle+1;
    }
    else {
      right=middle-1;
    }
  }
 
  cout << max_wormhole_width << endl;
}