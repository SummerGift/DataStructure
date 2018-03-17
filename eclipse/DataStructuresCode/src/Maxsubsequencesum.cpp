/*
 * Maxsubsequencesum.cpp
 *
 *  Created on: 2018年3月8日
 *      Author: Administrator
 */
#include <stdio.h>

int MaxSubsequenceSum(const int A[], int n) {
    int thissum, maxsum, i, j, k;

    maxsum = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) {
            thissum = 0;
            for (k = i; k <= j; k++) {
                thissum += A[k];
            }

            if (thissum > maxsum)
                maxsum = thissum;
        }

    return maxsum;
}


int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i,array_end;
    ThisSum = MaxSum = 0;
    array_end = 0;
    int array_begin = 0;
    int allnative = 1;
    int zero_count = 1;
    int save_array_begin = 0;

    for( i = 0; i < N; i++ )
    {
        ThisSum += A[i]; /* 向右累加 */

        if( A[i] >= 0 )
            allnative = 0;

        if( ThisSum > MaxSum )
        {
            MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
            zero_count++;
            array_end = i;
            save_array_begin = array_begin;
        }else
        if( ThisSum < 0 ) /* 如果当前子列和为负 */
        {
            ThisSum = 0 ; /* 则不可能使后面的部分和增大，抛弃之 */
            array_begin = i + 1;
        }
    }

    if ( allnative )
    {
        printf("0 %d %d",A[0], A[ N - 1 ]);
        return 0;
    }

    if( MaxSum == 0 )
    {
        printf("0 0 0");
    }else
    {
        printf("%d %d %d",MaxSum,A[save_array_begin],A[array_end]);
    }

    return 0;
}


//int main()
//{
//    int i, *a;
//    int arraycount;
//    scanf("%d",&arraycount);
//
//    a = (int *)malloc(sizeof(int) * arraycount); /*分配内存*/
//
//    for(i = 0; i < arraycount; i++)
//        scanf("%d", a + i);
//
//    MaxSubseqSum4(a, arraycount);
//    free(a);
//    return 0;
//}
