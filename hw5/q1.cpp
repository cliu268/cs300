// Remove duplication and sort
// https://xjoi.net/contest/4492/problem/1
/*
Description：
Given n numbers, please remove the duplications and sort the number in assending order.

Input:
First line enters an integer n. 
Second line enters n numbers.

Output:
One line, numbers sorted in assending order.

Sample input:
4
1 4 4 3

Sample output:
1 3 4

Constraints:
1 <= n <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  map<int, bool> visited;
  vector<int> arr;
  for (int i=0; i<n; i++) {
    int x; cin>>x;
    if (visited.find(x)==visited.end()) {
      visited[x]=true;
      arr.push_back(x);
    }
  }
  sort(arr.begin(), arr.end());
  for (int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
}