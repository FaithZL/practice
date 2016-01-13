#include <jni.h>
#include <iostream>
#include "com_study_jnilearn_HelloWorld.h"
// #include "HelloWorld.h"
using namespace std;

/*
 * Class:     HelloWorld
 * Method:    funIntß
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_com_study_jnilearn_HelloWorld_funInt(JNIEnv * jniEnv, jobject j, jint argInt)
{
	cout<<"call by C++  "<<argInt<<endl;
	return argInt;
}

/*
 * Class:     HelloWorld
 * Method:    funStr
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL 
Java_com_study_jnilearn_HelloWorld_funStr(JNIEnv * env, jobject j, jstring argStr)
{
	const char * cstr = env->GetStringUTFChars(argStr , 0);
	cout<<"call by C++  "<<cstr<<endl;
	char cap[128] = "language: ";
	strcat(cap, cstr);
	env->ReleaseStringUTFChars(argStr, cstr);
	return env->NewStringUTF(cap);
}

/*
 * Class:     HelloWorld
 * Method:    funBool
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL 
Java_com_study_jnilearn_HelloWorld_funBool(JNIEnv * jniEnv, jobject j, jboolean argBool)
{
	cout<<"call by C++  "<<argBool<<endl;
	return argBool;
}

/*
 * Class:     HelloWorld
 * Method:    funIntArr
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL 
Java_com_study_jnilearn_HelloWorld_funIntArr(JNIEnv * env, jobject j, jintArray argIntArr)
{
	cout<<"call by C++  "<<endl;
	jsize len = env->GetArrayLength(argIntArr);
	jint * p = env->GetIntArrayElements(argIntArr , 0);
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		cout<<"call by C++"<<p[i]<<endl;
		sum = sum + p[i];
	}
	env->ReleaseIntArrayElements(argIntArr , p , 0);
	return sum;
}





