#include "stdafx.h"
#include <Windows.h>
#include<iostream>
using namespace std;
int main()
{
	char str1[] = "abcde";
	char str2[] = "我是中国人";
	WCHAR str3[] = L"abcde";
	WCHAR str4[] = L"我是中国人";
	cout << sizeof(char) << endl;
	cout << "strlen(str1):" << strlen(str1) << endl;
	cout << "sizeof(str1):" << sizeof(str1) << endl;
	cout << "strlen(str2):" << strlen(str2) << endl;
	cout << "sizeof(str2):" << sizeof(str2) << endl;
	cout << "wcslen(str3)" << wcslen(str3) << endl;
	cout << "sizeof(str3):" << sizeof(str3) << endl;
	cout << "wcslen(str4)" << wcslen(str4) << endl;
	cout << "sizeof(str4):" << sizeof(str4) << endl;
	cout << str2 << endl;
	cout << str4 << endl;
	system("pause");
	return 0;
}