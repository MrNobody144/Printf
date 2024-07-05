/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:20 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:25 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

static int	cleanup(char *str, int flag)
{
	int	cnt;
	int	count;
	int	temp;

	cnt = 0;
	count = ft_strlen(str);
	while (--count >= 0)
	{
		if (str[count] >= 65 && str[count] <= 90)
		{
			if (flag)
			{
				temp = str[count] + 32;
				cnt += write(1, &temp, 1);
			}
			else
				cnt += write(1, &str[count], 1);
		}
		else
			cnt += write(1, &str[count], 1);
	}
	return (cnt);
}

static unsigned long	check_base(char *base)
{
	unsigned long	count;
	unsigned long	i;

	count = 0;
	i = 0;
	while (base[count] != '\0')
	{
		if (base[count] == 43 || base[count] == 45)
			return (0);
		while (base[++i] != '\0')
		{
			if ((base[i] == base[count]) && (i != count))
				return (0);
		}
		i = 0;
		count++;
	}
	if (count == 0)
		return (0);
	else
		return (count);
}

int	ft_litoa(unsigned long n, char *base, int flag)
{
	int				i;
	int				cnt;
	unsigned long	bs_num;
	char			*str;

	i = -1;
	bs_num = check_base(base);
	str = (char *)ft_calloc(20, 1);
	if (!str)
		return (0);
	cnt = write(1, "0x", 2);
	while (n >= bs_num)
	{
		str[++i] = base[n % bs_num];
		n /= bs_num;
	}
	str[++i] = base[n];
	cnt += cleanup(str, flag);
	free(str);
	return (cnt);
}
