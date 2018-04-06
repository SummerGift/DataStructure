/*
 * Reversing_Linked_List.cpp
 *
 *  Created on: 2018��4��6��
 *      Author: Administrator
 */

#include<stdio.h>
#include<stdlib.h>

struct DataNode {
    int addr;
    int data;
    int nextaddr;
    struct DataNode *link;
};
typedef struct DataNode *DataList;

// ϵ�� ָ�� ��Ҫ���ڵ����������β��ָ��
static void Attach(int addr, int data, int nextaddr, DataList *pRear) {
    DataList P;

    P = (DataList) malloc(sizeof(struct DataNode));
    P->addr = addr;
    P->data = data;
    P->nextaddr = nextaddr;
    P->link = NULL;
    (*pRear)->link = P; //��β�ڵ��ָ��ָ���µĽڵ�
    *pRear = P;         //����βָ��ָ���λ��
}

int first_addr, data_num, k;

//1�������ݶ���һ��������
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

//2�������������������򣬲���֮ǰ���ɵ������е�һ����ַ�Ľڵ����
//Ȼ�������һ����ַ���Һ����

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

    t = P;
    P = P->link;
    free(t);

    return P;
}

//�����ķ�ת
DataList ListReversing(DataList List) {
    DataList p = List, newH = NULL;
    while (p != NULL)                 //һֱ��������β
    {
        if (p->link != NULL) {
            p->link->nextaddr = p->addr;
        }

        DataList tmp = p->link;       //�ݴ�p��һ����ַ����ֹ�仯ָ��ָ����Ҳ�����������
        p->link = newH;               //p->nextָ��ǰһ���ռ�
        newH = p;                     //��������ͷ�ƶ���p������һ������
        p = tmp;                   //pָ��ԭʼ����pָ�����һ���ռ�
    }

    return newH;
}

void DataListprint(DataList List);

DataList DataListReversing(DataList List, int data_num, int k) {
    int z,remainder;
    int i = 1;
    int flag = 1;
    z = data_num / k;
    remainder = data_num % k;

    if(k == 1)
        return List;

    DataList P, Rear, t;
    P = (DataList) malloc(sizeof(struct DataNode));
    P->link = NULL;
    Rear = P;

    DataList List_t = List;
    int times_inter, times_out;
    DataList list_last_time = NULL, save_addr = NULL, next_addr = NULL;

    //����պ�����Ϊ0����ôҪÿ�ν�ȡ  K ������ת����ȡ z ��
    while (i <= z) {
        times_inter = k;

        while (--times_inter) {
            List_t = List_t->link;
        }

        if (List_t->link != NULL) {
            next_addr = List_t->link;   //����һ�������ĵ�һ��Ԫ�صĵ�ַ������ ������ܵ��� NULL
        }

        List_t->link = NULL;

        if (i == 1) {
            List_t = List;
        } else {
            List_t = next_addr;
        }

        //��ΪҪ��ת���� ������ʱ��Ž�ȥ�� List_t ���Ƿ�ת������һ��Ԫ�ص�ָ��
        save_addr = List_t;         //��һ��û�з�תǰ�����һ��Ԫ�صĵ�ַ���õ�����ʾ���������һ��Ԫ��
        list_last_time = ListReversing(List_t);

        Rear->link = list_last_time;                 //���µķ�ת�õ��������뵽��������
        Rear->nextaddr = list_last_time->addr;

        Rear = save_addr;                            //Rearָ��ָ�����������һ��Ԫ��

        List_t = next_addr;                          //

        i++;
    }

    if (!remainder) {
        Rear->nextaddr = -1;   //������Ҫ��ת������һ��Ԫ��
    } else {
        Rear->link = next_addr;
        Rear->nextaddr = next_addr->addr;
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

//int main() {
//    DataList save, p, p_rearrangement, p_output;
//    int count = 0;
//    //1����������
//    p = DataNode_read();
////  printf("������������£� \n");
////  DataListprint(p);
//    //2����������
//    p_rearrangement = DataNode_rearrangement(p, first_addr, data_num);
//    save = p_rearrangement;
////  printf("�����������������£� \n");
////  DataListprint(p_rearrangement);
//
//    while (p_rearrangement) {
//        count++;
//        p_rearrangement = p_rearrangement->link;
//    }
//
//    //printf("��ת����������£� p_output = %p \n", p_output);
//    //3����ת����
//    p_output = DataListReversing(save, count, k);
//    //4���������
////  printf("��ת����������£� p_output = %p \n", p_output);
//    DataListprint(p_output);
//
//    return 0;
//}

