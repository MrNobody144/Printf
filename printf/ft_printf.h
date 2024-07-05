/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:09:51 by jianliew          #+#    #+#             */
/*   Updated: 2024/05/20 16:40:32 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *f, ...);
char	*ft_itoa_base(int n, char *base);
int		ft_tolower(char *str);
char	*ft_toupper(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base(int n, char *base, char ch);
int		ft_uitoa(unsigned int n, char *base, int flag);
int		ft_litoa(unsigned long n, char *base, int flag);
void	ft_bzero(void *ptr, int size);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *str);
void	ft_bzero(void *ptr, int size);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *str);

#endif
