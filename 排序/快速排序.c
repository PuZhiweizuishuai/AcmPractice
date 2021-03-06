//快速排序

#include<stdio.h>
// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定


void sort(int *a, int left, int right);


int main(void)
{
	int a[10] = { 3,5,9,2,4,6,8,1,7,0 };
	int i;
	sort(a, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar();
	return 0;
}

void sort(int *a, int left, int right)
{
	if (left >= right)								/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
	{
		return;
	}
	int i = left;
	int j = right;
	int key = a[left];

	while (i < j)									/*控制在当组内寻找一遍*/
	{
		while (i < j && key <= a[j])				/*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
													序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/									
		{
			j--;/*向前寻找*/
		}

		a[i] = a[j];
		/*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
		a[left]，那么就是给key）*/

		while (i < j && key >= a[i])			/*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
												因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
		{
			i++;
		}

		a[j] = a[i];
	}

	a[i] = key;						/*当在当组内找完一遍以后就把中间数key回归*/
	sort(a, left, i - 1);			/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
	sort(a, i + 1, right);			/*用同样的方式对分出来的右边的小组进行同上的做法*/
									 /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}