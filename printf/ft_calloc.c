/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:57:11 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/13 14:34:50 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		i;
	void	*ptr;

	i = -1;
	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (num > 2147483647 / size)
		return (NULL);
	ptr = (void *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}
