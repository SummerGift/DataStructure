#include<stdio.h>
#include<stdlib.h>

#include<iostream>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

using namespace std;
unsigned int sum(int n) {
	if (n > 1)
		return n + sum(n - 1);
	else if (n == 1) {
		return 1;
	}
}

unsigned int fac(int n) {
	if (n >= 3) {
		return fac(n - 1) + fac(n - 2);
	}

	if (n == 2)
		return 1;

	if (n == 1)
		return 1;
}

unsigned int get_strlen(char *s){
	if(*s != '\0')
		return 1 + get_strlen(s + 1);
	if(*s == '\0')
		return 0;
}

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

//int main()
//{
//	cout << "sum :" << sum(100) << endl;
//
//	for(int i = 1;i <= 10;i++)
//		cout << "fac " << i << ":" << fac(i) << endl;
//
//	cout << "str len:" << get_strlen("1234") << endl;
//
//	return 0;
//}
