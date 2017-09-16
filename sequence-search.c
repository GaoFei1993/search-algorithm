#include <stdio.h>
#include <stdlib.h>

//二分查找（折半查找），关键字取折中偏小值
int Binary_Search_Basic(int a[], int value, int n)
{
	int low, high, mid;
	low = 0; high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == value)
			return mid;
		else if (a[mid]>value)
			high = mid - 1;
		else if (a[mid]<value)
			low = mid + 1;
	}
	return -1;
}

//二分查找，递归版本
int Binary_Search_Recursion(int a[], int value, int low, int high)
{	
	int mid = low + (high - low) / 2;
	if ((a[0] > value) || (a[high] < value))//主要用于初始时刻做判断，后续判断实际没有意义
		return -1;
	
	if (a[mid] == value)
		return mid;
	else if (a[mid] > value)
		return Binary_Search_Recursion(a, value, low, mid - 1);
	else if (a[mid]<value)
		return Binary_Search_Recursion(a, value, mid + 1, high);
}

void Test_Binary_SearchTable(void)
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[10] = { 9, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int Position;
	int SearchKey;

	printf("请输入需要查找的数(不超过2位数)：");
	scanf_s("%d", &SearchKey, 2);
	Position = Binary_Search_Basic(a, SearchKey, 10);
	if (Position == -1)
		printf("没有找到查找值%d\n", SearchKey);
	else
		printf("查找值%d在数组a下标为%d的位置上！\n", SearchKey, Position);

	Position = Binary_Search_Recursion(b, SearchKey, 0, 9);
	if (Position == -1)
		printf("没有找到查找值%d\n", SearchKey);
	else
		printf("查找值%d在数组b下标为%d的位置上！\n", SearchKey, Position);
}
