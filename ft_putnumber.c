/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/15 03:34:42 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len_str)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len_str = *len_str + 11;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		(*len_str)++;
		nb *= -1;
		ft_putnbr(nb, len_str);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, len_str);
		ft_putnbr(nb % 10, len_str);
	}
	else
	{
		ft_putchr((nb + '0'), len_str);
	}
}

void	ft_putptr(unsigned int nb, int *len_str)
{
	int		i;
	char	*hexnbr;
	char	str[25];

	hexnbr = "0123456789abcdef";
	write(1, "0x", 2);
	*len_str = *len_str + 2;
	if (nb == 0)
	{
		ft_putchr('0', len_str);
		return ;
	}
	i = 0;
	while (nb != 0)
	{
		str[i] = hexnbr[nb % 16];
		nb = nb / 16;
		i++;
	}
	while (i-- != 0)
		ft_putchr(str[i], len_str);
}

void	ft_puthex(unsigned int nb, int *len_str, char check_x)
{
	int		i;
	char	*hexnbr;
	char	str[25];

	if (check_x == 'x')
		hexnbr = "0123456789abcdef";
	else if (check_x == 'X')
		hexnbr = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchr('0', len_str);
		return ;
	}
	i = 0;
	while (nb != 0)
	{
		str[i] = hexnbr[nb % 16];
		nb = nb / 16;
		i++;
	}
	while (i != 0)
		ft_putchr(str[--i], len_str);
}

void	ft_putuns_nbr(unsigned int nb, int *len_str)
{
	if (nb > 9)
	{
		ft_putuns_nbr(nb / 10, len_str);
		ft_putuns_nbr(nb % 10, len_str);
	}
	else
		ft_putchr((nb + '0'), len_str);
}
