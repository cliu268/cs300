// Hoof, Paper, Scissors
// https://xjoi.net/contest/4389/problem/1
// http://www.usaco.org/index.php?page=viewproblem2&cpid=691
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6466&fragments=12032&problemId=15298
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
Hint: prefix sum. refere to week 1's class exercise of "Pivot Index of Array"
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  char letters[n+1];
  int paper[n+1]; int scissor[n+1]; int hoof[n+1];
  paper[0]=0; scissor[0]=0; hoof[0]=0;
  for (int i=1; i<=n; i++) {
    cin>>letters[i];
    paper[i]=paper[i-1]; scissor[i]=scissor[i-1]; hoof[i]=hoof[i-1];
    if (letters[i]=='P') {
      paper[i]++;
    }
    if (letters[i]=='H') {
      hoof[i]++;
    }
    if (letters[i]=='S') {
      scissor[i]++;
    }
  }
  int ans=max(paper[n], max(scissor[n], hoof[n]));
  for (int i=1; i<=n; i++) {
    ans=max(ans, paper[i]+hoof[n]-hoof[i]);
    ans=max(ans, paper[i]+scissor[n]-scissor[i]);
    ans=max(ans, hoof[i]+ paper[n]-paper[i]);
    ans=max(ans, hoof[i]+ scissor[n]-scissor[i]);
    ans=max(ans, scissor[i]+paper[n]-paper[i]);
    ans=max(ans, scissor[i]+hoof[n]-hoof[i]);
  }
  cout<<ans;
}
// USACO java solution http://www.usaco.org/current/data/sol_hps_silver_jan17.html