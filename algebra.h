#ifndef ALGEBRA_H_
#define ALGEBRA_H_
#endif /* ALGEBRA_H_ */

#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int reduct_zero(int i)
{
	if(i==0)
	{
		return 1;
	}
	else
		return i;
}

int compare(char *str,char c)
{
	int k=0,length=strlen(str);
	while(k!=length)
	{
		if(str[k]==c)
		{
			return 1;
		}
		k++;
	}
	return 0;
}

int expcmp(char *exp1,char *exp2)
{
	int k,count=0,l=strlen(exp1);
	for(k=0;k<l;k++)
	{
		if(compare(exp1,exp2[k])==1)
		{
			count++;
		}
	}
	if(count==strlen(exp1))
	{
		return 0;
	}
	else
		return 1;
}

int check_exp(char *exp)
{
	int k,count=-1;
	for(k=0;exp[k];k++)
	{
		if(isdigit(exp[k]))
		{
			count++;
			if(count!=k)
			{
				return 0;
			}
		}
	}
	return 1;
}

char *expstr(char *exp)
{
	int k,count=-1;
	char *ptr=(char*)malloc(100);
	if(ptr==NULL)
	{
		return NULL;
	}
	for(k=0;exp[k];k++)
	{
		if(!isdigit(exp[k]))
		{
			count++;
			ptr[count]=exp[k];
		}
	}
	count++;
	ptr[count]='\0';
	return ptr;

}

char *buildexp(int coeff,char *exp)
{
	int k,count=-1;
	char p[100],*build=(char*)malloc(100);
	sprintf(p,"%d",coeff);
	for(k=0;p[k];k++)
	{
		count++;
		build[count]=p[k];
	}
	k=0;
	for(k=0;exp[k];k++)
	{
		count++;
		build[count]=exp[k];
	}
	count++;
	build[count]='\0';
	return build;
}

char *add(char *exp1,char *exp2)
{
	char *end="\0";
	char *b1=(char*)malloc(100),*b2=(char*)malloc(100),*p1,*p2;
	int i1,i2,l1,l2;
	i1=atoi(exp1);
	i2=atoi(exp2);
	p1=expstr(exp1);
	p2=expstr(exp2);
	l1=strlen(p1);
	l2=strlen(p2);
	if(check_exp(exp1)==1&&check_exp(exp2)==1)
	{
		if(l1==0||l2==0)
		{
			printf("This is not an algebraic expression");
			return end;
		}
		if(l1!=l2)
		{
			b1=buildexp(reduct_zero(i1),p1);
			b2=buildexp(reduct_zero(i2),p2);
			strcat(b1,"+");
			strcat(b1,b2);
			return b1;
		}
		else
		{
			if(expcmp(p1,p2)==0)
			{
				b1=buildexp(reduct_zero(i1)+reduct_zero(i2),p1);
				return b1;
			}
			b1=buildexp(reduct_zero(i1),p1);
			b2=buildexp(reduct_zero(i2),p2);
			strcat(b1,"+");
			strcat(b1,b2);
			return b1;

		}
	}
	else
		printf("Invalid Expression!!!This operation has been terminated");
		return end;
}

char *subtract(char *exp1,char *exp2)
{
	char *end="\0";
	char *b1=(char*)malloc(100),*b2=(char*)malloc(100),*p1,*p2;
	int i1,i2,l1,l2;
	i1=atoi(exp1);
	i2=atoi(exp2);
	p1=expstr(exp1);
	p2=expstr(exp2);
	l1=strlen(p1);
	l2=strlen(p2);
	if(check_exp(exp1)==1&&check_exp(exp2)==1)
	{
		if(l1==0||l2==0)
		{
			printf("This is not an algebraic expression");
			return end;
		}
		if(l1!=l2)
		{
			b1=buildexp(reduct_zero(i1),p1);
			b2=buildexp(reduct_zero(i2),p2);
			strcat(b1,"-");
			strcat(b1,b2);
			return b1;
		}
		else
		{
			if(expcmp(p1,p2)==0)
			{
				b1=buildexp(reduct_zero(i1)-reduct_zero(i2),p1);
				return b1;
			}
			b1=buildexp(reduct_zero(i1),p1);
			b2=buildexp(reduct_zero(i2),p2);
			strcat(b1,"-");
			strcat(b1,b2);
			return b1;

		}
	}
	else
		printf("Invalid Expression!!!This operation has been terminated");
		return end;
}

