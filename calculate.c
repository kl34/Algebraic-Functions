#include<stdio.h>
#include<string.h>
#include"algebra.h"
int main()
{
	char exp1[100],exp2[100];
	gets(exp1);
	gets(exp2);
	printf("%s",subtract(exp1,exp2));
	return 0;
}
