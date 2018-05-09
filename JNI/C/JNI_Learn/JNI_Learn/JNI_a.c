#include "stdafx.h"
#include "../../../java/a/JNI_a.h"
#include <string.h>
//https://www.2cto.com/kf/201412/364156.html
/*
*静态方法。 jclass jclz
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getStringFromC(JNIEnv *env, jclass jclz) 
{
	return (*env)->NewStringUTF(env, "this is String From C");
}



/*
*非静态方法。 jobject jobj
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getStringFromC2(JNIEnv *env, jobject jobj) 
{
	return (*env)->NewStringUTF(env, "this is String From C2");
}

/*
* 
*访问非静态属性String
*获得并修改属性
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getKey(JNIEnv *env, jobject jobj) 
{
	//jclass
	jclass jclz = (*env)->GetObjectClass(env, jobj);
	//field ID
	jfieldID fid = (*env)->GetFieldID(env, jclz, "key", "Ljava/lang/String;");
	//得到key的值
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	/***C中对key的值进行修改****/
	char * c_str = (*env)->GetStringUTFChars(env, jstr, NULL);
	
	char *newc_str = (char *)malloc(sizeof(char) * 100);
	strcpy(newc_str, c_str);
	strcat(newc_str, "_new");
	/*******/
	//C -> jni  将C中char* 变成jni需要的jstring
	jstring new_jStr = (*env)->NewStringUTF(env, newc_str);
	//key新的值 设置回到java中
	(*env)->SetObjectField(env, jobj, fid, new_jStr);
	//资源释放
	(*env)->ReleaseStringUTFChars(env, jstr, c_str);
	free(newc_str);
	newc_str = NULL;
	return new_jStr;
}


JNIEXPORT jint JNICALL Java_JNI_1a_getStringLength
(JNIEnv *env, jobject instance, jstring jstr) 
{
	char * cStrEncodeByUTF8 = (*env)->GetStringUTFChars(env, jstr, NULL);//将jstr转成UTF-8编码的char *
	char * cStrEncodeByUnicode = (*env)->GetStringChars(env, jstr, NULL);//将jstr转成Unicode编码的char *
	printf("utf-8: %s\n", cStrEncodeByUTF8);
	printf("unicode: %s\n", cStrEncodeByUnicode);
	//正确获得字节长度。
	//（这里如果cStrEncodeByUTF8="生活"的长度是6，不是2，因为一个中文字符占用了3个字节。)
	//（这里如果cStrEncodeByUTF8="OK"的长度是2，因为一个英文字符占用1个字节。)
	printf("utf-8 length %d\n", strlen(cStrEncodeByUTF8));
	//strlen可能不能正确的显示Unicode编码（有英文字符会发生错误）
	//（这里如果cStrEncodeByUnicode="生活"的长度是4，不是2，因为一个中文字符占用了2个字节。)
	//（这里如果cStrEncodeByUnicode="OK"的长度是1，unicode所有字符都用2字节，但是字母"O"占用一个字节，剩下的字节会用"\0"补齐，strlen遇到"\0"就停止了)
	printf("unicode length %d\n", strlen(cStrEncodeByUnicode));//错误
	return (*env)->GetStringUTFLength(env, jstr);
}