// A. Swapping permutations
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6457&fragments=12042&problemId=3578
/*
Time  Limit: 1s   Memory Limit: 32M

Description:
You have a permutation of numbers from 1 to N, denoted as P1,P2,P3,...,PN. Additionally, you have M swappers (x1,y1),(x2,y2),...,(xM,yM), 
which swap the position of xi with yi. You can use each swapper any number of times, and your goal is to maximize the number of positions 
where Pi=i. Output the maximum number of such positions possible.

Input format:
The first line has two integers, N and M
The next M lines will have a pair, xi,yi, denoting a swapper

Output :
An integer representing the maximum number of positions where Pi=i

Sample input 1:
5 2
5 3 1 4 2
1 3
5 4

Sample output 1:
2

Sample input 2:
10 8
5 3 6 8 7 10 9 1 2 4
3 1
4 1
5 9
2 5
6 5
3 5
8 9
7 9

Sample output 2:
8

Appointment:
2<=N<=10^5,1<=M<=10^5,xi!=yi

Hint: DSU
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> e;
    DSU(int n) {
        e=vector<int>(n, -1);
    }
    int get(int x) {
        if (e[x]<0) {
            return x;
        }
        return e[x]=get(e[x]);
    }
    bool same(int x, int y) {
        return get(x)==get(y);
    }
    int sz(int x) {
        return -e[get(x)];
    }
    void unite(int x, int y) {
        x=get(x);
        y=get(y);
        if (x==y) {
            return;
        }
        if (e[x]>e[y]) {
            swap(x, y);
        }
        e[x]+=e[y];
        e[y]=x;
    }
};

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> l(n, 0);
    DSU dsu(n);

    for(ll i=0; i<n; i++){
        cin >> l[i];
    }

    while(m--){
        ll a, b; 
        cin >> a >> b;
        dsu.unite(a, b);
    }

    ll counter=0;

    for(ll i=0; i<n ; i++){
        if(dsu.get(i+1)==dsu.get(l[i])){
            counter ++;
        }
    }

    cout << counter;
}