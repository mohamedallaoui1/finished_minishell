/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specejoine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 08:47:16 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/13 17:59:31 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_specejoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s3;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
		s1 = ft_strdup("");
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	s3 = (char *)ft_calloc(sizeof(char) * (i + j + 2), 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s3[k++] = s1[i++];
		s3[k++] = ' ' ;
	while (s2[j])
		s3[k++] = s2[j++];
	return (free(s1), s3);
}
