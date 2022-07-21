// Subsequences Summing to Sevens
// https://xjoi.net/contest/4359/problem/2
// http://www.usaco.org/index.php?page=viewproblem2&cpid=595
/*
Farmer John's N cows are standing in a row, as they have a tendency to do from time to time. Each cow is labeled with a 
distinct integer ID number so FJ can tell them apart. FJ would like to take a photo of a contiguous group of cows but, 
due to a traumatic childhood incident involving the numbers 1…6, he only wants to take a picture of a group of cows if 
their IDs add up to a multiple of 7.

Please help FJ determine the size of the largest group he can photograph.

INPUT FORMAT (file div7.in):
The first line of input contains N (1≤N≤50,000). The next N lines each contain the N integer IDs of the cows 
(all are in the range 0…1,000,000).

OUTPUT FORMAT (file div7.out):
Please output the number of cows in the largest consecutive group whose IDs sum to a multiple of 7. If no such group exists, output 0.

You may want to note that the sum of the IDs of a large group of cows might be too large to fit into a standard 32-bit integer. 
If you are summing up large groups of IDs, you may therefore want to use a larger integer data type, like a 64-bit "long long" 
in C/C++.

SAMPLE INPUT:
7
3
5
1
6
2
14
10

SAMPLE OUTPUT:
5
In this example, 5+1+6+2+14 = 28.
Problem credits: Brian Dean

edge case SAMPLE INPUT:
7
3
5
1
6
2
14
11

edge case SAMPLE OUTPUT:
7
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main(void) {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);    
    int n;
    cin >> n;
    vector<ll> prefix_sum(n+1);
    prefix_sum[0] = 0;
    int range_start[7] = {};
    int range_end[7] = {};

    for (int i = 1; i <= n; i++) {
        ll cur_id;
        cin >> cur_id;
        prefix_sum[i] = prefix_sum[i-1] + cur_id;
        prefix_sum[i] %= 7;
        if (range_start[prefix_sum[i]] == 0) {
            range_start[prefix_sum[i]] = i;
        }
        range_end[prefix_sum[i]] = i;
    }
    range_start[0] = 0;   // if prefix_sum for both item i and j are divisible by 7, the range is NOT i to j but max(i, j) 
    int max_range = 0;
    for (int i = 0; i < 7; i++) {
        max_range = max(max_range, range_end[i] - range_start[i]);
    }
    cout << max_range;
    return 0;
}