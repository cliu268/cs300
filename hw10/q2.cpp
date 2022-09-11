// Game of Hammering the Gophers
// https://xjoi.net/contest/4847/problem/2
/*
Time Limit: 1000.  Memory Limit: 65536
Description:
The Gopher Game requires fast response and quick decision making. At beginning all gophers hide under the ground. Once game 
starts, them will pop up their heads from under ground, and you need to hit them with a hammar. Each time it takes one second 
to hammer a gopher. Each hit rewards you with a different point. All gophers show up in the same time at the beginning, but 
each gopher stays for a different limited time and go  back to under ground after that (never show up again). The time each 
gophers stay on the ground differs and the reward point for a hit differs as well. The goal is to find a strategy to optmize 
the hit sequence for the highest reward points.

Input:
3 lines in total. 
The first line contains an integer n (1<=n<=100) depicting that there are n gophers popping out of the ground.
The second line of n space-separated integers describe the time of stay for each gopher
The third line of n space-separated integers indicates the point/score (<=100) that for hitting the corresponding gopher. 
The i-th number in each row represents the information of the i-th gopher.

Output :
There is only one line and one integer, which means the maximum game score that you could possibly get.

Sample Input:
5
5 3 6 1 4
7 9 2 1 5

Sample Output:
24

Data Range:
1<=n<=100
Points <=100
*/