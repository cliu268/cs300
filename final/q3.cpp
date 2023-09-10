// Convention
// https://xjoi.net/contest/4849/problem/3
// http://www.usaco.org/index.php?page=viewproblem2&cpid=858
/*
Farmer John is hosting a new bovine grass-eating convention at his farm!
Cows from all over the world are arriving at the local airport to attend the convention and eat grass. Specifically, there are N 
cows arriving at the airport (1≤N≤10^5) and cow i arrives at time ti (0≤ti≤10^9). Farmer John has arranged M (1≤M≤10^5) buses 
to transport the cows from the airport. Each bus can hold up to C cows in it (1≤C≤N). Farmer John is waiting with the buses at 
the airport and would like to assign the arriving cows to the buses. A bus can leave at the time when the last cow on it arrives. 
Farmer John wants to be a good host and so does not want to keep the arriving cows waiting at the airport too long. What is the 
smallest possible value of the maximum waiting time of any one arriving cow if Farmer John coordinates his buses optimally? 
A cow’s waiting time is the difference between her arrival time and the departure of her assigned bus.

It is guaranteed that MC≥N.

INPUT FORMAT (file convention.in):
The first line contains three space separated integers N, M, and C. The next line contains N space separated integers 
representing the arrival time of each cow.

OUTPUT FORMAT (file convention.out):
Please write one line containing the optimal minimum maximum waiting time for any one arriving cow.

SAMPLE INPUT:
6 3 2
1 1 10 14 4 3

SAMPLE OUTPUT:
4

If the two cows arriving at time 1 go in one bus, cows arriving at times 3 and 4 in the second, and cows arriving at times 10 and 
14 in the third, the longest time a cow has to wait is 4 time units (the cow arriving at time 10 waits from time 10 to time 14).

Problem credits: Grace Cai
Hint:
Convention: binary search on answers
For binary search on answers, you usually have to implement your own binary search procedure (with check(), see Week 7 and 8 
class examples). Cannot use std::lower_bound() or std::upper_bound()
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m, c; cin>>n>>m>>c;
  vector<int> arrival(n);
  for (int i=0; i<n; i++) {
    cin>>arrival[i];
  }
  sort(arrival.begin(), arrival.end());
  int i=0; int j=arrival[n-1];
  int ans=0;
  while (i<=j) {
    int middle=(i+j)/2;
    int first=arrival[0]; int index=0;
    int cars=1;
    for (int i=1; i<n; i++) {
      if ((arrival[i]-first)>middle || (i-index+1)>c) {
        first=arrival[i];
        cars++;
        index=i;
      }
    }
    if (cars>m) {
      i=middle+1;
    }
    else {
      j=middle-1;
      ans=middle;
    }
  }
  cout<<ans;
}