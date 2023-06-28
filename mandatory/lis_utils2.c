/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:56:30 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:32:38 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	build_seq(t_lis *lis, int i, int n, int last)
{
	int	optimal;
	int	choice1;
	int	choice2;

	if (i == n)
		return ;
	optimal = lis_rec(lis, i, n, last);
	choice1 = lis_rec(lis, i + 1, n, last);
	choice2 = 1 + lis_rec(lis, i + 1, n, i);
	if (choice1 == optimal)
		build_seq(lis, i + 1, n, last);
	else
	{
		lis->arr[lis->arr_size++] = lis->tmp[i];
		build_seq(lis, i + 1, n, i);
	}
}

void	build_lis_sequence(t_lis *lis, t_sort *stack, int n)
{
	lis->arr = (int *)malloc(sizeof(int) * n);
	if (!lis->arr)
	{
		clean_stack_memory(stack);
		clean_lis_memory(lis, 2, n);
		error_exit();
	}
	lis->arr_size = 0;
	build_seq(lis, 0, n, -1);
}

int	find(t_lis *lis, int elem)
{
	int	i;

	i = 0;
	while (i < lis->len)
	{
		if (lis->arr[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

void	put_numbers_to_stack_b(t_sort *stack, t_lis *lis)
{
	while (stack->a_size != lis->len)
	{
		if (find(lis, stack->a[0]))
			rotate_a(stack, 1);
		else
			push_b(stack, 1);
	}
}
