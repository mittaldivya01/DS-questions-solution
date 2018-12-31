#include<stdio.h>
#include<stdlib.h>

//Main function
int main(int argc,char *argv[])
{
int n,d=0,size=0,pos=0,x=0,y=0,set=0;
char cmnd,c;

//file handling
FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");

//check size of hash array
fscanf(fp1,"%d %d\n",&size,&d);
if(size==0 || d==0)
return 0;
int e[size][d]={' '};


while(!feof(fp1))
{
fscanf(fp1,"%c ",&cmnd);

//Insert
if(cmnd =='i')
{do
{
fscanf(fp1,"%d%c",&n,&c);
pos=n%size;
y=0;
for(x=pos;x<size;)
{
if (e[x][y]==' ')
{e[x][y]=n;
break;
}
else
y++;
if(y==d)
{
x++;
y=0;
}

}
}while(c==',');
}
//search
else if(cmnd=='s')
{fscanf(fp1,"%d\n",&n);
set=0;
pos=n%size;
y=0;
for(x=pos;x<size;)
{
//writing comparison results into output file
if (e[x][y]==n)
{
++set;
fprintf(fp2,"%d comparisons",set);
set=0;
break;
}
else
{y++;
++set;
}
if(y==d)
{
x++;
y=0;
}
if((x==size) && (set!=0))
fprintf(fp2,"not found");
}
fprintf(fp2,"\n");
}

}
fclose(fp1);
fclose(fp2);
return 0;
}
