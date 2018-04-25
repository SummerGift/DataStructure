/*
 * 03_3_Tree_Traversals_Again.cpp
 *
 *  Created on: 2018年4月22日
 *      Author: SummerGift
 */

/*
03-树3 Tree Traversals Again（25 分）
An inorder binary tree traversal can be implemented in a non-recursive way with a stack.
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed,
the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop().
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations.
Your task is to give the postorder traversal sequence of this tree.

一个中序遍历的二叉树可以使用一个栈结构来非递归遍历。比如说一个六个节点的二叉树被遍历，带着值 1 - 6。
栈的操作为 P1  P2 P3 POP POP P4 POP POP P5 P6 POP POP
接下来特殊的二叉树可以被这一系列的操作产生。
你的任务是给出这棵树的后序遍历序列。

Figure 1
Input Specification:

Each input file contains one test case. For each case,
the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N).
Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack;
or "Pop" meaning to pop one node from the stack.

第一行包括一个小于等于30的正整数，代表树总共的结点数。接下来会有2N行，每一行描述栈操作 PUSH X 指的是将这个节点压入栈中，POP 操作的意思是将节点从栈中弹出。

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line.
A solution is guaranteed to exist. All the numbers must be separated by exactly one space,
and there must be no extra space at the end of the line.

用一行打出相关树的后序输出。

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:

3 4 2 6 5 1
*/


