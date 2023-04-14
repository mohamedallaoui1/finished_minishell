/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:06:33 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/14 02:28:59 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_putnbr(int fd, int a)
{
	char	*p;
	int		c;

	p = ft_itoa(a);
	write (fd, p, ft_strlen1(p));
	c = ft_strlen1(p);
	free(p);
	return (c);
}
