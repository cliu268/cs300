// Hoof, Paper, Scissors
// https://xjoi.net/contest/4389/problem/1
// http://www.usaco.org/index.php?page=viewproblem2&cpid=691
/*
You have probably heard of the game "Rock, Paper, Scissors". The cows like to play a similar game they call "Hoof, Paper, Scissors".

The rules of "Hoof, Paper, Scissors" are simple. Two cows play against each-other. They both count to three and then each 
simultaneously makes a gesture that represents either a hoof, a piece of paper, or a pair of scissors. Hoof beats scissors 
(since a hoof can smash a pair of scissors), scissors beats paper (since scissors can cut paper), and paper beats hoof 
(since the hoof can get a papercut). For example, if the first cow makes a "hoof" gesture and the second a "paper" gesture, 
then the second cow wins. Of course, it is also possible to tie, if both cows make the same gesture.

Farmer John wants to play against his prize cow, Bessie, at N games of "Hoof, Paper, Scissors" (1≤N≤100,000). Bessie, being an 
expert at the game, can predict each of FJ's gestures before he makes it. Unfortunately, Bessie, being a cow, is also very lazy. 
As a result, she tends to play the same gesture multiple times in a row. In fact, she is only willing to switch gestures at most 
once over the entire set of games. For example, she might play "hoof" for the first x games, then switch to "paper" for the 
remaining N−x games.

Given the sequence of gestures FJ will be playing, please determine the maximum number of games that Bessie can win.

INPUT FORMAT (file hps.in):
The first line of the input file contains N.

The remaining N lines contains FJ's gestures, each either H, P, or S.

OUTPUT FORMAT (file hps.out):
Print the maximum number of games Bessie can win, given that she can only change gestures at most once.

SAMPLE INPUT:
5
P
P
H
P
S

SAMPLE OUTPUT:
4
Problem credits: Mark Chen and Brian Dean
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
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);        
    return 0;
}