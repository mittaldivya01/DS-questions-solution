#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
int size,top1,top2,key,k,l=0;
char cmnd[5]=" ";

//file handling
FILE*  fp1;
FILE*  fp2;
fp1= fopen(argv[1],"r");
if(fp1== NULL)
exit(1);
fp2=fopen(argv[2],"w");
if(fp2== NULL)
exit(1);

fscanf(fp1,"%d\n",&size);
top2=size/2;
top1=size/2 -1;
int array[size];
for (l=0;l<size;l++)
{
array[l]=' ';
}

// Two stack operations as per given file
while(! feof(fp1))
{
fscanf(fp1,"%s %d %d\n",cmnd,&key,&k);

if(!strcmp(cmnd,"psh")&& k==1)
{
if(top1==-1)
fprintf(fp2,"overflow in stack %d\n",k);
else
{array[top1]=key;
--top1;
fprintf(fp2,"%d pushed in stack %d\n",key,k);
}
}
else if(!strcmp(cmnd,"pop") && key==1)
{
if(top1==(size/2 -1))
fprintf(fp2,"underflow in stack %d\n",key);
else
{++top1;
fprintf(fp2,"popped %d from stack %d\n",array[top1],key);
array[top1]=' ';
}
} 
else if(!strcmp(cmnd,"print") && key==1)
{
for (l=top1+1;l<= size/2 -1;l++)
{if(array[l]==' ')
continue;
//fprintf(fp2,"NIL ");
else if(l==size/2-1)
fprintf(fp2,"%d",array[l]);
else 
fprintf(fp2,"%d ", array[l]);
}
fprintf(fp2,"\n");
}
else if(!strcmp(cmnd,"psh") && k==2)
{
if(top2==size)
fprintf(fp2,"overflow in stack %d\n",k);
else
{array[top2]=key;
fprintf(fp2,"%d pushed in stack %d\n",key,k);
++top2;
}
}
else if (!strcmp(cmnd,"pop") && key==2)
{
if(top2==(size/2))
fprintf(fp2,"underflow in stack %d\n",key);
else
{--top2;
fprintf(fp2,"popped %d from stack %d\n",array[top2],key);
array[top2]=' ';
}
} 
else if(!strcmp(cmnd,"print") && key==2)
{
for (l=top2;l>=size/2;l--)
{
if(array[l]==' ')
continue;
//fprintf(fp2,"NIL ");
else if(l==size/2)
fprintf(fp2,"%d",array[l]);
else 
fprintf(fp2,"%d ",array[l]);
}
fprintf(fp2,"\n");
}
else if(!strcmp(cmnd,"print"))
{
for (l=0;l<size;l++)
{
if(l==size-1)
{if(array[l]==' ')
fprintf(fp2,"NIL");
else
fprintf(fp2,"%d",array[l]);
}
else if(array[l]==' ')
fprintf(fp2,"NIL ");
else 
fprintf(fp2,"%d ",array[l]);
}
fprintf(fp2,"\n");
}
else 
exit(1);

key=0;
k=0;
}
fclose(fp1);
fclose(fp2);
return 0;
}
