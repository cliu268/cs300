// B. Binary Search 2
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6467&fragments=12037&problemId=9331
/*
Binary search:
Given N (N<=10^6) ordered numbers from small to large, use binary search to find the position of the first number greater than M.

Input format:
The first line has integers N, M; the second line has n integers

Output format:
The position of the first number greater than M

Sample input 1:
5 3
1 2 4 4 5

Sample output 1:
3

Sample input 2:
5 5
1 2 4 4 5

Sample output 2:
6

Time limit: 1000  Space Constraints: 65536
*/
// Etaw
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
//         int n, m; cin>>n>>m;
//         vector<int> v(n);
//         FOR(i, 0, n) {
//             cin>>v[i];
//         }
//         cout<<upper_bound(v.begin(), v.end(), m)-v.begin()+1;
//     }
// }

// Ev old version based on binary search 1
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    int l=0, r=n-1, mid;

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    int ans= n+1;

    while(l<=r){
        mid=(l+r)/2;
        if(vec[mid]>m){
            ans=min(ans, mid+1);
            r= mid-1;
        }
        else if(vec[mid]<=m){
            l= mid+1;
        }
    }

    cout << ans << endl;
    
}