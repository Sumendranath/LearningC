#include"tree.h"

/*Global Variables*/
int nameID = 0;
char colorBasket[3][7] = {"blue", "yellow", "green"};
FILE* FGH;

void initDotFile(void);
void createDotFile(inode *Parent);
void closeDotFile(void);

void initRandom()
{
	srand((unsigned) time(NULL));
}

int randomGen(int lower, int upper) 
{ 
	int num = (rand() %	(upper - lower + 1)) + lower; 
	//printf("%d ", num);
	return(num);
} 
inode *createTree()
{
	inode *I=NULL;
	initRandom();
	I = new_inode(randomGen(CHILD_MIN,CHILD_MAX));
	I = gen_itree(I,TREE_LEVEL);
	return(I);
}
inode *new_inode(int n)
{ 
	inode *I;
	I = malloc(sizeof(inode));
	I->nChild = n;
	I->nodes = malloc( n*sizeof(inode*));
	I->name = nameID++;
	I->color=*(colorBasket+randomGen(0,2));
	return(I);
}


inode *gen_itree( inode *I, int nlevels)
{
	int i, next_level, next_n;
	if(nlevels == 0)
	{
		//printf("nlevels = 0\n");
	}
	else
	{
		next_level = nlevels-1;
		for(i=0;i<I->nChild;i++)
		{
			next_n=0+randomGen(CHILD_MIN,CHILD_MAX);//min max child
			I->nodes[i] = new_inode(next_n);
			//printf("I->nodes[%d]->n: %p %d \n",i, I->nodes[i],next_n);
			I->nodes[i] = gen_itree(I->nodes[i] , next_level);
		}
	}
	return(I);
}

void initDotFile()
{
	//String to DOT
	FGH = fopen("program.dot","w");
	if(FGH == NULL)
	{
		printf("Error!\n");
	}
	fprintf(FGH, "%s\n%s\n","digraph DotSampleTree {","node [style =filled]");
}

void closeDotFile()
{
	fprintf(FGH,"%s","}");
	fclose(FGH);
}


void createDotFile(inode *Parent)
{
	int i;
	inode *Child, *oldParent;
	//printf("\"%d\" [color=%s]\n",Parent->name,Parent->color);
	
	fprintf(FGH," \"%d\" [color=%s]\n",Parent->name,Parent->color);//Write to Dot file
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			fprintf(FGH,"%d->%d\n",Parent->name,Child->name);//Write to Dot file
			oldParent = Parent;
			Parent = Child;
			createDotFile(Parent);
			Parent = oldParent;
		}
		else
		{
			//Parent = oldParent;
		}
	}
}
void StringtoDot(inode *Parent)
{
	initDotFile();
	createDotFile(Parent);
	closeDotFile();
}


void getNodesByColor(inode *Parent,char *color)
{
	int i;
	inode *Child, *oldParent;
	if(!strcmp(color,Parent->color))
	{
		//printf("%d\n",Parent->name);
		//get list:TODO	
	}
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
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
}


int getMaxDepthOfTree(inode *Parent)
{
	int i;
	static int count=1,max = 0;
	inode *Child, *oldParent;
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			oldParent = Parent;
			Parent = Child;
			count++;
			getMaxDepthOfTree(Parent);
			Parent = oldParent;
		}
		else
		{
			if(count>max)
			{max = count;}
			count = 0;
		}
	}
	return(max);
}


	
inode *getIDfromName(inode *Parent, int name)
{
	int i;
	inode *Child, *oldParent, *returnID = NULL;
	if(Parent->name == name)
	{
		//printf("Debug\n");
		//printf("Node %d is at %p\n",name,Parent);
		return (Parent);
	}
	for(i=0;i<CHILD_MAX;i++)
	{
		if(NULL != Parent->nodes[i])
		{
			Child = Parent->nodes[i];
			oldParent = Parent;
			Parent = Child;
			getIDfromName(Parent,name);
			Parent = oldParent;
		}
		else
		{

		}
	}
}
