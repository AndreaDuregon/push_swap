/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:07:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 10:04:49 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_frame	create_frame(t_stack a, t_stack b)
{
	t_frame		frame;

	frame.a = a;
	frame.b = b;
	return (frame);
}
