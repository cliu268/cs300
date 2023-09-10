// Subarray Sums II
// https://xjoi.net/contest/4389/problem/3
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6466&fragments=12032&problemId=14112
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given an array of n integers, your task is to count the number of subarrays having sum x.

Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a1,a2,…,an: the contents of the array.

Output
Print one integer: the required number of subarrays.

Constraints
1 ≤ n ≤ 2⋅10^5
−10^9 ≤ x, ai ≤ 10^9

Example Input:
5 7
2 -1 3 5 -2

Example Output:
2

Hint: prefix sum, with map. Refer to Week 1's homework problem "Subsequences Summing to Sevens".
*/
// Etaw
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
 
// int main() {
//   ll n,x; scanf("%lld %lld", &n, &x);
//   map<ll, ll> sums;
//   ll num[n+1];
//   num[0]=0;
//   ll ans=0;
//   for (ll i=1; i<n+1; i++) {
//     ll p; scanf("%lld", &p);
//     num[i]=num[i-1]+p;
//     if (num[i]==x) {
//       ans++;
//     }
//     if (sums.find(num[i]-x)!=sums.end()) {
//       ans+=sums[num[i]-x];
//     }
//     if (sums.find(num[i])==sums.end()) {
//       sums[num[i]]=1;
//     }
//     else {
//       sums[num[i]]++;
//     }
//   }
//   printf("%lld", ans);
// }

// Ev
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, x, p, s=0, ans=0;
    cin >> n >> x;

    map<ll, ll> nums; //sum : # of subarrays with that sum
    nums[0] = 1; //one empty subarray has a sum of 0

    for(ll i=1; i<n+1; i++){
        cin >> p;
        s+=p;

        ans+= nums[s-x] ? nums[s-x] : 0;
        nums[s] = nums[s] ? nums[s] + 1: 1;
    }

    cout << ans << endl;
}