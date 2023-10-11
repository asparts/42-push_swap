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
    return (s->topItemIndex == s->maxSize - 1);
}

int isStackEmpty(struct stack *s)
{
	return (s->topItemIndex == s->maxSize - 1);
}

void push(struct stack *s, int x)
{
	//TODO: print pa (push a) or pb (push b)
	
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
	if (isStackEmpty(s))
		exit(EXIT_FAILURE);

	return (s->items[s->topItemIndex--]);
}