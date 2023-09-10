// Maximum Subarray Sum
// https://xjoi.net/contest/4492/problem/2
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6466&fragments=12032&problemId=14098
/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input:
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.

Output:
Print one integer: the maximum subarray sum.

Constraints:
1 ≤ n ≤ 2⋅10^5
−10^9 ≤ xi ≤ 10^9

Example Input:
8
-1 3 -2 5 3 -5 2 2

Example Output:
9
*/
// Etaw
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
 
// int main() {
//   ll n; scanf("%lld", &n);
//   ll prefix[n+1]; prefix[0]=0;
//   ll mini[n+1]; mini[0]=0;
//   for (ll i=1; i<=n; i++) {
//     ll x; cin>>x;
//     prefix[i]=prefix[i-1]+x;
//     if (i==1) {
//       mini[i]=x;
//     }
//     else {
//       mini[i]=min(prefix[i], mini[i-1]);
//     }
//   }
//   // vector<ll> change; change.push_back(1);
//   // ll currmax=prefix[1];
//   // for (ll i=2; i<=n; i++) {
//   //   if (prefix[i]>currmax) {
//   //     currmax=prefix[i];
//   //     change.push_back(i);
//   //   }
//   // }
//   ll ans=-100000000000000000;
//   // for (ll i=0; i<change.size(); i++) {
//   //   ans=max(ans, max(prefix[change[i]], prefix[change[i]]-mini[change[i]-1]));
//   // }
//   for (ll i=1; i<=n; i++) {
//     ans=max(ans, max(prefix[i], prefix[i]-mini[i-1]));
//   }
//   cout<<ans;
// }

// Ev
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    vector<ll> nums(n);
    vector<ll> psum(n);
    ll ans=-1E18, temp=0;

    for(ll i=0; i<n; i++){
        cin >> nums[i];
        if(i==0){
            psum[i] = nums[i];
        }
        else{
            psum[i] = psum[i-1] + nums[i];
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << nums[i] << " " << psum[i] << endl;
    // }

    for(ll i=0; i<n; i++){
        ans = max(ans, psum[i]-temp);
        temp = min(temp, psum[i]);
    }

    cout << ans << endl;
}