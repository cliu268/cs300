// Cow Dance Show
// https://xjoi.net/contest/4660/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6462&fragments=12039&problemId=15297
/*
After several months of rehearsal, the cows are just about ready to put on their annual dance performance; this year they are 
performing the famous bovine ballet "Cowpelia".

The only aspect of the show that remains to be determined is the size of the stage. A stage of size K can support K cows dancing 
simultaneously. The N cows in the herd (1 <= N<=10,000) are conveniently numbered 1... N in the order in which they must appear 
in the dance. Each cow i plans to dance for a specific duration of time d(i). Initially, cows 1 ... K appear on stage and start 
dancing. When the first of these cows completes her part, she leaves the stage and cow K+1 immediately starts dancing, and so on, 
so there are always K cows dancing (until the end of the show, when we start to run out of cows). The show ends when the last cow 
completes her dancing part, at time T.

Clearly, the larger the value of K, the smaller the value of T. Since the show cannot last too long, you are given as input an 
upper bound T_max specifying the largest possible value of T. Subject to this constraint, please determine the smallest possible 
value of K.

INPUT:
The first line of input contains N and T_max, where T_max is an integer of value at most 1 million.
The next N lines give the durations d(1) ... d(N) of the dancing parts for cows 1 ... N. Each d(i) value is an integer in the 
range 1 ... 100,000.
It is guaranteed that if K=N, the show will finish in time.

OUTPUT:
Print out the smallest possible value of K such that the dance performance will take no more than T_max units of time.

SAMPLE INPUT:
5 8
4
7
8
6
4

SAMPLE OUTPUT:
4
*/
// ETAW solution
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, t; cin>>n>>t;
  vector<int> duration(n);
  for (int i=0; i<n; i++) {
    cin>>duration[i];
  }
  int ans=n;
  int left=1; int right=n;
  while (left<=right) {
    int middle=(left+right)/2;
    priority_queue<int, vector<int>, greater<int>> q;
    int maxi=0;
    for (int i=0; i<middle; i++) {
      maxi=max(maxi, duration[i]);
      q.push(duration[i]);
    }
    for (int i=middle; i<n; i++) {
      q.push(q.top()+duration[i]);
      maxi=max(maxi, q.top()+duration[i]);
      q.pop();
    }
    if (maxi<=t) {
      ans=min(ans, middle);
      right=middle-1;
    }
    else {
      left=middle+1;
    }
  }
  cout<<ans;
}

// EV solution
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, tmax;
    cin >> n >> tmax;

    vector<ll> d(n, 0);

    for(ll i=0; i<n; i++){
        cin >> d[i];
    }

    ll k=n;
    
    ll l=0, r=n;
    

    while(l<=r){
        ll mid = (l+r)/2;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        ll max_time=0;
        for(ll i=0; i<mid; i++){
            q.push(d[i]);
            max_time=max(max_time, d[i]);
        }
        for(ll i=mid; i<n; i++){
            ll x = q.top();
            q.pop();
            x+=d[i];
            q.push(x);
            max_time=max(max_time, x);
        }
        if(max_time>tmax){
            l=mid+1;
        }
        else{
            r=mid-1;
            k=min(k, mid);
        }
    }

    cout << k << endl;
}
*/