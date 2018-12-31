#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node Structure
struct node
{
int data;
struct node *left,*right;
};

//New node creation
struct node* Nodecreate(int n)
{
struct node* new;
new=(struct node*) malloc(sizeof(struct node));
if(new)
{new->data=n;
new->left=NULL;
new->right=NULL; 
}
return new;
}

//Insertion
int BTreeI(struct node **t_ref,int n,FILE* fp2)
{
struct node *new,*temp;
new=Nodecreate(n);
temp=*t_ref;
//return if memory leaks and node is not created
if(!new)
return 0;
if(!*t_ref)
{
*t_ref=new;
}
else if(n< temp->data) 
{
BTreeI(&temp->left,n,fp2);
}
else if(n> temp->data)
{BTreeI(&temp->right,n,fp2);
}
return 1;
}


//print
int preprint(struct node *t,FILE *fp2,int size)
{
//if node t exist than print the subtree
if(t)
{if(size<=1)
fprintf(fp2,"%d",t->data);
else
{fprintf(fp2,"%d,",t->data);
size=size-1;
size=preprint(t->left,fp2,size);
size=preprint(t->right,fp2,size);
}
}
return size;
}


//Main function with command line input
int main(int argc,char *argv[])
{
int n=0,size=0;
char ch;
struct node *t=NULL;
FILE *fp1, *fp2;
//file handeling
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");
if(fp1==NULL || fp2==NULL)
return 0;

while(!feof(fp1))
{
do
{
//variable 'ch' checks for delimeter next to data read in input file
fscanf(fp1,"%d%c,",&n,&ch);
size=size+ BTreeI(&t, n,fp2);
n=preprint(t,fp2,size);
fprintf(fp2,"\n");
}while(ch==',');
}

fclose(fp1);
fclose(fp2);
return 0;
}
