// B. Angry Cows
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6457&fragments=12042&problemId=15249
/*
Bessie the cow has designed what she thinks will be the next big hit video game: "Angry Cows". The premise, which she believes is completely 
original, is that the player shoots cows with a slingshot into a one-dimensional scene consisting of a set of hay bales located at various 
points on a number line. Each cow lands with sufficient force to detonate the hay bales in close proximity to her landing site. The goal is 
to use a set of cows to detonate all the hay bales.

There are N hay bales located at distinct integer positions x1,x2,…,xN on the number line. If a cow is launched with power R landing at 
position x, this will causes a blast of "radius R", destroying all hay bales within the range x−R…x+R.

A total of K cows are available to shoot, each with the same power R. Please determine the minimum integer value of R such that it is 
possible to use the K cows to detonate every single hay bale in the scene.

INPUT FORMAT (file angry.in):
The first line of input contains N (1≤N≤50,000) and K (1≤K≤10). The remaining N lines all contain integers 
x1…xN (each in the range 0…1,000,000,000).

OUTPUT FORMAT (file angry.out):
Please output the minimum power R with which each cow must be launched in order to detonate all the hay bales.

SAMPLE INPUT:
7 2
20
25
18
8
10
3
1

SAMPLE OUTPUT:
5

Problem credits: Brian Dean  Hint: binary search
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
multiset<ll> hb;

bool works(ll m){
    auto curr = hb.begin();
    ll count=1;

    for(auto i = hb.begin(); i!=hb.end(); i++){
        if(*i - *curr > m*2){
            curr = i;
            count++;
        }
    }

    return count<=k;
}

int main(){
    
    cin >> n >> k;

    
    for(ll i=0; i<n; i++){
        ll x; cin >> x;
        hb.insert(x);
    }

    auto it = hb.end();
    it--;
    ll l=1, r=*it;
    ll ans=0;

    while(l<=r){
        ll mid = (l+r)/2;
        if(works(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout << ans;
}