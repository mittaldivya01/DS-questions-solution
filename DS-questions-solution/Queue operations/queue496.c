#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
int size,head,tail,key,l=0,count=0;
char cmnd[5]=" ";
FILE*  fp1;
FILE*  fp2;
fp1= fopen(argv[1],"r");
//printf("%s",argv[1]);
if(fp1== NULL)
return -1;
fp2=fopen(argv[2],"w");
if(fp2== NULL)
return -1;
fscanf(fp1,"%d\n",&size);
int queue[size +1];
head=0;
tail=size-1;
for (l=0;l<size;l++)
{
queue[l]=' ';
}
while(! feof(fp1))
{
fscanf(fp1,"%s %d\n",cmnd,&key);
//printf("\n%s %d %d",cmnd,key,k);
if(!strcmp(cmnd,"enq"))
{
if(count==size)
{fprintf(fp2,"overflow\n");
continue;
}
else if(head==tail && count==0 )
++head;
tail=(tail+1)%size;
queue[tail]=key;
count++;
fprintf(fp2,"%d added\n",key);
}
else if(!strcmp(cmnd,"deq"))
{
if(head==-1 || head>tail)
fprintf(fp2,"underflow\n");
else
{fprintf(fp2,"removed %d\n",queue[head]);
queue[head]=' ';
++head;
--count;
}
} 
else if(!strcmp(cmnd,"print") )
{
for (l=head;l<=tail;l++)
{if(queue[l+1]==' ')
{fprintf(fp2,"%d",queue[l]);
break;
}
else 
fprintf(fp2,"%d ",queue[l]);
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
