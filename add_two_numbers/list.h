

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct list
{
	int num;
	struct list *next;
};

//char			*ft_itoa(int n);
//static int		ft_numlen(int n);

#endif
