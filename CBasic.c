//C语言基础语法学习知识点

/**
 * todo 引入标准库
 *
 * 尖括号   ：寻找系统的头文件
 * 双引号：寻找我们自己定义的头文件
 */
#include <stdio.h>

/**
 * 自定义一个函数，来修改值
 *
 * 1) 该函数需要写在main函数之上，如果确实需要在main之下，则就需要在main函数之上先做声明，
 * @param i
 */
void changeValueValid(int* i){
    *i=888;
}

//此函数是无法修改传入的变量的数据，因为形参和传如的变量的内存地址是不一样的
void changeValueInvalid(int i){
    printf("输出形参i的内存地址：%p\n",&i);
    i=999;
}


//使用指针来进行交换两个数据
void switchValues(int* number1,
                  int* number2){
    int temp = *number1;
    *number1=*number2;
    *number2=temp;
}

//所有的c程序的函数入库
int main() {

    /**
     * 函数修改数据，
     * 1)不允许函数的重载
     * 2）由于涉及函数进栈弹栈的问题,会导致修改变量的值无法成功，需要使用指针来进行修改
     */
     int org=666;
     printf("原数据变量的内存地址：%p\n",&org);
     changeValueInvalid(org);
     printf("chang函数执行前的org的值是:%d\n",org);
     changeValueValid(&org);
     printf("chang函数执行后的org的值是:%d\n",org);

     printf("*********************\n\n");
     int number1 = 123;
     int number2= 456;
     printf("通过指针交换 前  两个数据的值：number1=%d,number2=%d\n",number1,number2);
     switchValues(&number1,&number2);
     printf("通过指针交换  后  两个数据的值：number1=%d,number2=%d\n",number1,number2);
     printf("*********************\n\n");

    /**
     * 指针： 指针就是内存地址
     * 1）使用%p作为占位符输出；
     * 2）在变量名前使用&来取变量的内存地址
     * 3）在声明变量的数据类型后跟一个*   ，代表是声明一个数据类型的指针；
     * 4）在指针变量前面使用*,是取出来指针变量所指的内存地址的值
     * 5) 指针变量之所以有数据类型，是因为在读取指针所指向的内存地址的值时，系统可以知道取多少个字节的数据
     * 6) 指针的size和数据类型没关系，和系操作系统有关，比如：32位系统是8位，64位是16位
     */
     int point=200;
     printf("输出point的内存地址：%p\n",&point);

     //此处如果用指针的占位符来输出变量的值，则会输出16进制数据
     printf("输出point的内存地址：%p\n",*(&point));

     int* point_p=&point;
     printf("指针变量的大小：%d\n",sizeof point_p);
     printf("point_p指针所指的内存地址中的值是：%d\n",*point_p);

     //通过指针来修改变量的值

     *point_p=300;
     printf("通过指针来修改变量的值：%d\n",point);


    /**
    * 2、获取内存字节数  sizeof来获取字节数
    */
    printf("int 类型占用的字节数：%d\n", sizeof(int));



    /**
     * 1、基本数据类型的占位输出
     */

    int i = 100;
    double d = 200.001;
    float f = 300;
    long l = 400;
    short s = 500;
    char c = 'c';
    //字符串
    char *str = "hello world";

    printf("int类型占位i=%d\n", i);
    printf("double类型的占位 d=%lf\n", d);
    printf("float类型的占位 f=%f\n", f);
    printf("long类型的占位 l=%d\n", l);
    printf("short类型的占位:s=%d\n", s);
    printf("char类型的占位 c=%c\n", c);
    printf("字符串的占位 str=%s\n", str);


    getchar();//该函数是一个阻塞函数，用于程序执行的停留
    return NULL;
}



