

#include <stdio.h>
#include <stdlib.h>

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
	int carry = 1;

	i = recursive_check(digits, digitsSize, 0, 0);
	returnSize[0] = digitsSize + i;
	plus = (int *)malloc((int)sizeof(int) * returnSize[0]);
	for (int x = digitsSize - 1 + i; x >= 0; x--)
	{
        	plus[x] = (digits[x - i] + carry) % 10;
        	carry = (digits[x - i] + carry) / 10;        
    	}
    	if (i && plus[1] == 0)
    	{
        	plus[1] = 0;
        	plus[0] = 1;
    	}    
	printf ( "i is %i", i);
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

