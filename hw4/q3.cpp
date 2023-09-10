// Subarray Sums I
// https://xjoi.net/contest/4456/problem/3
/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input:
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a1,a2,…,an: the contents of the array.

Output:
Print one integer: the required number of subarrays.

Constraints:
1 ≤ n ≤ 2⋅10^5
1 ≤ x,ai ≤ 10^9

Example Input:
5 7
2 4 1 2 7

Example Output:
3

Hint:
Subarray Sums I hint: try starting from the first element as the subarray. 
If sum is too small, add element to the subarray from right. 
If sum is too big, remove element from left.
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, x; scanf("%d %d", &n, &x);
  vector<int> arr(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  int i=0; int sum=arr[i]; int j=0;
  int curr=0;
  int ans=0;
  map<vector<int>, bool> visited;
  while (i<=j && j<=n-1) {
    if (sum==x) {
      if (visited.find({i, j})!=visited.end()) {
        i=curr+1; j=i; sum=arr[curr+1];
        curr++;
        continue;
      }
      ans++;
      visited[{i, j}]=true;
      i++; j++;
      sum-=arr[i-1]; sum+=arr[j];
    }
    if (sum<x) {
      sum+=arr[j+1];
      j++;
    }
    if (sum>x) {
      sum-=arr[i];
      i++;
    }
  }
  printf("%d", ans);
}