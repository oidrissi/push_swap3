/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:53:55 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/07 03:42:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_array	t_array;

struct s_array /* structure for dynamic array */
{
	int		*values;
	int		nb_elements; //the actual length of the array aka number of elements
	int		alloc_size; // the allocated memory size 
};

void	grow_array(t_array *array, int new_size);
t_array	*empty_array(int alloc_size);
void	array_destroyer(t_array *array);
void	set_array(t_array *array, int index, int element);
void	push_elem(t_array *array, int element);
int		pop_elem(t_array *array);
void	pa(t_array *a, t_array *b);
void	pb(t_array *a, t_array *b);
void	sa(t_array *array_a);
void	sb(t_array *array_a);
void	ss(t_array *array_a, t_array *array_b);
void    ra(t_array *a);
void    rra(t_array *a);
void    sorter(t_array *a, t_array *b);

#endif