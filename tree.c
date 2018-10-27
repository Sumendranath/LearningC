/*includes*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

/*global variables*/
int nameID = 0;
char colorBasket[3][7] = {"blue", "yellow", "green"};
typedef struct integerNode{
int nChild;//number of children
//int c;
//int i;
char *color;
int name;
struct integerNode **nodes;
} inode;

/*declarations*/
int randomGen(int lower, int upper); 
inode *new_inode(int n);
inode *gen_itree( inode *I, int nlevels);

/*definitions*/
int randomGen(int lower, int upper) 
{ 
	
	//int i; 
	//for (i = 0; i < count; i++) { 
		int num = (rand() %	(upper - lower + 1)) + lower; 
		//printf("%d ", num);
		return(num);
	//} 
} 

inode *new_inode(int n)
{ 
	inode *I;
	I = malloc(sizeof(inode));
	//printf("Sumen::::::::::::::%ld\n",sizeof(inode));
	I->nChild = n;
	//printf("Sumen:::::::::%d\n",n);
	I->nodes = malloc( n*sizeof(inode*));
	//printf("Sumen::::::::::::::%ld\n",n*sizeof(inode));
	I->name = nameID++;
	printf("Created new node with ID %d\n",I->name);
	//printf("%s\n",colorBasket+randomGen(0,2));	
	//srand((unsigned) time(NULL)); 
	I->color=*(colorBasket+randomGen(0,2));
	printf("Color = %s\n",I->color);
	return(I);
}

inode *gen_itree( inode *I, int nlevels)
{
	int i, next_level, next_n;
	//printf("\n");
	//printf("I : %p\n",I);
	//printf("nlevel : %d\n",nlevels);
	//printf("\n");
	if(nlevels == 0)
	{
		//printf("nlevels = 0\n");
	}
	else
	{
		//printf("I->nChild %d\n",I->nChild);
		next_level = nlevels-1;
		for(i=0;i<I->nChild;i++)
		{
			//printf("I: %p\n",I);
			//printf("adding node number: %d\n",i);
			
			next_n=0+randomGen(4,17);
			I->nodes[i] = new_inode(next_n);
			//printf("I->nodes[%d]->n: %p %d \n",i, I->nodes[i],next_n);
			I->nodes[i] = gen_itree(I->nodes[i] , next_level);
		}
		//printf("\n");
		//printf("returning I : %p\n",I);
	}
	return(I);
}

/*main code*/
int main() 
{ 
  inode *I;
srand((unsigned) time(NULL));
  I = new_inode(2);
  I = gen_itree(I,3);
  return(1);
} 
