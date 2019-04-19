#include <stdio.h>
//다시해보기 
int factorial(int n);
int factorial_(int n); 
int main()
{
	printf("%d\n",factorial(5));
	printf("%d\n",factorial(5));
	
	
	return 0;
}

int factorial(int n){
	if(n<=1) return 1;
	else return n*factorial(n-1);
}
int factorial_(int n){
	int i, v=1;
	for(i=n;i>0;i--)
		v *= i;
	return v;
}
