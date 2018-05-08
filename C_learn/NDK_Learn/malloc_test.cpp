#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <Windows.h> //only for system("pause")
/***********test malloc 正常使用*********/
//int main()
//{
//	int * intMalloc = (int *)malloc(sizeof(int) * 10);
//	// use intMalloc here....
//
//
//	free(intMalloc);
//	intMalloc = NULL;//如果不改为NULL，将会变成野指针
//
//	system("pause");
//	return 0;
//}
//result
//程序正常运行、


/***********test malloc 重复释放*********/
//int main()
//{
//	int * intMalloc = (int *)malloc(sizeof(int) * 10);
//	
//	free(intMalloc);
//	free(intMalloc);//重复释放同一块内存会导致程序中断
//	system("pause");
//	return 0;
//}
//result
////程序中断出错 



/***********test 指向NULL free释放程序正常运行*********/
//int main()
//{
//	int * intMalloc = (int *)malloc(sizeof(int) * 10);
//
//	free(intMalloc);
//	intMalloc = NULL;//如果不改为NULL，将会变成野指针
//	free(intMalloc);//释放一块指向NULL的
//	system("pause");
//	return 0;
//}
//result
//这个例子也告诉我们，intMalloc被释放后及时的设置为NULL，还可以保障free不会出错
//程序正常运行


/***********test malloc 申请过大内存失败返回NULL*********/
//int main()
//{
//	int * bigMalloc = (int *)malloc(sizeof(int) * 1024 * 1024 *512);//分配2G内存，分配失败
//	size_t t = sizeof(int) * 1023 * 1023 * 1024*200;
//	printf("t is %u\n",t);
//	t = sizeof(int) * 1024 * 1024 * 512;
//	printf("t is %u\n", t);
//	if (bigMalloc == NULL)
//	{
//		printf("bigMalloc failed，内存分配失败\n");
//	}
//
//	system("pause");
//	return 0;
//}
//result 
//内存分配失败，bigMalloc==NULL 在内存分配使用的时候要做NULL判断



/***********test malloc 申请过大内存不失败的原因，计算精度导致的数值发生变化*********/
//int main()
//{
//	int * bigMalloc = (int *)malloc(sizeof(int) * 1024 * 1024 * 1024);//分配4G内存，分配成功，但是内存并不是4G
//	size_t t = sizeof(int) * 1024 * 1024 * 1024 * 200;
//	printf("t is %u\n", t);//0
//	//malloc的函数原型，void* __cdecl malloc(_In_ _CRT_GUARDOVERFLOW size_t _Size);
//	//在32位中，size_t是unsigned int  在64位中unsigned __int64
//	// typedef unsigned int     size_t;
//	//typedef unsigned __int64 size_t;
//	//当4 * 1024 * 1024 * 1024 * 200已经>int.MAX 就会出现我们t并不等于我们设置的算术结果
//	t = sizeof(int) * 1024 * 1024 * 512;
//	printf("t is %u\n", t);
//	if (bigMalloc == NULL)
//	{
//		printf("bigMalloc failed，内存分配失败\n");
//	}
//
//	system("pause");
//	return 0;
//}
//result
//程序结果未知，但是我们分配内存已经不符合我们正确的需求，程序有错误。



/***********test malloc 移动分配内存的指针，free报错*********/
//int main()
//{
//	int * intMalloc = (int *)malloc(sizeof(int) * 10);
//	intMalloc++;//移动分配内存指针
//	free(intMalloc);//intMalloc位置发生移动
//	intMalloc = NULL;
//	system("pause");
//	return 0;
//}
//result
//程序出错