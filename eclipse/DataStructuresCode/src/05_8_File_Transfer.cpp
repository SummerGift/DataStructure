/*
 * 05_8_File_Transfer.cpp
 *
 *  Created on: 2018年5月21日
 *      Author: Administrator
 */

/*
05-树8 File Transfer（25 分）
We have a network of computers and a list of bi-directional connections.
Each of these connections allows a file transfer from one computer to another.
Is it possible to send a file from any computer on the network to any other?

Input Specification:

Each input file contains one test case. For each test case, the first line contains N (2≤N≤10^4),
 the total number of computers in a network.
Each computer in the network is then represented by a positive integer between 1 and N.
Then in the following lines, the input is given in the format:

I c1 c2
where I stands for inputting a connection between c1 and c2; or

C c1 c2
where C stands for checking if it is possible to transfer files between c1 and c2; or

S

where S stands for stopping this case.

Output Specification:

For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2,
respectively. At the end of each case, print in one line "The network is connected."
if there is a path between any pair of computers; or "There are k components."
where k is the number of connected components in this network.

Sample Input 1:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:

no
no
yes
There are 2 components.
Sample Input 2:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:

no
no
yes
yes
The network is connected.
*/

