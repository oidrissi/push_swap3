/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:22:04 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/10 23:49:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_elem(t_array *array, int element)
// {
// 	set_array(array, array->nb_elements, element);
// 	array->nb_elements++;
// }

// int	pop_elem(t_array *array)
// {
// 	int	tmp;
// 	int	i;

// 	i = 0;
// 	tmp = array->values[0];
// 	while (i < array->nb_elements)
// 	{
// 		array->values[i] = array->values[i + 1];
// 		i++;
// 	}
// 	return (tmp);
// }

void 	pa(t_array *a, t_array *b)
{
	int i;

	if (b->nb_elements == 0)
		return ;
	i = a->nb_elements;
	while (i >= 0)
	{
		a->values[i + 1] = a->values[i];
		i--;
	}
	a->values[0] = b->values[0];
	i = 1;
	while (i <= b->nb_elements)
	{
		b->values[i - 1] = b->values[i];
		i++;
	}
	b->nb_elements--;
	a->nb_elements++;
	write(1, "pa\n", 3);
}

void 	pb(t_array *a, t_array *b)
{
	int i;

	if (a->nb_elements == 0)
		return ;
	i = b->nb_elements - 1;
	while (i >= 0)
	{
		b->values[i + 1] = b->values[i];
		i--;
	}
	b->values[0] = a->values[0];
	i = 1;
	while (i <= a->nb_elements)
	{
		a->values[i - 1] = a->values[i];
		i++;
	}
	a->nb_elements--;
	b->nb_elements++;
	write(1, "pb\n", 3);
}

void	sa(t_array *array_a)
{
	int		tmp;

	tmp = array_a->values[1];
	array_a->values[1] = array_a->values[0];
	array_a->values[0] = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_array *array_b)
{
	int		tmp;

	tmp = array_b->values[1];
	array_b->values[1] = array_b->values[0];
	array_b->values[0] = tmp;
    write(1, "sb\n", 3);
}

void	ss(t_array *array_a, t_array *array_b)
{
	sa(array_a);
	sb(array_b);
    write(1, "ss\n", 3);
}