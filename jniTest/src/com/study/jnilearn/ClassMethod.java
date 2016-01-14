package com.study.jnilearn;


public class ClassMethod{

    private static void callStaticMethod(String str , int val){
        
        System.out.println("type is " + str + ",num is " + val);
        
    }
    
    private void callInstanceMethod(String str , int val){
        
        System.out.println("type is " + str + ",num is " + val);
        
    }

}