// Sum of Three Values
// https://xjoi.net/contest/4456/problem/2
/*
Description:
You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.

Input:
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,........,a_n: the array values.

Output:
Print three integers: the positions of the values. If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.

Sample input:
4 8
2 7 5 1

Sample output:
1 3 4

Constraints:
1 <= n <= 5000
1 <= x, a_i <= 10^9
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> num(n);
    vector<ll> uns(n);

    for(ll i=0; i<n; i++){
        cin >> num[i];
        uns[i] = num[i];
    }

    sort(num.begin(), num.end());

    ll leftp=1, rightp=n-1, basep=0;
    int ans=0;

    for(int i=0; i<n; i++){
        int temp = x - num[basep];
        while(leftp<rightp){
            if(num[leftp]+num[rightp]==temp){
                ans++;
                break;
            }
            if(num[leftp]+num[rightp]<temp){
                leftp++;
            }
            if(num[leftp]+num[rightp]>temp){
                rightp--;
            }
        }
        if(ans==0){
            basep++;
            leftp= basep+1;
            rightp= n-1;
        }
        
    }
    

    if(ans==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> rep(3);
        rep[0] = num[leftp];
        rep[1] = num[rightp];
        rep[2] = num[basep];

        //cout << rep[0] << " " << rep[1] << " " << rep[2] << endl;

        int cnt=0;

        for(int i=0; i<n; i++){
            if(!rep.empty()){
                for (auto itr = rep.begin(); itr != rep.end(); ) {
                    if(uns[i] == *itr){
                        cout << i+1 << " ";
                        itr = rep.erase(itr);  
                        break;                      
                    } else {
                        itr++;
                    }
                }
            }
        }
    }
}