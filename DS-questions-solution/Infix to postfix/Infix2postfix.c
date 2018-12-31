#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Main function
int main(int argc, char* argv[])
{
char* str;
char tmp[25],op[10];
int i=0, len=10,j=0;
printf("%s", argv[1]);
str=argv[1];
len=strlen(str);
printf("%d  %s", len,str);
if (len==0)
return 0;

for(i=0;i<len; )
{
tmp[i]=*str;
str++;
if(!strcmp(str,"("))
continue;
else if(!strcmp(str,")"))
{--j;
tmp[i]=op[j];
i++;
} 
else if(!strcmp(str,"+") || !strcmp(str,"-") || !strcmp(str,"*") || !strcmp(str,"/"))
{op[j]= *str; 
j++;}
else
i++;
}
printf("%s",tmp);

return 0;

}
