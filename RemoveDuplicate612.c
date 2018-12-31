#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct LL
{
int data;
struct LL* next;
};

struct LL* createLL(int n)
{
struct LL* z;
z=(struct LL* ) malloc(sizeof(struct LL));
z->data=n;
z->next=NULL;
return z;
}
void insertLL(struct LL **start_ref,FILE* fp2,int key);

int main(int argc, char* argv[])
{
int n;
char c;
//char *status;
FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
struct LL* start=NULL;

while(!feof(fp1))
{
do
{fscanf(fp1,"%d%c,",&n,&c);
insertLL(&start,fp2,n);
//fprintf(fp2,"%d,",n);
}while(c==' ');
}
return 0;
} 

void insertLL(struct LL **start_ref,FILE* fp2,int key)
{
struct LL *x,*y;
x=createLL(key);
y=*start_ref;
if(x==NULL)
{printf("memory overflow");
exit(1);}

if (*start_ref==NULL)
{*start_ref=x;
fprintf(fp2,"%d",x->data);
//printf("%d",x->data);
return;
}

while(y->next!=NULL)//not the last node
{if(key==y->data)
return;
else 
y=y->next;
} 
y->next=x;
//start=x;
fprintf(fp2," %d",y->next->data);
return;
}

