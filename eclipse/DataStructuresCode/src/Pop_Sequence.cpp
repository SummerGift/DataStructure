/*
 * Pop_Sequence.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: Administrator
 */

#include<cstdio>
#include<stack>
using namespace std;

//假设 1-(i-1) 都进入了栈，i 还没有进入栈。
//一个一个元素考虑出栈序列的元素x：
//1. i>x
//    这时X已经入过栈了。
//1.1 如果他不是栈顶那么就无法pop出x了
//1.2 如果x是栈顶，直接从堆栈pop就可以了，处理下一个出栈元素
//
//2. i<=x
//2.1 这时候X还没有入栈，要想要让X出栈，我们必须把从i到x都push到栈，这时候x在栈顶，Pop即可。
//注意：压入元素要保证栈里面的元素个数不超过给定的栈容量，否则也不可能将x弹出。

int pop_seqence_test() {
    stack<int> st;
    int stack_cap, test_seq_len, k;
    scanf("%d%d%d", &stack_cap, &test_seq_len, &k);    //依次输入栈的容量，输入测试序列的长度，测试序列的组数，
    while (k--) {                                   //对每一组测试序列分别进行测试
        int t = test_seq_len;
        int num = 1;                                //每次push到栈中的数字大小的记录
        bool flag = true;
        while (t--) {                               //对测试序列的每一个输入数据进行测试
            int x;
            scanf("%d", &x);                        //读入一个测试数据x
            while (num <= x)                        //x比当前栈顶下标要大
                st.push(num++);                     //一直push元素直到入栈的数字大小和x相等
            int last = st.top();                    //查看栈顶元素
            if (last != x || st.size() > stack_cap)    //如果栈顶元素不等于x,或者栈的大小已经超过栈容量则失败
                flag = false;
            st.pop();                               //栈顶元素和x相等，且不超容量则弹栈
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

