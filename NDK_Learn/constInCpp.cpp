#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> //only for system("pause")
//测试环境
//OS：WIN10
//VS :VS2015
/*********************char const *charP *********************/
//char c1 = 'a';
//char c2 = 'b';
//char const c3 = 'c';
//const char c4 = 'd';
//char const * p1 = &c3; //指针可以变，内容不能通过指针改变
//
//char * const p2 = &c1; //指针不能变，内容可以通过指针改变
//
//const char * p3 = &c2; //指针可以变，内容不能通过指针改变 （等同于P1）
//
////const * char p4;     //不存在这个规则。
//
//char const * const p5 = &c4;//指针不能变，内容不能通过指针改变
//
//							//记忆规则，
//							//1 char 永远在 * 前面
//							//const 和 * 位置关系决定char 和 * 谁是const。
//							//char * const 表示(char *) const 表示指针本身是const
//void testStartInCpp()
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




//const char*  test() {//返回值内容不能更改
//	char * c = (char *)malloc(sizeof(char) * 18);
//	strcpy(c, "hello test");
//	return c;
//}
//char * const test2() {//同char * test2()
//	char * c = (char *)malloc(sizeof(char) * 18);
//	strcpy(c, "hello test");
//	return c;
//}
//int main()
//{
//	char cmc[2];
//	const char *c = test();
//	*c = 'c';
//	c = cmc;
//	printf("%s\n", c);
//	free((void*)c);//可以通过这个方式强行进行free
//	c = NULL;
//	char *c2 = test2();
//	*c2 = 'c';
//	printf("%s\n", c2);
//	free(c2);//允许
//	c2 = NULL;
//	system("pause");
//	return 0;
//}





/*********************const在函数后面*********************/
//
//void testc()const //只有在类中函数才能用const在后面修饰
//{
//}
//int global;
//class Weman {
//public :
//	int age;
//};
//class Man {
//public:
//	int age;
//	Weman weman;
//	void setAge1(int a)
//	{
//		global = a;
//		age = a;
//		weman.age = a;
//	}
//	void setAge2(int a) const //用const 不能修改类中变量的值
//	{
//		global = a;
//		age = a;
//		weman.age = a;
//	}
//};
//



/*********************const 类只能调用const函数*********************/
//
//
//void changeC() {
//	char* string = (char *)malloc(sizeof(char) * 10);
//	char* string2 = (char *)malloc(sizeof(char) * 10);
//	strcpy(string, "hello");
//	strcpy(string2, "word");
//	char * const c1 = string;
//	c1 = string2;
//	c1[1] = 'w';
//}
//
//
//class Man {
//public:
//	int age;
//	
//	void setAge1(int a)
//	{
//		age = a;	
//	}
//	void setAge2(int a) const //用const 不能修改类中变量的值
//	{
//		//age = a;
//	}
//};
//void test() {
//	Man man1;
//	const Man man2;
//	man1.setAge1(2);
//	man1.setAge1(2);
//	man2.setAge1(2);//const类不能调用非const函数
//	man2.setAge2(2);
//}