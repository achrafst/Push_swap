/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:07:05 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 02:21:37 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_number(t_sort *stack)
{
	int	j;
	int	maxi;

	j = 0;
	maxi = 0;
	while (++j < stack->a_size)
	{
		if (stack->a[j] > stack->a[maxi])
			maxi = j;
	}
	return (maxi);
}

int	get_a_moves(t_sort *stack, int i)
{
	int	j;
	int	correct_pos;
	int	prev;

	correct_pos = -1;
	prev = INT_MAX;
	j = -1;
	while (++j < stack->a_size)
	{
		if (stack->a[j] > stack->b[i] && stack->a[j] <= prev)
		{
			correct_pos = j;
			prev = stack->a[j];
		}
	}
	if (correct_pos == -1)
	{
		correct_pos = get_max_number(stack);
		if (correct_pos < (stack->a_size / 2))
			return (correct_pos + 1);
		return (-(stack->a_size -1 - correct_pos));
	}
	else if (correct_pos <= (stack->a_size / 2))
		return (correct_pos);
	return (-(stack->a_size - correct_pos));
}

int	get_b_moves(t_sort *stack, int i)
{
	if (i <= (stack->b_size / 2))
		return (i);
	else
		return (-(stack->b_size - i));
}

void	sort_stack(t_sort *stack, t_lis *lis)
{
	int		i;
	t_move	*mv;

	mv = (t_move *)malloc(sizeof(t_move) * stack->b_size);
	if (!mv)
	{
		clean_stack_memory(stack);
		clean_lis_memory(lis, 3, stack->a_size);
		error_exit();
	}
	while (stack->b_size)
	{
		i = -1;
		while (++i < stack->b_size)
		{
			mv[i].a = get_a_moves(stack, i);
			mv[i].b = get_b_moves(stack, i);
		}
		push_min_to_a(stack, mv);
	}
	make_a_sorted(stack);
	free(mv);
}

void	make_a_sorted(t_sort *stack)
{
	int	mini;
	int	mine;

	mini = min_element(stack);
	mine = stack->a[mini];
	if (mini <= (stack->a_size / 2))
	{
		while (stack->a[0] != mine)
			rotate_a(stack, 1);
	}
	else
	{
		while (stack->a[0] != mine)
			reverse_rotate_a(stack, 1);
	}
}
