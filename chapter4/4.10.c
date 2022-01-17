/*

快速排序算法;先将一个集合分成两部分;根据第一个基准数字进行排序，便利所有数字小于基准数字的移到基准数字右边;
递归到集合元素数小于二 推出递归 开始递归下个子集,下个子集 也是同样的逻辑。
*/
#include <stdio.h>
extern void printArray(int *v);
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    printArray(v);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
        {
            swap(v, ++last, i);//++last 很关键 有两个作用(1) 将小于基准数移动到它右边 (2)标记小于它的数字 最后 调用 swap(v, left, last);将位置调换。
            printArray(v);     
        }
    swap(v, left, last);
    printArray(v);
    qsort(v, left, last - 1);
    printArray(v);
    qsort(v, last + 1, right);
}
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
//打印数组
void printArray(int *v)
{
    for (int p = *v; *v++; p = *v)
    {
        printf("%d", p);
    };
     printf("\n");
}
int main()
{
    int a[] = {8, 1, 7, 2, 4, 6, 9, 3, 5}, i;
    qsort(a, 0, 8);
    printArray(a);
};