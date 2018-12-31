#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct LL
{
int data;
struct LL *next;
};

struct LL* createLL(int n)
{
struct LL* new;
new=(struct LL*) malloc(sizeof(struct LL));
if(new)
{new->data=n;
new->next=NULL;
}
return new;
}
void insertLL(struct LL **start_ref,FILE *fp2,int key);
void del_alt_node(struct LL **start_ref,FILE *fp2);

int main(int argc,char *argv[])
{
int n=0,i=0;
char ch;
FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
if(fp1==NULL || fp2==NULL)
return 0;
struct LL* start=NULL;
while(!feof(fp1))
{
do
{fscanf(fp1,"%d%c,",&n,&ch);
++i;
if(i%2)
insertLL(&start,fp2,n);
}while(ch==' ');
}
//del_alt_node(&start,fp2);
return 0;
}

void insertLL(struct LL **start_ref,FILE *fp2,int key)
{
struct LL* x;
x=createLL(key);
struct LL* y;
//y=createLL(1);
y=*start_ref;

if (*start_ref==NULL)
{*start_ref=x;
fprintf(fp2,"%d ",x->data);
return;
}
while(y->next!=NULL)
y=y->next;

y->next=x;
//start=x;
fprintf(fp2,"%d ",x->data);
//printf(",%d",y->next->data);
return;
}

void del_alt_node(struct LL **start_ref,FILE *fp2)
{struct LL* y,*x;
y=*start_ref;
x=y;
while(x->next!=NULL)
{//fprintf(fp2,",%d",y->data);
y->next=y->next->next;
fprintf(fp2,"%d ",x->data);
x=y->next;
y=y->next;
}
/*x=*start_ref;
while(x->data)
{fprintf(fp2,"%d ",x->data);
x=x->next;
}*/
return;
}

