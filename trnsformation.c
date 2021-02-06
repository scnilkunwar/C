#include <stdio.h>

int points;
void input(int abscissa[], int ordinate[])
{
	printf("how many points?\n");
	scanf("%d", &points);
	
	for(int i=65;i<65+points;i++)
	{
		printf("enter %c's co-ordinates(x y):\n",i);
		scanf("%d %d", &abscissa[i-65], &ordinate[i-65]);
	}
}

void output(char operation[], int abscissa[], int ordinate[])
{
	printf("\n\n");
	puts(operation);
	
	for(int i=0;i<points;i++)
	{
		printf("%c'(%d, %d)\n",i+65, abscissa[i],ordinate[i]);
	}
}

int main()
{
	int option, x[20], y[20];
	
	again:
	printf("enter which transformation:\n");
	printf("1. reflection\n2. translation\n3. rotation\n4. enlargement\n");
	scanf("%d", &option);
	
	switch(option)
	{
		reflection:
		case 1: //reflection
		
			printf("enter option to calculate:\n");
			printf("1. reflection on x-axis\n2. reflection on y-axis\n3. reflection on y=x axis\n4. reflection on y=-x axis\n5. reflection on x=h axis\n6. reflection on y=k axis\n");
			scanf("%d", &option);
			
			switch(option)
			{
				case 1:  //reflection on x axis
					
					input(x, y);
				
					for(int i=0;i<points;i++)
					{
						y[i] = 0 - y[i];
					}
					
					output("reflection on x-axis\n", x, y);
					
				break;	//reflection on x axis close
					
				case 2: //reflection on y axis
					
					input(x, y);
				
					for(int i=0;i<points;i++)
					{
						x[i] = 0 - x[i];
					}
					
					output("reflection on y-axis\n", x, y);
					
				break; //reflection on y axis close
				
				case 3: //reflection on y=x axis
					
					input(x, y);
					
					output("reflection on y=x axis\n", y, x);
					
				break; //reflection on y=x axis close
					
				case 4:  //reflection on y=-x axis
					
					input(x, y);
					
					int temp;
					for(int i=0;i<points;i++)
					{
						temp = x[i];
						x[i] = -y[i];
						y[i] = -temp;
					}
					
					output("reflection on y=-x axis\n", x, y);
					
				break;  //reflection on y=-x axis close
					
				case 5: //reflection on x=h axis
					
					printf("enter value of h:\n");
					
					int h;
					scanf("%d",&h);
					
					input(x, y);
					
					for(int i=0;i<points;i++)
					{
						x[i] = 2*h-x[i];
					}
					
					output("reflection on x=h axis\n", x, y);
					
				break; //reflection on x=h axis close
					
				case 6: //reflection on y=k axis
					
					printf("enter value of k:\n");
					scanf("%d",&h);
					
					input(x, y);
					
					for(int i=0;i<points;i++)
					{
						y[i] = 2*h-y[i];
					}
					
					output("reflection on y=k axis\n", x, y);
					
				break; //reflection on y=k axis close
					
				default:
					printf("invalid option\n\n");
					goto reflection;
			}
			break; //reflection close
			
			case 2: //translation
				
				printf("enter translation vector(a b):\n");
				int a, b;
				scanf("%d %d",&a, &b);
				
				input(x, y);
					
				for(int i=0;i<points;i++)
				{
					x[i] += a;
					y[i] += b;
				}
					
				output("translation\n", x, y);
				
			break; //translation close
			
			rotation:
			case 3: //rotation
				
				printf("1. about origin\n2. about a point\n");
				scanf("%d", &option);
				
				switch(option)
				{
					aboutorigin:
					case 1: //about origin
					
						printf("enter rotation on:\n");
						printf("1. +90 or -270\n2. -90 or +270\n3. 180\n");
						scanf("%d", &option);
					
						switch(option)
						{
							case 1: //+90
							
								input(x, y);
					
								int temp;
								for(int i=0;i<points;i++)
								{
									temp = x[i];
									x[i] = -y[i];
									y[i] = temp;
								}
					
								output("rotation about +90\n", x, y);
							
							break; //+90 close
							
							case 2: //-90
								
								input(x, y);
								
								for(int i=0;i<points;i++)
								{
									temp = x[i];
									x[i] = y[i];
									y[i] = -temp;
								}
					
								output("rotation about -90\n", x, y);
							
							break; //-90 close
							
							case 3: //180
							
								input(x, y);
								for(int i=0;i<points;i++)
								{
									temp = x[i];
									x[i] = -y[i];
									y[i] = -temp;
								}
					
								output("rotation about 180\n", x, y);
								
							break; //180 close
							
							default:
								printf("\ninvalid option\n\n");
								goto aboutorigin;
						}
					
					break; //about origin close
					
					aboutpoint:
					case 2: //about point
					
						printf("enter rotation on:\n");
						printf("1. +90 or -270\n2. -90 or +270\n3. 180\n");
						scanf("%d", &option);
					
						switch(option)
						{
							case 1: //+90
								
								printf("enter center(a b):\n");
								scanf("%d %d",&a, &b);
							
								input(x, y);
					
								int temp;
								for(int i=0;i<points;i++)
								{
									temp = x[i];
									x[i] = -y[i] + a + b;
									y[i] = temp - a + b;
								}
					
								output("rotation about +90\n", x, y);
							
							break; //+90 close
							
							case 2: //-90
							
								printf("enter center(a b):\n");
								scanf("%d %d",&a, &b);
							
								input(x, y);
								for(int i=0;i<points;i++)
								{
									temp = x[i];
									x[i] = y[i] + a - b;
									y[i] = -temp + a + b;
								}
					
								output("rotation about -90\n", x, y);
								
							break; //-90 close
							
							case 3: //180
							
								printf("enter center(a b):\n");
								scanf("%d %d",&a, &b);
							
								input(x, y);
								for(int i=0;i<points;i++)
								{
									x[i] = 2*a - x[i];
									y[i] = 2*b - y[i];
								}
					
								output("rotation about 180\n", x, y);
								
							break; //180 close
							
							default:
								printf("\ninvalid option\n\n");
								goto aboutpoint;
						}
					
					break; //about point close
					
					default:
						printf("\ninvalid option\n\n");
						goto rotation;
				}
				
			break; //rotation close
			
			enlargement:	
			case 4: //enlargement
				
				printf("enter scale(k):\n");
				
				int k;
				scanf("%d",&k);
				
				printf("enter center(a b):\n");
				scanf("%d %d",&a, &b);
				
				input(x, y);
				
				for(int i=0;i<points;i++)
				{
					x[i] = k * (x[i] - a) + a;
					y[i] = k * (y[i] - b) + b;
				}
				
				output("enlargement\n", x, y);
			
			break; //enlargement close
				
			default:
				printf("\ninvalid option\n\n");
				goto again;
	}
	
	char ch;
	printf("\nyould you like to go again(y/n)?\n");
	scanf("%c",&ch);
	
	if(ch == 'y')
	{
		goto again;
	}
	
	else
	{
		printf("\nthank you");
	}
	return 0;
}
