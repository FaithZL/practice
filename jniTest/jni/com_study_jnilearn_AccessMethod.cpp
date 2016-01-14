#include <iostream>
#include "com_study_jnilearn_AccessMethod.h"

using namespace std;

/*
 * Class:     com_study_jnilearn_AccessMethod
 * Method:    callJavaStaticMethod
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_study_jnilearn_AccessMethod_callJavaStaticMethod
  (JNIEnv * env , jclass cls ,jstring str , jint val)
{
	jclass clazz = NULL;
	jmethodID mid_static_method = NULL;
	jstring str_arg = NULL;

	cout<<"start C++ "<<endl;

	clazz = env->FindClass("com/study/jnilearn/ClassMethod");

	if (clazz == NULL)
	{
		cout<<"can't find com/study/jnilearn/ClassMethod"<<endl;
		return;
	}
	mid_static_method = env->GetStaticMethodID(clazz , "callStaticMethod" ,"(Ljava/lang/String;I)V");

	if (mid_static_method == NULL)
	{
		cout<<"can't find static method   callStaticMethod"<<endl;
		return;
	}

	cout<<"call java method "<<endl;
	// str_arg = env->NewStringUTF("fuck");
	env->CallStaticVoidMethod(clazz , mid_static_method , str , val);
	//delete the local ref
	env->DeleteLocalRef(clazz);
	cout<<"end C++ function"<<endl;
}

/*
 * Class:     com_study_jnilearn_AccessMethod
 * Method:    callJavaInstanceMethod
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_study_jnilearn_AccessMethod_callJavaInstanceMethod
  (JNIEnv * env , jclass cls , jstring str , jint val)
{
	jclass clazz = NULL;
	jobject jobj = NULL;
	jmethodID mid_construct = NULL;
	jmethodID mid_instance = NULL;

	cout<<"start C++  "<<endl;

	clazz = env->FindClass("com/study/jnilearn/ClassMethod");
	if (clazz == NULL)
	{
		cout<<"can't find com/study/jnilearn/ClassMethod"<<endl;
		return;
	}

	mid_construct = env->GetMethodID(clazz , "<init>" , "()V");

	if (mid_construct == NULL)
	{
		cout<<"can't find default construct method"<<endl;
		return;
	}

	mid_instance = env->GetMethodID(clazz , "callInstanceMethod" , "(Ljava/lang/String;I)V");

	if (mid_instance == NULL)
	{
		cout<<"can't find callInstanceMethod"<<endl;
		return;
	}

	jobj = env->NewObject(clazz , mid_construct);
	if (jobj == NULL)
	{
		cout<<"can't create java object"<<endl;
		return;
	}
	cout<<"call java method "<<endl;
	env->CallVoidMethod(jobj , mid_instance , str ,val);

	env->DeleteLocalRef(clazz);
	env->DeleteLocalRef(jobj);
	cout<<"end C++"<<endl;
}








