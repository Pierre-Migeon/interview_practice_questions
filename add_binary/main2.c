

#include <stdlib.h>
#include <stdio.h>

int     char_length(char *s)
{
    int len = 0;
    while(*(s++))
        len++;
    return (len);
}

char * addBinary(char * a, char * b){
    int len = (char_length(a) > char_length(b)) ? char_length(a) : char_length(b) ;
    char    *out = NULL;
    out = (char *)malloc(len + 2);
    int carry = 0;
    
    
    while (*a || *b)
    {
        *(out++) = ((*a ^ *b) && 1) ? '1' - carry : '0' + carry;
        carry = (((*a & *b) && 1) || ((*a ^ *b) && carry)) ? 1 : 0;
        if (*a)
            a++;
        if (*b)
            b++;
    } 
    return (out);
    
}


int	main()
{
	char str1[3] = "11";
	char str2[2] = "1";
	char *str3;

	str3 = addBinary(str1, str2);
	printf ("String 3 is %s\n", str3);
}
