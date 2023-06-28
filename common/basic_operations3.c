/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:58:11 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:35:07 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	reverse_rotate_a(t_sort *stack, int n)
{
	int	tmp;

	if (stack->a_size <= 1)
		return ;
	tmp = stack->a[stack->a_size - 1];
	ft_memmove(stack->a + 1, stack->a, sizeof(int) * (stack->a_size - 1));
	stack->a[0] = tmp;
	if (n)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_sort *stack, int n)
{
	int	tmp;

	if (stack->b_size <= 1)
		return ;
	tmp = stack->b[stack->b_size - 1];
	ft_memmove(stack->b + 1, stack->b, sizeof(int) * (stack->b_size - 1));
	stack->b[0] = tmp;
	if (n)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_a_b(t_sort *stack, int n)
{
	if (stack->b_size <= 1 && stack->a_size <= 1)
		return ;
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	if (n)
		ft_putstr_fd("rrr\n", 1);
}
