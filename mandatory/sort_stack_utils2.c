/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:14:05 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:32:54 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_moves(t_sort *stack, void (*fun_ptr) (t_sort *, int), int n)
{
	while (n--)
		fun_ptr(stack, 1);
}

void	move_neg(t_sort *stack, t_move *mv, int mini)
{
	make_moves(stack, reverse_rotate_a_b, abs(max(mv[mini].a, mv[mini].b)));
	if (mv[mini].a < mv[mini].b)
		make_moves(stack, reverse_rotate_a, abs(mv[mini].a) - abs(mv[mini].b));
	else
		make_moves(stack, reverse_rotate_b, abs(mv[mini].b) - abs(mv[mini].a));
}

void	move_pos(t_sort *stack, t_move *mv, int mini)
{
	make_moves(stack, rotate_a_b, min(mv[mini].a, mv[mini].b));
	if (mv[mini].a < mv[mini].b)
		make_moves(stack, rotate_b, mv[mini].b - mv[mini].a);
	else
		make_moves(stack, rotate_a, mv[mini].a - mv[mini].b);
}

void	move_pos_neg(t_sort *stack, t_move *mv, int mini)
{
	if (mv[mini].a > 0)
		make_moves(stack, rotate_a, mv[mini].a);
	else
		make_moves(stack, reverse_rotate_a, abs(mv[mini].a));
	if (mv[mini].b > 0)
		make_moves(stack, rotate_b, mv[mini].b);
	else
		make_moves(stack, reverse_rotate_b, abs(mv[mini].b));
}

void	push_min_to_a(t_sort *stack, t_move *mv)
{
	int	i;
	int	mini;
	int	moves_num;
	int	prev_num;

	i = -1;
	prev_num = INT_MAX;
	while (++i < stack->b_size)
	{
		moves_num = (abs(mv[i].a) + abs(mv[i].b)) * (mv[i].a * mv[i].b <= 0);
		moves_num += (mv[i].a * mv[i].b > 0) * max(abs(mv[i].a), abs(mv[i].b));
		if (moves_num < prev_num)
		{
			mini = i;
			prev_num = moves_num;
		}
	}
	if (mv[mini].a < 0 && mv[mini].b < 0)
		move_neg(stack, mv, mini);
	else if (mv[mini].a > 0 && mv[mini].b > 0)
		move_pos(stack, mv, mini);
	else
		move_pos_neg(stack, mv, mini);
	push_a(stack, 1);
}
