// C语言文件操作

#include <stdio.h>
#include <stdlib.h>

//文件操作完成后，必须要在尾部对file关闭

int main() {
    printf("********C语言文件操作******\n");

    /**
     * 文件加解密
     * 1）二进制的方式进行加解密
     * 2）全部加密：对每一个字节进行加密，
     *    部分加密：只针对其中的一部分内容进行加密处理
     *    加密时对加密的字节进行异或操作，解密时同样进行异或操作，即可还原;
     *    异或的值在加解密中必须一致
     * 3)使用密钥进行加密，其实逐个取出密钥的每一个字符来进行对文件的每一个字节进行异或操作的加解密
     */
    char *fileCoding = "/Users/leonshi/Desktop/b.txt";
    char *fileEncode="/Users/leonshi/Desktop/b2.txt";//加密后的文件
    FILE * FileCoding = fopen(fileCoding,"rb");
    FILE * FileEncode=fopen(fileEncode,"wb");
    if (!FileCoding||!FileEncode)
    {
        printf("文件无法打开");
        exit(0);
    }
    int c;//接受读取的每一个字节
    while ((c=fgetc(FileCoding))!=EOF)
    {
        fputc(c^5,FileEncode);
    }

    fclose(FileCoding);
    fclose(FileEncode);







    /**
     * 文件大小
     * 1)系统没有提供专门获取文件大小的API
     * 2)思路：通过fseek 从文件头 挪动到文件尾部 将文件指针挪动的信息完善到文件指针中去
     *        再通过ftell 来读取指针挪动的信息，可以得到文件的length
     */
    char *fileSizeName = "/Users/leonshi/Desktop/b.txt";
    FILE * fileSize = fopen(fileSizeName,"rb");
    if (!fileSize)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    fseek(fileSize,0 ,SEEK_END);//会将文件挪动的信息完善到filesize 中去，需要通过ftell来获取
    long filelength = ftell(fileSize);
    printf("获取到文件的大小为：%ld\n",filelength);
    fclose(fileSize);



    /**
     * 文件复制
     * 1）通常会当成是二进制文件来复制
     * 2）如果是二进制读写就用 fread,fwrite;  不是二进制可以使用fgets,fputs来完成文件的读写
     */
    char *org = "/Users/leonshi/Desktop/b.txt";
    char *copy = "/Users/leonshi/Desktop/copy.txt";
    FILE *fileOrg = fopen(org, "rb");
    FILE *fileCopy = fopen(copy, "wb");
    if (!fileOrg || !fileCopy) {
        printf("文件打开失败");
        exit(0);
    }
    int buffer[512];
    int len;
    while ((len = fread(buffer, sizeof(int ), 512, fileOrg)) != 0) {
        fwrite(buffer, sizeof(int), len, fileCopy);
//        fputs(buffer,fileCopy);
    }
    fclose(fileOrg);
    fclose(fileCopy);


    /**
     * 文件写----fputs
     *
     */
    char *fileWName = "/Users/leonshi/Desktop/b.txt";
    FILE *fileW = fopen(fileWName, "w");
    if (!fileW) {
        printf("找不到文件\n");
        exit(0);
    }
    fputs("I want to write something to file:b.text", fileW);
    fclose(fileW);



    /**
     * 文件读----fopen
     * 1）参数1 ，文件路径
     * 2）模式：r ,w ,rb ,等
     * 3）返回值：结构体FILE
     */
    char *fileName = "/Users/leonshi/Desktop/a.txt";
    FILE *file = fopen(fileName, "r");
    char Buffer[100];
    while (fgets(Buffer, 100, file))//读取文件中的内存，按照指定的长度读取到缓存中去
    {
        printf("%s\n", Buffer);
    }
    fclose(file);


    return NULL;
}
