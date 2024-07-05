/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:20 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/15 16:01:01 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*cleanup(char	*str, int n)
{
	int		i;
	int		count;
	char	*nstr;

	count = ft_strlen(str);
	nstr = (char *)ft_calloc(count + 1, 1);
	if (n < 0)
	{
		free(nstr);
		nstr = (char *)ft_calloc(count + 2, 1);
	}
	if (!nstr)
		return (NULL);
	i = -1;
	if (n < 0)
		nstr[++i] = '-';
	while (--count >= 0)
		nstr[++i] = str[count];
	free(str);
	return (nstr);
}

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

char	*ft_itoa_base(int n, char *base)
{
	int		i;
	int		bs_num;
	long	lnb;
	char	*str;

	i = -1;
	bs_num = check_base(base);
	lnb = n;
	str = (char *)ft_calloc(11, 1);
	if (!str)
		return (NULL);
	if (lnb < 0)
		lnb *= -1;
	while (lnb >= bs_num)
	{
		str[++i] = base[lnb % bs_num];
		lnb /= bs_num;
	}
	str[++i] = base[lnb];
	str = cleanup(str, n);
	return (str);
}
