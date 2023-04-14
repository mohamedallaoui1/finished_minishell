/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:35:10 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/14 02:41:28 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_qoutes_norm(char *p, int *i, int *j, int *k)
{
	if (p[(*i)] == '"')
	{
		(*j)++;
		(*i)++;
		while (p[(*i)] && p[(*i)] != '"')
			(*i)++;
		if (p[(*i)++] == '"')
			(*j)++;
	}
	else if (p[(*i)] == '\'')
	{
		(*k)++;
		(*i)++;
		while (p[(*i)] && p[(*i)] != '\'')
			(*i)++;
		if (p[(*i)++] == '\'')
			(*k)++;
	}
	else
		(*i)++;
}

int	check_quotes(char *p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (p[i])
		check_qoutes_norm(p, &i, &j, &k);
	if (j % 2 == 0 && k % 2 == 0)
		return (1);
	else
		return (0);
}
