#include <algorithm>
// #include <cstdio>
// #include <iostream>
// using namespace std;
 
// struct Person {
//   int position;
//   int time;
//   bool operator<(const Person& other) const {
//     // Sort by time, then by oroginal position
//     if (time != other.time) return time < other.time;
//     return position < other.position;
//   }
// };
 
// int main() {
//   int n;
//   cin >> n;
//   Person persons[n];
 
//   for (int i = 0; i < n; i++) {
//     persons[i].position = i + 1;
//     cin >> persons[i].time;
//   }
//   sort(persons, persons+n);
//   double sum = 0;
//   // 300B exercise
//   for (int i=0; i<n; i++) {
//     sum+=persons[i].time*(n-i-1);
//     cout<<persons[i].position<<" ";
//   }
//   cout<<"\n";
//   double average = sum / n;
//   printf("%0.2lf", average);
// }