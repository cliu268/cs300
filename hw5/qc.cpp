// C. Subarray Distinct Values
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6459&fragments=12035&problemId=14295
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.

Input
The first input line has two integers n and k.
The next line has n integers x1,x2,…,xn: the contents of the array.

Output
Print one integer: the number of subarrays.

Constraints
1≤k≤n≤2⋅10^5
1≤xi≤10^9

Example Input:
5 2
1 2 3 1 1

Example Output:
10
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<b; i++)
using namespace std;

int main() {
    // freopen("bruh.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while (t--) {
        ll n, k; cin>>n>>k;
        vector<ll> v(n);
        FOR(i, 0, n) {
            cin>>v[i];
        }
        ll ans=0;
        multiset<ll> ms;
        queue<ll> q;
        ll curr=0;
        FOR(i, 0, n) {
            if (curr<k) {
                ans+=1+ms.size();
                if (ms.find(v[i])==ms.end()) {
                    curr++;
                }
                ms.insert(v[i]);
                q.push(v[i]);
            }
            else if (curr==k) {
                if (ms.find(v[i])==ms.end()) {
                    ll del=q.front();
                    while (ms.find(del)!=ms.end()) {
                        ms.erase(ms.find(q.front()));
                        del=q.front();
                        q.pop();
                    }
                    ans+=1+ms.size();
                    ms.insert(v[i]);
                    q.push(v[i]);
                }
                else {
                    ans+=1+ms.size();
                    ms.insert(v[i]);
                    q.push(v[i]);
                }
            }
        }
        cout<<ans;
    }
}