/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:21:17 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/24 15:58:11 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static int	ft_format(int ch, va_list index, int cnt)
{
	char	*bs;

	bs = "0123456789ABCDEF";
	if (ch == 'd' || ch == 'i' || ch == 'u')
		cnt += ft_putnbr_base(va_arg(index, int), "0123456789", ch);
	else if (ch == 'x')
		cnt += ft_uitoa(va_arg(index, int), bs, 1);
	else if (ch == 'X')
		cnt += ft_uitoa(va_arg(index, int), bs, 0);
	else if (ch == 'c')
		cnt += ft_putchar(va_arg(index, int));
	else if (ch == 's')
		cnt += ft_putstr(va_arg(index, char *));
	else if (ch == 'p')
		cnt += ft_litoa(va_arg(index, long int), bs, 1);
	else
		cnt -= cnt + 1;
	return (cnt);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	int		cnt;
	va_list	index;

	/* void *a = malloc(100);
	int b = *((int *)a);
	a += sizeof(int) */

	i = -1;
	cnt = 0;
	va_start(index, f);
	while (f[++i])
	{
		if (f[i] == '%')
		{
			i++;
			if (f[i] == '%')
				cnt += write(1, &f[i], 1);
			else
				cnt = ft_format(f[i], index, cnt);
		}
		else
			cnt += write(1, &f[i], 1);
		if (cnt < 0)
			return (-1);
	}
	va_end(index);
	return (cnt);
}

/* int main(void)
{
	//int x = 0;
	//char *str = NULL;


	int z = ft_printf(" %p %p ", 9223372036854775807, -9223372036854775808);
	printf("\n%d\n", z);

	return (0);
} */
