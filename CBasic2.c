#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * C语言中的动态静态开辟内存空间
 */

//静态开辟
void staticAction(){
    printf("statcAction函数进栈\n");
    int arr[5*1024];//栈成员，今天在栈区开辟内存空间 20
    printf("statcinoAction函数弹栈\n");
}
//堆区动态开辟

void dynamicAction(){

    printf("堆区动态开辟40M的内存空间\n");
    int* arr =malloc(10*1024*1024);//40M
    printf("arr自己的内存地址：%p,  动态开辟的内存地址：%p\n",&arr,arr);

    free(arr);
    printf("释放arr后，悬空指针：arr自己的内存地址：%p,  指向的内存地址：%p\n",&arr,arr);

    arr=NULL;
    printf("悬空指针 指向NULL ,自己的内存地址：%p,  指向内存地址：%p\n",&arr,arr);

}

void dynamicAction2(){
    int number=0;
    printf("请输入开辟的数量\n");
    scanf("%d",&number);
    int * arr=malloc(number);

    //元素输入
    for(int i=0;i<number;i++){
        printf("请输入第%d的元素：",i);
        scanf("%d",arr+i);
    }

    //输出结果
    for (int i = 0; i < number; i++) {
        printf("输出元素结果是：%d\n",*(arr+i));
    }

    if (arr){
        free(arr);
    }
    arr=NULL;
}

//动态开辟后，再次改动，realloc函数的使用
void dynamicReallocAction(){
    int number=0;
    printf("用户输入大小：");
    scanf("%d",&number);
    int* arr = malloc(number);
    for (int i = 0; i < number; i++) {
        printf("第%d个元素的地址：%p\n",i,arr+i);
    }


    printf("请再次输入需要开辟的空间大小：");
    scanf("%d",&number);
    realloc(arr,number);
    for (int i = 0; i < number; i++) {
        printf("重新开辟---->第%d个元素的地址：%p\n",i,arr+i);
    }

    if (arr){
        free(arr);
    }
    arr=NULL;
}

int main() {

    /**
     * 3、动态开辟:在堆区开辟
     *  1) 堆区开辟的内存，在函数弹栈时，不会释放内存空间，在栈区开辟是可以释放的
     *  2) 通过free 来释放了内存后，会出现悬空指针，所以必须给指针指向null
     *      悬空指针：是指指针指向的内存地址已经被释放掉了，
     *  3）野指针：没有任何指向的指针就是野指针，如：int *p;
     *     C开发中要避免出现野指针，所以在声明指针时可以直接赋值一个NULL ,按照这个规范来编码
     *  4）使用场景：开辟的内存空间是动态变化的时，需要动态开辟
     *  5) scanf 函数，需要接受一个变量的地址用于接受用户输入的值
     *  6) realloc 返回值：会有与原地址不一致，系统会将原地址内容全部拷贝，并且重新开辟一个全新地址的内存
     *             所以这就是为什么要传入原内存地址和开辟空间的总大小
     *             返回NULL时，因为内存不够，导致开辟空间失败，所以在使用时需要做非NULL判断逻辑
     */

    dynamicReallocAction();
    printf("******************\n\n");


    dynamicAction2();
    printf("******************\n\n");


    for (int i = 0; i < 5; ++i) {
        dynamicAction();
    }
    printf("******************\n\n");


    /**
     * 2、静态开辟：在栈区开辟
     *
     * 1）栈区开辟内存空间，有大小限制（和平台相关，约 2M左右），要注意栈溢出的问题，堆区基本上不会出现
     * 2）函数开始执行时进栈，执行完时弹栈，弹栈就会释放全部的栈成员，所以写一个死循环调用函数不会出现栈溢出
     * 3）通过任务管理器来看看弹栈引起的内存变化
     */

    printf("死循环来执行函数进栈弹栈的效果\n");
    while (0){
        staticAction();
    }
    printf("******************\n\n");

    /**
     * 1、C语言中的bool 值
     *
     * 0 为 false ,非0 为true ,和java不一样
     */
    int bool = 100;
    if (bool) {
        printf("我是真:%d\n", bool);
    } else {
        printf("我是假的\n");
    }

    printf("******************\n\n");

    return NULL;
}
