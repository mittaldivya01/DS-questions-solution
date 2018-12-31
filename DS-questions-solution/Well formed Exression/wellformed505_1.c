#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalpostfix(char* str);
int evaluation(int b,int a,char op);

int main(int argc, char* argv[])
{
char* str;
int i=0,len,op=0,parcount=0,ans=0;
str=argv[1];
len=strlen(str);
for (i=0;i<len; i++)
{//printf("\n %c",str[i]);
if (str[i]=='+' || str[i]=='-' || str[i]=='*' ||str[i]=='/')
--op;
else if (str[i]==' ')
continue;
else if (str[i]=='(')
++parcount;
else if (str[i]==')')
--parcount;
else
++op;

if(parcount<0)
{printf("error");
return 0;
}
}
if (op==1 && parcount==0)
printf("%d",ans=evalpostfix(str));
else
printf("error");

return 0;
}

int evalpostfix(char* str)
{int len,top=-1,i=0,a,b;
len=strlen(str);
char stack[len];
char op;
for (i=0;i<len; i++)
{
if (str[i]==' ' || str[i]=='(')
continue;
else if (str[i]==')')
{b=stack[top]-'0';
//printf("%d ",b);
--top;
op=stack[top];
--top;
a=stack[top] -'0';
//printf("%d",a);
stack[top]=evaluation(b,a,op) + '0';
//printf("\n %d \n",stack[top]);
//stack[top]=tmp;
}
else
{++top;
//printf("%d ",str[i]);
stack[top]=str[i];
//printf("%d \n",stack[top]);
}
}
return stack[top]-'0';
}

int evaluation(int b,int a,char op)
{
if (op=='+' ) 
return (a + b);

else if (op=='-' ) 
return (a - b);

else if (op=='*' ) 
return (a * b);

else if (op=='/' ) 
{if (b==0)
{printf("division by zero");
exit(1);
}
else
return (a / b);
}
else
return -1;
}

