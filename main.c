/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:29:14 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/11 00:59:04 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "stack.h"
#include "ftprintf/ft_printf.h"
#include "libft/libft.h"

//struct stack *s;

int	main(int argc, char **argv)
{
	 struct stack *stackA;
	 //struct stack *stackB;

	if (argc == 1) //TODO: display nothing, give prompt back?

	if (validateInput(argc, argv) == 0)
		ft_printf("Error\n");
	stackA = createNewStack(argc - 1, argv);
	//stackB = createNewStack(argc - 1, NULL);

	printStack(stackA);
	//printStack(stackB);
}

void printStack(struct stack *s)
{
	int i;
	while(s->size != 0)
	{
		i = pop(s);
		ft_printf("%d\n", i);
	}
}

/**
 * Returns 1 if all arguments in input are digits
 * 0 if they aren't
*/
int validateInput(int argc, char **argv)
{
	int j;
	long x;

	j = 0;
	while (argc > 0)
	{
		while (argv[argc][j] != '\0')
		{
			if (argv[argc][j] >= '0' && argv[argc][j] <= '9')
				j++;
			else
				return (0);
		}
		x = ft_atoi(argv[argc]);
		if (x < -2147483648 || x > 2147483647)
			return (0);
		if(alreadyExists(x, argv, argc))
			return (0);
		j = 0;
		argc--;
	}
	return (1);
}
/**
 * Take a note that we are looping from end of argv to start of it
*/
int alreadyExists(int num, char **argv, int i)
{
	i--;
	while (i != 0)
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i--;
	}
	return (0);
}

/**
 * Swap the first 2 elements at the top of stack 
*/
void swap(struct stack *s)
{
	int a;
	int b;

	a = pop(s);
	b = pop(s);

	push(s, b);
	push(s, a);
}
/**
 * Shift up all elements of stack by 1.
*/
void rotate(struct stack *s)
{
	int a;
	int b;
	struct stack *tempStack;

	tempStack = createNewStack(s->topItemIndex + 1, NULL);
	a = pop(s);

	while(s->topItemIndex != -1)
	{
		b = pop(s);
		push(tempStack, b);
	}
	push(s, a);
	while(tempStack->topItemIndex != -1)
	{
		b = pop(tempStack);
		push(s, b);
	}
	free(tempStack);
}

/**
 * Shift down all elements of stack a by 1.
*/
void reverseRotate(struct stack *s)
{
	int a;
	int b;
	struct stack *tempStack;

	tempStack = createNewStack(s->topItemIndex + 1, NULL);
	while (s->topItemIndex != 0)
	{
		a = pop(s);
		push(tempStack, a);
	}
	b = pop(s);
	while (tempStack->topItemIndex != -1)
	{
		a = pop(tempStack);
		push(s, a);
	}
	push(s, b);
	free(tempStack);
}

struct stack* createNewStack(int size, char **args)
{
	int i;
	int x;

	i = 1;
	struct stack *newStack = (struct stack*)malloc(sizeof(struct stack));
	newStack->size = size;
	newStack->topItemIndex = -1; //TODO: change this probably
	newStack->items = (int*)malloc(sizeof(int) * size);

	if (args != NULL)
	{
	newStack->size = 0;
		while (i <= size)
		{
			x = ft_atoi(args[i]);
			push(newStack, x);
			i++;
		}
	}

	return (newStack);
}
