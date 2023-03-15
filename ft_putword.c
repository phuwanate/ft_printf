/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:10:28 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/14 23:25:42 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(char c, int *len_str)
{
	write (1, &c, 1);
	(*len_str)++;
}

void	ft_putstr(char *s, int *len_str)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		(*len_str)++;
		i++;
	}
}
