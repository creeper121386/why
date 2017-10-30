#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int k,m,n,i,passwd;
    char a[500]={"0"};
    char fname[50];
    char encrypt[500]={0},decode[500]={0};
    sscanf(argv[2],"%d",&passwd);
    //声明变量及数组,将命令行参数的第三个参数转化为int类型供加密/解密使用

    FILE *fpRead=fopen(argv[3],"r");
    if(fpRead==NULL)
    {
    printf("error\n");
    exit(1);
    }
    //如果文件打开失败，打印“error”

    for(k=0;k<500;k++)
    {
        fscanf(fpRead,"%s",&a[k]);
    }
    //读取文件并储存在数组a中

    for(i=0;i<strlen(a);i++)
    {
       encrypt[i]=a[i]^passwd;
    }
    //将文件内容按位异或加密/解密，并将加密/解密后的内容储存在数组encrypt中

    printf("\nthe original code is %s\n",a);
    printf("\nencrypted/decrypted code is %s\n",encrypt);


    if(argv[1]=="-e")
        strcpy(fname,"encrypted.txt");
    if(argv[1]=="-d")
        strcpy(fname,"letter.txt");
    //若执行加密操作，则创建encrypted.txt，若执行解密操作则创建letter.txt，用于存放结果

    FILE *pf1=fopen(fname,"w+");
    for(m=0;m<500;m++)
    {
        putc(encrypt[m],pf1);
    }
    fclose(pf1);
    fflush(pf1);
    //创建新文件，并将数组encrypt写入该文件中

    printf("the result has been written into %s.txt\n",fname);
    return 0;
    //结束
}
