#include "LinkedList.h"

// Initialize Set
void initSet(Set& A) {
	A.Head = A.Tail = NULL;
}

// Return 1 if Set is empty, 0 otherwise
int	 isEmptySet(Set A) {
	return (A.Head == NULL);
}

// Delete a Set
void deleteSet(Set& A) {
	Node p = new tagNode;
	if (isEmptySet(A)) {
		return;
	}
	while (A.Head != NULL) {
		p = A.Head;
		A.Head = p->Next;
		delete p;
	}
	A.Tail = NULL;
}

// Print a Set
void displaySet(Set A) {
	if (isEmptySet(A)) {
		printf("Empty");
		return;
	}
	Node p = A.Head;
	while (p != NULL) {
		printf("%c ", p->c);
		p = p->Next;
	}
}

//Return true if given data is an element in Set else return false
int  isElementOfSet(Set A, char dataC) {
	Node p = new tagNode;
	p = A.Head;
	while (p != NULL) {
		if (p->c == dataC) {
			return 1;
		}
		p = p->Next;
	}
	return 0;
}

//Insert a node with a given data at the begining
void insertNode2Head(Set& A, char dataC) {
	Node p = new tagNode;
	if (p == NULL) {
		return;
	}
	p->c = dataC;
	p->Next = NULL;
	if (isEmptySet(A)) {
		A.Head = A.Tail = p;
	}
	else {
		p->Next = A.Head;
		A.Head = p;
	}
}

//Insert a node with given data at the tail 
void insertNode2Tail(Set& A, char dataC) {
	Node p = new tagNode;
	if (p == NULL) {
		return;
	}
	p->c = dataC;
	p->Next = NULL;
	if (isEmptySet(A)) {
		A.Head = A.Tail = p;
	}
	else {
		A.Tail->Next = p;
		A.Tail = p;
	}
}

//Insert a node with given data after a node q in list
void insertNode2After(Set& A, Node q, char dataC) {
	Node p = new tagNode;
	if (p == NULL) {
		return;
	}
	p->c = dataC;
	p->Next = NULL;
	if (isEmptySet(A)) {
		A.Head = A.Tail = p;
	}
	else {
		p->Next = q->Next;
		q->Next = p;
		if (q == A.Tail)
		{
			A.Tail = p;
		}
	}
}

//Insert a node with given data into the Set in sorted order
void insertNode(Set& A, char dataC) {
	Node t = new tagNode();
	t->c = dataC;
	t->Next = NULL;
	if (A.Head == NULL) {
		A.Head = t;
		A.Tail = t;
	}
	else {
		A.Tail->Next = t;
		A.Tail = t;
	}
}

//Insert a node with given data into the Set in sorted order
void insert_sort(Set& A, char dataC) {
	if (isEmptySet(A)) {
		insertNode2Head(A, dataC); // A is empty so add Node to Head
	}
	else {
		if (dataC > A.Tail->c) {
			insertNode2Tail(A, dataC); // add Node to tail
		}
		if (A.Head->c > dataC) {
			insertNode2Head(A, dataC); // add Node to head
		}
		if (dataC > A.Head->c && A.Tail->c > dataC) {
			Node q = A.Head;
			for (q = A.Head; q != NULL; q = q->Next) {
				if (dataC > q->c && q->Next->c > dataC) { // input > Node data and Node data in next > input
					insertNode2After(A, q, dataC);
				}
			}
		}
	}
}

// Create a Set by cosole input
void inputSet(Set& A) {
	char* dataC = new char;
	do {
		printf("\nInput elements of Set: ");
		std::cin >> dataC; // input a character
		fflush(stdin); // discard any buffered data
		if (strcmp("end", dataC) == 0) // condition stop
		{
			break;
		}
		insert_sort(A, dataC[0]);
	} while (1);

}

//Make a copy of a Set
Set	 copySet(Set A) {
	Set B;
	initSet(B);
	Node p = A.Head;
	while (p != NULL) {
		insertNode(B, p->c);
		p = p->Next;
	}
	return B;
}

// Check if Set A is a subset of Set B
int  isSubSetofSet(Set A, Set B) {
	Node p = new tagNode;
	p = A.Head;
	while (p != NULL) {
		// if a element of A is not a element of B, return false
		if (isElementOfSet(B, p->c) == 0) {
			return 0;
		}
		p = p->Next;
	}
	return 1;
}

//Check if two sets are equal 
int  isSetEqualSet(Set A, Set B) {
	if (isSubSetofSet(A, B) == 1) {
		if (isSubSetofSet(B, A) == 1) { // if Set A is a subset of Set B and Set B is a subset of Set A, return true
			return 1;
		}
	}
	return 0;
}

//Get Union of two sets 
Set  Union(Set A, Set B) {
	Set RE;
	initSet(RE);
	if (isEmptySet(A) && isEmptySet(B)) {
		return RE; // if A and B are Empty, return Empty
	}
	if (isEmptySet(A) && !isEmptySet(B)) {  // if A is empty, B is not empty, return B
		RE = copySet(B);
		return RE;
	}
	if (isEmptySet(B) && !isEmptySet(A)) { // if A is not empty, B is empty, return A
		RE = copySet(A);
		return RE;
	}
	if (isSetEqualSet(A, B) == 1) {
		RE = copySet(A); // if A and B are equal, return A or B
	}
	else {
		RE = copySet(A); // insert all elements of Set A to the result Set
		Node p = new tagNode;
		p = B.Head;
		while (p != NULL) {
			// insert those elements of Set B which is not present to the result Set
			if (isElementOfSet(RE, p->c) == 0) {
				insertNode(RE, p->c); //insert to sorted order Set
			}
			p = p->Next;
		}
	}
	return RE;
}

//Get Intersection of two sets
Set  Intersection(Set A, Set B) {
	Set RE;
	initSet(RE);
	if (isEmptySet(A) || isEmptySet(B)) {
		return RE; // if A or B is Empty, return Empty
	}
	if (isSetEqualSet(A, B) == 1) {
		RE = copySet(A); // if A and B are equal, return A or B
	}
	else {
		if (isSubSetofSet(A, B) == 1) {
			RE = copySet(A); // if A is a subset of B, return A
		}
		else
			if (isSubSetofSet(B, A) == 1) {
				RE = copySet(B);
			}
		//if B is a subset of A, return B
			else {
				Node p = new tagNode;
				p = A.Head;
				//Traverse Set A and search each element of it in Set B.
				//If the element was present in Set B, then insert the element to result set
				while (p != NULL) {
					if (isElementOfSet(B, p->c) == 1) {
						insertNode(RE, p->c); // insert to sorted order set
					}
					p = p->Next;
				}
			}
	}
	return RE;
}

//Get Complementation of two sets
Set Complementation(Set A, Set B) {
	Set RE;
	initSet(RE);
	//if A is Empty or A is equal to B or A is a subset of B , return Empty
	if ((isEmptySet(A)) || (isSetEqualSet(A, B)) || (isSubSetofSet(A, B))) {
		return RE;
	}
	if (isEmptySet(B)) {
		RE = copySet(A); // if B is empty, return A
	}
	else {
		Node p = new tagNode; p = A.Head;
		//Traverse Set A and search each element of it in Set B.
		//If the element is not present in Set B, then insert the element to result set
		while (p != NULL) {
			if (isElementOfSet(B, p->c) == 0) {
				insertNode(RE, p->c); // insert to sorted order set
			}
			p = p->Next;
		}
	}
	return RE;
}
