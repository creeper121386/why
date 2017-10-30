#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int k,m,n,i,password;
    char a[500]={"0"};
    char fname1[50];
    char fname2[50];
    char encrypt[500]={0},decode[500]={0};
    //声明变量及数组

    printf("enter the name of the file to encrypt or decrypt:\n");
    scanf("%s",fname1);
    //输入想要进行加密/解密操作的文件名
    printf("enter the password:\n");
    scanf("%d",&password);
    //输入密码

    FILE *fpRead=fopen(fname1,"r");
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
       encrypt[i]=a[i]^password;
    }
    //将文件内容按位异或加密/解密，并将加密/解密后的内容储存在数组encrypt中

    printf("\noriginal code is %s\n",a);
    printf("\nencrypted/decrypted code is %s\n",encrypt);

    printf("enter the name of a new file to store the result:\n");
    scanf("%s",fname2);
    //生成一个新的文件存储加密/解密结果，输入该文件的名字

    FILE *pf1=fopen(fname2,"w+");
    for(m=0;m<500;m++)
    {
        putc(encrypt[m],pf1);
    }
    fclose(pf1);
    fflush(pf1);
    //创建新文件，并将数组encrypt写入该文件

    printf("the result has been written into %s.txt\n",fname2);
    return 0;
    //结束
}
