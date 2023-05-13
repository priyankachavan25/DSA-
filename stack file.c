#include<stdio.h>
#include<stdlib.h>

FILE *fp1,*fp2,*fp3,*fp3,*fp4,*fp5,*input;

int i,j,k;
int main()
{
 int n,d,c,g;
 printf("let the length of numbers\n");
 scanf("%d",&d);
 printf("Range of numbers is \n");
 scanf("%d",&n);
int s[100];
    fp1=fopen("random.txt","w+");
    fp2=fopen("stack.txt","w+");
    fp3=fopen("pop.txt","w+");
    fp4=fopen("push.txt","w+");
    fp5=fopen("operation.txt","w+");
    int a[100];
    input=fp1;
    int top=i;
    for(i=0;i<d;i++)
    {
     a[i]=(rand()%(n+1));
     fprintf(fp1,"%d ",a[i]);
     printf("%d ",a[i]);
      printf("\n");
    }
    while(1)
    {
        printf("1-push\n");
        printf("2-pop\n");
        printf("3-done\n");
        scanf("%d",&c);
        if(c==1)
        {

            if(k>d)
            {
                printf("stack is completed\n");

            }
            else
            {
                s[j]=a[k];
                fprintf(fp4,"%d ",a[k]);
                k++;
                j++;
                fprintf(fp5,"push " );

            }


        }
        else if(c==2)
        {
            if(top==-1)
            {
                printf("stack is empty\n");
            }
            else
            {
               j--;
               fprintf(fp3,"%d ",s[j]);
               fprintf(fp5,"pop ");
            }

        }
        else if(c==3)
        {
            break;
        }
        else
        {
            printf("invalid\n");
        }

    }
     for(k=0;k<j;k++)
    {
     printf("%d ",s[k]);
     fprintf(fp2,"%d ",s[k]);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);




}
