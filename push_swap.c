/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:00:17 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/11 01:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
    	{
        	if (atoi(av[i]) == atoi(av[j]))
        	{
            	write(2, "Error\n", 6);
            	return 1;
            }
        	j++;
    	}
    	i++;
	}
	return 0;
}

long		ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

int	correct_input(char **av)
{
	int	i;
	int	j;

    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
            {
                write(2, "Error\n", 6);
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int	is_sorted(char **av, t_array *a)
{
    int	i;

    i = 0;
    while (i < a->nb_elements)
    {
        if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    int	i;
    t_array	*a;
	t_array	*b;

    a = (t_array *)malloc(sizeof(t_array));
    a->nb_elements = ac - 1;
    i = 1;
    if (ac == 1 || ac == 2 || !ac)
        return 0;
    if (correct_input(av) == 1 || check_dup(av) == 1 || is_sorted(av, a) == 1)
		return 0;
	a->values = (int *)malloc(sizeof(int) * a->nb_elements + 1);
	b = empty_array(1);
    while (i <= a->nb_elements)
    {
        a->values[i - 1] = ft_atoi(av[i]);
        i++;
    }
    sorter(a, b);
	i = 1;
	while (i <= a->nb_elements)
	{
		printf("Stack A|| %d\n", a->values[i - 1]);
		i++;
	}
	i = 1;
	while (i <= ac - 1)
	{
		printf("	    Stack B|| %d\n", b->values[i - 1]);
		i++;
	}
	array_destroyer(b);
	array_destroyer(a);
    return 1;
}

// merge_sort(t_array *a, t_array *b)
// {

// }

// int		midpoint_finder_a(t_array *a)
// {
// 	int mid;

// 	mid = a->values[nb_elements/2];
// 	return (mid);
// }

// int		midpoint_finder_b(t_array *b)
// {
// 	int mid;

// 	mid = a->values[nb_elements/2];
// 	return (mid);
// }

// void    sort_5(t_array *a, t_array *b)
// {
//     int i;
//     int mid;

//     i = 0;
//     mid = midpoint_finder_a(a);
//     while (i < a->nb_elements)
// 	{
// 		if (a->values[i] > a->values[mid])
// 			pb(a, b);
// 		// else if (a->values[i] )
// 		// i++;
// 		i++;
// 	}
// }