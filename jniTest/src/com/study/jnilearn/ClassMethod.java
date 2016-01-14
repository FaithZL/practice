package com.study.jnilearn;


public class ClassMethod{

    public static void callStaticMethod(String str , int val){
        
        System.out.println("string is " + str + ",num is " + val);
        
    }
    
    public void callInstanceMethod(String str , int val){
        
        System.out.println("string is " + str + ",num is " + val);
        
    }

}