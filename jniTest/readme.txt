g++ -dynamiclib -o libhelloworld.jnilib HelloWorld.cpp -framework JavaVM -I /Library/Java/JavaVirtualMachines/jdk1.7.0_79.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk1.7.0_79.jdk/Contents/Home/include/darwin
以上命令用于编译生成外部链接库文件供java调用

1.编写声明了 native 方法的 Java 类

2.将 Java 源代码编译成 class 字节码文件
mac 下命令为
javac dir/fileName -d targetDir

3.用 javah -jni 命令生成.h头文件（javah 是 jdk 自带的一个命令，-jni 参数表示将 class 中用native 声明的函数生成 JNI 规则的函数）

javah -jni -d ./jni -classpath ./bin className
-d means target directory
-o Specify the file name 
-classpath search path

4.用本地代码实现.h头文件中的函数

implement the function with cpp file

5.将本地代码编译成动态库（Windows：\*.dll，linux/unix：\*.so，mac os x：\*.jnilib）

mac command

g++ -dynamiclib -o dir/fileName xxx.cpp -framework JavaVM -I $JAVA_HOME/include -I $JAVA_HOME/include/darwin 

-dynamiclib: means generate a dynamic library 
-o: means target directory and file name
-I: include jni.h path and jni_md.h path

tips:
with filaName
win32: ClassName.dll
unix/linux: libClassName.so
mac os x: libClassName.jnilib



6.拷贝动态库至 java.library.path 本地库搜索目录下，并运行 Java 程序

java -classpath ./bin -Djava.library.path=libPath className



