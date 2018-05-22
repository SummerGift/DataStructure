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
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef int element_type;
typedef int set_name;
typedef element_type set_type[MaxSize];

set_name find(set_type S, element_type X) {
    for (; S[X] >= 0; X = S[X])
        ;
    return X;
}

void union_root(set_type S, set_name root1, set_name root2) {
    S[root2] = root1;
}

void initialization(set_type S, int n) {

}

void input_connection(set_type S) {
    element_type u,v;
    set_name root1,root2;
    scanf("%d %d\n", &u,&v);
    root1 = find(S, u - 1);
    root1 = find(S, v - 1);
}

void check_connection(set_type S) {
}

void check_network(set_type S, int n) {
}

int main() {
    set_type S;
    int n;
    char input_char;
    scanf("%d\n", &n);
    do {
        scanf("%c", &input_char);
        switch (input_char) {
        case 'I':
            input_connection(S);
            break;
        case 'C':
            check_connection(S);
            break;
        case 'S':
            check_network(S, n);
            break;
        }
    } while (input_char != 'S');
    return 0;
}
