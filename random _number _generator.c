#include<stdio.h>

main()
{
int arr[100],i,j,temp;
FILE *fp;
fp=fopen("dsa.txt","w+");
for(i=0;i<100;i++)
{
    arr[i]=rand()%(1001);
    fprintf(fp,"%d\n",arr[i]);
    printf("%d\n",arr[i]);
}
for(i=0;i<100;i++)
{
    for(j=0;j<100;j++)
    {
        if(arr[j+1]>arr[j])
        {
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
}
fclose(fp);
fp=fopen("dsa.txt","w+");
for(i=0;i<100;i++)
{
    fprintf(fp,"%d\n",arr[i]);
}
}
