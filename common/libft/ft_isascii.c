/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascci.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:17:09 by asettar           #+#    #+#             */
/*   Updated: 2022/10/07 21:17:19 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}