// Breed Counting
// https://xjoi.net/contest/4359/problem/1
// http://www.usaco.org/index.php?page=viewproblem2&cpid=572
/*
Farmer John's N cows, conveniently numbered 1…N, are all standing in a row (they seem to do so often that it now takes very 
little prompting from Farmer John to line them up). Each cow has a breed ID: 1 for Holsteins, 2 for Guernseys, and 3 for 
Jerseys. 
Farmer John would like your help counting the number of cows of each breed that lie within certain intervals of the ordering.

INPUT FORMAT (file bcount.in):
The first line of input contains N and Q (1≤N≤100,000, 1≤Q≤100,000).
The next N lines contain an integer that is either 1, 2, or 3, giving the breed ID of a single cow in the ordering.
The next Q lines describe a query in the form of two integers a,b (a≤b).

OUTPUT FORMAT (file bcount.out):
For each of the Q queries (a,b), print a line containing three numbers: the number of cows numbered a…b that are 
Holsteins (breed 1), Guernseys (breed 2), and Jerseys (breed 3).

SAMPLE INPUT:
6 3
2
1
1
3
2
1
1 6
3 3
2 4

SAMPLE OUTPUT:
3 2 1
1 0 0
2 0 1

Problem credits: Nick Wu
*/
// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <map>
// #include <set>
// using namespace std;

// int main(void) {
//     // freopen("bcount.in", "r", stdin);
//     // freopen("bcount.out", "w", stdout);    
//     int n, q;
//     cin >> n >> q;
//     vector<int> cows(n);
//     vector<int[3]> breed(n);

//     for (int i = 0; i < n; i++) {
//         cin >> cows[i];
//         if (i == 0) {
//             breed[i][cows[i]-1] = 1;
//         } else {
//             breed[i][0] = breed[i-1][0];
//             breed[i][1] = breed[i-1][1];
//             breed[i][2] = breed[i-1][2];
//             breed[i][cows[i]-1] = breed[i-1][cows[i]-1] + 1;
//         }
//     }
//     for (int i = 0; i < q; i++) {
//         int answer[3] = {0,0,0};
//         int start, end;
//         cin >> start >> end;
//         // brute force solution
//         /*
//         for (int j = start - 1; j < end; j++) {
//             answer[cows[j] - 1] += 1;
//         }
//         cout << answer[0] << " " << answer[1] << " " << answer[2] << endl;
//         */
//         // prefix sum solution
//         if (start == 1) cout << breed[end-1][0] << " " << breed[end-1][1] << " " << breed[end-1][2] << endl;
//         else {
//             cout << breed[end-1][0] - breed[start-2][0] << " " 
//             << breed[end-1][1] - breed[start-2][1] << " " 
//             << breed[end-1][2] - breed[start-2][2] << endl;
//         }
//     }
//     return 0;
// }

// Etaw
#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int n,q; cin>>n>>q;
  int hol[n];
  int gue[n];
  int jer[n];
  int x; cin>>x;
  if (x==1) {
    hol[0]=1; gue[0]=0; jer[0]=0;
  }
  if (x==2) {
    gue[0]=1; hol[0]=0; jer[0]=0;
  }
  if (x==3) {
    jer[0]=1; hol[0]=0; gue[0]=0;
  }
  for (int i=1; i<n; i++) {
    int y; cin>>y;
    if (y==1) {
      hol[i]=hol[i-1]+1; gue[i]=gue[i-1]; jer[i]=jer[i-1];
    }
    if (y==2) {
      gue[i]=gue[i-1]+1; hol[i]=hol[i-1]; jer[i]=jer[i-1];
    }
    if (y==3) {
      jer[i]=jer[i-1]+1; hol[i]=hol[i-1]; gue[i]=gue[i-1];
    }
  }
  for (int i=0; i<q; i++) {
    int a,b; cin>>a>>b;
    if (a==1) {
      cout<<hol[b-1]<<" "<<gue[b-1]<<" "<<jer[b-1]<<"\n";
      continue;
    }
    cout<<hol[b-1]-hol[a-2]<<" "<<gue[b-1]-gue[a-2]<<" "<<jer[b-1]-jer[a-2]<<"\n";
  }
}