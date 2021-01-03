#include "LinkedList.h"

int main()
{
	Set A, B, URE, IRE, CRE, DRE;
	initSet(A);
	initSet(B);
	initSet(URE);
	initSet(IRE);
	initSet(CRE);
	initSet(DRE);

	printf("\nInput A:");
	inputSet(A);
	printf("\nInput B:");
	inputSet(B);
	printf("\nSet A is: ");
	displaySet(A);
	printf("\n");
	printf("\nSet B is: ");
	displaySet(B);

	printf("\n");
	printf("\nUnion of two sets is: ");
	URE = Union(A, B);
	displaySet(URE);

	printf("\n");
	printf("\nIntersection of two sets is: ");
	IRE = Intersection(A, B);
	displaySet(IRE);

	printf("\n");
	printf("\nComplement of B in A (A-B) is: ");
	CRE = Complementation(A, B);
	displaySet(CRE);

	printf("\n");
	printf("\nComplement of A in B (B-A) is: ");
	DRE = Complementation(B, A);
	displaySet(DRE);
	printf("\n");

	deleteSet(A);
	deleteSet(B);
	deleteSet(URE);
	deleteSet(IRE);
	deleteSet(CRE);
	deleteSet(DRE);
	system("pause");
	return 0;

}
