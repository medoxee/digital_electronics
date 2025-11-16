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
int	not(int	X)
{
	return	!(X);
}

int	and(int	A, int	B)
{
	return	(A && B);
}

int	or(int	A, int	B)
{
	return (A || B);
}
// end of main logical functions.

int	nand(int	A, int	B)
{
	return not(and(A, B));
}

int	nor(int	A, int	B)
{
	return not(or(A, B));
}

int	xor(int	A, int	B)
{
	return or(and(A, not(B)), and(not(A), B));
}

int	xnor(int	A, int	B)
{
	return not(xor(A, B));
}

int	main(void)
{
	char	*logic_func_names[NUM_OF_LOGIC_FUNC] = {"and", "or", "nand", "nor", "xor", "xnor"};
	int	(*functions[NUM_OF_LOGIC_FUNC])(int, int) = {and, or, nand, nor, xor, xnor}; // array of logical functions(NOT is excluded)
	int	A;
	int	B;
	int	output; // result of A * B (*: operation)
		
	printf("Enter A and B values(0 or 1): ");
	if (scanf("%d %d", &A, &B) != 2)
	{
		printf("Invalid input (A and B must be 0 or 1)\n");
		return 1;
	}
	for (int i = 0; i < NUM_OF_LOGIC_FUNC; i++)
	{
		output = functions[i](A, B);
		printf("%s = %d\n", logic_func_names[i], output);
	}
	return 0;
}
