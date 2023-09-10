// Cutting Wood
// https://xjoi.net/contest/4659/problem/2
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6463&fragments=12038&problemId=8466
/*
Xiao Hua is called by Da Lin to chop down trees. He needs to get total m meters of wood. Now, Xiaohua got a strange logging 
machine. It works like this: Xiaohua sets a height limit h (meters), then the machine raises the saw blade to the height of h 
and make a cut there. Parts higher than h will be cut down. Of course, if a tree is lower than h then nothing will be cut away. 
What Xiaohua gets are the parts that have been cut off the tree.

For example, if the height of trees in a row are respectively 20, 15, 10 and 17 (meters), and Xiaohua sets the saw blade to a 
height of 15. The remaining heights of the trees (stumbs) after cutting will be 15, 15, 10 and 15 Meters.  And Xiaohua will get 
5 meters from the first tree and 2 meters from the fourth tree, for a total of 7 meters of wood.

Xiaohua cares about ecological environment. And he will not cut down too much trees. This is why he sets the blade as high as
possible. Please help Xiaohua find the maximum integer height h for the saw blade so that he can get at least m meters of wood. 
Any lower (by 1 meter) blade height will produce less than m meters of wood.

Input:
The first line has two integer numbers n and m, where n represents the number of trees, and m represents the total length of 
wood Xiaohua needs to colloect.
The n integer numbers in 2nd line describe the height of each tree (height<=10^9). You need to make sure that the sum of all 
tree heights is more than m.

Output:
One line with one integer number, indicating the highest possible height of the saw blade.

Sample Input:
5 20
4 42 40 26 46

Sample Output:
36

Data size:
30% data satisfies: 1≤n≤10, 1≤m≤30.
70% data satisfies: 1≤n≤10^3, 1≤m≤10^4.
100% data satisfies: 1≤n≤10^6, 1≤m≤2×10^9
*/
// Etaw 
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() {
  ll n, m; scanf("%lld %lld", &n, &m);
  vector<ll> trees(n);
  ll maxi=0;
  for (ll i=0; i<n; i++) {
    scanf("%lld", &trees[i]);
    maxi=max(maxi, trees[i]);
  }
  sort(trees.begin(), trees.end());
  ll left=0; ll right=maxi;
  ll ans=0;
  while (left<=right) {
    ll middle=(left+right)/2;
    ll sum=0;
    for (ll i=0; i<n; i++) {
      if (middle<trees[i]) {
        sum+=(trees[i]-middle);
      }
    }
    if (sum>=m) {
      ans=max(ans, middle);
      left=middle+1;
    }
    if (sum<m) {
      right=middle-1;
    }
  }
  cout<<ans;
}
// Ev
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll n, m;
// multiset<ll> wood;

// bool works(ll middle){
//     ll sum=0;
//     for (auto it = wood.begin(); it != wood.end(); it++){
//         if(*it > middle){
//             sum += *it - middle;
//         }
//     }
//     if(sum>=m){
//         return true;
//     }
//     return false;
// }

// int main(){

//     cin >> n >> m;

//     for(int i=0; i<n; i++){
//         ll x;
//         cin >> x;
//         wood.insert(x);
//     }

//     ll h=0;
//     auto it= wood.end();
//     it--;
//     ll l=0, r= *it;

//     while(l<=r){
//         ll mid = (l+r)/2;
//         if(works(mid)){
//             h=mid;
//             l=mid+1;
//         }
//         else{
//             r = mid-1;
//         }
//     }

//     cout << h << endl;
// }