#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
int size,top=-1,key,l=0;
char cmnd[5]=" ";
FILE*  fp1;
FILE*  fp2;
fp1= fopen(argv[1],"r");

if(fp1== NULL)
return -1;
fp2=fopen(argv[2],"w");
if(fp2== NULL)
return -1;
fscanf(fp1,"%d\n",&size);
int stack[size];
for (l=0;l<size;l++)
{
stack[l]=' ';
}
while(! feof(fp1))
{
fscanf(fp1,"%s %d\n",cmnd,&key);

//Stack operations description given in input file
if(!strcmp(cmnd,"psh"))
{
if(top==size-1)
fprintf(fp2,"overflow\n");
else
{++top;
stack[top]=key;
fprintf(fp2,"%d pushed\n",key);
}
}
else if(!strcmp(cmnd,"pop"))
{
if(top==-1)
fprintf(fp2,"underflow\n");
else
{fprintf(fp2,"popped %d\n",stack[top]);
stack[top]=' ';
--top;
}
} 
else if(!strcmp(cmnd,"print") )
{
for (l=top;l>=0;l--)
{
if(l==0)
{fprintf(fp2,"%d",stack[l]);
break;
}
else 
fprintf(fp2,"%d ",stack[l]);
}
fprintf(fp2,"\n");
}
else 
exit(1);

key=0;
}
fclose(fp1);
fclose(fp2);
return 0;
}
