package com.study.jnilearn;

import java.lang.System.*;

class HelloWorld {

	public int intVal = 6;

	private native int funInt(int arg1);
	
	private native String funStr(String arg1);

	private  native boolean funBool(boolean arg1);

	private native int funIntArr(int[] arg1 );

	public static void main(String[] args) {
		HelloWorld hw = new HelloWorld();

		String libraryDirs = System.getProperty("java.library.path");  
		System.out.println(libraryDirs);  


		System.out.println("call by java " + hw.funInt(511));
		System.out.println("call by java " + hw.funStr("faith"));
		System.out.println("call by java " + hw.funBool(true));
		int[] arrInt = new int[]{5,6,7,8,9};
		System.out.println("call by java " + hw.funIntArr(arrInt));	
		System.out.println(hw.intVal);
		
	}
	
	static { 
		System.loadLibrary("HelloWorld");  
		// System.load("/Users/satan_z/work/test/jniTest/lib/libHelloWorld.lib");
	} 
}
