// D. Cow-libi
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6463&fragments=12038&problemId=15573
/*
**Note: The time limit for this problem is 4s, two times the default.**
Somebody has been grazing in Farmer John's (1≤G≤10^5) private gardens! Using his expert forensic knowledge, FJ has been able to determine 
the precise time each garden was grazed. He has also determined that there was a single cow that was responsible for every grazing incident.

In response to these crimes each of FJ's N (1≤N≤10^5) cows have provided an alibi that proves the cow was in a specific location at a 
specific time. Help FJ test whether each of these alibis demonstrates the cow's innocence.

A cow can be determined to be innocent if it is impossible for her to have travelled between all of the grazings and her alibi. 
Cows travel at a rate of 1 unit distance per unit time.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input will contain G and N separated by a space.
The next G lines contain the integers x, y, and t (−10^9≤x,y≤10^9;0≤t≤10^9) separated by a space describing the location and time of 
the grazing. It will always be possible for a single cow to travel between all grazings.
The next N lines contain x, y, and t (−10^9≤x,y≤10^9;0≤t≤10^9) separated by a space describing the location and time of each cow's alibi.

OUTPUT FORMAT (print output to the terminal / stdout):
Output a single integer: the number of cows with alibis that prove their innocence.

SAMPLE INPUT:
2 4
0 0 100
50 0 200
0 50 50
1000 1000 0
50 0 200
10 0 170

SAMPLE OUTPUT:
2

There were two grazings; the first at (0,0) at time 100 and the second at (50,0) at time 200.
The first cow's alibi does not prove her innocence. She has just enough time to arrive at the first grazing.
The second cow's alibi does prove her innocence. She is nowhere near any of the grazings.
Unfortunately for the third cow, being at the scene of the crime does not prove innocence.
Finally, the fourth cow is innocent because it's impossible to make it from her alibi to the final grazing in time.

SCORING:
Inputs 2-4: 1≤G,N≤10^3. Also, for both the fields and alibis, −10^6≤x,y≤10^6 and 0≤t≤10^6.
Inputs 5-11: No additional constraints.
Problem credits: Mark Gordon
*/