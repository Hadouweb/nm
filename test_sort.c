#include "libft.h"
#include <stdio.h>

typedef struct 		s_node
{
	t_link			link;
	int 			value;
}					t_node;

typedef struct 		s_app
{
	t_list			list;
}					t_app;


t_node	*make_node(int v)
{
	t_node	*n;

	n = (t_node*)malloc(sizeof(t_node));
	n->value = v;
	n->link.next = NULL;
	n->link.prev = NULL;
	return n;
}

void	loop_list(t_app *app)
{
	t_link		*node;

	node = app->list.head;
	while (node)
	{
		t_node *n = PTR_NODE(node, t_node, link);
		printf("%d\n", n->value);
		node = node->next;
	}
}

int 	cmp(int a, int b)
{
	return a - b;
}

void 	insertion_sort(t_app *app, t_node *n)
{
	t_link		*node;
	t_node		*n2;

	node = app->list.head;
	printf("n0: %d\n", n->value);
	while (node)
	{
		printf("n1: %d\n", n->value);
		n2 = PTR_NODE(node, t_node, link);
		if (cmp(n->value, n2->value) > 0)
		{
			printf("n2: %d\n", n->value);
			ft_list_push_before_node(&app->list, &n2->link, &n->link);
			printf("n3: %d\n", n->value);
			return ;
		}
		node = node->next;
	}
	ft_list_push_back(&app->list, &n->link);
	printf("-------\n");
}

int		main(void)
{
	t_app	app;
	int 	i;

	ft_bzero(&app, sizeof(app));

	i = 0;
	while (i < 10)
	{
		t_node *n = make_node(i);
		insertion_sort(&app, n);
		i++;
	}
	loop_list(&app);
	return 0;
}