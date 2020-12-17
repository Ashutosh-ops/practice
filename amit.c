#include<stdio.h>
int a;
void get(int n)
{
	a++;
	if(n<1) return ;
	get(n-1);
	get(n-3);
//	printf("%d\n",n);
}

int main()
{
	get(6);
	printf("%d\n",a);
	return 0;
}
