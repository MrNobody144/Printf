/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:55:33 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/15 17:00:18 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_tolower(char *str)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			cnt += write(1, &str[i] + 32, 1);
		else if (str[i] < 48 || str[i] > 57)
			return (0);
		else
			cnt += write(1, &str[i], 1);
	}
	free(str);
	return (cnt);
}
