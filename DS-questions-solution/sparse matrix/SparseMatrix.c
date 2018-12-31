#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Sparse matrix structure
struct collec
{
int row,col,val;
};

int main(int argc, char *argv[])
{
struct collec coll[20];
int x=0,i=1,c=1,j=1;
char ch=' ';

FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
if(fp1==NULL || fp2==NULL)
return -1;

coll[1].row=0;
coll[1].col=0;

if(feof(fp1))
return 0;

while(!feof(fp1))
{
++coll[1].row;
coll[1].col=c;
c=1;
do
{
fscanf(fp1,"%d%c",&x,&ch);
//printf("%c",ch);
if(x==' '||x=='\n')
return 0;
else if(x!=0)
{
++i;
coll[i].row=coll[1].row;
coll[i].col=c;
coll[i].val=x;
}
++c;
}
while(ch==' ');
}

if(coll[j].row>0)
{
do
{

if(j==1)
fprintf(fp2,"%d %d %d\n",coll[j].row-1,coll[j].col-1,i-1);
else
fprintf(fp2,"%d %d %d\n",coll[j].row,coll[j].col,coll[j].val);
--i;
j++;

}
while(i!=0);
}
else 
fprintf(fp2,"0 0 0");
fclose(fp1);
fclose(fp2);
return 0;
} 

