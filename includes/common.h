/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:36:07 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 22:06:00 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

typedef struct s_sort
{
	int		*a;
	int		a_size;
	int		*b;
	int		b_size;
}t_sort;

void	error_exit(void);
void	clean_stack_memory(t_sort *stack);
void	display_a(t_sort *stack);
void	display_b(t_sort *stack);

void	push_a(t_sort *stack, int n);
void	push_b(t_sort *stack, int n);
void	swap(int *a, int *b);
void	swap_a(t_sort *stack, int n);
void	swap_b(t_sort *stack, int n);
void	swap_a_b(t_sort *stack, int n);
void	rotate_a(t_sort *stack, int n);
void	rotate_b(t_sort *stack, int n);
void	rotate_a_b(t_sort *stack, int n);
void	reverse_rotate_a(t_sort *stack, int n);
void	reverse_rotate_b(t_sort *stack, int n);
void	reverse_rotate_a_b(t_sort *stack, int n);

int		check_errors(int ac, char **argv);
int		invalid_numbers(char **s);
int		invalid_number(char *num);
void	free_memory(char **s);
void	put_numbers_to_stack_a(char **argv, t_sort *stack);
void	put_to_stack(char **s, t_sort *stack);
int		repeated_numbers(t_sort *stack, int number);
void	ft_initialize_stack(t_sort *stack, int len);

#endif
