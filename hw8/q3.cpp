// Divide Array into Segments
// https://xjoi.net/contest/4660/problem/3
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6462&fragments=12039&problemId=9253
/*
Time limit：1s  Memory limit：512M
Description：
Given an array A which consists of N positive integers, you have to divide it into M segments. The segments have to be 
continuous, and the maximum sum of each segment is the minimal.

For example, if we divide array 4 2 4 5 1 into 3 segments:
If we divide it into [4 2][4 5][1]，the sums of three segments are 6, 9, 1 ，where the maximum sum is 9；
If we divide it into [4][2 4][5 1]，the sums of three segments are 4, 6, 6 ，where the maximum sum is 6；
However you divide this array, the maximum sum will be no less than 6.

Input：
The first line contains two positive integers N，M；
The second line contains N non-negative integers  Ai​ (separated by space)

Output：
A positive integer, the minimum maximum sum of each segment.

Sample input：
5 3
4 2 4 5 1

Sample output：
6

Note：
For 20% data, N≤10；
For 40% data，N≤1000；
For 100% data，N≤10^5，M≤N， the sum of Ai​ <= 10^18
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> nums(n, 0);
    ll l=0, r=0;

    for(ll i=0; i<n; i++){
        cin >> nums[i];
        r+=nums[i];
        l=max(l, nums[i]);
    }

    ll ans=r;

    while(l<=r){
        ll mid=(l+r)/2;
        ll curr_sum=0;
        ll subs=1;
        ll max_sum=0;

        for(int i=0; i<n; i++){
            if(curr_sum + nums[i] > mid){
                subs++;
                curr_sum=nums[i];
                if(subs>m){
                    break;
                }
            }
            else{
                curr_sum+=nums[i];
            }
            max_sum=max(max_sum, curr_sum);
        }
        if(subs>m){
            l=mid+1;
        }
        else{
            r=mid-1;
            ans=min(ans, max_sum);
        }
    }

    cout << ans << endl;
}