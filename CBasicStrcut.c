#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 结构体与结构体指针学习笔记
 * @return
 */

/**
 * 结构体----等同于java中的类
 * 结构体的定义---需要使用struct关键字 + 结构体的名字+{}+;
 */

struct Dog {
    char *name;
    int age;
    char color;
};

struct Student {
    char *name;


    struct HomeTown {
        char *province;
        char *city;
        char *country;
        char *detailStreet;
    } Home;

    //课程结构体
    struct Course {
        char *courseName;
        char *teacher;
    } Course;
} Zhangsan = {"张三",
              {"四川省",
               "成都市",
               "高新区",
               "xxxxx"
              },
              {"语文课",
               "李老师"}
};


//源码写法，给结构体取别名，方便代码统一
typedef struct {

}AAA;

typedef enum{
    t=9,
    t1,
    t2
}D;


void subStrAction(char *des, char *org, int startIndex, int endIndex) {
    for (int i = startIndex; i < endIndex; ++i) {
        *(des++) = *(org + i);
    }
}

int main() {

    /**
     * 枚举的使用
     * 1）类型都是int
     */

    D  d=t1;
    printf("%d\n",d);

    /**
     * 结构体及其指针的使用
     * 1）需要使用struct 来声明结构体变量，通过 点运算符来对结构体成员进行操作
     * 2）可以在声明结构体时，直接声明变量并给变量赋值
     * 3）结构体可以在内部嵌套使用,
     *    在对嵌套的结构体进行初始时，可以使用{}来对内部嵌套的结构体初始化，用于分割;
     *    调用结构体内部嵌套的结构体时，可以直接通过点运算符来内部结构体变量
     * 4）结构体指针通过->访问成员
     * 5) typedef 来给结构体取别名，方便兼容和扩展
     */
    //单独声明，
    struct Dog dog;
    dog.color = 'r';
    dog.name = "dog";
    dog.age = 12;
    printf("dog结构体的单独赋值：name=%s,age=%d,color=%c\n", dog.name, dog.age, dog.color);

    //声明结构体时声明
    printf("Person结构体声明时定义变量：student name= %s，来自：%s-%s-%s-%s,课程是：%s-%s\n",
           Zhangsan.name,
           Zhangsan.Home.province,
           Zhangsan.Home.city,
           Zhangsan.Home.country,
           Zhangsan.Home.detailStreet,
           Zhangsan.Course.courseName,
           Zhangsan.Course.teacher);

    //结构体指针:栈区开辟空间
    struct Dog *dog1 = &dog;
    dog1->name = "dog1";
    dog1->age = 5;
    dog1->color = 'b';
    printf("dog1结构体指针的单独赋值：name=%s,age=%d,color=%c\n",
           dog1->name, dog1->age, dog1->color);

    //结构体指针：堆区开辟
    struct Dog *dog2 = malloc(sizeof(struct Dog));
    dog2->name = "堆区dog";
    dog2->age = 3;
    dog2->color = 'y';
    printf("dog2结构体指针的单独赋值：name=%s,age=%d,color=%c\n",
           dog2->name, dog2->age, dog2->color);
    free(dog2);
    dog2=NULL;

    //结构体数组：栈区
    struct Dog dogs[] = {
            dog,
            dog1,
            dog2
    };
    printf("dog数组结构体指针的单独赋值：name=%s,age=%d,color=%c\n",
           (dogs)->name, (dogs)->age, (dogs)->color);


    //结构体：堆区
    struct Dog *dogMalloc = malloc(sizeof(struct Dog) * 10);

    dogMalloc->name = "Dog----";
    dogMalloc->age = 10;
    dogMalloc->color = 'r';

    printf("动态开辟的结构体：name=%s   age=%d   color=%c\n",
           dogMalloc->name, dogMalloc->age, dogMalloc->color);
    free(dogMalloc);
    dogMalloc = NULL;


    char *str = "helloworld";
    char result[10] ;
    subStrAction(result, str, 2, 7);
    printf("main函数截取的内容是：%s\n", result);

    

    return NULL;
}
