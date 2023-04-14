/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoatjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:20:58 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/13 17:24:20 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_specequaot(char *s1, char *s2)
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
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s3[k++] = s1[i++];
	s3[k++] = ' ' ;
	s3[k++] = '\'';
	while (s2[j])
		s3[k++] = s2[j++];
	s3[k++] = '\'';
	s3[k] = '\0';
	return (free(s1), s3);
}
