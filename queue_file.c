#include<stdio.h>

#include<stdlib.h>
#define MAX 50

FILE *fp1,*fp2,*fp3,*fp3,*fp4,*fp5,*in;

int i,j,k;

int queue_array[MAX];
int rear = - 1;
int front = - 1;
int choice;

main()

{
 int n,d,c,g;
 printf("enter the lenght of numbers\n");
 scanf("%d",&d);
 printf("enter range of numbers\n");
 scanf("%d",&n);
 int s[100];
    fp1=fopen("random.txt","w+");
    fp2=fopen("queue.txt","w+");
    fp3=fopen("dequeue.txt","w+");
    fp4=fopen("enqueue.txt","w+");
    fp5=fopen("operation.txt","w+");
    int a[100];
    in=fp1;
    int top=i;
    for(i=0;i<d;i++)
    {
     a[i]=(rand()%(n+1));
     fprintf(fp1,"%d ",a[i]);
     printf("%d ",a[i]);
      printf("\n");
    }
    while (1)
{
printf("1.Insert element to queue\ n");
printf("2.Delete element from queue \n");
printf("3.Display all elements of queue \n");
printf("4.Quit\ n");
printf("Enter your choice : \n");
scanf("%d", &choice);
switch(choice)
{
case 1:
    if(rear == MAX - 1)
        printf("Queue Overflow  n");
    else
        {
    if(front== - 1)
        front = 0;

        rear = rear + 1;
        queue_array[rear] = a[k];
        fprintf(fp4,"%d ",queue_array[rear]);

                k++;

                fprintf(fp5,"enqueue " );

        }

          break;
case 2:  if(front == - 1 || front > rear)
         {
        printf("Queue Underflow n");
            return;
        }
        else
        {

               fprintf(fp3,"%d ",queue_array[front]);
               fprintf(fp5,"dequeue ");
               front = front + 1;
        }

        break;
case 3:

        break;
case 4:printf("%d",rear);
     for(k=front;k<=rear;k++)
    {
     printf("%d ",queue_array[k]);
     fprintf(fp2,"%d ",queue_array[k]);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    exit(0);


default:break;

}

}





}
