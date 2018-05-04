# 递归的思想与应用

- [递归代码示例](../eclipse/DataStructuresCode/src/Project_01_recursive_function.cpp)

## 1 递归是数学上分而治之的思想

- 将原问题分解为规模较小的问题进行处理
    - 分解后的问题与原问题类型完全相同，但规模较小
    - 通过小规模问题的解，能够轻易求得原问题的解
- 问题的分解是有限的（递归不能无限进行）
    - 当边界条件不满足时，分解问题（递归继续进行）
    - 当边界条件满足时，直接求解（递归结束）

### 1.1 递归模型的一般表示方法

![1525163251581](assets/1525163251581.png)


## 2 递归在程序设计中的应用

- 递归函数
  - 函数体中存在自我调用的函数
  - 递归函数`必须有递归出口`（边界条件）
  - 函数的`无限递归将导致程序崩溃`

### 2.1 递归求和

![1525163382095](assets/1525163382095.png)

- 代码实现：

```c
unsigned int sum(int n) {
    if (n > 1)
        return n + sum(n - 1);
    else if (n == 1) {
        return 1;
    }
}
```

### 2.2 斐波那契数列

![1525163413002](assets/1525163413002.png)

- 代码实现：

```c
unsigned int fac(int n) {
    if (n >= 3) {
        return fac(n - 1) + fac(n - 2);
    }

    if (n == 2)
        return 1;

    if (n == 1)
        return 1;
}
```
### 2.3 用递归的方法编写函数求字符串长度

![1525163475986](assets/1525163475986.png)

- 代码实现：

```c
unsigned int get_strlen(char *s) {
    if (*s != '\0')
        return 1 + get_strlen(s + 1);
    if (*s == '\0')
        return 0;
}
```
### 2.4 单向链表的转置

![1525184315854](assets/1525184315854.png)

- 代码实现：

```c
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
```

### 2.5 单向排序链表的合并

![1525184468714](assets/1525184468714.png)

- 代码实现：

```c
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
```

### 2.6 汉诺塔问题

![1525436823759](assets/1525436823759.png)

![1525436858718](assets/1525436858718.png)

- 代码实现：

```c
//汉诺塔问题：从 a 到 c, b 为中转站
void HanoiTower(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << "-->" << c << endl;
    } else {
        HanoiTower(n - 1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(n - 1, b, a, c);
    }
}
```

### 2.7 全排列问题

![1525441443912](assets/1525441443912.png)

- 代码实现：

```c
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
```

## 3 总结

- 递归是一种将问题`分而治之`的思想
- 用递归解决问题`首先要建立递归的模型`
- 递归解法`必须要有边界条件，否则无解`
- `不要陷入递归函数的执行细节`，学会通过代码描述递归问题，我们需要了解的是递归函数背后的递归模型，只要掌握了递归模型，递归函数仅仅是递归模型的描述而已。