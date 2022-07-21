// Restaurant Customers
// https://xjoi.net/contest/4359/problem/3
/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?

Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: 
the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9

Sample Input:
3
5 8
2 4
3 9

Sample Output:
2

Sample Input2:
10
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20

Sample Output2:
1
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(void) {
    map<int, int> freq;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int start, end;
        cin >> start >> end;
        if (freq.find(start) == freq.end()) {
            freq[start] = 1;
        } else { 
            freq[start] += 1;
        }
        if (freq.find(end+1) == freq.end()) {        
            freq[end+1] = -1;
        } else {
            freq[end+1] -= 1;
        }
    }    
    int answer = 0, current = 0;
    for (auto &itr : freq) {
        //cout << itr.first << " " << itr.second << endl;
        current += itr.second;
        answer = max(answer, current);
    }
    cout << answer;
    return 0;
}