#include <stdio.h>

double power(double x, int n);
double slow_power(double x, int n);
int main()
{
	printf("recursive = %lf\n",power(2,5));
	printf("slow = %lf\n",slow_power(2,5));
	return 0;
}

double power(double x, int n){
	if(n==0) return 1;
	else if(n%2 == 0) return power(x*x,n/2);
	else return x*power(x*x,(n-1)/2);
}
double slow_power(double x, int n){
	int i;
	double result=1;
	for(i=0;i<n;i++){
		result *= x;
	}
	return result;
}
