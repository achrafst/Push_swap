/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:01:11 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 02:24:53 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_element(t_sort *stack)
{
	int	mini;
	int	i;

	mini = 0;
	i = 1;
	while (i < stack->a_size)
	{
		if (stack->a[i] < stack->a[mini])
			mini = i;
		i++;
	}
	return (mini);
}

int	sorted_stack(t_sort *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack_3(t_sort *stack)
{
	int	mini;

	if (sorted_stack(stack))
		return ;
	mini = min_element(stack);
	if (mini == 0)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else if (mini == 1)
	{
		if (stack->a[0] > stack->a[2])
			rotate_a(stack, 1);
		else
			swap_a(stack, 1);
	}
	else
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	clean_stack_memory(stack);
	exit(0);
}
