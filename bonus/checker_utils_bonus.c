/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:33:36 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:35:35 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

void	read_instructions(t_sort *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_valid_instruction(stack, line) == 0)
		{
			clean_stack_memory(stack);
			error_exit();
		}
		line = get_next_line(0);
	}
}

int	check_valid_instruction(t_sort *stack, char *line)
{
	if (!ft_strncmp("sa", line, ft_strlen(line) - 1))
		swap_a(stack, 0);
	else if (!ft_strncmp("sb", line, ft_strlen(line) - 1))
		swap_b(stack, 0);
	else if (!ft_strncmp("ss", line, ft_strlen(line) - 1))
		swap_a_b(stack, 0);
	else if (!ft_strncmp("pa", line, ft_strlen(line) - 1))
		push_a(stack, 0);
	else if (!ft_strncmp("pb", line, ft_strlen(line) - 1))
		push_b(stack, 0);
	else if (!ft_strncmp("ra", line, ft_strlen(line) - 1))
		rotate_a(stack, 0);
	else if (!ft_strncmp("rb", line, ft_strlen(line) - 1))
		rotate_b(stack, 0);
	else if (!ft_strncmp("rr", line, ft_strlen(line) - 1))
		rotate_a_b(stack, 0);
	else if (!ft_strncmp("rra", line, ft_strlen(line) - 1))
		reverse_rotate_a(stack, 0);
	else if (!ft_strncmp("rrb", line, ft_strlen(line) - 1))
		reverse_rotate_b(stack, 0);
	else if (!ft_strncmp("rrr", line, ft_strlen(line) - 1))
		reverse_rotate_a_b(stack, 0);
	else
		return (0);
	return (1);
}
