#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *fp;
    fp=fopen("dsa.txt","w");
    int n;
    printf("\nEnter number: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);
    fp=fopen("dsas.txt","r");
    int m;
    printf("\nEnter sorting number: ");
    scanf("%d",&m);
    int a1[m];
    for(int i=0;i<m;i++)
    {
        fscanf(fp,"%d",&a1[i]);
    }
    fclose(fp);
    /*for(int i=0;i<m;i++)
    {
        printf("%d ",arr1[i]);
    }*/
    time_t t1,t2,t;
    t1=time(NULL);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-1-i;j++)
        {
            if(a1[j]>a1[j+1])
            {
                int temp=0;
                temp=a1[j];
                a1[j]=a1[j+1];
                a1[j+1]=temp;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        printf("%d ",a1[i]);
    }
    t2=time(NULL);
    t=t2-t1;
    printf("\n\nTime %d",t);
}
