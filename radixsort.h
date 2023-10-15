/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:18:00 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/15 23:18:02 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RADIXSORT_H
# define RADIXSORT_H

extern struct stack *s;

int getMax(struct stack *s);
void countSort(int *arr, int n, int x);
void radixSort(struct stack *s);

#endif