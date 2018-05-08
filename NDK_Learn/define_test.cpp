#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> //only for system("pause")
//测试环境
//OS：WIN10 EN版本。
//VS :VS2015
//问题集
//所有以#开头的预处理，都是会绕过编译器的预编译的检查。

///*********************#define *********************/
//#define NUM 5
//int main()
//{
//	printf("%d", NUM);
//	system("pause");
//	return 0;
//}

/*********************#include  *********************/
////include 会把内容包含到位置上。
//
//#define NUM 5
//int main()
//{
//	#include "code.txt";
//	printf("%d", NUM);
//	system("pause");
//	return 0;
//}

/*********************#define  *********************/
////typedef 和#define 
//
////会将x，y进行比较，如果x,y是地址，就比较地址位置。
//#define MAX(x,y) (x)>(y)?x:y
//int main()
//{
//	char *cc = (char *)malloc(sizeof(char) * 20);
//	char *cc2 = (char *)malloc(sizeof(char) * 20);
//	strcpy(cc, "Hello");
//	strcpy(cc2, "AWorld");
//	char *cc3 = MAX(cc, cc2);
//	printf("%s\n", cc3);
//	int big = MAX(2, 3);
//	printf("%d", big);
//	free(cc);
//	cc = NULL;
//	free(cc2);
//	cc2 = NULL;
//	system("pause");
//	return 0;
//}

/*********************#include*********************/
//<>会先检查系统的头文件，例如vs中可以通过在解决方案右键。通用属性中->调试源文件 这就是VS给我们提供的系统头文件
//"" 是我们自己加到项目中的文件

/*********************#ifdef*********************/
//选择性编译，主要用来做平台兼容

#define X86_CPU
#ifndef ARM_CPU
#define ARM_CPU
#endif // !ARM_CPU
#ifdef X86_CPU
#undef X86_CPU
#endif // X86_CPU
int main() 
{
#ifdef ARM_CPU
	printf("this is arm cpu\n");
#endif 
#ifdef X86_CPU
	printf("this is x86 cpu\n");
#endif // X86_CPU
	system("pause");

}

