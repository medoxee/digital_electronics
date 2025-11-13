#include <stdio.h>

#define NUM_OF_LOGIC_FUNC 6

/*
 * 		IN THE NAME OF ALLAH,
 * Developer: MOHAMED ARRAF (https://www.linkedin.com/in/mohamedarraf)
 * Description:
 * 	This program is an implementation of logical functions(gate)
 * NOT, AND, OR, NAND, NOR, XOR, XNOR
 */

// start of main logical functions
int	NOT(int	X)
{
	return	!(X);
}

int	AND(int	A, int	B)
{
	return	(A && B);
}

int	OR(int	A, int	B)
{
	return (A || B);
}
// end of main logical functions.

int	NAND(int	A, int	B)
{
	return NOT(AND(A, B));
}

int	NOR(int	A, int	B)
{
	return NOT(OR(A, B));
}

int	XOR(int	A, int	B)
{
	return OR(AND(A, NOT(B)), AND(NOT(A), B));
}

int	XNOR(int	A, int	B)
{
	return NOT(XOR(A, B));
}

int	main(void)
{
	char	*logic_func_names[NUM_OF_LOGIC_FUNC] = {"AND", "OR", "NAND", "NOR", "XOR", "XNOR"};
	int	(*functions[NUM_OF_LOGIC_FUNC])(int, int) = {AND, OR, NAND, NOR, XOR, XNOR}; // array of logical functions(NOT is excluded)
	int	A;
	int	B;
	int	output; // result of A * B (*: operation)
	
	printf("Enter A and B values(0 or 1): ");
	scanf("%d %d", &A, &B);
	// printf("Enter the logical function(AND or OR ...): ");
	// scanf("%s", &logical_function);
	for (int i = 0; i < NUM_OF_LOGIC_FUNC; i++)
	{
		output = functions[i](A, B);
		printf("%s = %d\n", logic_func_names[i], output);
	}
	return 0;
}
