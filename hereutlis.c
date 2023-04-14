/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hereutlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:39:27 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/14 02:43:33 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_qouats(char *p)
{
	int		i ;
	int		j;
	char	*new;
	char	type;

	i = 0;
	j = 0 ;
	new = ft_calloc(ft_strlen(p)+1, 1);
	while (p && p[i])
	{
		if (p[i] == '\'' || p[i] == '"')
		{
			type = p[i];
			i++;
			while (p && p[i] && p[i] != type)
			{
				new[j++] = p[i++];
			}
			i++;
		}
		else
			new[j++] = p[i++];
	}
	free(p);
	return (new);
}

int	is_expandad(char *p)
{
	int	i;

	i = 0;
	while (p && p[i])
	{
		if (p[i] == '\'' || p[i] == '"')
			return (0);
		i++;
	}
	return (1);
}
