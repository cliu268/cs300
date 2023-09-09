// Factory Machines
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6463&fragments=12038&problemId=14077
/*
Time limit: 1.00 s
Memory limit: 512 MB

A factory has n machines which can be used to make products. Your goal is to make a total of t products.

For each machine, you know the number of seconds it needs to make a single product. 
The machines can work simultaneously, and you can freely decide how many products each machine produces.

What is the shortest time needed to make t products?

Input

The first input line has two integers n and t: the number of machines and products.
The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.

Output
Print one integer: the minimum time needed to make t products.

Constraints
1≤n≤2⋅10^5
1≤t≤10^9
1≤ki≤10^9

Example Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t;
multiset<ll> machines;

bool works(ll middle){
    ll sum=0;
    for (auto it = machines.begin(); it != machines.end(); it++){
        sum += middle / *it;
        if(sum>=t){
            return true;
        }        
    }
    return false;
}

int main(){
    cin >> n >> t;

    for(ll i=0; i<n; i++){
        ll x; cin >> x;
        machines.insert(x);
    }

    auto it= machines.end();
    it--;
    ll ans=0, l=0, r=*it * t;

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

    cout << ans << endl;
}