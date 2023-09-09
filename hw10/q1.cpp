// Get Water
// https://xjoi.net/contest/4847/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6461&fragments=12041&problemId=8100
/*
Time limit：1s   Memory limit：128M
Description：
There are n persons lining in front of a faucet tap for water. Suppose it takes Ti time for person i to get water. 
Please program to find out the particular sequence of those persons in the line, so that the average waiting time for 
those n persons would be minimal.

Input：
The first line contains n.
The second line contains n integers, T1，T2，…，Tn (separated by a space) where Ti means the time it takes for each 
person i to get water.

Output：
The first line contains the sequence of those people in the line, an arrangement from 1 to n.
The second line is the average waiting time in this sequence (round to the hundredth).

Sample input 1：
10
56 12 1 99 1000 234 33 55 99 812

Sample output 1：
3 2 7 8 1 4 9 6 10 5
291.90

Note：
n<=1000
Ti<=1e6，the value of Ti may repeat.
In the case when Ti value is repeated, sorted them in the same order as input.
*/
// Etaw answer
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
 
struct Person {
  int position;
  int time;
  bool operator<(const Person& other) const {
    // Sort by time, then by oroginal position
    if (time != other.time) return time < other.time;
    return position < other.position;
  }
};
 
int main() {
  int n;
  cin >> n;
  Person persons[n];
 
  for (int i = 0; i < n; i++) {
    persons[i].position = i + 1;
    cin >> persons[i].time;
  }
  sort(persons, persons+n);
  double sum = 0;
  // 300B exercise
  for (int i=0; i<n; i++) {
    sum+=persons[i].time*(n-i-1);
    cout<<persons[i].position<<" ";
  }
  cout<<"\n";
  double average = sum / n;
  printf("%0.2lf", average);
}

// Ev answer by Etaw??
// #include <bits/stdc++.h>
// typedef long long ll;
// #define FOR(i, a, b) for (int i=a; i<b; i++)
// using namespace std;

// int main() {
//     // freopen("bruh.in", "r", stdin);
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int t=1;
//     // cin>>t;
//     while (t--) {
//         int n; cin>>n;
//         vector<pair<int, int>> v(n);
//         FOR(i, 0, n) {
//             int x; cin>>x;
//             v[i]={x, i+1};
//         }
//         sort(v.begin(), v.end());
//         double curr=0; int sum=0;
//         FOR(i, 1, n) {
//             sum+=v[i-1].first;
//             curr+=sum;
//         }
//         for (auto i : v) {
//             printf("%d ", i.second);
//         }
//         printf("\n");
//         curr/=(double)n;
//         printf("%.2f \n", curr);
//     }
// }