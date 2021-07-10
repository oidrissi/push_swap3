/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:23:43 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/07 03:34:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_array *a)
{
    int tmp;
    int n;
    
    if (a->nb_elements == 0)
        return ;
    n = 1;
    tmp = a->values[0];
    while (n < a->nb_elements)
    {
        a->values[n - 1] = a->values[n];
        n++;
    }
    a->values[n - 1] = tmp;
	write(1, "ra\n", 3);
}

void    rb(t_array *b)
{
    int tmp;
    int n;
    
    if (b->nb_elements == 0)
        return ;
    n = 1;
    tmp = b->values[0];
    while (n < b->nb_elements)
    {
        b->values[n - 1] = b->values[n];
        n++;
    }
    b->values[n - 1] = tmp;
    write(1, "rb\n", 3);
}

void    rra(t_array *a)
{
	size_t	i;
	int		tmp;

	if (a->nb_elements == 0)
        return ;
	tmp = a->values[a->nb_elements - 1];
	i = a->nb_elements - 1;
	while (i > 0)
	{
		a->values[i] = a->values[i - 1];
		i--;
	}
	a->values[0] = tmp;
	write(1, "rra\n", 4);
}

void    rrb(t_array *b)
{
	size_t	i;
	int		tmp;

	if (b->nb_elements == 0)
        return ;
	tmp = b->values[b->nb_elements - 1];
	i = b->nb_elements - 1;
	while (i > 0)
	{
		b->values[i] = b->values[i - 1];
		i--;
	}
	b->values[0] = tmp;
	write(1, "rrb\n", 4);
}
