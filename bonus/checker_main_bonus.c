/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:33:18 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:33:34 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char **argv)
{
	t_sort	*stack;
	int		len_stack;

	len_stack = check_errors(ac, argv);
	stack = (t_sort *)malloc(sizeof(t_sort));
	if (!stack)
		error_exit();
	ft_initialize_stack(stack, len_stack);
	put_numbers_to_stack_a(argv, stack);
	read_instructions(stack);
	if (sorted_stack(stack) && stack->b_size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_stack_memory(stack);
}
