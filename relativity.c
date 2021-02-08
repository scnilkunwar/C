#include <stdio.h>
#include <math.h>

int c = 300000000; 

double Gama(double v)
{
	double temp = (v*v)/(double)(c*c);
	double temp2 = 1 - temp;
	double temp3 = sqrt(temp2);
	return (1/temp3);
}

double alpha(double act_para, double change_para)
{
	double temp1 = act_para/change_para;
	double temp2 = 1 - temp1*temp1;
	double temp3 = sqrtf(temp2);
	return temp3;
}

double beta(double act_para, double change_para)
{
	double temp1 = change_para/act_para;
	double temp2 = 1 - temp1*temp1;
	double temp3 = sqrtf(temp2);
	return temp3;
}

int main()
{
	int option;
	start:
	printf("choose option\n1. length contraction\n2. time dilation\n3. mass increase\n");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1:
		optionn1:
		printf("\nchoose option to calculate\n1. actual length\n2. contracted length\n3. velocity\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("enter contracted length(l'): \n");
			double cont_l, v, act_l;
			scanf("%lf",&cont_l);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			double r = Gama(v);
			printf("actual length(l) is: %lf",r*cont_l);
			break;
			
			case 2:
			printf("enter actual length(l): \n");
			scanf("%lf",&act_l);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			r = Gama(v);
			printf("contracted length(l') is: %lf",act_l/r);
			break;
			
			case 3:
			printf("enter actual length(l): \n");
			scanf("%lf",&act_l);
			printf("enter contracted length(l'): \n");
			scanf("%lf",&cont_l);
			r = beta(act_l, cont_l);
			printf("velocity (v) is: %lf",r*(double)c);
			break;
			
			default:
			printf("invalid option!!\n\n");
			goto optionn1;
		}
		break;
		
		optionn2:
		case 2:
		printf("\nchoose option to calculate\n1. actual time\n2. changed time\n3. velocity\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("enter changed time(t'): \n");
			double chang_t, v, act_t;
			scanf("%lf",&chang_t);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			double r = Gama(v);
			printf("actual time(t) is: %lf",chang_t/r);
			break;
			
			case 2:
			printf("enter actual time(t): \n");
			scanf("%lf",&act_t);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			r = Gama(v);
			printf("changed time(t') is: %lf",act_t*r);
			break;
			
			case 3:
			printf("enter actual time(t): \n");
			scanf("%lf",&act_t);
			printf("enter changed time(t'): \n");
			scanf("%lf",&chang_t);
			r = alpha(act_t, chang_t);
			printf("velocity (v) is: %lf",r*(double)c);
			break;
			
			default:
			printf("invalid option!!\n\n");
			goto optionn2;	
		}
		break;
		
		optionn3:
		case 3:
		printf("\nchoose option to calculate\n1. actual mass\n2. changed mass\n3. velocity\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("enter changed mass(m'): \n");
			double chang_m, v, act_m;
			scanf("%lf",&chang_m);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			double r = Gama(v);
			printf("actual mass(m) is: %lf",chang_m/r);
			break;
			
			case 2:
			printf("enter actual mass(m): \n");
			scanf("%lf",&act_m);
			printf("enter velocity(v): \n");
			scanf("%lf",&v);
			r = Gama(v);
			printf("changed mass(m') is: %lf",act_m*r);
			break;
			
			case 3:
			printf("enter actual mass(m): \n");
			scanf("%lf",&act_m);
			printf("enter changed mass(m'): \n");
			scanf("%lf",&chang_m);
			r = alpha(act_m, chang_m);
			printf("velocity (v) is: %lf",r*(double)c);
			break;
			
			default:
			printf("invalid option!!\n\n");
			goto optionn3;	
		}
		break;
		default:
		printf("invalid option!!\n\n");
		goto start;
	}
	char ch;
	printf("\n\nwould you like to go again?(y/n)\n");
	scanf("%c",&ch);
	if(ch == 'y')
	{
		goto start;
	}
	else
	{
		printf("\nthank you!!");
	}
	return 0;
}
