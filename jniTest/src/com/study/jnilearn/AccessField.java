package com.study.jnilearn;
import java.lang.System.*;


public class AccessField{

	public native static void accessStaticField();

	public native static void accessInstanceField(ClassField obj);

	public static void main(String[] args) {
		ClassField obj = new ClassField();
		obj.setNum(511);
		obj.setStr("wly");

		System.out.println("str :" + obj.getStr());
		System.out.println("num :" + obj.getNum());

		accessInstanceField(obj);
		accessStaticField();

		System.out.println("str :" + obj.getStr());
		System.out.println("num :" + obj.getNum());

	}

	static{
		System.loadLibrary("AccessField");
	}

}