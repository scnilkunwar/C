#include <stdio.h>

int main()
{
	int n, i, x;
	
	printf("how many elements?\n");
	scanf("%d",&n);
	
	int arr[n];
	
	printf("enter %d elements\n",n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("which elements to search?\n");
	scanf("%d",&x);
	
	i=0;
	while(i <= n && arr[i] != x)
	{
		i++;
	}
	
	if((i+1) <= n)
	{
		printf("%d is in %d place",x, i+1);
	}
	
	else
	{
		printf("%d is not found",x);
	}
	
	return 0;
}
