//
// Created by leonshi on 2021/3/16.
//

/**
 * C语言实战---字符串
 */
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>


int getLength(char* string){
    int count =0;
    while (*string){//当没有找到字符串的\0结束符时，会一直循环
        string++;
        count++;
    }
    return count;
}

void toCharLower(char* org,char * lowerStr){
    char* temp = org;
    while (*temp){
        *lowerStr=tolower(*temp);
        lowerStr++;
        temp++;
    }
    *lowerStr++='\0';
    printf("全部小写后的结果：%s\n",lowerStr);
}

int main(){

    /**
     * 大小写的转换
     */
     char* name ="leon";
     char results[30];
    toCharLower(name,results);

    /**
     * 字符串的拼接
     * strcat,strcopy 函数
     */
     char des[25];
     char* first ="hi";
     char second[]={',','y','o','u','\0'};
     char* third="-";
     strcpy(des,first);
     strcat(des,second);
     strcat(des,third);
     printf("拼接的结果:%s\n",des);


    /**
     * 字符串的查询
     * strstr 函数 查找是否存在莫个subString，存在则返回第一次出现的位置开始的子字符串
     */
     char * text ="hellowrold";
     char * subText="o";
     char* pop=strstr(text,subText);
    if (pop){
        //不为NULL ,表示找到了子字符串
        printf("找到子字符串了：%s\n",pop);
    }else{
        //没有找到
        printf("没有找到\n");
    }


     //取出字符串的位置
     int index = pop-text;
     printf("位置:%d\n",index);

    /**
     * 字符串的比较  strcmp
     *
     * 0:代表相同，
     * 非0 则不同， 大于0 ，表示前者大于后者；小于0 ，表示前者小于后者 ASSIC码的比较
     */
     char *cmpStr1="helloworld";
     char * cmpStr2="helloworld";
     int result =strcmp(cmpStr1,cmpStr2);
     printf("字符串比较的结果：%d\n",result);

    /**
     * 字符串的转换  atoi ,atol等stdlib.h下面的函数
     * 1) 返回0 ，则代表转换失败，非0 则代表转换成功
     */
     char* num="2";
     printf("字符串转化为整数的结果是：%d\n",atoi(num));



    /**
     * 指针挪动获取值
     *
     * 1）不会统计\0结束符的长度,\0使用时，int类型会冲突
     * 2）数组作为参数传递，为了高效，会把数组优化成指针
     * 3）C语言比较少的使用返回值来返回函数的结果，而是通过将接收返回值的变量的地址传递进去，直接修改内存地址中的值，这样效率更高
     *
     */
     char moveStr[]={'h','e','l','l','o','\0'};
     printf("moveStr字符串的长度是： %d\n",getLength(moveStr));
    int length = sizeof moveStr /sizeof (char );
    printf("moveStr字符串的长度是： %d\n",length);


    /**
     * 字符串的两种表现方式
     * 1、字符数组
     * 2、字符指针
     *
     * 两种方式的差异点：
     * 1) 需要在字符数组中手动添加'\0'作为字符串的结束，否则会出现尾部系统的值的乱码，而字符指针则系统会默认添加，不需要手动添加
     * 2）字符数组可以通过下标直接修改，而字符指针如果用数组下标的方式会出现不允许访问的crash,由于字符串是在静态区域存放
     */

    //字符数组
    char str[]={'h','e','l','l','o'};
    str[0]='H';
    printf("字符数组的打印：%s\n",str);

    //字符指针
    char * strP="hello";
//    strP[0]='H';//此处会出现crash
    printf("字符指针的打印：%s\n",strP);


   return NULL;
}
