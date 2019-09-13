#include <stdlib.h>
#include <stdio.h>

int	numstrlen(char *num)
{
	int i = 0;

	while (num[i])
		i++;
	return (i);
}

void	adjust(char *out)
{
	int i;
	int j;

	i = 0;
	while(out[i] == '0')
		++i;
	j = i;
	while(out[i])
	{
		out[i - j] = out[i];
		i++;
	}
	out[i - j] = '\0';
}

char *pm_multiply(char *n1, char *n2)
{
	char *out;
	int last;
	int len1;
	int len2;
	int len3;

	len1 = numstrlen(n1);
	len2 = numstrlen(n2);
	len3 = len1 + len2;

	out = (char *)malloc(sizeof(char) * (len3 + 1));
	for(int x = len3 - 1; x > -1; x--)
		out[x] = '0';
	out[len3] = '\0';
	for (int i = len1 - 1; i > -1; i--)
		for (int j = len2 - 1; j > -1; j--)
		{
			last = (n1[i] - '0') * (n2[j] - '0') + (out[i + j + 1] - '0');
			out[i + j + 1] = last % 10 + '0';
			out[i + j] = last / 10 + (out[i + j] - '0') + '0';
		}
	adjust(out);
	return (out);
}

int	main()
{
	char num1[] = "999";
	char num2[] = "999";
	char *outnum;

	outnum = pm_multiply(num1, num2);
	printf ("%s\n", outnum);
	return (0);
}
