
#include "./list.h"

int	main()
{
	struct list *a, *head, *current;
	int number, i = 1;

	printf("Well yes it seems the program has started. Enter a number!\n");
	scanf("%i", &number);

	a = (struct list *)malloc(sizeof(struct list));
	head = a;
	while (number)
	{
		a->num = number % 10;
		a->next = (struct list *)malloc(sizeof(struct list));
		a = a->next;
		number /= 10;
		i *= 10;
	}
	i /= 10;
	while (head)
	{
		head->num *= i;
		number += head->num;
		current = head;
		head = head->next;
		free(current);
	}

}
