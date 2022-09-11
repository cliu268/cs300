// Get Water
// https://xjoi.net/contest/4847/problem/1
/*
Time limit：1s   Memory limit：128M
Description：
There are n persons lining in front of a faucet tap for water. Suppose it takes Ti time for person i to get water. 
Please program to find out the particular sequence of those persons in the line, so that the average waiting time for 
those n persons would be minimal.

Input：
The first line contains n.
The second line contains n integers, T1，T2，…，Tn (separated by a space) where Ti means the time it takes for each 
person i to get water.

Output：
The first line contains the sequence of those people in the line, an arrangement from 1 to n.
The second line is the average waiting time in this sequence (round to the hundredth).

Sample input 1：
10
56 12 1 99 1000 234 33 55 99 812

Sample output 1：
3 2 7 8 1 4 9 6 10 5
291.90

Note：
n<=1000
Ti<=1e6，the value of Ti may repeat.
In the case when Ti value is repeated, sorted them in the same order as input.
*/