#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// node structure
struct LL
{
int data;
struct LL* next;
};
struct LL* createLL(unsigned capacity)
{
struct LL* z;
z=(struct LL* ) malloc(capacity * sizeof(struct LL));
z->data=0;
z->next=NULL;
return z;
}

//Linkedlist Operations
void insertLL(struct LL **start_ref,FILE* fp2,int key);
char updateLL(struct LL **start_ref,FILE* fp2,int n,int d);
void deleteLL(struct LL **start_ref,FILE* fp2,int n);
void print(struct LL *start,FILE* fp2);

//main function
int main(int argc, char* argv[])
{
int n,d;
char cmnd,c;

FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
struct LL* start=NULL;

while(!feof(fp1))
{
fscanf(fp1,"%c ",&cmnd);
if(cmnd=='i')
{do
{fscanf(fp1,"%d%c,",&n,&c);
//printf("%d ",n);
insertLL(&start,fp2,n);
//fprintf(fp2,"%d,",n);
}while(c==',');

//printf("i %d %d",n,c-'0');
//fscanf(fp1,"\n");
fprintf(fp2,"\n");
//printf("\n");
}
else if (cmnd =='u')
{
fscanf(fp1,"%d,%d,",&n,&d);
//printf("%d  %d",n,d);
c=updateLL(&start,fp2,n,d);
//fprintf(fp2,"%c\n",c);
fprintf(fp2,"\n");
}
else if(cmnd=='p')
{
print(start,fp2);

fprintf(fp2,"\n");
}
else if (cmnd =='d')
{
fscanf(fp1,"%d,",&n);
//printf("%d  %d",n);
deleteLL(&start,fp2,n);
//fprintf(fp2,"%c\n",c);
fprintf(fp2,"\n");
}
}

return 0;
} 


void insertLL(struct LL **start_ref,FILE* fp2,int key)
{
struct LL* x;
x=createLL(1);
struct LL* y;

y=*start_ref;
if(x==NULL)
{printf("memory overflow");
exit(1);}
x->data=key;
x->next=NULL;
if (*start_ref==NULL)
{*start_ref=x;
fprintf(fp2,"%d",x->data);
//printf("%d",x->data);
return;
}
while(y->next!=NULL)
{y=y->next;
} 
y->next=x;
fprintf(fp2,",%d",y->next->data);
//printf(",%d",y->next->data);
return;
}

char updateLL(struct LL **start_ref,FILE* fp2,int n,int d)
{struct LL* x;
x=*start_ref;
while(x!=NULL)
{if (x->data==n)
{x->data=d;
print(*start_ref,fp2);
return 'u';
}
else
x=x->next;
}
fprintf(fp2,"not found");
return 'n';
}

void deleteLL(struct LL **start_ref,FILE* fp2,int n)
{struct LL *x;
x=*start_ref;
if(x->data==n)
{*start_ref=x->next;
print(*start_ref,fp2);
return;
}
while(x->next!=NULL)
{
if(x->next->data==n)
{x->next=x->next->next;
print(*start_ref,fp2);
return;
}
else
x=x->next;
}
fprintf(fp2,"not found");
return;
}

void print(struct LL *start,FILE* fp2)
{struct LL* x;
x=start;
if(start==NULL)
{//printf("print null");
return;
}
fprintf(fp2,"%d",x->data);
while(x->next!=NULL)
{x=x->next;
fprintf(fp2,",%d",x->data);
//printf("%d, ",x->data);
}
return;
}

