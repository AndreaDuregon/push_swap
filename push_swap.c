/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:44:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/18 12:49:29 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_frame	frame;
	int		*subseq;
	int		sub_len = 0;

	if (argc < 2)
		exit(0);
	frame = create_frame(argc);
	fill_stack(argv, argc, &frame.a);
	enumerate_stack(&frame.a);
	subseq = calc_max_subseq(&frame.a, &sub_len);
	// for (int i = 0; i < sub_len; i++)
	// 	printf("%d ", subseq[i]);
	// puts("");
	// printf("%d\n", sub_len);
	solve(&frame, subseq, sub_len, frame.a.dim);
	print_stack(frame);
}
