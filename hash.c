#include<stdio.h>
#include<stdlib.h>
#define max 100
int create(int num)
{
	int key;
	key=num%100;
	return key;
}
void linearprob(int a[max],int key,int num)
{
	int flag=0,i,count=10;
	if(a[key]==-1)
		a[key]=num;
	else
	{
		for(i=10;i<max;i++)
			if(a[i]!=-1)
				count++;
		if(count==max)
		{
			printf("\nhash table is full\n");
			display(a);
			exit(1);
		}
		for(i=key+1;i<max;i++)
			if(a[i]==-1)
			{
				a[i]=num;
				flag=1;
				break;
			}
		for(i=10;i<key&&flag==0;i++)
			if(a[i]==-1)
			{
				a[i]=num;
				flag=1;
				break;
			}
	}
}
void display(int a[max])
{
	int i;
	printf("\nhash table is...\n");
	printf("key/index\temployee id\n");
	printf(".........................\n");
	for(i=10;i<max;i++)
		printf("\n%d %d\n",i,a[i]);
}
int main()
{
	int a[max],num,key,i;
	int ans;
	printf("collision handling by linear probing\n");
	for(i=10;i<max;i++)
		a[i]=-1;
	do
	{
		printf("\nEnter four digit number");
		scanf("%d",&num);
		key=create(num);
		linearprob(a,key,num);
		printf("do you want to continue?\n");
		scanf("%d",&ans);
	}while(ans==1);
	display(a);
	return 0;
}
