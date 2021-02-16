#include <stdio.h>
#define n 100

float det(float matrix[n][n], int order)
{
	float deter;
	float minor[n][n];
	if(order == 2)
	{
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}
	
	else
	{
		float temp = matrix[0][0], temp1;
		
		// making a11 = 1
		for(int j=0;j<order;j++)
		{
			matrix[0][j] = matrix[0][j] / temp;
		}
		
		// making c1 = (1, 0, 0)
		for(int i=1;i<order;i++)
		{
			temp1 = matrix[i][0];
			for(int j=0;j<order;j++)
			{
				matrix[i][j] = matrix[i][j] - (matrix[0][j] * temp1);
			}
		}
		
		// making minor matrix
		for(int i=1;i<order;i++)
		{
			for(int j=1;j<order;j++)
			{
				minor[i-1][j-1] = matrix[i][j];
			}
		}
		
		return temp * det(minor, order-1); 
	}
}

int main()
{
	int order;
	float matrix[n][n];
	
	printf("enter matrix order: ");
	scanf("%d",&order);
	
	printf("enter matrix elements:\n");
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			printf("enter a%d%d: ",i+1, j+1);
			scanf("%f",&matrix[i][j]);
		}
	}
	
	for(int i=0;i<order;i++)
	{
		printf("|");
		for(int j=0;j<order;j++)
		{
			printf(" %.2f",matrix[i][j]);
		}
		printf(" |\n");
	}
	
	float detrmnt = det(matrix, order);
	
	printf("\n determinand is %.2f",detrmnt);
	
	return 0;
}
