#ifndef __TREE_HEADER
#define __TREE_HEADER

#include"cfgTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

//extern FILE* FGH; 

typedef struct integerNode{
int nChild;//number of children
char *color;
int name;
struct integerNode **nodes;
} inode;


void initRandom(void);
int randomGen(int lower, int upper); 
int getMaxDepthOfTree(inode*);
inode *new_inode(int n);
inode *gen_itree( inode *I, int nlevels);
inode *getIDfromName(inode*, int);
inode *createTree(void);
void StringtoDot(inode*);
void getNodesByColor(inode*,char*);


#endif
