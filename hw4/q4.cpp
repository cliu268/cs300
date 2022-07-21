// Diamond Collector
// https://xjoi.net/contest/4456/problem/4
// http://www.usaco.org/index.php?page=viewproblem2&cpid=643
/*
Bessie the cow, always a fan of shiny objects, has taken up a hobby of mining diamonds in her spare time! She has collected N 
diamonds (N≤50,000) of varying sizes, and she wants to arrange some of them in a pair of display cases in the barn.

Since Bessie wants the diamonds in each of the two cases to be relatively similar in size, she decides that she will not 
include two diamonds in the same case if their sizes differ by more than K (two diamonds can be displayed together in the same 
case if their sizes differ by exactly K). Given K, please help Bessie determine the maximum number of diamonds she can display 
in both cases together.

INPUT FORMAT (file diamond.in):
The first line of the input file contains N and K (0≤K≤1,000,000,000). The next N lines each contain an integer giving the 
size of one of the diamonds. All sizes will be positive and will not exceed 1,000,000,000.

OUTPUT FORMAT (file diamond.out):
Output a single positive integer, telling the maximum number of diamonds that Bessie can showcase in total in both the cases.

SAMPLE INPUT:
7 3
10
5
1
12
9
5
14

SAMPLE OUTPUT:
5

Problem credits: Nick Wu and Brian Dean

Hint:
Diamond Collector - bonus problem.
1. First solve a simpler version of the problem with only 1 case (instead of 2 cases in the problem description). 
You can try sorting the diamonds, and some kind of two pointer technique.
2. Then for this problem with 2 cases, choose a diamond in the sorted array of N diamonds. Apply the solution you get in (1) 
to the subarray at the left side of the chosen diamond, and apply the same solution to the right side subarray. The sum of 
the results from the left and right subarrays is the answer if you split the diamonds at the chosen diamond.
3. Repeat (2) for each diamond, and find the max among all the splits.
4. Now look at above steps again: because you need to do (2) for each diamond, the time complexity isn't great. 
Is there a way to speed it up?
*/