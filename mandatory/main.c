/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:25:45 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 02:25:46 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clean_lis_memory(t_lis *lis, int n, int dp_n)
{
	int	i;

	if (n >= 1)
		free(lis->tmp);
	if (n >= 2)
	{
		i = 0;
		while (i < dp_n)
		{
			free(lis->dp[i]);
			i++;
		}
		free(lis->dp);
	}
	if (n >= 3)
		free(lis->arr);
	free(lis);
}

int	main(int ac, char **argv)
{
	t_sort	*stack;
	t_lis	*lis;
	int		len_stack;

	len_stack = check_errors(ac, argv);
	stack = (t_sort *)malloc(sizeof(t_sort));
	if (!stack)
		error_exit();
	ft_initialize_stack(stack, len_stack);
	put_numbers_to_stack_a(argv, stack);
	if (stack->a_size == 3)
		sort_stack_3(stack);
	lis = (t_lis *)malloc(sizeof(t_lis));
	if (!lis)
	{
		clean_stack_memory(stack);
		error_exit();
	}
	longuest_increasing_subsequence(stack, lis);
	sort_stack(stack, lis);
	clean_stack_memory(stack);
}
