#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalpostfix(char* str);
int evaluation(char b,char a,char op);

int main(int argc, char* argv[])
{
char* str;
int i=0,len,op=0,ans=0;
str=argv[1];
len=strlen(str);
for (i=0;i<len; i++)
{
//printf("\n %c",str[i]);
if (str[i]=='+' || str[i]=='-' || str[i]=='*' ||str[i]=='/')
--op;
else if (str[i]==' ')
continue;
else
++op;
}
if (op==1)
printf("%d",ans=evalpostfix(str));
else
printf("invalid");

return 0;
}

//postfix evaluation
int evalpostfix(char* str)
{int len,top=-1,i=0,a,b;
len=strlen(str);
int stack[len];
for (i=0;i<len; i++)
{
if (!(str[i]=='+' || str[i]=='-' || str[i]=='*' ||str[i]=='/'))
{top++;
stack[top]=str[i] -'0';
}
else if (str[i]==' ')
continue;
else
{b=stack[top];
--top;
a=stack[top];
stack[top]=evaluation(b,a,str[i]);
}
}
return stack[top];
}


int evaluation(char b,char a,char op)
{
if (op=='+' ) 
return (a + b);

else if (op=='-' ) 
return (a - b);

else if (op=='*' ) 
return (a * b);

else if (op=='/' ) 
return (a / b);
else
return -1;

}

