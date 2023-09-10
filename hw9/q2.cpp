// Apartments
// https://xjoi.net/contest/4661/problem/2
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6467&fragments=12037&problemId=14016
/*
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible 
will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum 
allowed difference.

The next line contains n integers a_1, a_2,..., a_n: the desired apartment size of each applicant. 
If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.

The last line contains m integers b_1, b_2,..., b_m: the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.

Constraints
1 <= n, m <= 2 X 10^5
0 <= k <= 10^9
1 <= a_i, b_i <= 10^9

Example Input:
4 3 5
60 45 80 60
30 60 75

Output:
2

Sample input 2:
10 10 10
90 41 20 39 49 21 35 31 74 86
14 24 24 7 82 85 82 4 60 95

Sample output 2:
6
*/
// Ev 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> ppl(n, 0);
    multiset<ll> apmt;

    for(ll i=0; i<n; i++){
        cin >> ppl[i];
    }

    for(ll i=0; i<m; i++){
        ll x;
        cin >> x;
        apmt.insert(x);
    }

    sort(ppl.begin(), ppl.end());

    ll ans=0;

    for(int i=0; i<n; i++){
        if(!apmt.empty()){
            auto it= apmt.lower_bound(ppl[i]-k);
            if(it==apmt.end()){
                continue;
            }
            if(abs(*it - ppl[i]) <= k){
                ans++;
                // cout << ppl[i] << " " << *it << endl;
                apmt.erase(it);
            }
        }
        
    }

    cout << ans << endl;
}

// Etaw new answer
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
//         int n, m, k; cin>>n>>m>>k;
//         vector<int> v(n);
//         FOR(i, 0, n) {
//             cin>>v[i];
//         }
//         multiset<int> b;
//         FOR(i, 0, m) {
//             int x; cin>>x;
//             b.insert(x);
//         }
//         sort(v.begin(), v.end());
//         int ans=0;
//         FOR(i, 0, n) {
//             auto it=b.lower_bound(v[i]-k);
//             if (it==b.end()) {
//                 continue;
//             }
//             if (*(it)>v[i]+k) {
//                 continue;
//             }
//             ans++;
//             b.erase(it);
//         }
//         cout<<ans;
//     }
// }

// Etaw old answer w/o multiset
// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <map>
// #include <set>
// using namespace std;
 
// int main() {
//     int n, m, k; scanf("%d %d %d", &n, &m, &k);
//     vector<int> desire(n);
//     vector<int> apartments(m);
//     for (int i=0; i<n; i++) {
//         scanf("%d", &desire[i]);
//     }
//     for (int i=0; i<m; i++) {
//         scanf("%d", &apartments[i]);
//     }
//     sort(apartments.begin(), apartments.end());
//     sort(desire.begin(), desire.end());
//     int ans=0;
//     for (int i=0; i<n; i++) {
//         auto lower=lower_bound(apartments.begin(), apartments.end(), desire[i]-k);
//         if ((lower-apartments.begin())==apartments.size()) {
//             continue;
//         }
//         if (*lower>(desire[i]+k)) {
//             continue;
//         }
//         else {
//             ans++;
//             apartments.erase(lower);
//         }
//     }
//     printf("%d", ans);
// }