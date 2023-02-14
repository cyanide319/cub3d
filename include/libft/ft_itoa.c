/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:41:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/18 14:25:14 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_putnum(char *res, unsigned int num, size_t len)
{
	while (num > 0)
	{
		res[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	return (res);
}

static int	ft_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	long	n;

	n = nb;
	i = ft_len(n);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	else
		nb = n;
	str = ft_putnum(str, n, i);
	return (str);
}
