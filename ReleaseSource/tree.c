/*includes*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

#include"tree.h"


/*global variables*/



/*main code*/
int main() 
{ 
	inode *I, *RootID, *NodeID;
	int i, depth;
	
//Create Tree
	I = createTree();
	RootID = I;
	printf("\nRoot : %p\n",RootID);


//Analyze

	//Max depth of Tree
	NodeID = getIDfromName(RootID,5);
	depth = getMaxDepthOfTree(RootID);
	printf("depth = %d\n",depth);


	// Color search
	getNodesByColor(RootID,"green");

//Report
StringtoDot(RootID);


//Modify

	return(1);
} 
