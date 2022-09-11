// Clumsy Dancer
// https://xjoi.net/contest/4849/problem/1
/*
The cow is recognized as a clumsy dancer. Then, John found that cows with musical cells could produce more milk. Therefore, 
he put his entire lap of cattle into the dance training class, including all the bulls (because a pair consisting a man and a 
women is needed when dancing). These cows consists n male and n female. Before the start of the first class, the dance teacher 
wanted to divide them into one-to-one pairs (of course, the male and the female are in a pair). The smaller the height difference 
between the two cows, the better they will match when they dance. Given the height of all the cows and ask how to match them to 
make the height difference of all the cows smallest.

Input :
The first line is an integer n.
Next n lines, each line an integer, indicating the height of the n bulls;
The next n lines, one integer per line, indicate the height of the n cows.

Output :
Only one line, an integer, indicating the minimum sum of all height differences.

Sample input:
4
2
8
5
5
1
4
10
7

Sample output:
6

Data Range:
For 50% of the data, 1 <= n <= 50;
For 100% of the data, 1 <= n <= 1000.

Time Limit:
1000

Memory Limit:
65536

Hint:
Sample explanation:
The best match is this: (2, 1) (8, 10) (5, 4) (5, 7)
*/