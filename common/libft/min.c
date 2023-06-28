/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:45:38 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 02:46:23 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
