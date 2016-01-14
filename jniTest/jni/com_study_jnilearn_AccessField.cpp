#include "com_study_jnilearn_AccessField.h"
#include <iostream>

using namespace std;

/*
 * Class:     com_study_jnilearn_AccessField
 * Method:    accessStaticField
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_study_jnilearn_AccessField_accessStaticField
  (JNIEnv * env, jclass cls)
{

	jclass clazz = NULL;
	jfieldID fid = NULL;
	jint j_num = 0;
	jint j_new_num = 0;

	cout<<"start C++"<<endl;
	clazz = env->FindClass("com/study/jnilearn/ClassField");

	fid = env->GetStaticFieldID(clazz , "_num" , "I");

	j_num = env->GetStaticIntField(clazz , fid);

	cout<<"in C++ _num is "<<j_num<<endl;

	env->SetStaticIntField(clazz , fid , 630);

	cout<<"end C++"<<endl;


	//test 

	cout<<"start test"<<endl;

	jobject jobj = NULL;

	jmethodID mid = NULL; 
	mid = env->GetStaticMethodID(cls , "accessInstanceField" , "(Lcom/study/jnilearn/ClassField;)V");

	if(mid == NULL)
	{
		cout<<"mid no found"<<endl;
		return;
	}

	jmethodID mid_con = NULL;
	mid_con = env->GetMethodID(clazz , "<init>" , "(Ljava/lang/String;I)V");

	if (mid_con == NULL)
	{
		cout<<"con mid no found !"<<endl;
		return;
	}

	jstring j_str = env->NewStringUTF("test");

	jobj = env->NewObject(clazz , mid_con , j_str , 780);

	if (jobj == NULL)
	{
		cout<<"obj create fail"<<endl;
		return;
	}

	env->CallStaticVoidMethod(clazz , mid , jobj);
	env->DeleteLocalRef(clazz);
	env->DeleteLocalRef(jobj);

}

/*
 * Class:     com_study_jnilearn_AccessField
 * Method:    accessInstanceField
 * Signature: (Lcom/study/jnilearn/ClassField;)V
 */
JNIEXPORT void JNICALL Java_com_study_jnilearn_AccessField_accessInstanceField
  (JNIEnv * env, jclass cls, jobject jobj)
{
	jclass clazz = NULL;
	jfieldID fid = NULL;
	jstring j_str = NULL;
	jstring j_new_str = NULL;
	const char * c_str = NULL;

	cout<<"start C++"<<endl;
	printf("%p\n", env);
	cout<<jobj<<endl;



	clazz = env->GetObjectClass(jobj);
	if (clazz == NULL)
	{
		cout<<"class was no found"<<endl;
		return;		
	}

	fid = env->GetFieldID(clazz , "_str" , "Ljava/lang/String;");
	if (fid == NULL)
	{
		cout<<"_str field no found"<<endl;
		return;
	}

	j_str = (jstring)env->GetObjectField(jobj , fid);
		
	c_str = env->GetStringUTFChars(j_str , NULL);
	if(c_str == NULL)
	{
		cout<<"c_str create fail"<<endl;
		return;
	}
	printf("in C++  str is %s\n", c_str);
	env->ReleaseStringUTFChars(j_str , c_str);
	j_new_str = env->NewStringUTF("angel");
	if(j_new_str == NULL)
	{
		cout<<"newString create fail"<<endl;
		return;
	}
	env->SetObjectField(jobj , fid , j_new_str);

	env->DeleteLocalRef(j_new_str);
	env->DeleteLocalRef(j_str);
	env->DeleteLocalRef(clazz);
	cout<<"end C++"<<endl;

}












