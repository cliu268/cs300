// Rope Cutting
// https://xjoi.net/contest/4659/problem/3
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6463&fragments=12038&problemId=3579
/*
Time  limit: 0.2s   Memory limit: 32M
Description:
There are N ropes, each has a length L_i. If you cut out K of ropes of the same length from them, what is the possible longest 
length for each of these K ropes? The answer is rounded to nearest hundredth (rounded to 2 decimal places).

Input format:
Enter two integers N and K in the first line.
In the second line, enter N floating-point numbers L_i (i from 1 to N).

Output format:
Output a floating point number rounded to nearest hundredth (rounded to 2 decimal places). 

Sample input:
4 11
8.02 7.43 4.57 5.39

Sample output:
2.00

Notes: 1 <= N <= 10000, 1 <= K <= 10000, 1 <= L_i <= 100000
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
multiset<ll> ropes;

bool works(ll middle){
    ll sum=0;
    for (auto it = ropes.begin(); it != ropes.end(); it++){
        sum += *it / middle;
    }
    if(sum>=k){
        return true;
    }
    return false;
}

int main(){

    cin >> n >> k;

    for(ll i=0; i<n; i++){
        float x;
        cin >> x;
        ropes.insert(x*100);
    }

    ll ans=0;
    auto it = ropes.end();
    it--;
    ll l=1, r=*it;

    while(l<=r){
        ll mid=(l+r)/2;
        if(works(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    printf("%.2f\n", ans/100.0);
}