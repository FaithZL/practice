package com.study.jnilearn;
import java.lang.System.*;

public class ClassField{

	private String _str;

	private static int _num;

	public int getNum(){
		return ClassField._num;
	}

	public void setNum(int num){
		_num = num;
	}

	public String getStr(){
		return _str;
	}

	public void setStr(String str){
		_str = str;
	}

}