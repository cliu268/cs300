// Forest Queries
// https://xjoi.net/contest/4441/problem/1
/*
You are given an n×n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square 
has coordinates (1,1), and the lower-right square has coordinates (n,n).

Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?

Input:
The first input line has two integers n and q: the size of the forest and the number of queries.
Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.

Finally, there are q lines describing the queries. Each line has four integers y1, x1, y2, x2 corresponding to the corners 
of a rectangle.

Output:
Print the number of trees inside each rectangle.

Constraints:
1 ≤ n ≤ 1000
1 ≤ q ≤ 2⋅10^5
1 ≤ y1 ≤ y2 ≤ n
1 ≤ x1 ≤ x2 ≤ n

Example Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2

Example Output:
3
1
2
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,q; scanf("%d %d", &n, &q);
  int prefix[n+1][n+1];
  int arr[n+1][n+1];
  for (int i=0; i<=n; i++) {
    prefix[i][0]=0;
    prefix[0][i]=0;
    arr[i][0]=0;
    arr[0][i]=0;
  }
   
  for (int i=1; i<=n; i++) {
    string s; cin>>s;
    for (int j=0; j<n; j++) {
      prefix[i][j+1]=prefix[i][j]+prefix[i-1][j+1]-prefix[i-1][j];
      if (s[j]=='*') {
        arr[i][j+1]=1;
        prefix[i][j+1]++;
      }
      else {
        arr[i][j+1]=0;
      }
    }
  }
  for (int i=0; i<q; i++) {
    int y1, x1, y2, x2; scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    int ans=prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
    printf("%d", ans);
    printf("\n");
  }
}