/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:00:31 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 02:00:32 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_initialize_stack(t_sort *stack, int len)
{
	stack->a = (int *)malloc(sizeof(int) * len);
	if (!stack->a)
	{
		free(stack);
		error_exit();
	}
	stack->b = (int *)malloc(sizeof(int) * len);
	if (!stack->b)
	{
		free(stack->a);
		free(stack);
		error_exit();
	}
	stack->a_size = 0;
	stack->b_size = 0;
}

int	repeated_numbers(t_sort *stack, int number)
{
	int	j;

	j = -1;
	while (++j < stack->a_size - 1)
	{
		if (stack->a[j] == number)
			return (1);
	}
	return (0);
}

void	put_to_stack(char **s, t_sort *stack)
{
	int	i;

	i = 0;
	while (s[i])
	{
		stack->a[stack->a_size++] = ft_atoi(s[i]);
		if (repeated_numbers(stack, stack->a[stack->a_size - 1]))
		{
			clean_stack_memory(stack);
			error_exit();
		}
		i++;
	}
}

void	put_numbers_to_stack_a(char **argv, t_sort *stack)
{
	char	**s;
	int		i;

	i = 0;
	while (argv[++i])
	{
		s = ft_split(argv[i], ' ');
		if (!s)
		{
			clean_stack_memory(stack);
			error_exit();
		}
		put_to_stack(s, stack);
		free_memory(s);
	}
}
