package com.study.jnilearn;
import java.lang.System.*;

public class AccessMethod{
	
	public native static void callJavaStaticMethod(String str , int val);

	public native static void callJavaInstanceMethod(String str , int val);
	
	public static void main(String[] args){
		
		callJavaInstanceMethod("instance  " , 5);
		callJavaStaticMethod("static ", 6);
		
	}
	
	static{
		System.loadLibrary("AccessMethod");
	}
}
