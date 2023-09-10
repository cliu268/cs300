// Maximum Subarray Sum II
// https://xjoi.net/contest/4492/problem/3
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6459&fragments=12035&problemId=14099
/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.

Input:
The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.
The second line has n integers x1,x2,…,xn: the array values.

Output:
Print one integer: the maximum subarray sum.

Constraints:
1 ≤ n ≤ 2⋅10^5
1 ≤ a ≤ b ≤ n
−10^9 ≤ xi ≤ 10^9

Example Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Example Output:
8
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<ll> nums(n, 0);
    vector<ll> psum(n, 0);

    for(int i=0; i<n; i++){
        cin >> nums[i];
        
        if(i==0){
            psum[i] = nums[i];
        }
        else{
            psum[i] = psum[i-1] + nums[i];
        }
    }

    int start = 0, end = b;
    ll temp=-1000000000000, ans = 0;
    multiset<ll> max_psum;

    for(int i=a-1; i<b; i++){
        max_psum.insert(psum[i]);
    }

    multiset<ll>::iterator it = max_psum.end();
    it--;
    ans = *it;

    for(int i=0; i<n-a; i++){
        start = i+a-1;
        end = i+b;
        max_psum.erase(max_psum.find(psum[start]));
        if (end < n) max_psum.insert(psum[end]);
        it = max_psum.end();
        it--;
        ans = max(ans, *it-psum[i]);
    }

    cout << ans << endl;

}

