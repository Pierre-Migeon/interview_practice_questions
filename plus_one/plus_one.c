
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int	recursive_check(int *digits, int digitSize, int current, int count)
{
	int final = 0;

	if (digitSize == 0)
		return (0);
	if (digits[current] == 9)
		count++;
	if (count == digitSize)
		return (1);
	if (current == digitSize - 1)
		return (0);
	final = recursive_check(digits, digitSize, current + 1, count);
	return (final);
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i;
	int *plus;
	int carry = 0;

	i = recursive_check(digits, digitsSize, 0, 0);
	returnSize[0] = digitsSize + i;
	plus = (int *)malloc((int)sizeof(int) * returnSize[0]);
	for (int x = digitsSize - 1 + i; x >= 0; x--)
	{
        if (x == 0 && i)
            plus[0] = 1;
        if (x == digitsSize - 1 + i)
            plus[x] = digits[x - i] + 1;
        else if (x - i >= 0)
            plus[x] = digits[x - i] + carry;
        if (plus[x] > 9)
        {
            plus[x] = 0;
            carry = 1;        
        }
        else
            carry = 0;       
    }
	return (plus);
}



int	main()
{
	int digits[1] = { 9 };
	int returnSize = 0;
	int *digits2;

	digits2 = plusOne(digits, 1, &returnSize);
	printf ("returnSize is %i\n", returnSize);

	for(int x = 0; x < returnSize; x++)
	{
		printf("%i value is %i\n", x, digits2[x]);
	}
	free (digits2);
	return (0);
}
