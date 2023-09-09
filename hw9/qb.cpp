// B. Friendship Circle
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6460&fragments=12040&problemId=9561
/*
Description:
There are n students in class. Some of them are friends, and some of them are not. Friendship has transitivity. For example, if A is B's 
friend, and B is C's friend, then A will be C's friend as a result of transitivity. A social circle is defined as a set of people who are 
all friends with each other. Note that there could be multiple social circles.

An n by n matrix M is given, representing the friendships in class. If M[i][j] = 1, the i-th student and j-th student are direct friends 
with each other; otherwise their relationship is unknown (with transitivity students could be friends even if they are not friends directly). 
Please compute the number of social circles in total.

Input:
The first line is an integer, n.
Over the next n lines, there are n integers in each line, either a 1 or 0, where a 1 represents a direct friendship.

Output:
One integer representing total number of social circles.

Sample Input：
3
1 1 0
1 1 1
0 1 1

Sample Output：
1

Constraints: 1<=n<=200
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
        int n; cin>>n;
        DSU dsu(n);
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                int x; cin>>x;
                if (x==1 && i!=j) {
                    dsu.unite(i, j);
                }
            }
        }
        set<int> s;
        FOR(i, 0, n) {
            s.insert(dsu.get(i));
        }
        cout<<s.size();
    }
}