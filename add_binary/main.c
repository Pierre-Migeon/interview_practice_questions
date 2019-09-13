
#include <stdio.h>


int     char_length(char *s)
{
    int len = 0;
    while(*(s++))
        len++;
    return (len);
}


char * addBinary(char * a, char * b){
    int len = (char_length(a) > char_length(b)) ? char_length(a) + 2 : char_length(b) + 2;
    char out[len];
    int i = 0;
    int carry = 0;
    
    while(*a && *b)
    {
        if (*a - '0' && *b - '0')
        {
        	out[i++] = (carry == 1) ? '1' : '0';
        	carry = 1;
        }
        else if (*a - '0' || *b - '0')
		out[i++] = (carry == 1) ? '0' : '1';
	else
	{
		out[i++] = (carry == 1) ? '1' : '0';
		carry = 0;
	}
        a++;
        b++;
    }
	while (carry)
		if (*a || *b)
		{
			out[i++] = (*a == '1' || *b == '1') ? '0' : '1';
			carry = (*a == '1' || *b == '1') ? 1 : 0;
		}
		else
		{
			out[i++] = '1';
			carry = 0;
		}
	while ( *a || *b )
		out[i++] = (*a) ? *a : *b;
	out[i] = '\0';
	return (&out[0]);
}

int	main()
{

	char str1[3] = "100";
	char str2[4] = "1010";
	char *add;
	add = addBinary(str1, str2);

	printf ("%s\n", add);


	return (0);
}
