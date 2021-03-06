/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_subseq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:58:48 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 12:18:20 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_arr(int *copy, int len_seq, int min)
{
	int		tmp;

	while (copy[0] != min)
	{
		if (copy[0] != min)
		{
			tmp = copy[0];
			ft_memmove_int(&copy[0], &copy[1], len_seq);
			copy[len_seq - 1] = tmp;
			continue ;
		}
	}
}

int		*calc_lis(int *init_seq, int len_seq, int *max_lis, int *j)
{
	int		i;
	int		*lis;

	if (!(lis = ft_calloc(len_seq, sizeof(int))))
		return (0);
	while (*j < len_seq)
	{
		i = 0;
		while (i < *j)
		{
			if ((init_seq[i] < init_seq[*j]) && lis[i] == lis[*j])
				if (++lis[*j] > *max_lis)
					*max_lis = lis[*j];
			i++;
		}
		(*j)++;
	}
	return (lis);
}

void	take_min(int *copy, int len)
{
	int		min;

	min = find_min(copy, len);
	rotate_arr(copy, len, min);
}

int		*max_subseq(int j, int *lis, int max_lis, int *copy)
{
	int flag;
	int *ret;

	if (!(ret = malloc(sizeof(int) * max_lis + 1)))
		return (NULL);
	flag = 0;
	while (--j >= 0)
	{
		if ((flag == 0 && lis[j] == max_lis) || ((lis[j] == max_lis)
										&& lis[j] < ret[max_lis + 1]))
		{
			ret[max_lis--] = copy[j];
			flag = 1;
		}
	}
	return (ret);
}

int		*calc_max_subseq(t_stack *stack, int *sub_len)
{
	int		*copy;
	int		*lis;
	int		max_lis;
	int		j;
	int		*ret;

	j = 0;
	max_lis = 0;
	copy = copy_stack(stack);
	take_min(copy, stack->dim);
	lis = calc_lis(copy, stack->dim, &max_lis, &j);
	ret = 0;
	ret = max_subseq(j, lis, max_lis, copy);
	free(lis);
	free(copy);
	*sub_len = max_lis + 1;
	return (ret);
}
