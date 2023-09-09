// Angry Cows
// https://xjoi.net/contest/4660/problem/2
/*
Time limit：1s   Memory limit：512M
Description：
Farmer John built a cottage that has n cowsheds (all in the same line). The i-th cowshed lies in xi. There are m cows who are 
not satisfied with their cowsheds and constantly attack each other. John doesn't want his cows to hurt each other, so he decided 
to separate those cows and maximize the distance between the closest two cows. Find out the maximum distance between the closest 
two cows.

Input：
The first line contains two integers n and m, separated by space
The second line contains n integers---the position xi (separated by space)

Output：
an integer---the maximum distance between the closest two cows

Sample input：
5 3
1 2 8 4 9

Sample output：
3

Note：
Place the cows to 1, 4 ,8. Therefore the smallest distance would be 3
note：
2≤n≤10^5, 0≤xi​≤10^9, 2≤m≤n
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m; cin>>n>>m;
  vector<int> cows(n);
  for (int i=0; i<n; i++) {
    cin>>cows[i];
  }
  sort(cows.begin(), cows.end());
  int left=1; int right=cows[n-1];
  int ans=0;
  while (left<=right) {
    int middle=(left+right)/2;
    int counter=1;
    int i=0;
    while (i<n) {
      bool found=false; int newIndex;
      for (int j=i+1; j<n; j++) {
        if ((cows[j]-cows[i])>=middle) {
          found=true;
          newIndex=j;
          counter++;
          break;
        }
      }
      if (!found) {
        break;
      }
      else {
        i=newIndex;
      }
    }
    if (counter>=m) {
      ans=max(ans, middle);
      left=middle+1;
    }
    else {
      right=middle-1;
    }
  }
  cout<<ans;
}