#include <stdio.h>

#include <math.h>

int main()
{
	int n;
	
	printf("how many elements?\n");
	scanf("%d",&n);
	
	int arr[n], i, x, j, m;
	
	printf("enter %d element(s)\n",n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	i = 0;
	j = n-1;
	
	printf("which elements to search?\n");
	scanf("%d",&x);
	
	while(i < j)
	{
		m = floorf((i+j)/2);
		
		if(x > arr[m])
		{
			i = m + 1;
		}
		
		else
		{
			j = m;
		}
		
	}
	
	if(x = arr[i])
	{
		printf("%d is in %d place", x, i+1);
	}
	
	else
	{
		printf("not found");
	}
	return 0;
}
