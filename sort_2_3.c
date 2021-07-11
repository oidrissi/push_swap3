/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:13:16 by marvin            #+#    #+#             */
/*   Updated: 2021/07/07 03:13:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_array *a)
{
	if (a->values[0] > a->values[1])
        sa(a);
}

void	sort_3(t_array *a)
{
	if ((a->values[0] > a->values[1]) && (a->values[0] > a->values[2]))
    {
        ra(a);
        if (a->values[0] > a->values[1])
            sa(a);
    }
    else if ((a->values[0] > a->values[1]) && (a->values[0] < a->values[2]))
        sa(a);
	else if ((a->values[0] < a->values[1] && (a->values[0] > a->values[2])))
		rra(a);
    else if ((a->values[1] > a->values[2]))
    {
        rra(a);
        sa(a);
    }
	else if ((a->values[0] < a->values[1]) && (a->values[2] < a->values[0]))
		rra(a);
}

void	reverse_sort_3(t_array *a)
{
	if ((a->values[0] > a->values[1]) && (a->values[0] > a->values[2]))
    {
        rra(a);
        if (a->values[0] > a->values[1])
            sa(a);
    }
    else if ((a->values[0] > a->values[1]) && (a->values[0] < a->values[2]))
        sa(a);
	else if ((a->values[0] < a->values[1] && (a->values[0] > a->values[2])))
		ra(a);
    else if ((a->values[1] > a->values[2]))
    {
        ra(a);
        sa(a);
    }
	else if ((a->values[0] < a->values[1]) && (a->values[2] < a->values[0]))
		ra(a);
}


int	find_highest_elem(t_array *a)
{
	int	i;
	int max;
	int tmp;

	i = 0;
	max = a->values[0];
	tmp = 0;
	while (i <= a->nb_elements)
	{
		if (a->values[i] > max)
		{
			max = a->values[i];
			tmp = i;
		}
		i++;
	}
	return (tmp);
}

int	find_smallest_elem(t_array *a)
{
	int	i;
	int min;
	int tmp;

	i = 0;
	min = a->values[0];
	while (i < a->nb_elements)
	{
		if (a->values[i] < min)
		{
			min = a->values[i];
			tmp = i;
		}
		i++;
	}
	return (tmp);
}

int		find_lowest(t_array *a)
{
	int i;
	int ret;
	int tmp;

	i = 0;
	ret = a->values[0];
	tmp = 0;
	while (i < a->nb_elements)
	{
		if (a->values[i] < ret)
		{
			ret = a->values[i];
			tmp = i;
		}
		i++;
	}
	return (tmp);
}

void 	move_lowest_to_top(t_array *a)
{
	int x;

	x = find_lowest(a);
	if (x == 0)
		return ;
	// printf("lowest: %d  \n", x);
	if (a->nb_elements - x < x)
	{
		while (x < a->nb_elements)
		{
			rra(a);
			x++;
		}
	}
	else
	{
		while (x > 0)
		{
			ra(a);
			x--;
		}
	}
}

void	sort_6(t_array *a, t_array *b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		move_lowest_to_top(a);
		pb(a, b);
		i++;
	}
	sort_3(a);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}

void	sort_n(t_array *a, t_array *b)
{
	int	i;
	int	pb_count;

	i = a->nb_elements;
	pb_count = 0;
	while (i > 6)
	{
		move_lowest_to_top(a);
		pb(a, b);
		pb_count++;
		i--;
	}
	sort_6(a, b);
	while (pb_count > 0)
	{
		pa(a, b);
		pb_count--;
	}
}

void	sort_5_6(t_array *a, t_array *b)
{
	if (a->nb_elements == 4)
	{
		move_lowest_to_top(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
	if (a->nb_elements == 5)
	{
		move_lowest_to_top(a);
		pb(a, b);
		move_lowest_to_top(a);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		pa(a, b);
	}
	if (a->nb_elements == 6)
		sort_6(a, b);
}


void    sorter(t_array *a, t_array *b)
{
    if (a->nb_elements == 2)
		sort_2(a);
    else if (a->nb_elements == 3)
		sort_3(a);
	else if (a->nb_elements > 3 && a->nb_elements <= 6)
		sort_5_6(a, b);
	else if (a->nb_elements > 6)
		sort_n(a, b);
}