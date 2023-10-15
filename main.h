/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:34:32 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/10 22:35:53 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

extern struct stack *s;

int	main(int argc, char **argv);
int validateInput(int argc, char **argv);
int alreadyExists(int num, char **argv, int i);
void swap(struct stack *s);
void rotate(struct stack *s);
void reverseRotate(struct stack *s);
struct stack* createNewStack(int size, char **args);


#endif
