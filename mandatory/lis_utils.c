/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:55:55 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 01:56:22 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lis_rec(t_lis *lis, int i, int end, int last)
{
	int	ans;

	if (i == end)
		return (0);
	if (last != -1 && lis->dp[i][last] != -1)
		return (lis->dp[i][last]);
	ans = lis_rec(lis, i + 1, end, last);
	if (last == -1 || lis->tmp[last] < lis->tmp[i])
		ans = max(ans, 1 + lis_rec(lis, i + 1, end, i));
	if (last != -1)
		lis->dp[i][last] = ans;
	return (ans);
}

void	set_dp(int **dp, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			dp[i][j] = -1;
	}
}

void	make_dp_array(t_lis *lis, t_sort *stack)
{
	int	i;

	lis->dp = (int **)malloc(sizeof(int *) * stack->a_size);
	if (!lis->dp)
	{
		clean_stack_memory(stack);
		clean_lis_memory(lis, 1, 0);
		error_exit();
	}
	i = -1;
	while (++i < stack->a_size)
	{
		lis->dp[i] = (int *)malloc(sizeof(int) * stack->a_size);
		if (!lis->dp[i])
		{
			clean_stack_memory(stack);
			clean_lis_memory(lis, 2, i);
			error_exit();
		}
	}
	set_dp(lis->dp, stack->a_size);
}

void	longuest_increasing_subsequence(t_sort *stack, t_lis *lis)
{
	int	i;

	lis->tmp = (int *)malloc(sizeof(int) * stack->a_size);
	if (!lis->tmp)
	{
		clean_stack_memory(stack);
		free(lis);
		error_exit();
	}
	i = min_element(stack);
	ft_memcpy(lis->tmp, stack->a + i, (stack->a_size - i) * sizeof(int));
	ft_memcpy(lis->tmp + (stack->a_size - i), stack->a, i * sizeof(int));
	make_dp_array(lis, stack);
	lis->len = lis_rec(lis, 0, stack->a_size, -1);
	build_lis_sequence(lis, stack, stack->a_size);
	put_numbers_to_stack_b(stack, lis);
	clean_lis_memory(lis, 3, stack->a_size + stack->b_size);
}
