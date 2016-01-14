package com.study.jnilearn;
import java.lang.System.*;

public class ClassField{

	private String _str;

	private static int _num;

	public ClassField(){
		_str = "defaut";
		_num = 10000;
	}

	public ClassField(String str , int num){
		_str = str;
		_num = num;
	}

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