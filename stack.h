/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:35:08 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/11 18:35:10 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>

/**
* Stack data structure
*/
struct stack
{ //TODO: do i need char for determining stack name..?
	int	maxSize;
	int	topItemIndex;
	int	*items;
};

struct stack* createNewStack(int size)
{
	struct stack *newStack = (struct stack*)malloc(sizeof(struct stack));
	newStack->maxSize = size;
	newStack->topItemIndex = -1; //TODO: change this probably
	newStack->items = (int*)malloc(sizeof(int) * size);

	return (newStack);
}

#endif