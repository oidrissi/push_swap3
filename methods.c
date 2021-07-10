/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 05:14:40 by marvin            #+#    #+#             */
/*   Updated: 2021/07/08 05:14:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grow_array(t_array *array, int new_size)
{
	int	*new_array;
	int	i;

	i = 0;
	new_array = malloc((new_size) * sizeof(int));
	while (i < array->nb_elements)
	{
		new_array[i] = array->values[i];
		i++;
	}
	free(array->values);
	array->values = new_array;
}

/*
** alloc_size is ac - 1
*/

t_array	*empty_array(int alloc_size)
{
	t_array	*e_arr;

	e_arr = malloc(sizeof(t_array));
	e_arr->alloc_size = alloc_size;
	e_arr->values = (int *)malloc((alloc_size) * sizeof(int));
	e_arr->nb_elements = 0;
	return (e_arr);
}

void	array_destroyer(t_array *array)
{
	free(array->values);
	free(array);
}

void	set_array(t_array *array, int index, int element)
{
	if (index < array->alloc_size)
		array->values[index] = element;
	else if (index >= array->alloc_size)
	{
		grow_array(array, (index * 2) + 1);
		array->values[index] = element;
	}
}