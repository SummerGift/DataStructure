#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

using namespace std;

//递归求和
unsigned int sum(int n) {
	if (n > 1)
		return n + sum(n - 1);
	else if (n == 1) {
		return 1;
	}
}

//求斐波那契数列的第N个值
unsigned int fac(int n) {
	if (n >= 3) {
		return fac(n - 1) + fac(n - 2);
	}

	if (n == 2)
		return 1;

	if (n == 1)
		return 1;
}

//求字符串的长度
unsigned int get_strlen(char *s){
	if(*s != '\0')
		return 1 + get_strlen(s + 1);
	if(*s == '\0')
		return 0;
}

//链表的反转
List reverse(List list) {
	if ((list == NULL || list->Next == NULL)) {
		return list;
	} else {
		List guard = list->Next;
		List ret = reverse(list->Next);
		guard->Next = list;
		list->Next = NULL;
		return ret;
	}
}

//有序链表的合并
List List_Merge(List L1, List L2) {
	if (L1 == NULL) {
		return L2;
	} else if (L2 == NULL) {
		return L1;
	} else if (L1->Data <= L2->Data) {
		List list_1 = L1->Next;
		List list = List_Merge(list_1, L2);
		L1->Next = list;
		return L1;
	} else {
		List list_2 = L2->Next;
		List list = List_Merge(list_2, L1);
		L2->Next = list;
		return L2;
	}
}

//汉诺塔问题 从 a 到 c, b 为中转站
void HanoiTower(int n, char a, char b, char c) {
	if (n == 1) {
		cout << a << "-->" << c << endl;
	} else {
		HanoiTower(n - 1, a, c, b);
		HanoiTower(1, a, b, c);
		HanoiTower(n - 1, b, a, c);
	}
}

//全排列问题
void permutation(char *s, char *e) {
	if (*s == '\0') {
		cout << e << endl;
	} else {
		int len = strlen(s);

		for (int i = 0; i < len; i++) {
			if ((i == 0) || (s[0] != s[i])) {
				swap(s[0], s[i]);
				permutation(s + 1, e);
				swap(s[0], s[i]);
			}
		}
	}
}

int main()
{
//	cout << "sum :" << sum(100) << endl;
//
//	for(int i = 1;i <= 10;i++)
//		cout << "fac " << i << ":" << fac(i) << endl;
//
//	cout << "str len:" << get_strlen("1234") << endl;
//
//	HanoiTower(3, 'a', 'b', 'c');

//	char string[] = "aaa";
//	permutation(string,string);

	return 0;
}
