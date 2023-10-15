/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:33:44 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/11 18:33:57 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int isStackFull(struct stack *s)
{
	//TODO: delete if not needed
    return (s->topItemIndex == s->size - 1);
}

int isStackEmpty(struct stack *s)
{
	//TODO: Make sure this works
	return (s->topItemIndex == s->size - 1 && s->size != 0);
}

void push(struct stack *s, int x)
{
	//TODO: print pa (push a) or pb (push b)
	
	s->size++;
	s->items[++s->topItemIndex] = x;
}

/**
* get the top element of the stack
*/
int peek(struct stack *s)
{
	if (!isStackEmpty(s))
		return (s->items[s->topItemIndex]);
	else
		exit(EXIT_FAILURE);	
}

int pop(struct stack *s)
{
//TODO: prints
	if (isStackEmpty(s) != 1)
		exit(EXIT_FAILURE);

	s->size--;
	return (s->items[s->topItemIndex--]);
}
int getMax(struct stack *s)
{
	int max;
	int i;

	max = s->items[0];
	i = 0;
	while (i < s->topItemIndex)
	{
		if (s->items[i] > max)
		{
			max = s->items[i];
		}
		i++;
	}
	return (max);
}
