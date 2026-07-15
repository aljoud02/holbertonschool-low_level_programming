#include <stdio.h>

/**
 * add - Adds two numbers
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
 * subtract - Subtracts the second number from the first
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
 * multiply - Multiplies two numbers
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
 * divide - Divides the first number by the second
 * @a: First number
 * @b: Second number
 *
 * Return: Result of a / b
 */
int divide(int a, int b)
{
	return (a / b);
}

/**
 * main - Entry point for the menu-driven simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int num1, num2, result;

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

		if (choice < 1 || choice > 4)
		{
			printf("Invalid option. Please try again.\n\n");
			continue;
		}

		printf("Enter first number: ");
		scanf("%d", &num1);
		printf("Enter second number: ");
		scanf("%d", &num2);

		if (choice == 1)
		{
			result = add(num1, num2);
			printf("Result: %d\n\n", result);
		}
		else if (choice == 2)
		{
			result = subtract(num1, num2);
			printf("Result: %d\n\n", result);
		}
		else if (choice == 3)
		{
			result = multiply(num1, num2);
			printf("Result: %d\n\n", result);
		}
		else if (choice == 4)
		{
			if (num2 == 0)
			{
				printf("Error: Division by zero is undefined.\n\n");
			}
			else
			{
				result = divide(num1, num2);
				printf("Result: %d\n\n", result);
			}
		}

	} while (choice != 0);

	return (0);
}

