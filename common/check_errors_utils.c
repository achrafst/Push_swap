/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asettar <asettar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:00:01 by asettar           #+#    #+#             */
/*   Updated: 2023/02/20 22:09:13 by asettar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	clean_stack_memory(t_sort *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	free_memory(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	invalid_number(char *num)
{
	int	i;
	int	s;

	i = 0;
	if ((num[0] == '-' || num[0] == '+') && num[1])
		i++;
	while (num[i] == '0')
		i++;
	s = i;
	while (num[i])
	{
		if (!ft_isdigit(num[i++]))
			return (1);
	}
	if ((num[0] != '-' || num[0] == '+') && (i - s > 10
			|| (i - s == 10 && ft_memcmp("2147483647", num + s, 10) < 0)))
		return (1);
	if (num[0] == '-' && (i - s > 10
			|| (i - s == 10 && ft_memcmp("2147483648", num + s, 10) < 0)))
		return (1);
	return (0);
}

int	invalid_numbers(char **s)
{
	int		i;
	int		j;

	j = -1;
	while (s[++j])
	{
		i = 0;
		if (invalid_number(s[j]))
			return (1);
	}
	return (0);
}

int	check_errors(int ac, char **argv)
{
	char	**s;
	int		len;
	int		j;
	int		i;

	if (ac == 1)
		exit(0);
	i = 0;
	len = 0;
	while (argv[++i])
	{
		s = ft_split(argv[i], ' ');
		if (!s)
			error_exit();
		if (s[0] == NULL)
			error_exit();
		if (invalid_numbers(s))
			error_exit();
		j = -1;
		while (s[++j])
			len++;
		free_memory(s);
	}
	return (len);
}
