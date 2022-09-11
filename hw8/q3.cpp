// Divide Array into Segments
// https://xjoi.net/contest/4660/problem/3
/*
Time limit：1s  Memory limit：512M
Description：
Given an array A which consists of N positive integers, you have to divide it into M segments. The segments have to be 
continuous, and the maximum sum of each segment is the minimal.

For example, if we divide array 4 2 4 5 1 into 3 segments:
If we divide it into [4 2][4 5][1]，the sums of three segments are 6, 9, 1 ，where the maximum sum is 9；
If we divide it into [4][2 4][5 1]，the sums of three segments are 4, 6, 6 ，where the maximum sum is 6；
However you divide this array, the maximum sum will be no less than 6.

Input：
The first line contains two positive integers N，M；
The second line contains N non-negative integers  Ai​ (separated by space)

Output：
a positive integer, the minimum maximum sum of each segment.

Sample input：
5 3
4 2 4 5 1

Sample output：
6

Note：
For 20% data, N≤10；
For 40% data，N≤1000；
For 100% data，N≤10^5，M≤N， the sum of Ai​ <= 10^18
*/