#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *new_node(int value)
{
	struct ListNode *new;
	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	new->val = value;
	new->next = NULL;
	return (new);
}

void	join(struct ListNode *a, struct ListNode *b)
{
	a->next = b;
}

struct ListNode	*addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	if (!l1) return l2;
	if (!l2) return l1;

	struct ListNode *out = new_node(0);
	struct ListNode *head = out;
	int new_val = 0;

	while(l1 || l2)
	{
		if (l1)
		{
			new_val += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			new_val += l2->val;
			l2 = l2->next;
		}
		out->next = new_node(new_val % 10);
		out = out->next;
		new_val /= 10;
	}
	if (new_val)
		out->next = new_node(new_val);
	return (head->next);
}

int	main()
{
	struct ListNode *a = new_node(9);
	struct ListNode *b = new_node(9);
	struct ListNode *c = new_node(9);
	struct ListNode *h1 = a;
	join(a, b);
	join(b, c);

	struct ListNode *d = new_node(9);
        struct ListNode *e = new_node(9);
        struct ListNode *f = new_node(9);
	struct ListNode *h2 = d;
	join(d, e);
	join(e,f);

	h1 = addTwoNumbers(h1, h2);

	while(h1)
	{
		printf ("%i ", h1->val);
		h1 = h1->next;
	}
	printf ( "\n" );

	return (0);
}
