/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:56:29 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/14 18:06:14 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupper(char *str)
{
	int		i;
	int		q;
	char	*nstr;

	i = -1;
	q = -1;
	nstr = ft_calloc(ft_strlen(str), 1);
	while (str[++i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			nstr[++q] = str[i] - 32;
		else if (str[i] < 48 || str[i] > 57)
			return (NULL);
		else
			nstr[++q] = str[i];
	}
	return (nstr);
}
