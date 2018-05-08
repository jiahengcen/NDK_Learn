#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> //only for system("pause")
//测试环境
//OS：WIN10 EN版本。
//VS :VS2015
//问题集
//1在英文操作系统中，找不到中文路径。应该如何解决
//2如果read_fp为NULL，使用fclose会发生错误。要加NULL判断。
//3 rb 表示以二进制的方式进行读写
//4 如果文件大小大于long的最大值，怎么获得文件大小？
//5 rb和r处理fopen有区别，文件加解密，最好只用rb，wb

/*********************file read *********************/
//int main()
//{
//	char * path = "C:\\Project\\CProject\\NDK_test\\hello.txt";
//	FILE * fp = fopen(path, "r");
//	if (fp != NULL)
//	{
//		char buffer[100];
//		while (fgets(buffer, 100, fp))
//		{
//			printf("%s", buffer);
//		}
//
//	}
//	else
//	{
//		printf("use right path.");
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}



/*********************file write *********************/
//int main()
//{
//	char * path = "C:\\Project\\CProject\\NDK_test\\hello_write.txt";
//	FILE * fp = fopen(path, "w");
//	if (fp != NULL) 
//	{
//		char * w = "this is world need to write";
//		fputs(w, fp);
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}


/*********************file write二进制文件 *********************/
//fread 和fwrite的使用。
//如果read_fp为NULL，使用fclose会发生错误。要加NULL判断。
//?在英文操作系统中，找不到中文路径。应该如何解决
//int main() 
//{
//	char * read_path = "C:\\Project\\CProject\\NDK_test\\english.png";
//	//char * read_path = "C:\\Project\\CProject\\NDK_test\\函数指针实现Struct中函数.png";
//	char * write_path = "C:\\Project\\CProject\\NDK_test\\rite.png";
//	//rb 表示以二进制的方式进行读写
//	
//	FILE * read_fp = fopen(read_path, "rb");
//	//wite
//	//wb 表示以二进制的方式进行读写
//	FILE * write_fp = fopen(write_path, "wb");
//	char buff[50];
//	int len = 0;
//	//???如果这里我们用int来作为基本单位呢？
//	if (read_fp != NULL) 
//	{
//		while ((len = fread(buff, sizeof(char), 50, read_fp)) != 0)
//		{
//			fwrite(buff, sizeof(char), len, write_fp);
//		}
//	}
//	else 
//	{
//		printf("because use chinese,cause problem.");
//	}
//	if (read_fp != NULL) 
//	{
//		fclose(read_fp);
//	}
//	if (write_fp != NULL)
//	{
//		fclose(write_fp);
//	}
//	
//	system("pause");
//	return 0;
//}


/*********************file write二进制文件#不能使用的方法#*********************/
//fread 和fwrite的使用。

//int main() 
//{
//	char * read_path = "C:\\Project\\CProject\\NDK_test\\1.png";
//	//char * read_path = "C:\\Project\\CProject\\NDK_test\\函数指针实现Struct中函数.png";
//	char * write_path = "C:\\Project\\CProject\\NDK_test\\13.png";
//	//rb 表示以二进制的方式进行读写
//	
//	FILE * read_fp = fopen(read_path, "rb");
//	//wite
//	//wb 表示以二进制的方式进行读写
//	FILE * write_fp = fopen(write_path, "wb");
//	int buff[43];
//	int len = 0;
//	if (read_fp != NULL) 
//	{
//		while ((len = fread(buff, sizeof(int), 43, read_fp)) != 0)
//		{
//			fwrite(buff, sizeof(int), len, write_fp);
//		}
//	}
//	else 
//	{
//		printf("because use chinese,cause problem.");
//	}
//	if (read_fp != NULL) 
//	{
//		fclose(read_fp);
//	}
//	if (write_fp != NULL)
//	{
//		fclose(write_fp);
//	}
//	
//	system("pause");
//	return 0;
//}


/*********************file 文件大小ftell fseek*********************/
//?如果文件大小大于long的最多值怎么办？？？
//
//int main()
//{
//	char * read_path = "C:\\Project\\CProject\\NDK_test\\writeByInt.png";
//	FILE * fp = fopen(read_path, "r");
//	//ftell()返回的是当前流指针的位置。
//
//	if (fp != NULL) 
//	{
//		/*fseek(
//			FILE* _Stream, //文件流
//			long  _Offset,// 相对偏移量 可以使用
//			int   _Origin //这是表示开始添加偏移 offset 的位置。它一般指定为下列常量之一： SEEK_SET SEEK_CUR SEEK_END
//		);*/
//		//SEEK_SET	文件的开头
//		//SEEK_CUR	文件指针的当前位置
//		//SEEK_END	文件的末尾
//		fseek(fp, -10, SEEK_SET);
//		long currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//0
//		fseek(fp, 10, SEEK_SET);
//		currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//10
//		fseek(fp, 15, SEEK_CUR);
//		currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//25
//		fseek(fp, -5, SEEK_CUR);
//		currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//20
//		fseek(fp, 0, SEEK_END);
//		currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//26376 文件的大小
//		fseek(fp, 10, SEEK_END);
//		currentPosition = ftell(fp);
//		printf("currentPosition %ld.\n", currentPosition);//26386 
//	}
//	system("pause");
//	return 0;
//}

//result
/*
currentPosition 0.
currentPosition 10.
currentPosition 25.
currentPosition 20.
currentPosition 26376.
currentPosition 26386.
Press any key to continue . . .
*/


/*********************file 文本文件加密，解密*********************/
//经过两次异或运算，还是原来的数
//void encode(char normal_path[],char encode_path[])
//{
//	FILE * nor_fp = fopen(normal_path, "r");
//	FILE * encode_fp = fopen(encode_path, "w");
//	int ch;
//	if (nor_fp != NULL&&encode_fp!=NULL)
//	{
//		while ((ch = fgetc(nor_fp)) != EOF)
//		{
//			fputc(ch ^ 2, encode_fp);
//		}
//	}
//	if (nor_fp != NULL) 
//	{
//		fclose(nor_fp);
//	}
//	if (encode_fp != NULL)
//	{
//		fclose(encode_fp);
//	}
//}
//void decode(char encode_path[], char decode_path[])
//{
//	FILE * encode_fp = fopen(encode_path, "r");
//	FILE * decode_fp = fopen(decode_path, "w");
//	int ch;
//	if (encode_fp != NULL&&decode_fp != NULL)
//	{
//		while ((ch = fgetc(encode_fp)) != EOF)
//		{
//			fputc(ch ^ 2, decode_fp);
//		}
//	}
//	if (encode_fp != NULL)
//	{
//		fclose(encode_fp);
//	}
//	if (decode_fp != NULL)
//	{
//		fclose(decode_fp);
//	}
//}
//int main()
//{
//	char * read_path = "C:\\Project\\CProject\\NDK_test\\hello.txt";
//	char * encode_path = "C:\\Project\\CProject\\NDK_test\\hello_encode.txt";
//	char * decode_path = "C:\\Project\\CProject\\NDK_test\\hello_decode.txt";
//	encode(read_path, encode_path);
//	decode(encode_path, decode_path);
//
//	system("pause");
//	return 0;
//}

/*********************file 二进制文件加密，解密*********************/
//这里重点是rb和r区别，如果我们把rb变成r就会有出错。网上说在用r的时候，\n\r会当成一个字符。那我们如果在文字加解密的时候。是不是都不应该使用r或w
//
//
//void encode(char normal_path[], char encode_path[],char * password)
//{
//	FILE * nor_fp = fopen(normal_path, "rb");
//	FILE * encode_fp = fopen(encode_path, "wb");
//	int ch;
//	int pwd_lenth = strlen(password);
//	int i = 0;
//	if (nor_fp != NULL&&encode_fp != NULL)
//	{
//		while ((ch = fgetc(nor_fp)) != EOF)
//		{
//			fputc(ch ^ password[i%pwd_lenth], encode_fp);
//			i = (i++) % 10001;
//		}
//	}
//	if (nor_fp != NULL)
//	{
//		fclose(nor_fp);
//	}
//	if (encode_fp != NULL)
//	{
//		fclose(encode_fp);
//	}
//}
//void decode(char encode_path[], char decode_path[],char * password)
//{
//	FILE * encode_fp = fopen(encode_path, "rb");
//	FILE * decode_fp = fopen(decode_path, "wb");
//	int ch;
//	int pwd_lenth = strlen(password);
//	int i = 0;
//	if (encode_fp != NULL&&decode_fp != NULL)
//	{
//		while ((ch = fgetc(encode_fp)) != EOF)
//		{
//			fputc(ch ^ password[i%pwd_lenth], decode_fp);
//			i = (i++) % 10001;
//		}
//	}
//	if (encode_fp != NULL)
//	{
//		fclose(encode_fp);
//	}
//	if (decode_fp != NULL)
//	{
//		fclose(decode_fp);
//	}
//}
//int main()
//{
//	char * read_path = "C:\\Project\\CProject\\NDK_test\\1.png";
//	char * encode_path = "C:\\Project\\CProject\\NDK_test\\a.png";
//	char * decode_path = "C:\\Project\\CProject\\NDK_test\\b.png";
//	encode(read_path, encode_path,"Book");
//	decode(encode_path, decode_path,"Book");
//
//	system("pause");
//	return 0;
//}