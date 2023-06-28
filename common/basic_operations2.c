/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:57:30 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:35:14 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	swap_a_b(t_sort *stack, int n)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	if (n)
		ft_putstr_fd("ss\n", 1);
}

void	rotate_a(t_sort *stack, int n)
{
	int	tmp;

	if (stack->a_size <= 1)
		return ;
	tmp = stack->a[0];
	ft_memmove(stack->a, stack->a + 1, sizeof(int) * (stack->a_size - 1));
	stack->a[stack->a_size - 1] = tmp;
	if (n)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_sort *stack, int n)
{
	int	tmp;

	if (stack->b_size <= 1)
		return ;
	tmp = stack->b[0];
	ft_memmove(stack->b, stack->b + 1, sizeof(int) * (stack->b_size - 1));
	stack->b[stack->b_size - 1] = tmp;
	if (n)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_a_b(t_sort *stack, int n)
{
	if (stack->b_size <= 1 && stack->b_size <= 1)
		return ;
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	if (n)
		ft_putstr_fd("rr\n", 1);
}
