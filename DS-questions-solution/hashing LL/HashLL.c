#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Linked list node structure
struct LL
{
int data;
struct LL* next;
};

//node creation with given capacity
struct LL* createLL(unsigned capacity)
{
struct LL* z;
z=(struct LL* ) malloc(capacity * sizeof(struct LL));
z->data=0;
z->next=NULL;
return z;
}

//Insert
void insertLL(struct LL **start_ref,FILE* fp2,int key)
{
struct LL* x;
x=createLL(1);
struct LL* y;
//y=createLL(1);
y=*start_ref;
if(x==NULL)
{printf("memory overflow");
exit(1);}
x->data=key;
x->next=NULL;
if (*start_ref==NULL)
{*start_ref=x;
//*fprintf(fp2,"%d",x->data);
//printf("%d",x->data);
return;
}
while(y->next!=NULL)
{y=y->next;
} 
y->next=x;
//start=x;
//*fprintf(fp2,",%d",y->next->data);
//printf(",%d",y->next->data);
return;
}

//Search
void searchLL(struct LL **start_ref,FILE* fp2,int n)
{struct LL *x;
int i=1;
x=*start_ref;

while(x!=NULL)
{
if(x->data==n)
{
fprintf(fp2,"%d comparisons",i);
return;
}
else 
{x=x->next;
i++;}
}
fprintf(fp2,"not found");
return;
}

//Update
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

//Delete
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

//print output of linked list in output file
void print(struct LL *start,FILE* fp2)
{struct LL* x;
x=start;
if(start==NULL)
{fprintf(fp2,"not found");
return;
}
fprintf(fp2,"%d",x->data);
while(x->next!=NULL)
{x=x->next;
fprintf(fp2,",%d",x->data);
}
return;
}

//Main function
int main(int argc, char* argv[])
{
int n,d,size,i=0;
char cmnd,c;
//file handling
FILE *fp1, *fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
fscanf(fp1,"%d\n",&size);
struct LL* start[size]={NULL};
/*for(n=0;n<=size;n++)
start[n]=NULL;*/

//Input file handling for various operations
while(!feof(fp1))
{
fscanf(fp1,"%c ",&cmnd);
if(cmnd=='i')
{do
{fscanf(fp1,"%d%c,",&n,&c);
i=n%size;
insertLL(&start[i],fp2,n);
}while(c==',');
}
else if(cmnd=='s')
{fscanf(fp1,"%d,",&n);
i=n%size;
searchLL(&start[i],fp2,n);
fprintf(fp2,"\n");
}
else if (cmnd =='u')
{
fscanf(fp1,"%d,%d,",&n,&d);
i=n%size;
c=updateLL(&start[i],fp2,n,d);
fprintf(fp2,"\n");
}
else if (cmnd =='d')
{
fscanf(fp1,"%d,",&n);
i=n%size;
deleteLL(&start[i],fp2,n);
fprintf(fp2,"\n");
}
}

return 0;
} 


