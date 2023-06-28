/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 05:34:26 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 05:34:27 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "common.h"

void	read_instructions(t_sort *stack);
int		check_valid_instruction(t_sort *stack, char *line);
int		sorted_stack(t_sort *stack);

#endif