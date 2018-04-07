# Lecture-5 树与树的表示



分层次组织在管理上有更高的效率。

数据管理的基本操作之一：查找

查找：根据某个给定的关键字k，从集合R中找出关键字与K相同的记录

静态查找：集合中的记录是固定的

​	没有插入和删除操作

动态查找：集合中的记录是动态变化的

​	除了查找，还可能发生插入和删除



##  静态查找

方法一：顺序查找

```c
/*在表Tbl[1]~Tbl[n]中查找关键字为K的数据元素*/
int SequentialSearch(StaticTable *Tbl, ElementType K) { 
	int i;
	Tbl->Element[0] = K; /*建立哨兵*/
	for (i = Tbl->Length; Tbl->Element[i] != K; i--)
		;
	return i; /*查找成功返回所在单元下标；不成功返回0*/
}
```

顺序查找算法的时间复杂度为O(n)。




方法二：二分查找