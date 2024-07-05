/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:24:05 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:56 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	check_base(char *base)
{
	int	count;
	int	i;

	count = -1;
	i = 0;
	while (base[++count] != '\0')
	{
		if (base[count] == 43 || base[count] == 45)
			return (0);
		while (base[++i] != '\0')
		{
			if ((base[i] == base[count]) && (i != count))
				return (0);
		}
		i = 0;
	}
	if (count == 0)
		return (0);
	else
		return (count);
}

int	ft_putnbr_base(int nbr, char *base, char ch)
{
	long int	lnbr;
	long int	bs_num;
	int			cnt;

	lnbr = nbr;
	bs_num = check_base(base);
	cnt = 0;
	if (bs_num == 0)
		return (0);
	if (ch == 'u')
		return (ft_uitoa(nbr, base, 0));
	if (lnbr < 0)
	{
		cnt += write(1, "-", 1);
		lnbr *= -1;
	}
	if (lnbr >= 0 && lnbr < bs_num)
		cnt += write(1, &base[lnbr], 1);
	else
	{
		cnt += ft_putnbr_base(lnbr / bs_num, base, ch);
		cnt += write(1, &base[lnbr % bs_num], 1);
	}
	return (cnt);
}
