#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> //only for system("pause")
//测试环境
//OS：WIN10
//VS :VS2015
/*********************const和指针变量*********************/
//char c1 = 'a';
//char c2 = 'b';
//char const c3 = 'c';
//const char c4 = 'd';
//char const * p1=&c3; //指针可以变，内容不能通过指针改变
//char * const p2=&c1; //指针不能变，内容可以通过指针改变
//const char * p3=&c2; //指针可以变，内容不能通过指针改变 （等同于P1）
////const * char p4;     //不存在这个规则。
//char const * const p5 = &c4;//指针不能变，内容不能通过指针改变
////记忆规则，
////1 char 永远在 * 前面
////const 和 * 位置关系决定char 和 * 谁是const。
////char * const 表示(char *) const 表示指针本身是const
//void testStartInC()
//{
//	p1 = &c2;
//	//*p1 = 'c';
//	//p2 = &c3;
//	*p2 = 'c';
//	p3 = &c1;
//	//*p3 = 'c';
//	//p5 = &c3;
//	//*p5 = 'c';
//}

/*********************const 函数返回值 *********************/
//const char*  test1() {//返回值内容不能更改
//	char * c = (char *)malloc(sizeof(char) * 18);
//	strcpy(c, "hello test");
//	return c;
//}
//char * const test2() {//同char * test2()
//	char * c = (char *)malloc(sizeof(char) * 18);
//	strcpy(c, "hello test");
//	return c;
//}
//char const * test3() {//返回值内容不能更改 （同test1()）
//	char * c = (char *)malloc(sizeof(char) * 18);
//	strcpy(c, "hello test");
//	return c;
//}
//int main()
//{
//	
//	const char *c = test1();
//	*c = 'c';//不允许修改
//	printf("%s\n", c);
//	free((void*)c);//可以通过这个方式强行进行free
//	c = NULL;
//	char *c2 = test2();
//	*c2 = 'c';
//	printf("%s\n", c2);
//	free(c2);
//	c2 = NULL;
//	const char *c3 = test3();
//	*c3 = 'c';//不允许修改
//	printf("%s\n", c3);
//	free((void*)c3);//可以通过这个方式强行进行free
//	c3 = NULL;
//	system("pause");
//	return 0;
//}



/*********************const形参 *********************/
////const在做形参的时候，和
//void test1(char * const c1, char const * c2, const char * c3 ,const char * const c4) 
//{
//	char c = 'c';
//	c1 = &c;  //不允许
//	*c1 = 'b';
//	c2 = &c;
//	*c2 = 'b';//不允许
//	c3 = &c;
//	*c3 = 'b';//不允许
//	c4 = &c;  //不允许
//	*c4 = 'b';//不允许
//}
//
//
//int main()
//{
//	system("pause");
//	return 0;
//}