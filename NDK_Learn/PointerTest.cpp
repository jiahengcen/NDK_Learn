#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> //only for system("pause")


//数组指针和指针数组
//int main()
//{
//	int a = 3;
//	int *temp1=&a;
//	int *temp2=&a;
//	//指针数组
//	int* intArray[2] = { temp1,temp2 };
//	//行指针         数值指针，也称行指针   
//	//P指向的数组
//	int(*p)[5];
//	int intArr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//	//p = intArr;
//	//p++;
//	p = &intArr[1];
//	//p = intArr[1];
//	printf("p is %d\n", (*p)[2]);
//	printf("p is %d\n", p[1][2]);
//	system("pause");
//    return 0;
//}


/////****************函数指针****************///
//int cal(int a, int b)
//{
//	return a + b;
//}
//int(*add)(int, int);
//int(*cal2)(void*, void*);
//使用这种方式优点是可以适配各种类型，缺点是，不知道真实的类型，在调用的时候，会出现错误。
//或许隐藏类型本身也是优点吧。
//int*(*cal3)(void*, void*);
//int main()
//{
//	int i1 = 1;
//	int i2 = 2;
//	add = cal;
//	add(3, 4);
//	cal2 = (int(*)(void*ss, void*sss))cal;
//	int result = cal2((void*)i1, (void*)i2);
//	printf("cal2 result is %d\n", result);
//	cal3 = (int*(*)(void*ss, void*sss))cal;
//	result = (int)(cal3((void*)i1, (void*)i2));
//	printf("cal3 result is %d\n", result);
//
//	system("pause");
//	return 0;
//}
