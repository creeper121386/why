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
    //��������������

    printf("enter the name of the file to encrypt or decrypt:\n");
    scanf("%s",fname1);
    //������Ҫ���м���/���ܲ������ļ���
    printf("enter the password:\n");
    scanf("%d",&password);
    //��������

    FILE *fpRead=fopen(fname1,"r");
    if(fpRead==NULL)
    {
    printf("error\n");
    exit(1);
    }
    //����ļ���ʧ�ܣ���ӡ��error��

    for(k=0;k<500;k++)
    {
        fscanf(fpRead,"%s",&a[k]);
    }
    //��ȡ�ļ�������������a��

    for(i=0;i<strlen(a);i++)
    {
       encrypt[i]=a[i]^password;
    }
    //���ļ����ݰ�λ������/���ܣ���������/���ܺ�����ݴ���������encrypt��

    printf("\noriginal code is %s\n",a);
    printf("\nencrypted/decrypted code is %s\n",encrypt);

    printf("enter the name of a new file to store the result:\n");
    scanf("%s",fname2);
    //����һ���µ��ļ��洢����/���ܽ����������ļ�������

    FILE *pf1=fopen(fname2,"w+");
    for(m=0;m<500;m++)
    {
        putc(encrypt[m],pf1);
    }
    fclose(pf1);
    fflush(pf1);
    //�������ļ�����������encryptд����ļ�

    printf("the result has been written into %s.txt\n",fname2);
    return 0;
    //����
}
