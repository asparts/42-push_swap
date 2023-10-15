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
#include "ftprintf/ft_printf.h"
#include "libft/libft.h"
/**
* Stack data structure
*/
struct stack
{ //TODO: do i need char for determining stack name..?
	int	size;
	int	topItemIndex;
	int	*items;
};

int isStackFull(struct stack *s);
int isStackEmpty(struct stack *s);
void push(struct stack *s, int x);
int peek(struct stack *s);
int pop(struct stack *s);

#endif