// Concert Tickets
// https://xjoi.net/contest/4661/problem/3

/*
Time limit: 1.00 s
Memory limit: 512 MB
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the 
nearest possible price such that it does not exceed the maximum price.

Input:
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h1,h2,…,hn: the price of each ticket.
The last line contains m integers t1,t2,…,tm: the maximum price for each customer in the order they arrive.

Output:
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print −1.

Constraints:
1≤n,m≤2⋅10^5
1≤hi,ti≤10^9

Example
Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m; scanf("%d %d", &n, &m);
  vector<int> tickets(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &tickets[i]);
  }
  vector<int> customers(m);
  for (int i=0; i<m; i++) {
    scanf("%d", &customers[i]);
  }
  sort(tickets.begin(), tickets.end(), greater<int> ());
  for (int i=0; i<m; i++) {
    auto lower=lower_bound(tickets.begin(), tickets.end(), customers[i], greater<int>());
    if (lower==tickets.end()) {
      printf("%d", -1);
      printf("\n");
      continue;
    }
    else {
      printf("%d", tickets[lower-tickets.begin()]);
      printf("\n");
      tickets.erase(tickets.begin()+(lower-tickets.begin()));
    }
  }
}