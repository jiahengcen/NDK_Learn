#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> //only for system("pause")
//测试环境
//OS：WIN10
//VS :VS2015
/*******************test calloc**********************/
int main()
{
	int * tempInt = (int *)calloc(10, sizeof(int));
	int i = 0;
	int *tt = tempInt;
	for (i; i < 10; i++) 
	{
		
		*tt = i;
		tt++;
	}
	i = 0;
	tt = tempInt;
	for (i; i < 10; i++)
	{
		printf("i is %d ,address is %#x\n", *tempInt,tempInt);
		tempInt++;
	}
	system("pause");
	return 0;
}
/**result**/
//分配的内存空间是连续的
/*
i is 0, address is 0x9b9090
i is 1, address is 0x9b9094
i is 2, address is 0x9b9098
i is 3, address is 0x9b909c
i is 4, address is 0x9b90a0
i is 5, address is 0x9b90a4
i is 6, address is 0x9b90a8
i is 7, address is 0x9b90ac
i is 8, address is 0x9b90b0
i is 9, address is 0x9b90b4
press any key to continue . . .
*/

/*******************test calloc**********************/
//int main()
//{
//	int * tempInt = (int *)calloc(10, sizeof(int));
//	int i = 0;
//	for (i; i < 10; i++)
//	{
//		tempInt[i] = i;
//	}
//	for (i; i < 10; i++)
//	{
//		printf("i is %d ,address is %#x\n", tempInt[i], &tempInt[i]);
//	}
//	system("pause");
//	return 0;
//}
/**result**/
//分配的内存空间是连续的,并且内存初始化为0
/*
i is 0, address is 0x949da0
i is 0, address is 0x949da4
i is 0, address is 0x949da8
i is 0, address is 0x949dac
i is 0, address is 0x949db0
i is 0, address is 0x949db4
i is 0, address is 0x949db8
i is 0, address is 0x949dbc
i is 0, address is 0x949dc0
i is 0, address is 0x949dc4
Press any key to continue . . .
*/
/*******************test calloc分配的空间是否连续**********************/
//struct BigData
//{
//	int array[100];
//	char cArray[100];
//};
//
//int main()
//{
//	
//	int i;
//	for (i = 0; i < 100; i++)
//	{
//		struct BigData * arrayList = (struct BigData*)calloc(i*100, sizeof(struct BigData));
//		if (arrayList == NULL)
//		{
//			printf("arrayList calloc failed, i is %d\n", &i);
//		}
//		else
//		{
//			int j;
//			int address = (int)arrayList;
//			memset(arrayList, 1, i * 100 * sizeof(struct BigData));
//			int size = sizeof(struct BigData);
//			for (j = 0; j < i*100; j++) 
//			{
//				//struct BigData * b = &arrayList[j];
//				if ((address + j*size) != (int)&arrayList[j])
//				{
//					printf("address is %#x, real is %#x", (address + j*size), &arrayList[j]);
//				}
//			}
//
//		}
//		free(arrayList);
//		arrayList = NULL;
//
//
//	}
//	system("pause");
//	return 0;
//}
//result
//在当前的测试当中，calloc分配的内存还是连续的。
//是否会出现不连续的情况，并不清楚。目前我们先当calloc的功能是malloc+memset(0)功能之和