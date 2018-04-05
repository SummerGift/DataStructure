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

    while (data_num--) {
        while (List_t) {
            if (List_t->addr == firstaddr) {
                Attach(List_t->addr, List_t->data, List_t->nextaddr, &Rear);
                firstaddr = List_t->nextaddr;
                break;
            } else {
                List_t = List_t->link;
            }
        }
        List_t = List;
    }
	
	// todo 在 attach 函数中结尾已经指向 NULL了,这里应该无需再次处理链表结尾

    t = P;
    P = P->link;
    free(t);

    return P;
}

DataList DataListReversing(DataList List, int data_num, int k) {
	int z,remainder;
	z = data_num / k;
	remainder = data_num % k;
	//printf("z = %d,remainder = %d \n", z, remainder);

	//如果刚好余数为0，那么要每次截取  K 个来反转，截取 z 次

	if(k == 1)
		return List;

	DataList P, Rear, t;
	P = (DataList) malloc(sizeof(struct DataNode));
	P->link = NULL;
	Rear = P;
	DataList List_t = List;
	int i = 1;
	int times, times_inter, times_out;
	DataList list_last_time = NULL;
	DataList save_addr = NULL;
	DataList last_addr = NULL;
	int flag = 1;

//	printf("LINE:%d, the z = %d. \n", __LINE__, z);

	while (i <= z) {
		times = k;
		times_inter = k;
		times_out = k;

//		printf("LINE:%d, the i = %d. \n", __LINE__, i);

		while (times_out--) {

//			printf("LINE:%d, the times_inter = %d. \n", __LINE__, times_inter);
			while (--times_inter) {
				List_t = List_t->link;
			}
                                                             //问题的关键是
			if ((times_out + 1) == k) {                      //指针移动到这一组的最后一个元素时，将下一个元素的指针先存起来

//				printf("LINE:%d, the save_addr = %p. \n", __LINE__, save_addr);
				save_addr = List_t->link;
				flag = 0;
			}

//			printf("LINE:%d, want to add list data = %d. \n", __LINE__, List_t->data);


			Rear->link = List_t;             //将需要加入的元素加入到链表中
			Rear = List_t;                   //更新尾节点指针

//			printf("LINE:%d, the times_out = %d. \n", __LINE__, times_out);
//			printf("LINE:%d, the List_t = %p. \n", __LINE__, List_t);
//			printf("LINE:%d, the List_t data = %d. \n", __LINE__, List_t->data);
//			printf("LINE:%d, 尾节点的指针指向的地址： %p. \n", __LINE__, Rear->link);


			//处理节点内数据地址的重写
			if (list_last_time != NULL) {
				list_last_time->nextaddr = List_t->addr;
			}
			list_last_time = List_t;             //更新上一个节点的指针

            if( i == 1)
            {
				List_t = List;                       //对List_t重新赋值，重新开始向后遍历,这里有问题，为何又用数据开始时候的值，而不是上一次的saveaddr
            }else{
            	List_t = last_addr;                       //对List_t重新赋值，重新开始向后遍历,这里有问题，为何又用数据开始时候的值，而不是上一次的saveaddr
            }

			times_inter = --times;               //更新下一次所需要遍历的次数
		}


		flag = 1;
		List_t = save_addr;
		last_addr = save_addr;
		i++;

//		printf("LINE:%d, the save_addr = %p. \n", __LINE__, save_addr);
//		printf("LINE:%d, the save_addr->data = %d. \n", __LINE__, save_addr->data);
//		printf("LINE:%d, the save_addr->link->data = %d. \n", __LINE__, save_addr->link->data);

		//return NULL;
	}

	if (!remainder) {


//		printf("LINE:%d, the Rear = %p. \n", __LINE__, Rear);
//		printf("LINE:%d, the Rear data = %d. \n", __LINE__, Rear->data);

		Rear->link = NULL;
		Rear->nextaddr = -1;

//		printf("LINE:%d, the Rear->data = %d. \n", __LINE__, Rear->data);

	} else {
		Rear->link = save_addr;
		Rear->nextaddr = save_addr->addr;
	}

    t = P;
    P = P->link;
    free(t);

	return P;
}

void DataListprint(DataList List) {
	while (List) {
		if (List->nextaddr != -1) {
			printf("%05d %d %05d\n", List->addr, List->data, List->nextaddr, List);
		} else {
			printf("%05d %d %d\n", List->addr, List->data, List->nextaddr, List);
		}
		List = List->link;
	}
}

int main() {
	DataList p, p_rearrangement, p_output;
	//1、读入链表
	p = DataNode_read();
//	printf("读入的链表如下： \n");
//	DataListprint(p);
	//2、重新排序
	p_rearrangement = DataNode_rearrangement(p, first_addr, data_num);
//	printf("重新排序后的链表如下： \n");
//	DataListprint(p_rearrangement);
	//3、反转链表
	p_output = DataListReversing(p_rearrangement, data_num, k);
	//4、输出链表
//	printf("反转后的链表如下： p_output = %p \n", p_output);
	DataListprint(p_output);

	return 0;
}
