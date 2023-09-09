// Choose Classes
// https://xjoi.net/contest/4848/problem/1
/*
Time：1s  Memory：128M
Description：
School has n classes. Class i has the start time Si and the end time Ei. At any given time, student can only attend one class, 
and can get the benefit only after attended the whole class.
There are conflicts between the class schedules, and parents want their kids to learn as much as they can. How to choose the 
classes so that the students can attend most number of the classes?

Input format：
First line: an integer n (n≤1000), the number of classes available to choose from.
Followed by n lines: 2 integers per line, Si and Ei (Si < Ei ≤ 32767)

Output format：
The max number of classes that a student can possibly attend.

Sample input：
3
0 6
0 4
4 8

Sample output：
2
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  vector<vector<int>> classes;
  for (int i=0; i<n; i++) {
    int x, y; cin>>x>>y;
    classes.push_back({y, x});
  }
  sort(classes.begin(), classes.end());
  int i=1; int left=classes[0][1]; int right=classes[0][0];
  int ans=1;
  while (i<n) {
    if (classes[i][1]>=right) {
      ans++;
      left=classes[i][1];
      right=classes[i][0];
      i++;
      continue;
    }
    else {
      i++;
    }
  }
  cout<<ans;
}