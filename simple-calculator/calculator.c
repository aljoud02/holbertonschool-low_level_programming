#include <stdio.h>

/**
 * add - Adds two integers
 * @a: First number
 * @b: Second number
 *
 * Return: Result of a + b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * subtract - Subtracts the second integer from the first
 * @a: First number
 * @b: Second number
 *
 * Return: Result of a - b
 */
int subtract(int a, int b)
{
	return (a - b);
}

/**
 * multiply - Multiplies two integers
 * @a: First number
 * @b: Second number
 *
 * Return: Result of a * b
 */
int multiply(int a, int b)
{
	return (a * b);
}

/**
 * divide - Divides the first integer by the second as a double
 * @a: First number
 * @b: Second number
 *
 * Return: Result of a / b
 */
double divide(int a, int b)
{
	return ((double)a / b);
}

/**
 * main - Entry point for the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int a, b;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		scanf("%d", &choice);

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		if (choice == 1)
		{
			printf("Result: %d\n", add(a, b));
		}
		else if (choice == 2)
		{
			printf("Result: %d\n", subtract(a, b));
		}
		else if (choice == 3)
		{
			printf("Result: %d\n", multiply(a, b));
		}
		else if (choice == 4)
		{
			if (b == 0)
			{
				printf("Error: division by zero\n");
			}
			else
			{
				printf("Result: %g\n", divide(a, b));
			}
		}

	} while (choice != 0);

	return (0);
}

