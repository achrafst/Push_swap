/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:57:34 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:35:19 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_a(t_sort *stack, int n)
{
	if (stack->a_size <= 1)
		return ;
	swap(stack->a, stack->a + 1);
	if (n)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_sort *stack, int n)
{
	if (stack->b_size <= 1)
		return ;
	swap(stack->b, stack->b + 1);
	if (n)
		ft_putstr_fd("sb\n", 1);
}

void	push_b(t_sort *stack, int n)
{
	int	tmp;

	if (!stack->a_size)
		return ;
	tmp = stack->a[0];
	ft_memmove(stack->a, stack->a + 1, (stack->a_size - 1) * sizeof(int));
	stack->a_size -= 1;
	ft_memmove(stack->b + 1, stack->b, stack->b_size * sizeof(int));
	stack->b[0] = tmp;
	stack->b_size += 1;
	if (n)
		ft_putstr_fd("pb\n", 1);
}

void	push_a(t_sort *stack, int n)
{
	int	tmp;

	if (!stack->b_size)
		return ;
	tmp = stack->b[0];
	ft_memmove(stack->b, stack->b + 1, (stack->b_size - 1) * sizeof(int));
	stack->b_size -= 1;
	ft_memmove(stack->a + 1, stack->a, stack->a_size * sizeof(int));
	stack->a[0] = tmp;
	stack->a_size += 1;
	if (n)
		ft_putstr_fd("pa\n", 1);
}

/*void	display_a(t_sort *stack)
{
	for(int i=0; i < stack->a_size; i++)
		printf("%d ", stack->a[i]);
	printf("\n");
}

void	display_b(t_sort *stack)
{
	for(int i=0; i < stack->b_size; i++)
		printf("%d ", stack->b[i]);
	printf("\n");
}*/
