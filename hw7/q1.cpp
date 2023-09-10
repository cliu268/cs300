// Binary Search
// https://xjoi.net/contest/4659/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6467&fragments=12037&problemId=1037
/*
Time limit:1000 Memory limit:65536
Description:
Binary search:
Given N numbers (N <= 10 ^ 6) that are already sorted in ascending order. Please use binary search to find whether a 
given number M exists or not. If there is this number, output the position of first occurrence (counted start from 1 and 
from left to right). If there is no such a number output 0.

Input:
In the first line there are two integer numbers N and M.
The second line has N integers.

Output:
The postion when M appears for the first time (count from left to right). Output 0 if there is no such a number.

Sample input:
7 4
1 2 4 4 5 7 9

Sample output:
3
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n, m; cin>>n>>m;
//   vector<int> numbers(n);
//   for (int i=0; i<n; i++) {
//     cin>>numbers[i];
//   }
//   int left=0; int right=n-1;
//   while (left<=right) {
//     int middle=(left+right)/2;
//     if (numbers[middle]==m) {
//       if (numbers[middle-1]!=m || middle==0) {
//         cout<<middle+1;
//         return 0;
//       }
//       right=middle-1;
//     }
//     if (numbers[middle]>m) {
//       right=middle-1;
//     }
//     if (numbers[middle]<m) {
//       left=middle+1;
//     }
//   }
//   cout<<0;
// }
// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    int l=0, r=n-1, mid;

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    int ans=0;
    bool pointer=false;

    while(l<=r){
        mid=(l+r)/2;
        if(vec[mid]==m){
            while(vec[mid]==m){
                ans=mid;
                mid--;
            }
            pointer=true;
            break;
        }
        else if(vec[mid]>m){
            r= mid-1;
        }
        else if(vec[mid]<m){
            l= mid+1;
        }
    }

    if(pointer==true){
        cout << ans+1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    
}