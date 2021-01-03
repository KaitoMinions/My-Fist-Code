#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

//Linked list tagNode
typedef struct tagNode {
	char c;
	tagNode* Next;
};

typedef tagNode* Node;

typedef struct tagList {
	Node Head;
	Node Tail;
};
//Linked list Set
typedef tagList Set;

//Functions

void initSet(Set&);	// Initialize Set
int	 isEmptySet(Set);	// Check if Set is empty
void deleteSet(Set&);  // Delete Set
void displaySet(Set);	// Print elements in Set
int  isElementOfSet(Set, char); // Check if given data is element in Set
void insertNode2Head(Set&, char); // Insert a node with given data at Head
void insertNode2Tail(Set&, char); // Insert a node with given data at Tail
void insertNode2After(Set&, Node, char); // Insert a node with given data after a node 
void insertNode(Set&, char); // Insert a node with given data into the Set in sorted order
void inputSet(Set&); // Create a Set by console input
Set	 copySet(Set);  //Copy a Set
int  isSubSetofSet(Set, Set); // Check if Set A is a subset of Set B
int  isSetEqualSet(Set, Set); // Check if two Sets are equal
Set  Union(Set, Set); // Get Union of two Sets
Set  Intersection(Set, Set); // Get Intersection of two Sets
Set  Complementation(Set, Set); // Get Complementation of two Sets
