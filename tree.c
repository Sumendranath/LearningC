/*includes*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

/*macros*/
#define CHILD_MIN 	2
#define CHILD_MAX	3
#define TREE_LEVEL 	5

/*global variables*/
int nameID = 0;
FILE* FGH;
char colorBasket[3][7] = {"blue", "yellow", "green"};
//colorSpotArr[50][2]; // have to see some other idea.
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
	//printf("Created new node with ID %d\n",I->name);
	
	//printf("%s\n",colorBasket+randomGen(0,2));	
	//srand((unsigned) time(NULL)); 
	I->color=*(colorBasket+randomGen(0,2));
	//printf("Prev: \"%d\" [color=%s]\n",I->name,I->color);
	//printf("Color = %s\n",I->color);
    
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
			
			next_n=0+randomGen(CHILD_MIN,CHILD_MAX);//min max child
			I->nodes[i] = new_inode(next_n);
			//printf("I->nodes[%d]->n: %p %d \n",i, I->nodes[i],next_n);
			I->nodes[i] = gen_itree(I->nodes[i] , next_level);
		}
		//printf("\n");
		//printf("returning I : %p\n",I);
	}
	return(I);
}


void StringtoDot(inode *Parent)
{
	int i;
	inode *Child, *oldParent;
	printf("\"%d\" [color=%s]\n",Parent->name,Parent->color);
	fprintf(FGH," \"%d\" [color=%s]\n",Parent->name,Parent->color);
	//AppendFile
	//FGH = fopen("program.txt","a"); 
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			printf("%d->%d\n",Parent->name,Child->name);
			fprintf(FGH,"%d->%d\n",Parent->name,Child->name);
			//AppendFile
			oldParent = Parent;
			Parent = Child;
			StringtoDot(Parent);
			Parent = oldParent;
		}
		else
		{
			//Parent = oldParent;
		}
	}
	//Parent = oldParent;
	//Close the File
}


void getNodesByColor(inode *Parent,char *color)
{
	int i;
	inode *Child, *oldParent;
	//printf("\"%d\" [color=%s]\n",Parent->name,Parent->color);
	if(!strcmp(color,Parent->color))
	{
		printf("%d\n",Parent->name);	
	}
	//fprintf(FGH," \"%d\" [color=%s]\n",Parent->name,Parent->color);
	//AppendFile
	//FGH = fopen("program.txt","a"); 
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			//printf("%d->%d\n",Parent->name,Child->name);
			//fprintf(FGH,"%d->%d\n",Parent->name,Child->name);
			//AppendFile
			oldParent = Parent;
			Parent = Child;
			getNodesByColor(Parent,color);
			Parent = oldParent;
		}
		else
		{
			//Parent = oldParent;
		}
	}
	//Parent = oldParent;
	//Close the File
}
/*void colorSpots(inode *Parent)
{
	int i;
	inode *Child, *oldParent;
	printf("\"%d\" [color=%s]\n",Parent->name,Parent->color);
	colorSpotArr[][] = Parent->name
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			//printf("%d->%d\n",Parent->name,Child->name);
			//fprintf(FGH,"%d->%d\n",Parent->name,Child->name);
			//AppendFile
			oldParent = Parent;
			Parent = Child;
			colorSpots(Parent);
			Parent = oldParent;
		}
		else
		{
			//Parent = oldParent;
		}
	}
}*/
/*main code*/
int main() 
{ 
	inode *I, *RootID;
	int i;
	srand((unsigned) time(NULL));
//Create Tree
	
	I = new_inode(randomGen(CHILD_MIN,CHILD_MAX));
	I = gen_itree(I,TREE_LEVEL);
	RootID = I;
	//printf("\nRoot : %p\n",RootID);


//Analyze
//Open a File
	FGH = fopen("program.dot","w");
	if(FGH == NULL)
	{
	  printf("Error!\n");
	}
	fprintf(FGH, "%s\n%s\n","digraph DotSampleTree {","node [style =filled]");
	StringtoDot(RootID);
	fprintf(FGH,"%s","}");
	fclose(FGH);
	//Close File
	//fclose(FGH);

// Color search
getNodesByColor(RootID,"green");

//colorspots
//colorSpots(RootID);
//Report

//Modify

	return(1);
} 
