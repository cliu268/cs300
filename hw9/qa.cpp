// A. Disjoint Set Union
// https://xjoi.net/contest/4208/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6460&fragments=12040&problemId=8214
// see cs202 hw11 q1.cpp for Etaw answer
/*
Time limit：1s   Memory limit：512MB

Description：
This problem is simply the classic disjoint set union algorithm. There are N elements, and there will be M operations to be applied. 
Each element starts in its own set, i.e., there are N sets to start with. Each of these M operations will either merge two sets together 
or query if two elements are in the same set. See input format for more details.

Input：
The first line contains two integers N and M, which means there are N elements and M operations.
The next M lines, each line contains three integers Zi、Xi、Yi.
When Zi=1，merge the two sets which contain Xi and Yi.
When Zi=2，if Xi and Yi belong to the same set, output "Y". Otherwise output "N". 

Output：
As described above, for each Zi=2, there is a line of output. Each line contains a capital letter, "Y" or "N".

Sample input 1：
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

Sample output 1：
N
Y
N
Y

Note：N<=10000，M<=200000
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10000];

int find(ll x){
    int root = x;

    while(root!=arr[root]){
        root = arr[root];
    }

    while(arr[x]!=root){
        int parent = arr[x];
        arr[x]=root;
        x = parent;
    }

    return root;
}

void unite(ll x, ll y){
    x=find(x);
    y=find(y);
    arr[x]=y;
}

int main(){
    ll n, m;
    cin >> n >> m;

    for(ll i=1; i<n; i++){
        arr[i] = i;
    }

    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;

        if(a==1){
            unite(b, c);
        }
        else{
            if(find(b)==find(c)){
                cout << "Y" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }
    }
    
}