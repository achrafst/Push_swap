/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:39:03 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 04:43:35 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef struct s_lis
{
	int	len;
	int	*tmp;
	int	**dp;
	int	*arr;
	int	arr_size;
}t_lis;

typedef struct s_move
{
	int	a;
	int	b;
}t_move;

/*exit_clean_functions*/
void	clean_lis_memory(t_lis *lis, int n, int dp_n);

/*error and initialisation functions*/
int		check_errors(int ac, char **argv);
int		invalid_numbers(char **s);
void	free_memory(char **s);
void	put_numbers_to_stack_a(char **argv, t_sort *stack);
void	put_to_stack(char **s, t_sort *stack);
int		repeated_numbers(t_sort *stack, int number);
void	ft_initialize_stack(t_sort *stack, int len);

/*lis utils*/
void	set_dp(int **dp, int n);
int		lis_rec(t_lis *lis, int i, int end, int last);
void	build_seq(t_lis *lis, int i, int n, int last);
void	build_lis_sequence(t_lis *lis, t_sort *stack, int n);
void	longuest_increasing_subsequence(t_sort *stack, t_lis *lis);
int		find(t_lis *lis, int elem);
void	put_numbers_to_stack_b(t_sort *stack, t_lis *lis);

/*sort stack utils*/
void	sort_stack(t_sort *stack, t_lis *lis);
int		get_b_moves(t_sort *stack, int i);
int		get_a_moves(t_sort *stack, int i);
int		get_max_number(t_sort *stack);
void	make_a_sorted(t_sort *stack);
int		min_element(t_sort *stack);
void	sort_stack_3(t_sort *stack);
int		sorted_stack(t_sort *stack);
void	push_min_to_a(t_sort *stack, t_move *mv);
void	move_pos_neg(t_sort *stack, t_move *mv, int mini);
void	move_pos(t_sort *stack, t_move *mv, int mini);
void	move_neg(t_sort *stack, t_move *mv, int mini);
void	make_moves(t_sort *stack, void (*fun_ptr) (t_sort *, int), int n);

#endif
