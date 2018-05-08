#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <Windows.h> //only for system("pause")

/******************* char 的基本操作 *******************/
//int main()
//{
//	char* ch = (char*)malloc(sizeof(char) * 100);//ch内存没有初始化，在结尾要加上\0不然会出现意想不到的结果
//	ch[0] = 'C';
//	ch[1] = 'H';
//	ch[2] = 'I';
//	ch[3] = 'N';
//	ch[4] = 'A';
//	ch[5] = '\n';
//	ch[6] = EOF;
//	ch[7] = 'a';
//	ch[6] = '\0';
//	printf("%s", ch);//'\0'和EOF都是char的结束符。
//	
//	char a[100] = {'M','C','I','N','A','\n'};//a内存初始化
//	printf("%s", a);//
//	char cc[] = "china";
//	cc[2] = 'c';//程序不报错，cc大小为6，是china+'\0'大大小
//	char *charPoint = "china";
//	charPoint[2] = 'c';//程序报错，我们给charPoint指向常量区，修改就会报错。
//	printf("%s", cc);//
//	system("pause");
//	return 0;
//}


/******************* char strcpy *******************/
//int main()
//{
//	char* ch = (char*)malloc(sizeof(char) * 100);
//	strcpy(ch, "china");//会自动在china后面加入\0
//	printf("%s", ch);//打印china，后面没有乱码
//	printf("\n");
//	strcat(ch, " great");
//	printf("%s", ch);
//	system("pause");
//	return 0;
//}


///******************* char strcat *******************/
//int main()
//{
//	char* ch = (char*)malloc(sizeof(char) * 7);
//	strcpy(ch, "china");//会自动在china后面加入\0
//	printf("%s", ch);//打印china，后面没有乱码
//	printf("\n");
//	strcat(ch, " great");//将great 拼接到china后面。
//	//这里要注意的是，ch我们分配的地址空间。
//	//如果我们分配一个很小的地址空间，我们字符超过了我们分配的空间
//	//程序不会报错。但是程序已经访问其他地址。修改了其他地址，这会导致我们程序出现严重的bug
//	int i = 0;
//	for (i; i < 1000; i++) 
//	{
//		strcat(ch, " great");
//	}
//	printf("%s", ch);
//	printf("\n");
//	system("pause");
//	return 0;
//}