// Game of Hammering the Gophers Whac-A-Mole
// https://xjoi.net/contest/4847/problem/2
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6461&fragments=12041&problemId=1317
/*
Time Limit: 1000.  Memory Limit: 65536
Description:
The Gopher Game requires fast response and quick decision making. At beginning all gophers hide under the ground. Once game 
starts, them will pop up their heads from under ground, and you need to hit them with a hammar. Each time it takes one second 
to hammer a gopher. Each hit rewards you with a different point. All gophers show up in the same time at the beginning, but 
each gopher stays for a different limited time and go  back to under ground after that (never show up again). The time each 
gophers stay on the ground differs and the reward point for a hit differs as well. The goal is to find a strategy to optmize 
the hit sequence for the highest reward points.

Input:
3 lines in total. 
The first line contains an integer n (1<=n<=100) depicting that there are n gophers popping out of the ground.
The second line of n space-separated integers describe the time of stay for each gopher
The third line of n space-separated integers indicates the point/score (<=100) that for hitting the corresponding gopher. 
The i-th number in each row represents the information of the i-th gopher.

Output :
There is only one line and one integer, which means the maximum game score that you could possibly get.

Sample Input:
5
5 3 6 1 4
7 9 2 1 5

Sample Output:
24

Data Range:
1<=n<=100
Points <=100
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; scanf("%d", &n);
  vector<int> times(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &times[i]);
  }
  vector<int> values(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &values[i]);
  }
  map<int, vector<int>, greater<int>> gophers;
  for (int i=0; i<n; i++) {
    if (gophers.find(values[i])!=gophers.end()) {
      gophers[values[i]].push_back(times[i]);
      continue;
    }
    gophers[values[i]]={times[i]};
  }
  map<int, vector<int>>::iterator it;
  vector<int> order(n, 0);
  for (it=gophers.begin(); it!=gophers.end(); it++) {
    for (int x=0; x<it->second.size(); x++) {
      int i=min(it->second[x]-1, n-1);
      while (order[i]!=0 && i>=0) {
        if (i==0) {
          i=-1;
          break;
        }
        i--;
      }
      if (i<0) {
        continue;
      }
      else {
        order[i]=it->first;
      }
    }
  }
  int ans=0;
  for (int i=0; i<n; i++) {
    ans+=order[i];
    // cout<<order[i]<<" ";
  }
  printf("%d", ans);
}

// Ev answer that is wrong 40/100 so far
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
//     return(a.second > b.second);
// }

// int main(){
//     ll n; 
//     cin >> n;

//     vector<pair<ll, ll>> m (n);
//     multiset<ll> size;

//     for(ll i=0; i<n; i++){
//         cin >> m[i].first;
//         size.insert(m[i].first);
//     }
//     for(ll i=0; i<n; i++){
//         cin >> m[i].second;
//     }

//     sort(m.begin(), m.end(), sortbysec);
//     auto it = size.end();
//     it--;

//     vector<ll>ans(*it+1, 0);
//     multiset<ll> index;

//     for(ll i=1; i<*it+1; i++){
//         index.insert(i);
//     }

//     for(ll i=0; i<n; i++){
//         if(ans[m[i].first]==0){
//             ans[m[i].first] = m[i].second;
//             auto piss = index.find(m[i].first);
//             index.erase(piss);
//             // cout << "devil" << endl;
//         }
//         else{
//             // cout << "hi" << endl;
//             if(ans[1]==0){
//                 auto pit = index.lower_bound(m[i].first);
//                 pit--;
//                 // cout << m[i].first << " " << *pit << endl;
//                 ans[*pit] = m[i].second;
//                 index.erase(*pit);
//             }
            
//         }
//     }

//     ll sum=0;

//     for(ll i=0; i<*it+1; i++){
//         sum+= ans[i];
//     }

//     cout << sum << endl;
// }