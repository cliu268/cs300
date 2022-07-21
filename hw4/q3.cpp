// Subarray Sums I
// https://xjoi.net/contest/4456/problem/3
/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input:
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a1,a2,…,an: the contents of the array.

Output:
Print one integer: the required number of subarrays.

Constraints:
1 ≤ n ≤ 2⋅10^5
1 ≤ x,ai ≤ 10^9

Example Input:
5 7
2 4 1 2 7

Example Output:
3

Hint:
Subarray Sums I hint: try starting from the first element as the subarray. 
If sum is too small, add element to the subarray from right. 
If sum is too big, remove element from left.
*/