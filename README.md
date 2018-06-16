# Readme

## About this repo

- This repo consists of my notes of datastructures classes taught in University of ZHEJIANG on MOOC.

- Most of the code that this branch contains will be written by C/C++.

- Record C/C++ data structure exercises.

- Summarize the learning content and put forward my own understanding.

___

## Content

### 1. 数据结构与算法学习分析总结
#### 第一章：基本概念
- [ ] [Lecture 1.1 - 数据结构与算法](./Lectures/Lecture-1.1-数据结构与算法.md)
- [x] [Lecture 1.2 - 递归的思想与应用](./Lectures/Lecture-1.2-递归的思想与应用.md)
#### 第二章：表、栈和队列
- [x] [Lecture 2.1 - 抽象数据类型 ADT](./Lectures/Lecture-2.1-抽象数据类型ADT.md)
- [x] [Lecture 2.2 - 表 ADT](./Lectures/Lecture-2.2-表ADT.md)
- [x] [Lecture 2.3 - 堆栈 ADT](./Lectures/Lecture-2.3-堆栈ADT.md)
- [ ] [Lecture 2.4 - 队列 ADT](./Lectures/Lecture-2.4-队列ADT.md)
- [x] [Lecture 2.5 - 通用链表的实现](./Lectures/Lecture-2.5-通用链表的实现.md)
#### 第三章：树
- [x] [Lecture 3.1 - 树的预备知识](./Lectures/Lecture-3.1-树的预备知识.md)
- [x] [Lecture 3.2 - 二叉树](./Lectures/Lecture-3.2-二叉树.md)
- [x] [Lecture 3.3 - 查找树 ADT(二叉查找树)](./Lectures/Lecture-3.3-查找树ADT(二叉查找树).md)
- [x] [Lecture 3.4 - AVL树](./Lectures/Lecture-3.4-AVL树.md)
#### 第四章：优先队列（堆）
- [x] [Lecture 4.1 - 堆](./Lectures/Lecture-4.1-堆.md)
- [x] [Lecture 4.2 - 哈夫曼树与哈夫曼编码](./Lectures/Lecture-4.2-哈夫曼树与哈夫曼编码.md)
- [ ] [Lecture 4.3 - 不相交集 ADT](./Lectures/Lecture-4.3-不相交集ADT.md)
#### 第五章：图论算法
- [x] [Lecture 5.1 - 图](./Lectures/Lecture-4.1-堆.md)
#### 第六章：排序

### 2. 数据结构与算法分析练习题

#### 1. Complexity

* 01-1 [Maxsubsequencesum question (C)](./eclipse/DataStructuresCode/src/01_1_Maxsubsequencesum_question.cpp)
* 01-2 [Maximum Subsequence Sum (C)](./eclipse/DataStructuresCode/src/01_2_Maximum_Subsequence_Sum.cpp)
* 01-3 [BinarySearch (C)](./eclipse/DataStructuresCode/src/01_3_BinarySearch.cpp)
* 01-4 [RecursiveProject(C++)](./eclipse/DataStructuresCode/src/Project_01_recursive_function.cpp) 

#### 2. List

* 02-1 [List Merge (C)](./eclipse/DataStructuresCode/src/02_1_List_Merge.cpp)
* 02-2 [List mult add (C)](./eclipse/DataStructuresCode/src/02_2_list_mult_add.cpp)
* 02-3 [Reversing Linked List (C)](./eclipse/DataStructuresCode/src/02_3_Reversing_Linked_List.cpp)
* 02-4 [Pop Sequence (C++)](./eclipse/DataStructuresCode/src/02_4_Pop_Sequence.cpp)

#### 3. Trees

- 03-1 [Tree isomorphism (C)](./eclipse/DataStructuresCode/src/03_1_Tree_isomorphism.cpp)
- 03-2 [List Leaves (C++)](./eclipse/DataStructuresCode/src/03_2_List_Leaves.cpp)
- 03-3 [Tree Traversals Again (C)](./eclipse/DataStructuresCode/src/03_3_Tree_Traversals_Again.cpp)
- 04-4 [Is Same BinarySearch Tree (C)](./eclipse/DataStructuresCode/src/04_4_IsSameBinarySearchTree.cpp)
- 04-5 [Root of AVL_Tree (C)](./eclipse/DataStructuresCode/src/04_5_Root_of_AVL_Tree.cpp)
- 04-6 [Complete Binary Search Tree (C)](./eclipse/DataStructuresCode/src/04_6_Complete_Binary_Search_Tree.cpp)
- 04-7 [Binarysearch tree operation set (C)](./eclipse/DataStructuresCode/src/04_7_Binarysearch_tree_operation_set.cpp)
- 05-7 [Heap Path (C)](./eclipse/DataStructuresCode/src/05_7_heap_path.cpp)
- 05-8 [File Transfer (C)](./eclipse/DataStructuresCode/src/05_8_File_Transfer.cpp)
- 05-9 [Huffman Codes (C)](./eclipse/DataStructuresCode/src/05_9_Huffman_Codes.cpp)

## Note style

### Code

All code will be marked \`\`\`Language ...code... \`\`\` when the lecture is read in raw format. When viewed through Github and Pandoc, it will be color coded based on the language as such:

* C
    ```c
    #include <stdio.h>
    int main(void){
        char * foo = "bar";
        printf("%s",foo);
        return 0;
    }
    ```
  * All C code is Compiled with ```MinGW.org GCC-6.3.0-1```.
