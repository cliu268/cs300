// D. Road Construction
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6460&fragments=12040&problemId=14126
/*
Description:
There are n cities and initially no roads between them. However, every day a new road will be constructed, and eventually there will be a 
total of m roads.
A cluster is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the 
number of clusters and the size of the largest cluster.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.
Then, there are m lines describing the new roads. Each line has two integers a and b representing a new road being constructed between 
cities a and b.
You may assume that every road will be constructed between two different cities.

Output
Print m lines, each line containing two integers: the number of clusters and the size of the largest cluster after building the road.

Sample input:
5 3
1 2
1 3
4 5

Sample output:
4 2
3 3
2 3

Constraints:  1≤n≤10^5  1≤m≤2⋅10^5  1≤a,b≤n
Time limit: 1.00 s  Memory limit: 256 MB
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<b; i++)
using namespace std;

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
int main() {
    // freopen("bruh.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while (t--) {
        int n, m; cin>>n>>m;
        DSU dsu(n);
        set<int> s;
        FOR(i, 0, n) {
            s.insert(i);
        }
        int maxi=1;
        cout<<"\n";
        FOR(i, 0, m) {
            int a, b; cin>>a>>b;
            a--; b--;
            a=dsu.get(a); b=dsu.get(b);
            dsu.unite(a, b);
            if (a==dsu.get(a)) {
                s.erase(b);
            }
            else if (b==dsu.get(b)) {
                s.erase(a);
            }
            else {
                s.erase(a);
                s.erase(b);
            }
            s.insert(dsu.get(a));
            maxi=max(maxi, dsu.sz(a));
            // for (auto j : s) {
            //     cout<<j<<" ";
            // }
            cout<<s.size()<<" "<<maxi<<"\n";
        }
    }
}