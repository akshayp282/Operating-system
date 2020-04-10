#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void sort(int a[],int size, int flag)
{
	int i;
	qsort(a,size, sizeof(int),cmpfunc);
	if(flag==1)
	{
		for(i=size-1;i>=0;i--)
		{
			printf(" -> %d",a[i]);
		}
	}
	else
	{
		for(i=0;i<size;i++)
		{
			printf(" -> %d",a[i]);
		}
	}
}


int main()
{
	int n,max,current,prev,*a,*q1,*q2;
	int i,total=0,j=0,k=0;
	int z1,z2,z3,f;
	char buffer[10],invalid[1];
	
	write(1,"Enter size of disk: ",strlen("Enter size of disk: "));
	z1=read(0,buffer,sizeof(buffer));
	max=atoi(buffer);
	
	write(1,"Enter number of pending requests: ",strlen("Enter number of pending requests: "));
	z1=read(0,buffer,sizeof(buffer));
	n=atoi(buffer);
	
	
	write(1,"Enter the current request (Should be less than size of size of disk): ",strlen("Enter the current request (Should be less than size of size of disk): "));
	z1=read(0,buffer,sizeof(buffer));
	current=atoi(buffer);
	if(current>=max || current<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		z2=read(0,invalid,1);
		return 0;
	}
		
	write(1,"Enter the previous request (Should be less than size of size of disk): ",strlen("Enter the previous request (Should be less than size of size of disk): "));
	z1=read(0,buffer,sizeof(buffer));
	prev=atoi(buffer);
	if(prev>=max || prev<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		z2=read(0,invalid,1);
		return 0;
	}

	a=(int*)malloc(n*(sizeof(int)));	
	q1=(int*)malloc(n*(sizeof(int)));
	q2=(int*)malloc(n*(sizeof(int)));
		
	write(1,"Enter the requests (Should be less than size of size of disk): ",strlen("Enter the requests (Should be less than size of size of disk): "));
	
	for(i=0;i<n;i++)
	{
		z1=read(0,buffer,sizeof(buffer));
		a[i]=atoi(buffer);
		if(a[i]>=max || a[i]<=0)
		{
			write(1,"Invalid request",strlen("Invalid request"));
			z2=read(0,invalid,1);
			return 0;
		}
		if(a[i]<current)
		{
			q1[j]=a[i];
			j++;	
		}
		else
		{
			q2[k]=a[i];
			k++;	
		}
			
	}

	if(current<prev)
	{
		printf("%d",current);
		sort(q1,j,1);
		printf(" -> 0");
		sort(q2,k,0);
		if(k==0)
			total= current;
		else	
			total=current+q2[k-1];
        	printf("/nTotal distance moved by disk arm is %d",total);						
	}
	else
	{
		printf("%d",current);
		sort(q2,k,0);
		printf("-> %d",max);
		sort(q1,j,1);
		if(j==0)
			total=max-current;
		else	
			total=max-current+max-q1[0];
		printf("\nTotal distance moved by disk arm is %d",total);
	}
	
	
	free(a);
	free(q1);
	free(q2);
	return 0;
}