// Why Did the Cow Cross the Road II
// https://xjoi.net/contest/4516/problem/3
// http://www.usaco.org/index.php?page=viewproblem2&cpid=715
/*
The long road through Farmer John's farm has N crosswalks across it, conveniently numbered 1…N (1≤N≤100,000). To allow cows 
to cross at these crosswalks, FJ installs electric crossing signals, which light up with a green cow icon when it is ok for 
the cow to cross, and red otherwise. Unfortunately, a large electrical storm has damaged some of his signals. Given a list 
of the damaged signals, please compute the minimum number of signals that FJ needs to repair in order for there to exist some 
contiguous block of at least K working signals.

INPUT FORMAT:
The first line of input contains N, K, and B (1≤B,K≤N). The next B lines each describe the ID number of a broken signal.

OUTPUT FORMAT:
Please compute the minimum number of signals that need to be repaired in order for there to be a contiguous block of K 
working signals somewhere along the road.

SAMPLE INPUT:
10 6 5
2
10
1
5
9

SAMPLE OUTPUT:
1

Problem credits: Brian Dean

Hint:
Why did the cow cross the road II: sliding window
*/