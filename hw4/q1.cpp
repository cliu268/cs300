// Sum of Two Values
// https://xjoi.net/contest/4456/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6464&fragments=12034&problemId=14095
/*
Description:
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input:
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2, ..... ,a_n: the array values.

Output:
Two integers: the positions of the values. If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.
 
Sample input:
4 8
2 7 5 1

Sample output:​
4 2

Constraints:
1 <= n <= 2 ...... 10^5
1 <= x,a_i <= 10^9
*/
// Ev
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

    ll leftp=0, rightp=n-1;
    int ans=0;

    while(leftp<rightp){
        if(num[leftp]+num[rightp]==x){
            ans++;
            break;
        }
        if(num[leftp]+num[rightp]<x){
            leftp++;
        }
        if(num[leftp]+num[rightp]>x){
            rightp--;
        }
    }

    if(ans==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int l = num[leftp];
        int r = num[rightp];
        int cnt=0;
        for(int i=0; i<n; i++){
            if(uns[i]==l || uns[i]==r){
                cnt++;
                cout << i+1 << " ";
                if (cnt==2) {
                    break;
                }
            }
        }
    }
}

// Etaw old
// #include <bits/stdc++.h>
// using namespace std;
 
// struct IntegerAndIndex {
//   int value;
//   int index;
//   // For std::sort(): how to compare two IntegerAndIndex objects.
//   bool operator<(IntegerAndIndex b) {
//     return (value < b.value) || (value == b.value && index < b.index);
//   }
// };
 
// int main() {
//   int N, X;
//   scanf("%d %d", &N, &X);
//   IntegerAndIndex int_indexs[N];
//   for (int i = 0; i < N; i++) {
//     scanf("%d", &int_indexs[i].value);
//     int_indexs[i].index = i;
//   }
//   // Sort with custom comparator defined in struct IntegerAndIndex.
//   sort(int_indexs, int_indexs + N);
 
//   // 300B coding exercise
//   int i=0; int j=N-1;
//   while (i<j) {
//     if ((int_indexs[i].value+int_indexs[j].value)==X) {
//       cout<<int_indexs[i].index+1<<" "<<int_indexs[j].index+1;
//       return 0;
//     }
//     if ((int_indexs[i].value+int_indexs[j].value)<X) {
//       i++;
//     }
//     if ((int_indexs[i].value+int_indexs[j].value)>X) {
//       j--;
//     }
//   }
//   cout<<"IMPOSSIBLE";
// }