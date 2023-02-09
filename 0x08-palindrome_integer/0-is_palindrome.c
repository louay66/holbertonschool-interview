#include <stdlib.h>
#include <stdio.h>
/**
 * is_palindrome- return 1 or 0
 *
 * @n: diget to check
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return ((reversed == original) ? 1 : 0);
}
