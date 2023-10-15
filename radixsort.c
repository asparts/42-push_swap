/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:17:53 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/15 23:17:56 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radixsort.h"
#include "stack.h"
#include "main.h"

int getMax(struct stack *s)
{
	int max;
	int i;

	max = s->items[0];
	i = 0;
	while (i <= s->topItemIndex)
	{
		if (s->items[i] > max)
		{
			max = s->items[i];
		}
		i++;
	}
	return (max);
}

/**
 * function to do counting sort of arr[] according
 * to the digit represented by x
*/
void countSort(int *arr, int n, int x)
{
	int *output;
	int i;
	int *count;
	output = malloc(n * sizeof(int) + 1);
	count = malloc(10 * sizeof(int) + 1);
    i = 0;
	while(i < n)
	{
		count[(arr[i] / x) % 10]++;
		i++;
	}
	i = 1;
	while (i <= 10)
	{
		count[i] += count[i-1];
        i++;
	}
	/**Build output array*/
	i = n - 1;
	while (i >= 0)
	{
		output[count[(arr[i] / x) % 10] - 1] = arr[i];
		count[(arr[i] / x) % 10]--;
        i--;
	}
	/**Copy the output array to arr[] so that arr[] now contains sorted numbers according to current digit*/
	i = 0;
    while(i < n)
    {
        arr[i] = output[i];
        i++;
    }
}

void radixSort(struct stack *s)
{
	int exp;
	int max; 

	max = getMax(s);
    exp = 1;
	while (max / exp > 0)
	{
		countSort(s->items, s->size, exp);
        exp *= 10;
	}
}