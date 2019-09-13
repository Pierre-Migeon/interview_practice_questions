
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
    if (!(*a))
        return (b);
    if (!(*b))
        return (a);
    int len = (char_length(a) > char_length(b)) ? char_length(a) + 1 : char_length(b) + 1;
    int lena = char_length(a) - 1;
    int lenb = char_length(b) - 1;
    char *out = (char *)malloc(len + 1);
    int carry = 0;
    *(out + len--) = '\0';
    while (lena >= 0 && lenb >= 0)
    {
        *(out + len) = ((*(a + lena) ^ *(b + lenb)) && 1) ? '1' - carry : '0' + carry;
        carry = (((*(a + lena) ^ *(b + lenb)) && carry) || (*(a + lena) + *(b + lenb)) % 98 == 0) ? 1 : 0;
 	len--;
	lena--;
	lenb--;
    }
    while(lena >= 0)
    {
       *(out + len) = a[lena] == '1' ? *(a + lena) - carry : *(a + lena) + carry;
        carry = (a[lena] == '1' && carry) ? 1 : 0;
	len--;
	lena--;
    }
    while(lenb >= 0)
    {
        *(out + len) = (b[lenb] == '1') ? b[lenb] - carry :  b[lenb] + carry;
        carry = (b[lenb] == '1' && carry) ? 1: 0; 
	lenb--;
	len--;
    } 
	if (carry)
		*(out + len) = '1';
    	else 
		len++;
    return out + len;
}



int	main()
{
	char str1[5] = "0111";
	char str2[2] = "1";
	char *str3;

	str3 = addBinary(str1, str2);
	printf ("String 3 is %s\n", str3);
}
