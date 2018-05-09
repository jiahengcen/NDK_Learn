#include "stdafx.h"
#include <string>
#include "../../../java/a/JNI_a.h"
#define USE_CPP
#ifdef USE_CPP
/*
*静态方法。 jclass jclz
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getStringFromC(JNIEnv *env, jclass jclz)
{
	return (env)->NewStringUTF( "this is String From C++");
}
/*
*非静态方法。 jobject jobj
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getStringFromC2(JNIEnv *env, jobject jobj)
{
	return (env)->NewStringUTF( "this is String From C++2");
}

/*
*
*访问非静态属性String
*获得并修改属性
*/
JNIEXPORT jstring JNICALL Java_JNI_1a_getKey(JNIEnv *env, jobject jobj)
{
	jclass jcz = env->GetObjectClass(jobj);
	jfieldID fidKey = env->GetFieldID(jcz, "key", "Ljava/lang/String;");
	jobject str = env->GetObjectField(jobj, fidKey);
	const char *c_str = env->GetStringUTFChars((jstring)str, NULL);
	char* newc_str = new char[100];
	strcpy(newc_str, "I Love ");
	strcat(newc_str, c_str);
	jstring new_jstr = env->NewStringUTF(newc_str);
	env->SetObjectField(jobj, fidKey, new_jstr);
	env->ReleaseStringUTFChars(static_cast<jstring>(str), c_str);
	delete newc_str;
	newc_str = NULL;
	return new_jstr;
}

#endif // USE_CPP
