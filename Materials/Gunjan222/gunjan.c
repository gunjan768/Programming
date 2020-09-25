#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
	return a;

	return b;
}

int check(int val)
{
	if(val<0)
	{	
		printf("You have entered the negative value\n");
		return 1;	
	}
	
	return 0;
}

void calculate(int n,int arrival[],int bus[])
{
	int complete[n+1],tat[n+1],i;
	int waiting[n+1]; 
	float avgWait=0,avgTAT=0;

	complete[0]=0;
	
	for(i=1;i<=n;i++)
	{
		int start=max(arrival[i],complete[i-1]);
		complete[i]=start+bus[i];
	}
	
	for(i=1;i<=n;i++)
	{
		tat[i]=complete[i]-arrival[i];

		waiting[i]=tat[i]-bus[i];
		
		if(waiting[i]<0)
		waiting[i]=0;
		
		avgWait+=waiting[i];
		avgTAT+=tat[i];
	}
	
	printf("\nComplete time\n");
	for(i=1;i<=n;i++)
	{
		printf("Process %d : %d\n",i,complete[i]);
	}

	printf("\nTotal around time\n");
	for(i=1;i<=n;i++)
	{
		printf("Process %d : %d\n",i,tat[i]);
	}

	printf("\nWaiting time\n");
	for(i=1;i<=n;i++)
	{
		printf("Process %d : %d\n",i,waiting[i]);
	}

	printf("\nAverage Total Around Time : %f\n",avgTAT/n);
	printf("\nAverage Waiting Time : %f\n",avgWait/n);
}

void sort(int arrival[],int bus[],int n)
{
	int i,j,ind;

	for(i=1;i<=n-1;i++)
	{
		int mn=arrival[i];
		int ind=-1;

		for(j=i+1;j<=n;j++)
		{
			if(mn>arrival[j])
			{
				mn=arrival[j];
				ind=j;
			}
		}
		
		if(ind!=-1)
		{
			int temp=arrival[i];
			arrival[i]=arrival[ind];
			arrival[ind]=temp;

			temp=bus[i];
			bus[i]=bus[ind];
			bus[ind]=temp;	
		}		
	}
}

int main()
{
	int n,i;
	
	printf("\nEnter the total number of process : ");
	scanf("%d",&n);
	
	if(check(n))
	return 0;

	int arrival[n+1],bus[n+1];
	
	printf("\nEnter the arrival time of each process\n");

	for(i=1;i<=n;i++)
	{
		printf("Process %d : ",i);
		scanf("%d",&arrival[i]);

		if(check(arrival[i]))
		return 0;
	}

	printf("\nEnter the bus time of each process\n");

	for(i=1;i<=n;i++)
	{
		printf("Process %d : ",i);
		scanf("%d",&bus[i]);

		if(check(bus[i]))
		return 0;
	}
	
	sort(arrival,bus,n);
	calculate(n,arrival,bus);
}
