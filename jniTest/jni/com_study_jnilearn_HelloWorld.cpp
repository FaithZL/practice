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
	jboolean isopy;
	printf("isCopy:%d\n",isopy);
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
	
	cout<<"Method 1:"<<endl;

	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		cout<<"call by C++"<<p[i]<<endl;
		sum = sum + p[i];
	}
	cout<<"the sum is "<<sum<<endl;
	env->ReleaseIntArrayElements(argIntArr , p , 0);

	cout<<"Method 2:"<<endl;
	sum = 0;
	//apply some buffer according by datatype and length
	jint * pInt = (jint *)malloc(sizeof(jint) * len);
	//initialize buffer
	memset(pInt , 0 , sizeof(jint) * len);
	//copy the argIntArr elements to the buffer. and  use SetIntArrayRegion(...) to change elements
	env->GetIntArrayRegion(argIntArr , 0 , len , pInt);

	for (int i = 0; i < len; ++i)
	{
		cout<<"call by C++  "<<pInt[i]<<endl;
		sum = sum + pInt[i];
	}
	free(pInt);
	cout<<"the sum is  "<<sum<<endl;
	cout<<"C++ end"<<endl;
	return sum;
}







