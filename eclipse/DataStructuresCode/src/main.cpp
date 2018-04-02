#include<stdio.h>
#include<stdlib.h>

struct DataNode {
	int addr;
	int data;
	int nextaddr;
	struct DataNode *link;
};
typedef struct DataNode *DataList;

// 系数 指数 需要将节点插入链表的尾部指针
static void Attach(int addr, int data, int nextaddr, DataList *pRear) {
	DataList P;

	P = (DataList) malloc(sizeof(struct DataNode));
	P->addr = addr;
	P->data = data;
	P->nextaddr = nextaddr;
	P->link = NULL;
	(*pRear)->link = P; //让尾节点的指针指向新的节点
	*pRear = P;         //更新尾指针指向的位置
}

int first_addr, data_num, k;

//1、将数据读入一个链表内
DataList DataNode_read() {

	int addr, data, nextaddr , datanumber;
	DataList P, Rear, t;

	scanf("%d %d %d", &first_addr, &data_num, &k);
	datanumber = data_num;

	printf("the args are : %d %d %d \n",first_addr, data_num, k);

	P = (DataList) malloc(sizeof(struct DataNode));
	P->link = NULL;
	Rear = P;

	while (datanumber--) {
		scanf("%d %d %d", &addr, &data, &nextaddr);
		Attach(addr, data, nextaddr, &Rear);
	}

	t = P;
	P = P->link;
	free(t);

	return P;
}

//2、对链表进行重新排序，查找之前生成的链表中第一个地址的节点插入，
//然后根据下一个地址查找后插入

DataList DataNode_rearrangement(DataList List, int firstaddr, int data_num) {
	DataList P, Rear, t;
	P = (DataList) malloc(sizeof(struct DataNode));
	P->link = NULL;
	Rear = P;

	DataList List_t = List;

	printf("the data_num are : %d  \n",data_num);

	while (data_num--) {
		while (List_t) {
			if (List_t->addr == firstaddr) {
				Attach(List_t->addr, List_t->data, List_t->nextaddr, &Rear);
				firstaddr = List_t->nextaddr;
				break;
			}
			List_t = List_t->link;
		}
	}

	t = P;
	P = P->link;
	free(t);

	return P;
}

DataList DataListReversing(DataList List, int k) {
}

void DataListprint(DataList List) {
	while (List) {
		printf("%d %d %d\n", List->addr, List->data, List->nextaddr);
		List = List->link;
	}
}

int main() {
	DataList p, p_rearrangement;
	//1、读入链表
	p = DataNode_read();
	DataListprint(p);
	p_rearrangement = DataNode_rearrangement(p, first_addr, data_num);
	DataListprint(p_rearrangement);

	//2、反转链表
	//DataListReversing(DataList List);
	//3、输出链表
	//DataListprint(DataList List);
	return 0;
}
