/*
 * Tree_isomorphism.cpp
 *
 *  Created on: 2018年4月14日
 *      Author: SummerGift
 */

#include<stdio.h>
#include<stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];


Tree buildtree(struct TreeNode T[])
{
	int i,N;
	char cl, cr;
	Tree *check, Root;

	scanf("%d\n",&N);
	if(N)
	{
		check = (int *)malloc(N);
		if(check)
		{
			for(i = 0; i < N; i++) check[i] = 0;
		}else{
			printf("malloc error");
			return -1;
		}

		for(i = 0; i < N; i++)
		{
			scanf("%c %c %c\n",&T->Element, &cl, &cr);
			if(cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}else{
				T[i].Left = NULL;
			}
		}

		for(i = 0; i < N; i++)
			if(!check[i]) break;

		Root = i;                   //T[i]中沒有任何节点的left和 right指向他，就是根节点
        free(check);
	}

	return Root;

}

int Isomorphic( Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == Null)) /* both empty */
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0; /* one of them is empty */
	if (T1[R1].Element != T2[R2].Element)
		return 0; /* roots are different */
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) /* both have no left subtree */
		return Isomorphic(T1[R1].Right, T2[R2].Right);

}

int main()
{

/*	Tree r1, r2;

	r1 = buildtree(t1);
	r2 = buildtree(t2);

	if (isomorphis(r1, r2)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}*/

	printf("hello summer");

	return 0;
}

